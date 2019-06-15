#ifndef NUKLEARSELECTABLE_H
#define NUKLEARSELECTABLE_H

#include <string>
#include <functional>

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearSelectable : public NuklearElement
    {
    public:
        NuklearSelectable(struct nk_context * ctx);

        void render();

        void setText( std::string text );

        bool isActive();

        void setActive( bool active );

    private:
        std::string text;

        int active;
    };
}

#endif // NUKLEARSELECTABLE_H
