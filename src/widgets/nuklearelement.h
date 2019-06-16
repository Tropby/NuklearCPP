#ifndef NUKLEARELEMENT_H
#define NUKLEARELEMENT_H

#include "../nuklear/nuklear.h"
#include <list>
#include <functional>

namespace nkcpp
{
    class NuklearElement
    {
    public:
        NuklearElement(nk_context * ctx);
        virtual ~NuklearElement();

        bool isVisible();
        void hide();
        void show();

        virtual void render() = 0;

    protected:
        nk_context * ctx;

    private:
        bool visible;

    };

    typedef std::function< void(NuklearElement*) > NK_CPP_CALLBACK_FUNCTION;
}
#endif // NUKLEARELEMENT_H
