#ifndef NUKLEARCPPAPPLICATION_H
#define NUKLEARCPPAPPLICATION_H

#include "platforms/nuklearbasewindow.h"
#include <list>

namespace nkcpp
{
    class NuklearCPPApplication
    {
    public:
        static NuklearCPPApplication *getInstace();
        static int exec();

        static void registerBaseWindow( NuklearBaseWindow * bw );
    private:
        NuklearCPPApplication();
        static NuklearCPPApplication * instance;
        std::list<NuklearBaseWindow*> windows;
    };
}
#endif // NUKLEARCPPAPPLICATION_H
