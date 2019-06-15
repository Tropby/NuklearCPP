#ifndef NUKLEARELEMENT_H
#define NUKLEARELEMENT_H

#include "../nuklear/nuklear.h"
#include <list>
#include <functional>


namespace nkcpp
{
    typedef std::function< void() > NK_CPP_CALLBACK_FUNCTION;

    class NuklearElement
    {
    public:
        NuklearElement(struct nk_context * ctx);
        virtual ~NuklearElement();

        void update();

        void addChild( NuklearElement * ne );
        NuklearElement *addButton(std::string text, NK_CPP_CALLBACK_FUNCTION callback);
        NuklearElement *addLabel(std::string text);
        NuklearElement *addLayoutRowDynamic(int height, int cols);
        NuklearElement *addLayoutRowStatic(int height, int width, int cols);
        NuklearElement *addCheckbox(std::string text, bool active);
        NuklearElement *addGroup();

        unsigned int childCount();
        bool isVisible();
        void hide();
        void show();

    protected:
        virtual void render() = 0;
        void renderChilds();
        struct nk_context * ctx;

    private:
        std::list<NuklearElement*> childs;
        bool visible;

    };
}
#endif // NUKLEARELEMENT_H
