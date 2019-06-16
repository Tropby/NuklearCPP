#ifndef NUKLEARBUTTON_H
#define NUKLEARBUTTON_H

#include <string>
#include <functional>

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearButton : public NuklearElement
    {
    public:
        NuklearButton(struct nk_context * ctx);

        void render();

        void setText( std::string text );

        void setOnClick( NK_CPP_CALLBACK_FUNCTION callback );

    private:
        std::string text;

        NK_CPP_CALLBACK_FUNCTION onClick;
    };
}
#endif // NUKLEARBUTTON_H
