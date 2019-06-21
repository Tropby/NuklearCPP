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

        void setOnChanged( NK_CPP_CALLBACK_FUNCTION onChagned );
    private:
        std::string text;
        int active;
        NK_CPP_CALLBACK_FUNCTION onChanged;
    };
}

#endif // NUKLEARSELECTABLE_H
