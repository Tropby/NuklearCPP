#ifndef NUKLEARLAYOUTROWDYNAMIC_H
#define NUKLEARLAYOUTROWDYNAMIC_H

#include "nuklearcontainer.h"
#include <vector>

namespace nkcpp
{
    class NuklearLayoutRowDynamic : public NuklearContainer
    {
    public:
        NuklearLayoutRowDynamic(struct nk_context * ctx, int height, int colCount);
        NuklearLayoutRowDynamic(struct nk_context * ctx, int height, std::vector<float> cols);

        void render();

    private:
        int height;
        std::vector<float> cols;

    };
}

#endif // NUKLEARLAYOUTROWDYNAMIC_H
