#ifndef MAPOBJECT_H
#define MAPOBJECT_H

// in MapObject.h MapObject.cpp Map.h Map.cpp WallDestroyer.h WallDestroyer.cpp
//#define DEBUG_OUTPUT

/**
 *  \file MapObject.h
 *
 *  Defines class MapObject which represents a object on map.
 *
 */

#include<SDL.h>

/** \class MapObject
 *  \brief class which represents an object on map
 *  \details This class contains all properties for describing a type of tile
 *           that can be placed on map like tile ID and texture on which should
 *           be placed. Also contains a method Draw() which draws it on a map.
 */

class MapObject
{
    public:
        typedef enum Tile
        {
              EMPTY = 0,
              DESTRUCTIBLE_WALL = 1,
              INDESTRUCTIBLE_WALL = 2
        } Tile;

        /**
         *  \brief Constructor for MapObject.
         *
         *  Makes an object of class MapObject according to given attributes.
         *  \param id describes type of tile on map
         *  \param texture pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param SrcR location and size of texture on given SLD_Texture
         *
         */
        MapObject(Tile id, SDL_Texture *texture, SDL_Rect SrcR);

        Tile GetId() const { return m_id; }

        /**
         *  \brief Draws a tile on given SDL_Renderer.
         *
         *  Draws a tile on the map according to it's coordinates.
         *  \param renderer represents SDL_Renderer on which a tile
         *  will be drawn on
         *  \param DestR location and size of renderer where should texture be drawn
         *
         *  \return void
         */
        void Draw(SDL_Renderer* renderer, const SDL_Rect *DestR);

    protected:
        SDL_Rect        m_SrcR;

    private:
        Tile            m_id;
        SDL_Texture*    m_texture;
};

#endif // MAPOBJECT_H
