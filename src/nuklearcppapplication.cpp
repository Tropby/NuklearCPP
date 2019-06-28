#include "nuklearcppapplication.h"

namespace nkcpp
{
    NuklearCPPApplication* NuklearCPPApplication::instance = nullptr;

    NuklearCPPApplication *NuklearCPPApplication::getInstace()
    {
        if( !instance )
            instance = new NuklearCPPApplication();
        return instance;
    }

    int NuklearCPPApplication::exec()
    {
        int running = 1;
        while( running )
        {
            running = processEvents();
        }

        return 0;
    }

    int NuklearCPPApplication::processEvents()
    {
        int running = 0;
        NuklearCPPApplication * i = getInstace();
        for( NuklearBaseWindow *bw : i->windows )
        {
            if( bw->isRunning() )
            {
                bw->update();
                running += 1;
            }
        }
        return running;
    }

    void NuklearCPPApplication::registerBaseWindow(NuklearBaseWindow *bw)
    {
        getInstace()->windows.push_back( bw );
    }

    NuklearCPPApplication::NuklearCPPApplication()
    {

    }
}
