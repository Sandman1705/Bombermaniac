#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

/**
 *  \file DisplayManager.h
 *
 *  Defines class DisplayManager which contains the mechanisms for navigating
 *  between multiple Display objects as well as keeping track of all previous
 *  Display that the game can eventually return to.
 *
 */

#include "Display/Display.h"
#include "SDL.h"
#include <stack>

/** \class DisplayManager
 *
 * \brief Class which is used for navigating between multiple Display objects.
 *        It implements methods for navigating menus and game display.
 * \details Contains mechanisms for navigating between multiple Display objects,
 *          whether it means to go the a new Display or go back to a previous
 *          one. Contains methods Update() and Draw() which will call the
 *          proper methods of the current display unless that Display sends the
 *          message that it should be changed in which case it changes current
 *          Display with the correct new one.
 *
 */
class DisplayManager
{
    public:
        /**
         *  \brief Constructor for DisplayManager
         *
         *  Initializes the object of DisplayManager according to given window
         *  size as well as pointers to texture and renderer of program window.
         *  Also requires pointer to boolean which represents whether the
         *  program should still be running.
         *  \param texture pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param renderer represents the SDL_Renderer on which the bombs
         *         will be drawn on.
         *  \param running pointer to boolean which tells the main loop of the
         *         program whether it should still be running or not
         *  \param window_width integer value which represents the width of the
         *         program's window
         *  \param window_height integer value which represents the height of
         *         the program's window
         *
         */
        DisplayManager(SDL_Texture* texture,
                       SDL_Renderer* renderer,
                       bool* running,
                       unsigned int window_width,
                       unsigned int window_height);
        ~DisplayManager();

        /**
         *  \brief Update method of the DisplayManager
         *
         *  Checks whether the current Display should be changed either to
         *  to previous or to next by calling Display::ShouldLeaveToPrevious()
         *  or Display::ShouldLeaveToNext() and Display::NextDisplay() of the
         *  current Display. It it should not be changed the it just calls the
         *  Display::Update() method of the current Display.
         *
         *  \return void
         */
        void Update();/**
         *  \brief Draw method of the DisplayManager
         *
         *  Calls the Display::Draw() method of the current Display.
         *  \param renderer represents the SDL_Renderer on which the Display
         *         will be drawn on.
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer);

    protected:

        /**
         *  \brief Swaps the current Display with the given one
         *
         *  Method that is used to go from the current Display to the next one
         *  which is given as a parameter. It is not meant to be used explicitly
         *  but internally by the Update() method.
         *  \param display pointer to Display to which the program should switch
         *         to
         *
         *  \return void
         */
        void EnterDisplay(Display* display);
        /**
         *  \brief Swaps the current Display with the previous one
         *
         *  Method that is used to go from the current Display to the previous
         *  one. It is not meant to be used explicitly but internally by the
         *  Update() method.
         *
         *  \return void
         */
        void LeaveDisplay();
        /**
         *  \brief Returns pointer to the current Display that is displayed.
         *
         *  It is not meant to be used explicitly but internally by the Update()
         *  method.
         *
         *  \return pointer to current Display
         */
        Display* CurrentDisplay();

    private:
        std::stack<Display*> m_displays;
        SDL_Renderer*        m_renderer;

        unsigned int         m_window_width;
        unsigned int         m_window_height;
};

#endif // DISPLAYMANAGER_H
