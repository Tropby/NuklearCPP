#include "nuklearselectable.h"

namespace nkcpp
{
    NuklearSelectable::NuklearSelectable(nk_context *ctx) : NuklearElement (ctx), active(0), onChanged(nullptr)
    {

    }

    void NuklearSelectable::render()
    {
        if( nk_selectable_label( this->ctx, text.c_str(), NK_TEXT_LEFT, &active ) )
        {
            if(onChanged)
                onChanged(this);
        }
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

    void NuklearSelectable::setOnChanged(NK_CPP_CALLBACK_FUNCTION onChagned)
    {
        this->onChanged = onChagned;
    }
}
