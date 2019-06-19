#ifndef NUKLEARLABEL_H
#define NUKLEARLABEL_H

#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearLabel : public NuklearElement
    {
    public:
        NuklearLabel(struct nk_context * ctx);

        void render();

        void setText( std::string text );

    private:
        std::string text;
    };
}

#endif // NUKLEARLABEL_H
