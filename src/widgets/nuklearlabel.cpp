#include "nuklearlabel.h"

namespace nkcpp
{
    NuklearLabel::NuklearLabel(struct nk_context *ctx) : NuklearElement (ctx)
    {

    }

    void NuklearLabel::render()
    {
        nk_label( ctx, this->text.c_str(), NK_TEXT_LEFT);
    }

    void NuklearLabel::setText(std::string text)
    {
        this->text = text;
    }
}
