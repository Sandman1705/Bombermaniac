#ifndef MAPOBJECT_H
#define MAPOBJECT_H

// in MapObject.h MapObject.cpp Map.h Map.cpp WallDestroyer.h WallDestroyer.cpp
//#define DEBUG_OUTPUT

#include<SDL.h>

class MapObject
{
    public:
        typedef enum Tile
        {
              EMPTY = 0,
              DESTRUCTABLE_WALL = 1,
              INDESTRUCTABLE_WALL = 2
        } Tile;

        MapObject(Tile id, SDL_Texture *texture, SDL_Rect SrcR);

        Tile Get_id() { return m_id; }
        void Draw(SDL_Renderer* renderer, const SDL_Rect *DestR);

    protected:

    private:
        Tile            m_id;
        SDL_Texture*    m_texture;
        SDL_Rect        m_SrcR;
};

#endif // MAPOBJECT_H
