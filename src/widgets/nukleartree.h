#ifndef NUKLEARTREE_H
#define NUKLEARTREE_H

#include "nuklearcontainer.h"

namespace nkcpp
{
    class NuklearTree : public NuklearContainer
    {
    public:
        NuklearTree(struct nk_context * ctx);

        void render();

        void setText( std::string text );


    protected:
        std::string text;

        static int uniqueId;
        int id;
    };
}

#endif // NUKLEARTREE_H
