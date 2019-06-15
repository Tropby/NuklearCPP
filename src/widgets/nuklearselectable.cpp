#include "nuklearselectable.h"

namespace nkcpp
{
    NuklearSelectable::NuklearSelectable(nk_context *ctx) : NuklearElement (ctx), active(0)
    {

    }

    void NuklearSelectable::render()
    {
        nk_selectable_label( this->ctx, text.c_str(), NK_TEXT_LEFT, &active );
    }

    void NuklearSelectable::setText(std::string text)
    {
        this->text = text;
    }

    bool NuklearSelectable::isActive()
    {
        return active;
    }

    void NuklearSelectable::setActive(bool active)
    {
        this->active = ( active ? 1 : 0 );
    }
}
