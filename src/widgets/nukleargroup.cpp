#include "nukleargroup.h"

namespace nkcpp
{
    NuklearGroup::NuklearGroup(nk_context *ctx) : NuklearContainer (ctx)
    {

    }

    void NuklearGroup::render()
    {
        if( nk_group_begin(ctx, "", NK_WINDOW_BORDER) )
        {
            NuklearContainer::renderChilds();
            nk_group_end(ctx);
        }
    }
}
