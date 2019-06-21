#ifndef NUKLEARBUTTON_H
#define NUKLEARBUTTON_H

#include <string>
#include <functional>

#include "nuklearelement.h"

namespace nkcpp
{
    /**
     * @brief The NuklearButton class
     *
     * This class renders a button
     */
    class NuklearButton : public NuklearElement
    {
    public:
        NuklearButton(struct nk_context * ctx);

        /**
         * @brief renders the button
         */
        void render();

        /**
         * @brief Setter for the text
         * @param text The text shown on the button
         */
        void setText( std::string text );

        /**
         * @brief Sets the callback method for a click event.
         * @param callback Method that should be called if the event occures
         */
        void setOnClick( NK_CPP_CALLBACK_FUNCTION callback );

    private:
        std::string text;

        NK_CPP_CALLBACK_FUNCTION onClick;
    };
}
#endif // NUKLEARBUTTON_H
