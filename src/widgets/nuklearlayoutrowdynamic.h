#ifndef NUKLEARLAYOUTROWDYNAMIC_H
#define NUKLEARLAYOUTROWDYNAMIC_H

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearLayoutRowDynamic : public NuklearElement
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
