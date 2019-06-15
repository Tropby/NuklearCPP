#ifndef NUKLEARBASEWINDOWWIN32_H
#define NUKLEARBASEWINDOWWIN32_H

#include "../nuklearbasewindow.h"
#include <windows.h>

namespace nkcpp
{
    class NuklearBaseWindowWin32 : public NuklearBaseWindow
    {
    public:
        NuklearBaseWindowWin32( NuklearBaseWindowBehavior behavior );

    protected:
        WNDCLASSW wc;
        HWND wnd;

        // NuklearBaseWindow interface
    public:
        void setWindowTitle(std::string title);
    };
}

#endif // NUKLEARBASEWINDOWWIN32_H
