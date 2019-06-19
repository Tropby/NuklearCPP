#ifndef NUKLEARCHART_H
#define NUKLEARCHART_H

#include <vector>

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearChart : public NuklearElement
    {
    public:
        NuklearChart(struct nk_context * ctx);

        void addValue( float value );
        void setChartType( nk_chart_type chartType );

        void setCount( int count );
        void setOffset( int offset );

        void render();

    private:
        std::vector<float> values;
        int count;
        int offset;
        nk_chart_type chartType;
    };
}



#endif // NUKLEARCHART_H
