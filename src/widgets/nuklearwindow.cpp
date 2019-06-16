#include "nuklearwindow.h"

namespace nkcpp
{
    NuklearWindow::NuklearWindow(struct nk_context *ctx) : NuklearContainer (ctx)
    {
        x = 0;
        y = 0;
        w = 100;
        h = 100;
    }

    void NuklearWindow::render()
    {
        if (nk_begin(ctx, text.c_str(), nk_rect(x, y, w, h), flags))
        {
            NuklearContainer::renderChilds();
        }
        nk_end(ctx);
    }

    void NuklearWindow::resize(int x, int y, int w, int h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }

    void NuklearWindow::setText(std::string text)
    {
        this->text = text;
    }

    void NuklearWindow::setFlags(nk_flags flags)
    {
        this->flags = flags;
    }

    nk_flags NuklearWindow::getFlags()
    {
        return this->flags;
    }

    void NuklearWindow::addFlags(nk_flags flags)
    {
        this->flags |= flags;
    }

    void NuklearWindow::removeFlags(nk_flags flags)
    {
        this->flags &= ~flags;
    }
}
