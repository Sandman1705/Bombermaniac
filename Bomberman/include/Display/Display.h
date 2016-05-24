#ifndef DISPLAY_H
#define DISPLAY_H

/**
 *  \file Display.h
 *
 *  Defines abstract class Display which is basis for a single display or screen
 *  in the game
 *
 */

#include <SDL.h>
#include <string>
#include "System/KeyboardInput.h"

/** \class Display
 *
 * \brief Abstract class which represents a single display or screen in the game
 * \details Defines basic behavior for every display in the game. Includes
 *          methods Update() and Draw() which every screen must define. Methods
 *          Init() Enter() Leave() Destroy() define behavior of a display when
 *          it becomes active or inactive.
 *
 */
class Display
{
    public:
        /**
         *  \brief Constructor for Display
         *
         *  Class Display is abstract. Constructor is used for initializing
         *  base elements of every class that inherits Display
         *
         */
        Display();
        virtual ~Display() = 0;

        /**
         *  \brief Initializes elements of display
         *
         *  Method that is automatically called by DisplayManager the first time
         *  the display becomes active. Every class that inherits display should
         *  redefine this method if it has elements that need to be initialized
         *  before they can be used.
         *
         *  \return void
         */
        virtual void Init();
        /**
         *  \brief Resets certain values of display. Starts background elements.
         *
         *  Method that is automatically called by DisplayManager every time the
         *  display becomes active. Every class that inherits display should
         *  redefine this method if it has elements that need to be reset or
         *  or reinitialized when the display comes back into use.
         *  \param mode represents id of mode the display should run
         *
         *  \return void
         */
        virtual void Enter(int mode = 0);
        /**
         *  \brief Pauses the display. Stops background elements.
         *
         *  Method that is automatically called by DisplayManager every time
         *  this display is used to switch to the next display (not counting
         *  going back). Every class that inherits display should redefine this
         *  method if it has elements that need to are need disabled until
         *  display becomes active again or are working in the background but
         *  are not used in other displays.
         *
         *  \return void
         */
        virtual void Leave();
        /**
         *  \brief Destroys the display.
         *
         *  Method that is automatically called by DisplayManager the last time
         *  the display is used. Destroys elements of display and frees up the
         *  memory if it was using any. Every class that inherits display should
         *  redefine this method if it has elements that need to freed or
         *  destroyed after the display is no longer needed.
         *
         *  \return integer which represents mode the previous screen should
         *          run; default return value is 0
         */
        virtual int Destroy();

        /**
         *  \brief Updates the display
         *
         *  Abstract method. This method should be redefined so that a display
         *  acts according to user input or makes changes that need to be done
         *  periodically, whatever the display needs. Also when the display
         *  needs to be changed either because of user input of some other
         *  reason changes its internal state specifically values
         *  m_leave_previous and m_leave_next so that methods
         *  ShouldLeaveToPrevious() or ShouldLeaveToNext() return true if the
         *  game should go the previous or next Display respectively. In the
         *  case of ShouldLeaveToNext() it should make an object of appropriate
         *  class that inherits Display and place its pointer into
         *  m_next_display so that the next call of method NextDisplay() returns
         *  pointer to it.
         *
         *  \return void
         */
        virtual void Update() = 0;
        /**
         *  \brief Draws the display
         *
         *  Abstract method. This method should be redefined so that the display
         *  draws all its elements.
         *
         *  \return void
         */
        virtual void Draw(SDL_Renderer* renderer) const = 0;

        /**
         *  \brief Tells if the game should return to previous display
         *
         *  Used by DisplayManager to see if the Display is done and should be
         *  destroyed, after which the game will go back to previous Display.
         *
         *  \return true if the game should go to next display, false otherwise
         */
        bool ShouldLeaveToPrevious() { return m_leave_previous; }
        /**
         *  \brief Tells if the game should go to next Display
         *
         *  Used by DisplayManager to see if the Display is done and the game
         *  should move to next Display which can be obtained with method
         *  NextDisplay().
         *
         *  \return true if the game should return to previous display, false
         *          otherwise
         */
        bool ShouldLeaveToNext() { return m_leave_next; }
        /**
         *  \brief Returns pointer to Display the game should change to if going
         *         to next Display
         *
         *  Used by DisplayManager to see obtain the Display it should go to if
         *  ShouldLeaveToNext() returns true
         *
         *  \return pointer to Display of the Display the game should change to
         */
        Display* NextDisplay() { return m_next_display; }

    protected:
        bool            m_leave_previous; /**< tells if the game should go back to previous Display */
        bool            m_leave_next; /**< tells if the game should go to next Display */
        Display*        m_next_display; /**< pointer of next Display if the game should go to next Display */
        KeyboardInput*  m_keyboard_input; /**< pointer to KeyboardInput from which the user's input is read */

    private:

};

#endif // DISPLAY_H
