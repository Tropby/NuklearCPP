/**
  * @author Tropby
  * @date 2019-06-20
  **/

#ifndef NUKLEARCPPAPPLICATION_H
#define NUKLEARCPPAPPLICATION_H

#include "platforms/nuklearbasewindow.h"
#include <list>

namespace nkcpp
{
    /**
     * @brief The NuklearCPPApplication class
     *
     * This class is used to handle all base windows that are used in
     * your application. By now the Nuklear ANSI C demo libraries can
     * only handle one Window at a time.
     */
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
