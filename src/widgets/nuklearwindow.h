#ifndef NUKLEARWINDOW_H
#define NUKLEARWINDOW_H

#include <string>
#include "nuklearcontainer.h"

namespace nkcpp
{
    class NuklearWindow : public NuklearContainer
    {
    public:
        NuklearWindow(struct ::nk_context * ctx);

        void render();

        void resize( int x, int y, int w, int h );

        void setText( std::string text );

    private:
        std::string text;
        int x, y, w, h;
    };
}
#endif // NUKLEARWINDOW_H
