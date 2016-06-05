#ifndef LOADINGDISPLAY_H
#define LOADINGDISPLAY_H

/**
 *  \file LoadingDisplay.h
 *
 *  Defines class LoadingDisplay which represents the Display that is seen
 *  between levels when the game is loading
 *
 */

#include "Display/Display.h"
#include "Utility/Timer.h"
#include <SDL.h>
#include <vector>

/** \class LoadingDisplay
 *
 * \brief Class which represents the Display that is seen between levels the
 *        the game is loading
 * \details Class LoadingDisplay only contains simple texture that represents
 *          the text which tells on what level the player currently is or in
 *          special cases the game over of game completed messages. This class
 *          is in charge of making GameDisplay object with the proper parameters
 *          one of which is the number of the current level.
 *
 */
class LoadingDisplay : public Display
{
    public:
        /**
         *  \brief Constructor for LoadingDisplay
         *
         *  Makes the LoadingDisplay with the given parameters
         *  \param texture pointer to SDL_Texture from which the various game
         *         assets will be draw and will be passed on to GameDisplay
         *  \param renderer represents the SDL_Renderer on which the Display
         *         will be drawn on.
         *  \param window_width width of the program's window in pixels
         *  \param window_height height of the program's window in pixels
         *  \param max_level number of levels the game has
         *
         */
        LoadingDisplay(SDL_Texture* texture,
                       SDL_Renderer* renderer,
                       unsigned int window_width,
                       unsigned int window_height,
                       unsigned int max_level);
        ~LoadingDisplay();
        LoadingDisplay(const LoadingDisplay& other) = delete; /**< \brief Default copy constructor is disabled */
        LoadingDisplay& operator=(const LoadingDisplay&) = delete; /**< \brief Default operator = is disabled */

        void Init();
        void Enter(int mode);
        void Leave();
        int Destroy();

        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        SDL_Texture*                m_texture;
        SDL_Renderer*               m_renderer;
        std::vector<SDL_Texture*>   m_textures;
        std::vector<SDL_Rect>       m_textures_draw_src;
        std::vector<SDL_Rect>       m_textures_draw_dest;
        unsigned int                m_window_width;
        unsigned int                m_window_height;
        unsigned int                m_current_level;
        const unsigned int          m_max_level;
        Timer                       m_timer;
        bool                        m_game_over;
        Mix_Music*                  m_music;

        void MakeTexture(std::string text);
        void DestroyTextures();

};

#endif // LOADINGDISPLAY_H
