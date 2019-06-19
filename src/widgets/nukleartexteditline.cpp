#include "nukleartexteditline.h"

#include <string.h>

namespace nkcpp
{
    NuklearTextEditLine::NuklearTextEditLine(struct nk_context *ctx) : NuklearElement (ctx), onChange(nullptr), onLostFocus(nullptr)
    {

    }

    void NuklearTextEditLine::render()
    {
        nk_flags event = nk_edit_string_zero_terminated(ctx,
                NK_EDIT_SIMPLE|(readonly?NK_EDIT_READ_ONLY:0),
                buffer, sizeof(buffer),

                    nk_filter_decimal);

        switch( event )
        {
        case NK_EDIT_ACTIVE:
            if( onChange )
                onChange(this);
            break;
        case NK_EDIT_INACTIVE:
            break;
        case NK_EDIT_ACTIVATED:
            break;
        case NK_EDIT_DEACTIVATED:
            break;
        case NK_EDIT_COMMITED:
            if( onLostFocus )
                onLostFocus(this);
            break;
        }
    }

    void NuklearTextEditLine::setText(std::string text)
    {
        strcpy_s( buffer, sizeof(buffer), text.c_str() );
    }

    std::string NuklearTextEditLine::getText()
    {
        return std::string(buffer);
    }

    void NuklearTextEditLine::setOnChange(NK_CPP_CALLBACK_FUNCTION onChange)
    {
        this->onChange = onChange;
    }

    void NuklearTextEditLine::setOnLostFocus(NK_CPP_CALLBACK_FUNCTION onLostFocus)
    {
        this->onLostFocus = onLostFocus;
    }

    void NuklearTextEditLine::setReadonly(bool readonly)
    {
        this->readonly = readonly;
    }

    bool NuklearTextEditLine::isReadonly()
    {
        return this->readonly;
    }
}
