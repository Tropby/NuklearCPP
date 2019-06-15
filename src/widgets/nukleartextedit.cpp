#include "nukleartextedit.h"

#include <string.h>

namespace nkcpp
{
    NuklearTextEdit::NuklearTextEdit(struct nk_context *ctx) : NuklearElement (ctx), onChange(nullptr), onLostFocus(nullptr)
    {

    }

    void NuklearTextEdit::render()
    {
        nk_flags event = nk_edit_string_zero_terminated(ctx,
                NK_EDIT_BOX|NK_EDIT_AUTO_SELECT, //fcous will auto select all text (NK_EDIT_BOX not sure)
                buffer, sizeof(buffer), nk_filter_ascii);//nk_filter_ascii Text Edit accepts text types.

        switch( event )
        {
        case NK_EDIT_ACTIVE:
            if( onChange )
                onChange();
            break;
        case NK_EDIT_INACTIVE:
            break;
        case NK_EDIT_ACTIVATED:
            break;
        case NK_EDIT_DEACTIVATED:
            break;
        case NK_EDIT_COMMITED:
            if( onLostFocus )
                onLostFocus();
            break;
        }
    }

    void NuklearTextEdit::setText(std::string text)
    {
        strcpy_s( buffer, sizeof(buffer), text.c_str() );
    }

    std::string NuklearTextEdit::getText()
    {
        return std::string(buffer);
    }

    void NuklearTextEdit::setOnChange(NK_CPP_CALLBACK_FUNCTION onChange)
    {
        this->onChange = onChange;
    }

    void NuklearTextEdit::setOnLostFocus(NK_CPP_CALLBACK_FUNCTION onLostFocus)
    {
        this->onLostFocus = onLostFocus;
    }
}
