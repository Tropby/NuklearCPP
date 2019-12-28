#ifndef NUKLEARBASEWINDOW_H
#define NUKLEARBASEWINDOW_H

#include <list>
#include "../widgets/nuklearwindow.h"
#include "../nuklear/nuklear.h"

namespace nkcpp
{
    class NuklearBaseWindow
    {
    public:
        enum NuklearBaseWindowBehavior
        {
            NK_NBWB_MULTI_WINDOW,
            NK_NBWB_SINGLE_WINDOW
        };

        NuklearBaseWindow(NuklearBaseWindowBehavior behavior );
        virtual ~NuklearBaseWindow(){}

        void update();
        bool isRunning();
        virtual void resize( int width, int height ) = 0;

        NuklearWindow *addNuklearWindow();

        virtual void setWindowTitle(std::string title) = 0;

    protected:
        virtual void begin() = 0;
        virtual void end() = 0;
        virtual void init( std::string fontName = "Arial", int fontSize = 14 );
        virtual bool closed() = 0;

        nk_context * ctx;

        std::list<NuklearWindow *> nuklearWindows;
        NuklearBaseWindowBehavior behavior;
    };
}

#endif // NUKLEARBASEWINDOW_H
