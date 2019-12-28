#include "nukleartree.h"

namespace nkcpp
{
    int NuklearTree::uniqueId = 0;

    NuklearTree::NuklearTree(nk_context *ctx) : NuklearContainer (ctx)
    {
        this->id = uniqueId++;
    }

    void NuklearTree::render()
    {
        if (nk_tree_push_id(ctx, NK_TREE_TAB, this->text.c_str(), NK_MINIMIZED, this->id ))
        {
            this->renderChilds();
            nk_tree_pop(ctx);
        }
    }

    void NuklearTree::setText(std::string text)
    {
        this->text = text;
    }
}
