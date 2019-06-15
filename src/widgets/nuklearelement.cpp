#include "nuklearelement.h"

#include <iostream>

#include "nuklearbutton.h"
#include "nuklearlabel.h"
#include "nuklearlayoutrowdynamic.h"
#include "nuklearlayoutrowstatic.h"
#include "nuklearcheckbox.h"
#include "nukleargroup.h"
#include "nuklearselectable.h"
#include "nuklearslider.h"
#include "nukleartextedit.h"

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

    NuklearElement *NuklearElement::addSelectable(std::string text, bool active)
    {
        NuklearSelectable * sel = new NuklearSelectable( this->ctx );
        sel->setText(text);
        sel->setActive(active);
        this->addChild(sel);
        return sel;
    }

    NuklearElement *NuklearElement::addSlider(float min, float value, float max, float step)
    {
        NuklearSlider * slider = new NuklearSlider( this->ctx );
        slider->setMax(max);
        slider->setMin(min);
        slider->setStep(step);
        slider->setValue(value);
        this->addChild(slider);
        return slider;
    }

    NuklearElement *NuklearElement::addTextEdit(std::string text)
    {
        NuklearTextEdit * te = new NuklearTextEdit( this->ctx );
        te->setText(text);
        this->addChild(te);
        return te;
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
