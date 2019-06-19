#include "nuklearprogressbar.h"

namespace nkcpp
{
    NuklearProgressBar::NuklearProgressBar(nk_context *ctx) : NuklearElement (ctx), value(33.0), max(100.0), modifyable(NK_FIXED)
    {

    }

    void NuklearProgressBar::render()
    {
        if( nk_progress(ctx, &value, max, modifyable) )
        {
            if( onChange )
                onChange(this);
        }
    }

    void NuklearProgressBar::setValue(unsigned int value)
    {
        this->value = value;
    }

    void NuklearProgressBar::setMax(unsigned int max)
    {
        this->max = max;
    }

    void NuklearProgressBar::setModifyable(bool modifyable)
    {
        if( modifyable )
        {
            this->modifyable = NK_MODIFIABLE;
        }
        else
        {
            this->modifyable = NK_FIXED;
        }

    }

    unsigned int NuklearProgressBar::getValue()
    {
        return this->value;
    }

    unsigned int NuklearProgressBar::getMax()
    {
        return this->max;
    }

    bool NuklearProgressBar::isModifyable()
    {
        return (modifyable == NK_MODIFIABLE);
    }

    void NuklearProgressBar::setOnChange(NK_CPP_CALLBACK_FUNCTION callback)
    {
        onChange = callback;
    }
}
