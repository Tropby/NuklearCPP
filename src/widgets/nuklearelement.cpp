#include "nuklearelement.h"

#include <iostream>

#include "nuklearbutton.h"
#include "nuklearlabel.h"
#include "nuklearlayoutrowdynamic.h"
#include "nuklearlayoutrowstatic.h"
#include "nuklearcheckbox.h"
#include "nukleargroup.h"

namespace nkcpp
{
    NuklearElement::NuklearElement(struct nk_context *ctx) : ctx(ctx), visible(true)
    {

    }

    NuklearElement::~NuklearElement()
    {

    }

    void NuklearElement::update()
    {
        render();
    }

    void NuklearElement::addChild(NuklearElement * ne)
    {
        this->childs.push_back(ne);
    }

    NuklearElement * NuklearElement::addButton(std::string text, NK_CPP_CALLBACK_FUNCTION callback )
    {
        NuklearButton * bttn = new NuklearButton( this->ctx );
        bttn->setText(text);
        bttn->setOnClick( callback );
        this->addChild(bttn);
        return bttn;
    }

    NuklearElement *NuklearElement::addLabel(std::string text)
    {
        NuklearLabel * label = new NuklearLabel( this->ctx );
        label->setText(text);
        this->addChild(label);
        return label;
    }

    NuklearElement *NuklearElement::addLayoutRowDynamic(int height, int cols)
    {
        NuklearLayoutRowDynamic * row = new NuklearLayoutRowDynamic( this->ctx, height, cols );
        this->addChild(row);
        return row;
    }

    NuklearElement *NuklearElement::addLayoutRowStatic(int height, int width, int cols)
    {
        NuklearLayoutRowStatic * row = new NuklearLayoutRowStatic( this->ctx, height, width, cols );
        this->addChild(row);
        return row;
    }

    NuklearElement *NuklearElement::addCheckbox(std::string text, bool active)
    {
        NuklearCheckbox * cb = new NuklearCheckbox( this->ctx );
        cb->setText(text);
        cb->setActive(active);
        this->addChild(cb);
        return cb;
    }

    NuklearElement *NuklearElement::addGroup()
    {
        NuklearGroup * g = new NuklearGroup( this->ctx );
        this->addChild(g);
        return g;
    }

    unsigned int NuklearElement::childCount()
    {
        return this->childs.size();
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

    void NuklearElement::renderChilds()
    {
        for( NuklearElement * ne : this->childs )
        {
            if( ne->isVisible() )
                ne->render();
        }
    }
}
