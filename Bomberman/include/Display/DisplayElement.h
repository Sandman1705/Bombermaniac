#ifndef DISPLAYELEMENT_H
#define DISPLAYELEMENT_H

/**
 *  \file DisplayElement.h
 *
 *  Defines abstract class DisplayElement which is basis for a single element
 *  of GameDisplay i.e. Manager classes.
 *
 */

#include "SDL.h"

/** \class DisplayElement
 *
 * \brief Abstract class which represents an element of GameDisplay that is
 *        periodically updated and displayed on the screen.
 * \details Defines basic behavior for every display element of GameDisplay.
 *          Includes methods Update() and Draw() which every element must
 *          define. Requires SDL_Texture which will be used for Draw().
 *
 */
class DisplayElement
{
    public:
        /**
         *  \brief Constructor for DisplayElement
         *
         *  Class DisplayElement is abstract. Constructor requires pointer to
         *  SDL_Texture which will be used by method Draw().
         *  \param texture Pointer to SDL_Texture which is used for Draw()
         *
         */
        DisplayElement(SDL_Texture* texture);
        virtual ~DisplayElement() = 0;

        /**
         *  \brief Update method for DisplayElement
         *
         *  Abstract method. This method should be redefined so that a
         *  DisplayElement acts according to user input or makes changes that
         *  need to be done periodically, whatever the function of that element
         *  is.
         *  \return void
         *
         */
        virtual void Update() = 0;
         /**
         *  \brief Draws the display
         *
         *  Abstract method. This method should be redefined so that the
         *  DisplayElement draws all its elements
         *  \param renderer represents the SDL_Renderer on which the Display
         *         will be drawn on.
         *
         *  \return void
         */
        virtual void Draw(SDL_Renderer* renderer) const = 0;

    protected:
        SDL_Texture*    m_texture;

    private:
};

#endif // DISPLAYELEMENT_H
