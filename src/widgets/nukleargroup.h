#ifndef NUKLEARGROUP_H
#define NUKLEARGROUP_H

#include "nuklearcontainer.h"

namespace nkcpp
{
    class NuklearGroup : public NuklearContainer
    {
    public:
        NuklearGroup(struct nk_context * ctx);

        void render();

    private:
        int height;
        int cols;

    };
}
#endif // NUKLEARGROUP_H
