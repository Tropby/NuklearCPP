#ifndef NUKLEARGUIPARSER_H
#define NUKLEARGUIPARSER_H

#include "nuklearcpp.h"
#include <string>

namespace nkcpp
{
    class NuklearGUIParser
    {
    public:
        NuklearGUIParser();

        void load( std::string filename, NuklearBaseWindow * baseWindow, NuklearContainer * baseContainer = nullptr );
    };
}

#endif // NUKLEARGUIPARSER_H
