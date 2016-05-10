#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <SDL.h>
#include "MapObject.h"

class Map
{
    public:
        Map(std::string path_to_file, SDL_Texture* texture, unsigned int tile_size);
        ~Map();
        //TODO Copy constructor
        //TODO Operator=

        unsigned int Get_height() const { return m_height; }
        unsigned int Get_width() const { return m_width; }
        unsigned int Get_tile_size() const { return m_tile_size; }

        bool Walkable(unsigned int i,unsigned int j) const;
        void Draw(SDL_Renderer* renderer) const;
        void DestroyWall(unsigned int i, unsigned int j);
        MapObject::Tile Get_tile_type(unsigned int i, unsigned int j) const;


    protected:

    private:
        unsigned int                            m_height;
        unsigned int                            m_width;
        std::vector<std::vector<MapObject*>>    m_layout;
        const int                               m_tile_size;
        SDL_Texture*                            m_texture;

        static const unsigned int               TEXTURE_SIZE = 64;
};

#endif // MAP_H
