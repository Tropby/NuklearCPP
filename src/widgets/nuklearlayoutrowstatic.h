#ifndef NUKLEARLAYOUTROWSTATIC_H
#define NUKLEARLAYOUTROWSTATIC_H

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearLayoutRowStatic : public NuklearElement
    {
    public:
        NuklearLayoutRowStatic(struct nk_context * ctx, int height, int width, int cols);

        void render();

    private:
        int height;
        int width;
        int cols;

    };
}

#endif // NUKLEARLAYOUTROWSTATIC_H
