#include "../../../nuklearcppconfig.h"
#ifdef NK_CPP_INCLUDE_GDI

#include <windows.h>
#include "../../../nuklear/nuklear.h"

#include "nukleargdiinput.h"

namespace nkcpp
{
    NuklearGDIInput::NuklearGDIInput(struct nk_context *ctx)
    {
        this->ctx = ctx;
    }

    void NuklearGDIInput::update()
    {
        /* Input */
        MSG msg;
        nk_input_begin(ctx);
        if (needs_refresh == 0)
        {
            if (GetMessageW(&msg, nullptr, 0, 0) <= 0)
                running = 0;
            else {
                TranslateMessage(&msg);
                DispatchMessageW(&msg);
            }
            needs_refresh = 1;
        }
        else
        {
            needs_refresh = 0;
        }

        while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                running = 0;
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
            needs_refresh = 1;
        }
        nk_input_end(ctx);
    }

    bool NuklearGDIInput::isRunning()
    {
        return running != 0;
    }
}
#endif
