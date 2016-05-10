#include "Map.h"

#include <stdio.h>      /*  NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>      /* fstream open close */

#include <iostream>     /* FOR DEBUG   REMOVE LATER */

Map::Map(std::string path_to_file, SDL_Texture* texture, unsigned int tile_size)
    : m_tile_size(tile_size)
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

    SDL_Rect SrcR;
    unsigned int texture_size = 64;
    SrcR.y = 126;
    SrcR.w = texture_size;
    SrcR.h = texture_size;

    for (unsigned i=0; i<m_height; ++i)
        for (unsigned j=0; j<m_width; ++j)
        {
            int id;
            fs >> id;
            SrcR.x = 365 + texture_size * id;
            m_layout[i][j] = new MapObject(id, texture, SrcR);
        }

    fs.close();
}

Map::~Map()
{
    for (unsigned i = 0; i < this->Get_height(); ++i)
    {
        for (unsigned j = 0; j < this->Get_width(); ++j)
        {
            delete m_layout[i][j];
        }
    }
}

bool Map::Walkable(unsigned int i,unsigned int j) const
{
    if (m_layout[i][j]->Get_id() == EMPTY)
        return true;
    else
        return false;
}


void Map::Draw(SDL_Renderer* renderer)
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
            m_layout[i][j]->Draw(renderer, &DestR);
        }
    }
}
