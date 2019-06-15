#ifndef NUKLEARBASEWINDOWD3D9_H
#define NUKLEARBASEWINDOWD3D9_H

#include "../../../nuklearcppconfig.h"
#ifdef NK_CPP_INCLUDE_D3D9

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <d3d9.h>

#include "../nuklearbasewindowwin32.h"
#include "../../../nuklear/demo/d3d9/nuklear_d3d9.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace nkcpp
{
    class NuklearBaseWindowD3D9 : public NuklearBaseWindowWin32
    {
    public:
        NuklearBaseWindowD3D9( NuklearBaseWindowBehavior behavior );
        ~NuklearBaseWindowD3D9();

        static LRESULT CALLBACK WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
        bool closed();

        void resize( int width, int height );

    protected:
        void begin();
        void end();
        void init();

    private:
        IDirect3DDevice9 *device;
        IDirect3DDevice9Ex *deviceEx;
        D3DPRESENT_PARAMETERS present;

        struct nk_colorf bg;
        int running;

        void create_d3d9_device(int width, int height);
    };
}

#endif

#endif // NUKLEARBASEWINDOWD3D9_H
