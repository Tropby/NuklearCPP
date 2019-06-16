#include "nuklearcheckbox.h"

namespace nkcpp
{
    NuklearCheckbox::NuklearCheckbox(nk_context *ctx) : NuklearElement (ctx), active(0), onChanged(nullptr)
    {

    }

    void NuklearCheckbox::render()
    {
        if( nk_checkbox_label( this->ctx, text.c_str(), &active ) )
        {
            if( onChanged )
                onChanged(this);
        }
    }

    void NuklearCheckbox::setText(std::string text)
    {
        this->text = text;
    }

    bool NuklearCheckbox::isActive()
    {
        return active;
    }

    void NuklearCheckbox::setActive(bool active)
    {
        this->active = ( active ? 1 : 0 );
    }

    void NuklearCheckbox::setOnChanged(NK_CPP_CALLBACK_FUNCTION onChagned)
    {
        this->onChanged = onChagned;
    }
}
