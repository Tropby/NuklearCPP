#include "nuklearslider.h"

namespace nkcpp
{
    NuklearSlider::NuklearSlider(nk_context *ctx) : NuklearElement (ctx), value(33.0), min(0.0), max(100.0), step(1.0)
    {

    }

    void NuklearSlider::render()
    {
        if( nk_slider_float(ctx, min, &value, max, step) )
        {
            if( onChange )
                onChange(this);
        }
    }

    void NuklearSlider::setMin(float min)
    {
        this->min = min;
    }

    void NuklearSlider::setValue(float value)
    {
        this->value = value;
    }

    void NuklearSlider::setMax(float max)
    {
        this->max = max;
    }

    void NuklearSlider::setStep(float step)
    {
        this->step = step;
    }

    float NuklearSlider::getMin()
    {
        return min;
    }

    float NuklearSlider::getValue()
    {
        return value;
    }

    float NuklearSlider::getMax()
    {
        return max;
    }

    float NuklearSlider::getStep()
    {
        return step;
    }

    void NuklearSlider::setOnChange(NK_CPP_CALLBACK_FUNCTION callback)
    {
        onChange = callback;
    }
}
