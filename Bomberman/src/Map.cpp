#include "Map.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>      /* fstream open close */
#include "Constants/TextureMapObjectConstants.h"

#ifdef DEBUG_OUTPUT_MAP
#include <iostream>
#endif // DEBUG_OUTPUT_MAP

Map::Map(std::string path_to_file, SDL_Texture* texture, unsigned int tile_size)
    : m_tile_size(tile_size), m_texture(texture)
{
    std::fstream fs;
    fs.open (path_to_file, std::fstream::in);

    if (!fs.is_open())
    {
        #ifdef DEBUG_OUTPUT_MAP
        std::cout << "Error opening file " << path_to_file << std::endl;
        #endif // DEBUG_OUTPUT_MAP
        exit(EXIT_FAILURE);
    }

    fs >> m_height >> m_width;

    m_layout.resize(m_height);
    for (unsigned i=0; i<m_height; ++i)
        m_layout[i].resize(m_width);

    srand(time(nullptr));
    for (unsigned i=0; i<m_height; ++i)
        for (unsigned j=0; j<m_width; ++j)
        {
            int id;
            fs >> id;
            //MapObject::Tile tile;
            switch(id)
            {
            case 0:
                //tile = MapObject::EMPTY;
                m_layout[i][j] = new MapObject(MapObject::EMPTY, m_texture, rand() % TEXTURE_MAP_EMPTY_KIND_COUNT);
                break;
            case 1:
                //tile = MapObject::DESTRUCTIBLE_WALL;
                m_layout[i][j] = new DestructibleWall(m_texture, rand() % TEXTURE_MAP_DESTRUCTIBLE_KIND_COUNT);
                break;
            case 2:
                //tile = MapObject::INDESTRUCTIBLE_WALL;
                m_layout[i][j] = new MapObject(MapObject::INDESTRUCTIBLE_WALL, m_texture, rand() % TEXTURE_MAP_INDESTRUCTIBLE_KIND_COUNT);
                break;
            default:
                //tile = MapObject::EMPTY;
                m_layout[i][j] = new MapObject(MapObject::EMPTY, m_texture);
                break;
            }
        }

    fs.close();
}

Map::~Map()
{
    for (unsigned i = 0; i < m_height; ++i)
    {
        for (unsigned j = 0; j < m_width; ++j)
        {
            delete m_layout[i][j];
        }
    }
}

bool Map::Walkable(unsigned int i,unsigned int j) const
{
    if (m_layout[i][j]->GetId() == MapObject::EMPTY)
        return true;
    else
        return false;
}


void Map::Draw(SDL_Renderer* renderer) const
{
    SDL_Rect DestR;
    int tile_size = m_tile_size;

    DestR.x = 0;
    DestR.y = 0;
    DestR.w = tile_size;
    DestR.h = tile_size;

    for (unsigned i = 0; i < m_height; ++i)
    {
        for (unsigned j = 0; j < m_width; ++j)
        {
            DestR.y = tile_size*i;
            DestR.x = tile_size*j;
            m_layout[i][j]->Draw(renderer, &DestR);
        }
    }
}

void Map::DestroyWall(unsigned int i, unsigned int j)
{
    if (m_layout[i][j]->GetId() == MapObject::DESTRUCTIBLE_WALL)
    {
        DestructibleWall* wall = (DestructibleWall*)m_layout[i][j];
        wall->DecreaseIntegrity(25);
        if (wall->IsDestroyed())
        {
            delete m_layout[i][j];
            m_layout[i][j] = new MapObject(MapObject::EMPTY, m_texture);
            #ifdef DEBUG_OUTPUT_MAP
            std::cout << "MapObject at X:" << j << " Y:" << i << " is replaced with EMPTY." << std::endl;
            #endif // DEBUG_OUTPUT_MAP
        }
    }
    #ifdef DEBUG_OUTPUT_MAP
    else
    {
        std::cout << "MapObject at X:" << j << " Y:" << i << " is not DESTRUCTABLE_WALL." << std::endl;
    }
    #endif // DEBUG_OUTPUT_MAP
}


MapObject::Tile Map::GetTileType(unsigned int i, unsigned int j) const
{
    return m_layout[i][j]->GetId();
}

