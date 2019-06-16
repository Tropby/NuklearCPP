#include "nuklearcontainer.h"

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
    NuklearContainer::NuklearContainer(nk_context * ctx) : NuklearElement (ctx)
    {

    }

    void NuklearContainer::addChild(NuklearElement * ne)
    {
        this->childs.push_back(ne);
    }

    NuklearElement * NuklearContainer::addButton(std::string text)
    {
        NuklearButton * bttn = new NuklearButton( this->ctx );
        bttn->setText(text);
        this->addChild(bttn);
        return bttn;
    }

    NuklearElement *NuklearContainer::addLabel(std::string text)
    {
        NuklearLabel * label = new NuklearLabel( this->ctx );
        label->setText(text);
        this->addChild(label);
        return label;
    }

    NuklearContainer *NuklearContainer::addLayoutRowDynamic(int height, int cols)
    {
        NuklearLayoutRowDynamic * row = new NuklearLayoutRowDynamic( this->ctx, height, cols );
        this->addChild(row);
        return row;
    }

    NuklearContainer *NuklearContainer::addLayoutRowStatic(int height, int width, int cols)
    {
        NuklearLayoutRowStatic * row = new NuklearLayoutRowStatic( this->ctx, height, width, cols );
        this->addChild(row);
        return row;
    }

    NuklearElement *NuklearContainer::addCheckbox(std::string text, bool active)
    {
        NuklearCheckbox * cb = new NuklearCheckbox( this->ctx );
        cb->setText(text);
        cb->setActive(active);
        this->addChild(cb);
        return cb;
    }

    NuklearContainer *NuklearContainer::addGroup()
    {
        NuklearGroup * g = new NuklearGroup( this->ctx );
        this->addChild(g);
        return g;
    }

    NuklearElement *NuklearContainer::addSelectable(std::string text, bool active)
    {
        NuklearSelectable * sel = new NuklearSelectable( this->ctx );
        sel->setText(text);
        sel->setActive(active);
        this->addChild(sel);
        return sel;
    }

    NuklearElement *NuklearContainer::addSlider(float min, float value, float max, float step)
    {
        NuklearSlider * slider = new NuklearSlider( this->ctx );
        slider->setMax(max);
        slider->setMin(min);
        slider->setStep(step);
        slider->setValue(value);
        this->addChild(slider);
        return slider;
    }

    NuklearElement *NuklearContainer::addTextEdit(std::string text)
    {
        NuklearTextEdit * te = new NuklearTextEdit( this->ctx );
        te->setText(text);
        this->addChild(te);
        return te;
    }

    unsigned int NuklearContainer::childCount()
    {
        return this->childs.size();
    }

    void NuklearContainer::renderChilds()
    {
        for( NuklearElement * ne : this->childs )
        {
            if( ne->isVisible() )
            {
                ne->render();
            }
        }
    }
}
