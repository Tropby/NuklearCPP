#ifndef NUKLEARCHECKBOX_H
#define NUKLEARCHECKBOX_H

#include <string>
#include <functional>

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearCheckbox : public NuklearElement
    {
    public:
        NuklearCheckbox(struct nk_context * ctx);

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

#endif // NUKLEARCHECKBOX_H
