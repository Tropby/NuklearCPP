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

    private:
        std::string text;

        int active;
    };
}

#endif // NUKLEARCHECKBOX_H
