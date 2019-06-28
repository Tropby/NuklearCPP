#include "nuklearbasewindow.h"

#include "../nuklearcppapplication.h"

namespace nkcpp
{
    NuklearBaseWindow::NuklearBaseWindow( NuklearBaseWindowBehavior behavior )
    {
        this->behavior = behavior;
        NuklearCPPApplication::registerBaseWindow(this);
    }

    void NuklearBaseWindow::update()
    {
        begin();
        for( NuklearWindow * nw : nuklearWindows )
        {
            nw->render();
        }
        end();
    }

    bool NuklearBaseWindow::isRunning()
    {
        return !closed();
    }

    NuklearWindow *NuklearBaseWindow::addNuklearWindow()
    {
        NuklearWindow * nw = new NuklearWindow( this->ctx );
        nuklearWindows.push_back(nw);
        return nw;
    }

    void NuklearBaseWindow::init(std::string fontName, int fontSize)
    {

    }
}
