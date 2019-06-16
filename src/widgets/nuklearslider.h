#ifndef NUKLEARSLIDER_H
#define NUKLEARSLIDER_H

#include <string>
#include <functional>

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearSlider : public NuklearElement
    {
    public:
        NuklearSlider(struct nk_context * ctx);

        void render();

        void setMin( float min );
        void setValue( float value );
        void setMax( float max );
        void setStep( float step );

        float getMin();
        float getValue();
        float getMax();
        float getStep();

        void setOnChange( NK_CPP_CALLBACK_FUNCTION callback );

    private:
        float value;
        float min;
        float max;
        float step;

        NK_CPP_CALLBACK_FUNCTION onChange;
    };
}

#endif // NUKLEARSLIDER_H
