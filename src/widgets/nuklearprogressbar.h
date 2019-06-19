#ifndef NUKLEARPROGRESSBAR_H
#define NUKLEARPROGRESSBAR_H

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearProgressBar : public NuklearElement
    {
    public:
        NuklearProgressBar(struct nk_context * ctx);

        void render();

        void setValue( unsigned int value );
        void setMax( unsigned int max );
        void setModifyable( bool modifyable );

        unsigned int getValue();
        unsigned int getMax();
        bool isModifyable();

        void setOnChange( NK_CPP_CALLBACK_FUNCTION callback );

    private:
        nk_size value;
        nk_size max;
        nk_modify modifyable;

        NK_CPP_CALLBACK_FUNCTION onChange;
    };
}

#endif // NUKLEARPROGRESSBAR_H
