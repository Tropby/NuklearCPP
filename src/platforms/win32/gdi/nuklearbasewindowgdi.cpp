#include "../../../nuklearcppconfig.h"
#ifdef NK_CPP_INCLUDE_GDI

#include "nuklearbasewindowgdi.h"

#define COBJMACROS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define NK_ASSERT
#include "../../../nuklear/nuklear.h"

namespace nkcpp
{
    NuklearBaseWindowGDI::NuklearBaseWindowGDI(NuklearBaseWindowBehavior behavior) : NuklearBaseWindowWin32 ( behavior )
    {

    }

    NuklearBaseWindowGDI::~NuklearBaseWindowGDI()
    {
        nk_gdifont_del(font);
        ReleaseDC(wnd, dc);
        UnregisterClassW(wc.lpszClassName, wc.hInstance);
    }

    void NuklearBaseWindowGDI::begin()
    {
        input->update();
    }

    void NuklearBaseWindowGDI::end()
    {
        /* Draw */
        nk_gdi_render(nk_rgb(30,30,30));
    }

    void NuklearBaseWindowGDI::init()
    {
        ATOM atom;
        RECT rect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
        DWORD style = WS_OVERLAPPEDWINDOW;
        DWORD exstyle = WS_EX_APPWINDOW;

        /* Win32 */
        memset(&wc, 0, sizeof(wc));
        wc.style = CS_DBLCLKS;
        // Reserve space to store the instance pointer
        wc.cbWndExtra  = sizeof(NuklearBaseWindowGDI*);
        wc.lpfnWndProc = &NuklearBaseWindowGDI::WindowProc;

        wc.hInstance = GetModuleHandleW(nullptr);
        wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wc.lpszClassName = L"NuklearWindowClass";
        atom = RegisterClassW(&wc);

        AdjustWindowRectEx(&rect, style, FALSE, exstyle);
        wnd = CreateWindowExW(exstyle, wc.lpszClassName, L"Nuklear Demo",
            style | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
            rect.right - rect.left, rect.bottom - rect.top,
            nullptr, nullptr, wc.hInstance, nullptr);

        SetWindowLongPtrW(wnd, 0, reinterpret_cast<LONG_PTR>(this));

        dc = GetDC(wnd);

        /* GUI */
        font = nk_gdifont_create("Arial", 14);        

        ctx = nk_gdi_init(font, dc, WINDOW_WIDTH, WINDOW_HEIGHT);

        input = new NuklearGDIInput(ctx);

        NuklearBaseWindow::init();
    }

    LRESULT  NuklearBaseWindowGDI::WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        switch (msg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_SIZING:
        case WM_SIZE:
            NuklearBaseWindowGDI* ta = reinterpret_cast<NuklearBaseWindowGDI*>(GetWindowLongPtrW(wnd, 0));

            if( ta )
            {
                // Update Window Rect
                RECT rect;
                if(GetWindowRect(wnd, &rect))
                {
                    int width = rect.right - rect.left;
                    int height = rect.bottom - rect.top;
                    if( ta->behavior == NK_NBWB_SINGLE_WINDOW )
                    {
                        for( NuklearWindow * nw : ta->nuklearWindows )
                            nw->resize( 0, 0, width, height);
                    }
                }
            }
        }

        if (nk_gdi_handle_event(wnd, msg, wparam, lparam))
            return 0;

        return DefWindowProcW(wnd, msg, wparam, lparam);
    }

    bool NuklearBaseWindowGDI::closed()
    {
        return !input->isRunning();
    }

    void NuklearBaseWindowGDI::resize(int width, int height)
    {
        SetWindowPos(wnd, nullptr, 0, 0, width, height, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
        if( behavior == NK_NBWB_SINGLE_WINDOW )
        {
            for( NuklearWindow * nw : nuklearWindows )
               nw->resize(0,0,width,height);
        }
    }
}
#endif
