#include "nuklearbutton.h"

namespace nkcpp
{
    NuklearButton::NuklearButton(struct nk_context *ctx) : NuklearElement (ctx), onClick(nullptr)
    {

    }

    void NuklearButton::render()
    {
        if (nk_button_label(this->ctx, this->text.c_str()))
        {
            if( onClick )
                onClick();
        }
    }

    void NuklearButton::setText(std::string text)
    {
        this->text = text;
    }

    void NuklearButton::setOnClick(NK_CPP_CALLBACK_FUNCTION callback)
    {
        this->onClick = callback;
    }
}
