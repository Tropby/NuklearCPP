#include "nuklearcheckbox.h"

namespace nkcpp
{
    NuklearCheckbox::NuklearCheckbox(nk_context *ctx) : NuklearElement (ctx), active(0)
    {

    }

    void NuklearCheckbox::render()
    {
        nk_checkbox_label( this->ctx, text.c_str(), &active );
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
}
