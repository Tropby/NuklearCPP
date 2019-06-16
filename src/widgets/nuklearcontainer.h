#ifndef NUKLEARCONTAINER_H
#define NUKLEARCONTAINER_H

#include "nuklearelement.h"



namespace nkcpp
{
    class NuklearContainer : public NuklearElement
    {
    public:
        NuklearContainer(nk_context * ctx);

        void addChild( NuklearElement * ne );
        NuklearElement *addButton(std::string text);
        NuklearElement *addLabel(std::string text);
        NuklearElement *addCheckbox(std::string text, bool active);
        NuklearElement *addSelectable(std::string text, bool active);
        NuklearElement *addSlider(float min, float value, float max, float step);
        NuklearElement *addTextEdit(std::string text);

        NuklearContainer *addLayoutRowDynamic(int height, int cols);
        NuklearContainer *addLayoutRowStatic(int height, int width, int cols);
        NuklearContainer *addGroup();

        unsigned int childCount();
        void renderChilds();

    private:
        std::list<NuklearElement*> childs;
    };
}

#endif // NUKLEARCONTAINER_H
