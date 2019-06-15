#include "nuklearlayoutrowdynamic.h"

namespace nkcpp
{
    NuklearLayoutRowDynamic::NuklearLayoutRowDynamic(nk_context *ctx, int height, int cols) : NuklearElement (ctx)
    {
        this->height = height;
        this->cols = cols;
    }

    void NuklearLayoutRowDynamic::render()
    {
        nk_layout_row_dynamic(ctx, this->height, this->cols);
        NuklearElement::renderChilds();
    }
}