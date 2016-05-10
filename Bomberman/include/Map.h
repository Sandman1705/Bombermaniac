#ifndef MAP_H
#define MAP_H
#include <vector>
#include <string>
#include <SDL.h>
#include "MapObject.h"

class Map
{
    public:
        //Map(int height, int width);
        Map(std::string path_to_file, SDL_Texture* texture, unsigned int tile_size);
        ~Map();

        unsigned int Get_height() { return m_height; }
        unsigned int Get_width() { return m_width; }
        unsigned int Get_tile_size() { return m_tile_size; }

        bool Walkable(unsigned int i,unsigned int j) const;
        void Draw(SDL_Renderer* renderer);

        enum Tile
        {
              EMPTY = 0,
              DESTRUCTABLE_WALL = 1,
              INDESTRUCTABLE_WALL = 2
        };

    protected:

    private:
        unsigned int                            m_height;
        unsigned int                            m_width;
        std::vector<std::vector<MapObject*>>    m_layout;
        const int                               m_tile_size;
        std::string                             m_path_to_file;
};

#endif // MAP_H
