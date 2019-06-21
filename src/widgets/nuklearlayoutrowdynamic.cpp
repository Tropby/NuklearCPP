#include "nuklearlayoutrowdynamic.h"
#include <iostream>

namespace nkcpp
{
    NuklearLayoutRowDynamic::NuklearLayoutRowDynamic(nk_context *ctx, int height, int colCount) : NuklearContainer (ctx)
    {
        this->height = height;
        for( int i = 0; i < colCount; i++ )
            this->cols.push_back(1.0f / colCount);
    }

    NuklearLayoutRowDynamic::NuklearLayoutRowDynamic(nk_context *ctx, int height, std::vector<float> cols) : NuklearContainer (ctx)
    {
        this->height = height;
        this->cols = cols;
    }

    void NuklearLayoutRowDynamic::render()
    {
        nk_layout_row_begin(ctx, NK_DYNAMIC, this->height, static_cast<int>(this->cols.size()));
        {
            unsigned int i = 0;
            for( NuklearElement * ne : this->childs )
            {                
                nk_layout_row_push(ctx, this->cols[ i % this->cols.size() ]);
                if( ne->isVisible() )
                {
                    ne->render();
                }
                i++;
            }
        }
        nk_layout_row_end(ctx);
    }
}
