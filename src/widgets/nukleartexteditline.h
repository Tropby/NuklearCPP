#ifndef NUKLEARTEXTEDIT_H
#define NUKLEARTEXTEDIT_H

#include <string>
#include <functional>

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearTextEditLine : public NuklearElement
    {
    public:
        NuklearTextEditLine(struct nk_context * ctx);
        void render();
        void setText( std::string text );
        std::string getText();

        void setOnChange( NK_CPP_CALLBACK_FUNCTION onChange );
        void setOnLostFocus( NK_CPP_CALLBACK_FUNCTION onLostFocus );
        void setReadonly( bool readonly );
        bool isReadonly();

    private:
        std::string text;
        char buffer[1024];

        bool readonly;
        NK_CPP_CALLBACK_FUNCTION onChange;
        NK_CPP_CALLBACK_FUNCTION onLostFocus;

    };
}

#endif // NUKLEARTEXTEDIT_H
