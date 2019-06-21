#ifndef NUKLEARELEMENT_H
#define NUKLEARELEMENT_H

#include "../nuklear/nuklear.h"

#include <list>
#include <functional>

namespace nkcpp
{
    /**
     * @brief The NuklearElement class
     *
     * The NuklearElement is the base class for all widgets and layouts that are
     * defined by NuklearCPP.
     */
    class NuklearElement
    {
    public:
        NuklearElement(nk_context * ctx);
        virtual ~NuklearElement();

        /**
         * @brief isVisible
         *
         * Returns the visibility of the element.
         *
         * @return the visibility. True if the element is visible in the GUI
         */
        bool isVisible();

        /**
         * @brief hides the element
         */
        void hide();

        /**
         * @brief shows the element
         */
        void show();

        /**
         * @brief Sets the name of the element
         * @param name The name of the element
         */
        void setName( std::string name );

        /**
         * @brief Returns the name of the element
         * @return the name of the element
         */
        std::string getName();

        /**
         * @brief the virtual method that renders the element
         *
         * Every element have to implement this render method.
         * The renderer should call the Nuklear ANSI C methods to
         * create the GUI.
         */
        virtual void render() = 0;

        void setFlags( nk_flags flags );
        nk_flags getFlags();
        void addFlags( nk_flags flags );
        void removeFlags( nk_flags flags );

    protected:
        nk_context * ctx;

    private:
        bool visible;
        std::string name;
        nk_flags flags;

    };

    /**
     * @brief The standard callback function definition
     *
     * This is the NuklearCPP standard callback function that is used by
     * every widget to create callbacks. The parameter of the callback
     * is the widget that creates the event. All events are directly called
     * if they occure.
     */
    typedef std::function< void(NuklearElement*) > NK_CPP_CALLBACK_FUNCTION;
}
#endif // NUKLEARELEMENT_H
