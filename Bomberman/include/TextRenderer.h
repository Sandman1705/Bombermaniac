#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class TextRenderer
{
    public:
        TextRenderer(const std::string &font_file, unsigned int font_size);
        ~TextRenderer();

        SDL_Texture* RenderText(const std::string &message, SDL_Color color, SDL_Renderer *renderer);

    protected:

    private:
        TTF_Font*       m_font;
};

#endif // TEXTRENDERER_H
