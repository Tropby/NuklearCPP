#include "../../../nuklearcppconfig.h"
#ifdef NK_CPP_INCLUDE_D3D9

#include "nuklearbasewindowd3d9.h"

#define NK_ASSERT
#include "../../../nuklear/nuklear.h"

#define COBJMACROS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d9.h>

namespace nkcpp
{

    NuklearBaseWindowD3D9::NuklearBaseWindowD3D9( NuklearBaseWindowBehavior behavior ) : NuklearBaseWindowWin32 ( behavior )
    {

    }

    NuklearBaseWindowD3D9::~NuklearBaseWindowD3D9()
    {
        nk_d3d9_shutdown();
        if (deviceEx)IDirect3DDevice9Ex_Release(deviceEx);
        else IDirect3DDevice9_Release(device);
        UnregisterClassW(wc.lpszClassName, wc.hInstance);
    }

    LRESULT NuklearBaseWindowD3D9::WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        switch (msg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_SIZE:

            NuklearBaseWindowD3D9* ta = reinterpret_cast<NuklearBaseWindowD3D9*>(GetWindowLongPtrW(wnd, 0));

            if( ta )
            {
                if (ta->device)
                {
                    UINT width = LOWORD(lparam);
                    UINT height = HIWORD(lparam);

                    if (width != 0 && height != 0 &&
                        (width != ta->present.BackBufferWidth || height != ta->present.BackBufferHeight))
                    {
                        nk_d3d9_shutdown();
                        if (ta->deviceEx)IDirect3DDevice9Ex_Release(ta->deviceEx);
                        else IDirect3DDevice9_Release(ta->device);
                        ta->create_d3d9_device(width, height);

                        ta->ctx = nk_d3d9_init(ta->device, width, height);
                        {
                            struct nk_font_atlas *atlas;
                            nk_d3d9_font_stash_begin(&atlas);
                            nk_d3d9_font_stash_end();
                        }
                    }
                    if( ta->behavior == NK_NBWB_SINGLE_WINDOW )
                    {
                        for( NuklearWindow * nw : ta->nuklearWindows )
                            nw->resize(0,0,width,height);
                    }
                }
            }
            break;
        }

        if (nk_d3d9_handle_event(wnd, msg, wparam, lparam))
            return 0;

        return DefWindowProcW(wnd, msg, wparam, lparam);
    }

    bool NuklearBaseWindowD3D9::closed()
    {
        return !running;
    }

    void NuklearBaseWindowD3D9::resize(int width, int height)
    {

        if (width != 0 && height != 0 &&
            (width != present.BackBufferWidth || height != present.BackBufferHeight))
        {
            SetWindowPos(wnd, nullptr, 0, 0, width, height, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

            nk_d3d9_shutdown();
            if (deviceEx)IDirect3DDevice9Ex_Release(deviceEx);
            else IDirect3DDevice9_Release(device);
            create_d3d9_device(width, height);

            ctx = nk_d3d9_init(device, width, height);
            {
                struct nk_font_atlas *atlas;
                nk_d3d9_font_stash_begin(&atlas);
                nk_d3d9_font_stash_end();
            }
        }
        if( behavior == NK_NBWB_SINGLE_WINDOW )
        {
            for( NuklearWindow * nw : nuklearWindows )
               nw->resize(0,0,width,height);
        }
    }

    void NuklearBaseWindowD3D9::begin()
    {
        /* Input */
        MSG msg;
        nk_input_begin(ctx);
        while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                running = 0;
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
        nk_input_end(ctx);
    }

    void NuklearBaseWindowD3D9::end()
    {
        /* Draw */
          {
              HRESULT hr;
              hr = IDirect3DDevice9_Clear(device, 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL,
                  D3DCOLOR_COLORVALUE(bg.r, bg.g, bg.b, bg.a), 0.0f, 0);
              NK_ASSERT(SUCCEEDED(hr));

              hr = IDirect3DDevice9_BeginScene(device);
              NK_ASSERT(SUCCEEDED(hr));
              nk_d3d9_render(NK_ANTI_ALIASING_ON);
              hr = IDirect3DDevice9_EndScene(device);
              NK_ASSERT(SUCCEEDED(hr));

              if (deviceEx) {
                  hr = IDirect3DDevice9Ex_PresentEx(deviceEx, NULL, NULL, NULL, NULL, 0);
              } else {
                  hr = IDirect3DDevice9_Present(device, NULL, NULL, NULL, NULL);
              }
              if (hr == D3DERR_DEVICELOST || hr == D3DERR_DEVICEHUNG || hr == D3DERR_DEVICEREMOVED) {
                  /* to recover from this, you'll need to recreate device and all the resources */
                  MessageBoxW(NULL, L"D3D9 device is lost or removed!", L"Error", 0);
                  exit(-1);
              } else if (hr == S_PRESENT_OCCLUDED) {
                  /* window is not visible, so vsync won't work. Let's sleep a bit to reduce CPU usage */
                  Sleep(10);
              }
              NK_ASSERT(SUCCEEDED(hr));
          }
    }

    void NuklearBaseWindowD3D9::init()
    {
        RECT rect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
        DWORD style = WS_OVERLAPPEDWINDOW;
        DWORD exstyle = WS_EX_APPWINDOW;

        /* Win32 */
        memset(&wc, 0, sizeof(wc));
        wc.style = CS_DBLCLKS;

        wc.cbWndExtra  = sizeof(NuklearBaseWindowD3D9*);
        wc.lpfnWndProc = &NuklearBaseWindowD3D9::WindowProc;

        wc.hInstance = GetModuleHandleW(0);
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.lpszClassName = L"NuklearWindowClass";
        RegisterClassW(&wc);

        AdjustWindowRectEx(&rect, style, FALSE, exstyle);

        wnd = CreateWindowExW(exstyle, wc.lpszClassName, L"Nuklear Demo",
            style | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
            rect.right - rect.left, rect.bottom - rect.top,
            nullptr, nullptr, wc.hInstance, nullptr);

        SetWindowLongPtrW(wnd, 0, reinterpret_cast<LONG_PTR>(this));

        create_d3d9_device(WINDOW_WIDTH, WINDOW_HEIGHT);

        /* GUI */
        ctx = nk_d3d9_init(device, WINDOW_WIDTH, WINDOW_HEIGHT);
        {
            struct nk_font_atlas *atlas;
            nk_d3d9_font_stash_begin(&atlas);
            nk_d3d9_font_stash_end();
        }

        bg.r = 0.10f;
        bg.g = 0.18f;
        bg.b = 0.24f;
        bg.a = 1.0f;

        NuklearBaseWindow::init();
    }

    void NuklearBaseWindowD3D9::create_d3d9_device(int width, int height)
    {
        device = nullptr;

        HRESULT hr;

        present.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
        present.BackBufferWidth = width;
        present.BackBufferHeight = height;
        present.BackBufferFormat = D3DFMT_X8R8G8B8;
        present.BackBufferCount = 1;
        present.MultiSampleType = D3DMULTISAMPLE_NONE;
        present.SwapEffect = D3DSWAPEFFECT_DISCARD;
        present.hDeviceWindow = wnd;
        present.EnableAutoDepthStencil = TRUE;
        present.AutoDepthStencilFormat = D3DFMT_D24S8;
        present.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
        present.Windowed = TRUE;

        {/* first try to create Direct3D9Ex device if possible (on Windows 7+) */
            typedef HRESULT WINAPI Direct3DCreate9ExPtr(UINT, IDirect3D9Ex**);
            Direct3DCreate9ExPtr *Direct3DCreate9Ex = (Direct3DCreate9ExPtr *)GetProcAddress(GetModuleHandleA("d3d9.dll"), "Direct3DCreate9Ex");
            if (Direct3DCreate9Ex) {
                IDirect3D9Ex *d3d9ex;
                if (SUCCEEDED(Direct3DCreate9Ex(D3D_SDK_VERSION, &d3d9ex)))
                {
                    hr = d3d9ex->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, wnd,
                        D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE | D3DCREATE_FPU_PRESERVE,
                        &present, NULL, &deviceEx);
                    if (SUCCEEDED(hr))
                    {
                        device = (IDirect3DDevice9 *)deviceEx;
                    }
                    else
                    {
                        /* hardware vertex processing not supported, no big deal
                        retry with software vertex processing */
                        hr = d3d9ex->CreateDeviceEx( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, wnd,
                            D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE | D3DCREATE_FPU_PRESERVE,
                            &present, NULL, &deviceEx);
                        if (SUCCEEDED(hr)) {
                            device = (IDirect3DDevice9 *)deviceEx;
                        }
                    }
                    IDirect3D9Ex_Release(d3d9ex);
                }
            }
        }

        if (!device) {
            /* otherwise do regular D3D9 setup */
            IDirect3D9 *d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

            hr = d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, wnd,
                D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE | D3DCREATE_FPU_PRESERVE,
                &present, &device);
            if (hr != D3D_OK) {
                /* hardware vertex processing not supported, no big deal
                retry with software vertex processing */
                hr = d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, wnd,
                    D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE | D3DCREATE_FPU_PRESERVE,
                    &present, &device);
                NK_ASSERT(SUCCEEDED(hr));
            }
            IDirect3D9_Release(d3d9);
        }

        if(!device)
        {
            IDirect3D9* pd3d = Direct3DCreate9(D3D_SDK_VERSION);

            present = { 0 };
            present.hDeviceWindow = wnd;
            present.Windowed = true;
            present.SwapEffect = D3DSWAPEFFECT_DISCARD;
            present.BackBufferCount = 2;
            present.BackBufferFormat = D3DFMT_X8R8G8B8;
            present.BackBufferHeight = WINDOW_HEIGHT;
            present.BackBufferWidth = WINDOW_WIDTH;
            present.EnableAutoDepthStencil = TRUE;
            present.AutoDepthStencilFormat = D3DFMT_D16;
            present.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
            present.MultiSampleType = D3DMULTISAMPLE_NONE;
            pd3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, NULL, D3DCREATE_HARDWARE_VERTEXPROCESSING, &present, &device);
        }
    }
}
#endif
