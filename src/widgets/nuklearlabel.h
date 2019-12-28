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

        void setVerticalAlignment( enum nk_text_align alignment );
        void setHorizontalAlignment( enum nk_text_align alignment );
        void setText( std::string text );

    protected:
        std::string text;
        enum nk_text_align verticalAlign;
        enum nk_text_align horizontalAlign;

    };
}

#endif // NUKLEARLABEL_H
