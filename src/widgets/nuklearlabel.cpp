#include "nuklearlabel.h"

namespace nkcpp
{
    NuklearLabel::NuklearLabel(struct nk_context *ctx) : NuklearElement (ctx), text("")
    {
        this->verticalAlign = NK_TEXT_ALIGN_MIDDLE;
        this->horizontalAlign = NK_TEXT_ALIGN_LEFT;
    }

    void NuklearLabel::render()
    {
        nk_label( ctx, this->text.c_str(), this->horizontalAlign | this->verticalAlign );
    }

    void NuklearLabel::setHorizontalAlignment(nk_text_align alignment)
    {
        this->horizontalAlign = alignment;
    }

    void NuklearLabel::setVerticalAlignment(enum nk_text_align alignment)
    {
        this->verticalAlign = alignment;
    }

    void NuklearLabel::setText(std::string text)
    {
        this->text = text;
    }
}
