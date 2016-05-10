#include "WallDestroyer.h"

#ifdef DEBUG_OUTPUT
#include<iostream>
#endif // DEBUG_OUTPUT

WallDestroyer::WallDestroyer(Map* level,
                             unsigned int start_x,
                             unsigned int start_y,
                             unsigned int tile_size,
                             double intensity)
    :   m_level(level),
        m_start_x(start_x),
        m_start_y(start_y),
        m_tile_size(tile_size),
        m_intensity(intensity)
{
    int i = m_start_y / tile_size; // row number
    int j = m_start_x / tile_size; // column number
    #ifdef DEBUG_OUTPUT
    std::cout << "WallDestroyer Start at: (i,j)=" << i << "," << j << std::endl;
    #endif // DEBUG_OUTPUT
    MapObject::Tile up    = level->Get_tile_type(i-1,j);
    MapObject::Tile down  = level->Get_tile_type(i+1,j);
    MapObject::Tile left  = level->Get_tile_type(i,j-1);
    MapObject::Tile right = level->Get_tile_type(i,j+1);
     //UP
    if (up == MapObject::EMPTY)
        Spread(i-1,j,-1,0);
    else if (up == MapObject::DESTRUCTABLE_WALL)
        Destroy(i-1,j);
     //DOWN
    if (down == MapObject::EMPTY)
        Spread(i+1,j,1,0);
    else if (down == MapObject::DESTRUCTABLE_WALL)
        Destroy(i+1,j);
     //LEFT
    if (left == MapObject::EMPTY)
        Spread(i,j-1,0,-1);
    else if (left == MapObject::DESTRUCTABLE_WALL)
        Destroy(i,j-1);
     //RIGHT
    if (right == MapObject::EMPTY)
        Spread(i,j+1,0,1);
    else if (right == MapObject::DESTRUCTABLE_WALL)
        Destroy(i,j+1);
}

void WallDestroyer::Spread(int row, int col, int direction_row, int direction_col)
{
    #ifdef DEBUG_OUTPUT
    std::cout << "WallDestroyer Explosion spread to: (i,j)=" << row << "," << col << std::endl;
    #endif // DEBUG_OUTPUT

}

void WallDestroyer::Destroy(int row, int col)
{
    #ifdef DEBUG_OUTPUT
    std::cout << "WallDestroyer Destroying wall: (i,j)=" << row << "," << col << std::endl;
    #endif // DEBUG_OUTPUT
    m_level->DestroyWall(row,col);
}

