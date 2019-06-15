#ifndef NUKLEARWINDOW_H
#define NUKLEARWINDOW_H

#include <string>
#include "nuklearelement.h"

namespace nkcpp
{
    class NuklearWindow : public NuklearElement
    {
    public:
        NuklearWindow(struct ::nk_context * ctx);

        void render();

        void resize( int x, int y, int w, int h );

        void setText( std::string text );

        void setFlags( nk_flags flags );
        nk_flags getFlags();
        void addFlags( nk_flags flags );
        void removeFlags( nk_flags flags );

    private:
        std::string text;
        int x, y, w, h;

        nk_flags flags;
    };
}
#endif // NUKLEARWINDOW_H
