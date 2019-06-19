#include "nuklearchart.h"

namespace nkcpp
{
    NuklearChart::NuklearChart(struct nk_context *ctx) : NuklearElement (ctx), count(0), offset(0)
    {

    }

    void NuklearChart::addValue(float value)
    {
        values.push_back(value);
        count++;
    }

    void NuklearChart::setChartType(nk_chart_type chartType)
    {
        this->chartType = chartType;
    }

    void NuklearChart::setCount(int count)
    {
        this->count = count;
    }

    void NuklearChart::setOffset(int offset)
    {
        this->offset = offset;
    }

    void NuklearChart::render()
    {
        int o, c, s;

        o = offset;
        c = count;
        s = static_cast<int>(values.size());

        if ( o > s )
            o = s;

        if( o + c > s )
            c = s - offset;

        nk_plot(ctx, chartType, values.data(), c, o);

        //nk_label( ctx, this->text.c_str(), NK_TEXT_LEFT);
    }
}
