#ifndef EXITDISPLAY_H
#define EXITDISPLAY_H

/**
 *  \file ExitDisplay.h
 *
 *  Defines class ExitDisplay which is a special type of Display that does not
 *  draw anything but just tells that the program should quit
 *
 */

#include "Display/Display.h"

/** \class ExitDisplay
 *
 * \brief Class which represents ExitDisplay which quits the game
 * \details Special type of display that does not draw anything but only tells
 *          the main loop of the program that is should close itself.
 *
 */
class ExitDisplay : public Display
{
    public:
        /**
         *  \brief Constructor for ExitDisplay
         *
         *  It only requires the pointer to boolean value which it used by main
         *  loop of SDL program to see if it should still run or not.
         *
         */
        ExitDisplay(bool* running = nullptr);
        ~ExitDisplay();

        /**
         *  \brief Enter method of ExitDisplay
         *
         *  Redefines basic behavior of Display::Enter(). It changes the value
         *  of boolean given in constructor to false so that the game will quit.
         *  \param mode this value is not needed in ExitDisplay
         *
         *  \return void
         */
        void Enter(int mode = 0);

        /**
         *  \brief Updates the Display
         *
         *  It changes the value of boolean given in constructor to false so
         *  that the game will quit.
         *
         *  \return void
         */
        void Update();
        /**
         *  \brief Draws the Display
         *
         *  Since this is a special type of Display it will not draw anything.
         *  \param renderer not required since it does not draw anything, it can
         *         be nullptr.
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        bool*   m_running;
};

#endif // EXITDISPLAY_H
