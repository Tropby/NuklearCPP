#include "nukleargroup.h"

namespace nkcpp
{
    NuklearGroup::NuklearGroup(nk_context *ctx) : NuklearElement (ctx)
    {

    }

    void NuklearGroup::render()
    {
        if( nk_group_begin(ctx, "", NK_WINDOW_BORDER) )
        {
            NuklearElement::renderChilds();
            nk_group_end(ctx);
        }
    }
}
