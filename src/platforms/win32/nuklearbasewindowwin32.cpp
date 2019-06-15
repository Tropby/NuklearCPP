#include "nuklearbasewindowwin32.h"

#include <windows.h>

namespace nkcpp
{
    NuklearBaseWindowWin32::NuklearBaseWindowWin32(NuklearBaseWindowBehavior behavior) : NuklearBaseWindow (behavior)
    {

    }

    void NuklearBaseWindowWin32::setWindowTitle(std::string title)
    {
        SetWindowTextA(wnd, title.c_str());
    }
}
