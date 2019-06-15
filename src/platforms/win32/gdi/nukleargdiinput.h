#ifndef NUKLEARGDIINPUT_H
#define NUKLEARGDIINPUT_H

#include "../../../nuklearcppconfig.h"
#ifdef NK_CPP_INCLUDE_GDI

#include "../../../nuklear/nuklear.h"

namespace nkcpp
{
    class NuklearGDIInput
    {
    public:
        NuklearGDIInput( nk_context *ctx );

        void update();
        bool isRunning();

    private:
        int running = 1;
        int needs_refresh = 1;

        nk_context *ctx;
    };
}

#endif

#endif // NUKLEARGDIINPUT_H
