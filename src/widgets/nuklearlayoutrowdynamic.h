#ifndef NUKLEARLAYOUTROWDYNAMIC_H
#define NUKLEARLAYOUTROWDYNAMIC_H

#include "nuklearcontainer.h"

namespace nkcpp
{
    class NuklearLayoutRowDynamic : public NuklearContainer
    {
    public:
        NuklearLayoutRowDynamic(struct nk_context * ctx, int height, int cols);

        void render();

    private:
        int height;
        int cols;

    };
}

#endif // NUKLEARLAYOUTROWDYNAMIC_H
