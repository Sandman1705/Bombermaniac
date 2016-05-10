#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include"SDL.h"

class MapObject
{
    public:
        MapObject();
        //virtual ~MapObject();

        unsigned int Getid() { return m_id; }
        //void Setid(unsigned int val) { m_id = val; }
        //SDL_Texture* Gettexture() { return m_texture; }
        //void Settexture(SDL_Texture* val) { m_texture = val; }

        void Draw(SDL_Renderer* renderer, const int tile_size, int x, int y);

    protected:

    private:
        unsigned int m_id;
        SDL_Texture* m_texture;
};

#endif // MAPOBJECT_H
