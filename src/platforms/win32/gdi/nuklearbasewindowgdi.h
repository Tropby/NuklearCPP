#ifndef NUKLEARBASEWINDOWGDI_H
#define NUKLEARBASEWINDOWGDI_H

#include "../../../nuklearcppconfig.h"
#ifdef NK_CPP_INCLUDE_GDI

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "nukleargdiinput.h"

#include "../nuklearbasewindowwin32.h"
#include "../../../nuklear/demo/gdi/nuklear_gdi.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace nkcpp
{
    class NuklearBaseWindowGDI : public NuklearBaseWindowWin32
    {
    public:
        NuklearBaseWindowGDI(NuklearBaseWindowBehavior behavior);
        ~NuklearBaseWindowGDI();
        static LRESULT CALLBACK WindowProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);
        bool closed();

        void resize( int width, int height );
        void centerWindow();

    protected:
        void begin();
        void end();
        void init(std::string fontName = "Arial", int fontSize = 14);

    private:
        /* GDI Handle */
        HDC dc;

        GdiFont* font;
        NuklearGDIInput * input;
    };
}

#endif

#endif // NUKLEARBASEWINDOWGDI_H
