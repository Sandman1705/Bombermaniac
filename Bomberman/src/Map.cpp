#include "Map.h"

#include <stdio.h>      /*  NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>      /* fstream open close */

#include <iostream>     /* FOR DEBUR   REMOVE LATER */

//random map
/*
Map::Map(int height, int width)
    : m_height(height), m_width(width), m_layout(m_height, std::vector<int>(m_width)), m_tile_size(32)
{
    srand (time(NULL));
    for (unsigned i=0; i<m_height; ++i)
    {
        for (unsigned j=0; j<m_width; ++j)
        {
            m_layout[i][j]=rand() % 3;
        }
    }
}
*/

Map::Map(std::string path_to_file, const std::vector<SDL_Texture*> *textures)
    : m_tile_size(40)
{
    std::fstream fs;
    fs.open (path_to_file, std::fstream::in);

    if (!fs.is_open())
    {
        std::cout << "Error opening file " << path_to_file << std::endl;
        exit(EXIT_FAILURE);
    }

    fs >> m_height >> m_width;

    m_layout.resize(m_height);
    for (unsigned i=0; i<m_height; ++i)
        m_layout[i].resize(m_width);

    for (unsigned i=0; i<m_height; ++i)
        for (unsigned j=0; j<m_width; ++j)
        {
            int id;
            fs >> id;
            m_layout[i][j] = new MapObject(id, (*textures)[id]);
        }

    fs.close();
}

bool Map::Walkable(unsigned int i,unsigned int j) const
{
    if (m_layout[i][j]->Get_id() == EMPTY)
        return true;
    else
        return false;
}


void Map::Draw(SDL_Renderer* renderer, const std::vector<SDL_Texture*> *textures)
{
    SDL_Rect DestR;
    int tile_size = Get_tile_size();

    DestR.x = 0;
    DestR.y = 0;
    DestR.w = tile_size;
    DestR.h = tile_size;

    for (unsigned i = 0; i < this->Get_height(); ++i)
    {
        for (unsigned j = 0; j < this->Get_width(); ++j)
        {
            DestR.y = tile_size*i;
            DestR.x = tile_size*j;
            m_layout[i][j]->Draw(renderer, tile_size, &DestR);
        }
    }
}
