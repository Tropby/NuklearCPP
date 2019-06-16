#include "nuklearlayoutrowstatic.h"

namespace nkcpp
{
    NuklearLayoutRowStatic::NuklearLayoutRowStatic(nk_context *ctx, int height, int width, int cols) : NuklearContainer (ctx)
    {
        this->height = height;
        this->width = width;
        this->cols = cols;
    }

    void NuklearLayoutRowStatic::render()
    {
        nk_layout_row_static(ctx, this->height, this->width, this->cols);
        NuklearContainer::renderChilds();
    }
}
