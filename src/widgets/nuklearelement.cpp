#include "nuklearelement.h"

namespace nkcpp
{
    NuklearElement::NuklearElement(struct nk_context *ctx) : ctx(ctx), visible(true)
    {

    }

    NuklearElement::~NuklearElement()
    {

    }

    bool NuklearElement::isVisible()
    {
        return visible;
    }

    void NuklearElement::hide()
    {
        visible = false;
    }

    void NuklearElement::show()
    {
        visible = true;
    }

    void NuklearElement::setName(std::string name)
    {
        this->name = name;
    }

    std::string NuklearElement::getName()
    {
        return name;
    }
}
