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
        NuklearCPPApplication * i = getInstace();

        int running = 1;
        while( running )
        {
            running = 0;
            for( NuklearBaseWindow *bw : i->windows )
            {
                if( bw->isRunning() )
                {
                    bw->update();
                    running += 1;
                }
            }
        }

        return 0;
    }

    void NuklearCPPApplication::registerBaseWindow(NuklearBaseWindow *bw)
    {
        getInstace()->windows.push_back( bw );
    }

    NuklearCPPApplication::NuklearCPPApplication()
    {

    }
}
