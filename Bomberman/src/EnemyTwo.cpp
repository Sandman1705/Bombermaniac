#include "EnemyTwo.h"
#include "Map.h"
#include <iostream>
EnemyTwo::EnemyTwo(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x, unsigned int val_y)
 : Enemy(tex, tile_size, val_x, val_y)
{
    m_speed = 74; //timer speed
    m_move_speed = m_move_speed *m_tile_size/32; //speed according to 32px tile size

    m_rotation_const = 3;
    m_enemy_size_w = 17;
    m_enemy_size_h = 23;
    m_enemy_size_w = m_enemy_size_w *tile_size/32;
    m_enemy_size_h = m_enemy_size_h *tile_size/32; //size according to 32px tile size
}

void EnemyTwo::Draw(SDL_Renderer *renderer)
{
    SDL_Rect SrcR;
    SDL_Rect DestR;

    unsigned int SHAPE_SIZE_x = 24;
    unsigned int SHAPE_SIZE_y = 26;

    unsigned int source_x = 0;
    unsigned int source_y = 159;
    unsigned int texture_offset = SHAPE_SIZE_x;

    SrcR.y = source_y;
    SrcR.w = SHAPE_SIZE_x;
    SrcR.h = SHAPE_SIZE_y;


    if(m_status % m_rotation_const == 0)
    {
        SrcR.x = source_x;
    }
    if(m_status % m_rotation_const == 1)
    {
        SrcR.x = source_x + texture_offset;
    }
    if(m_status % m_rotation_const == 2)
    {
        SrcR.x = source_x + 2*texture_offset;
    }

    //----------------------
    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_enemy_size_w;
    DestR.h = m_enemy_size_h;
    //----------------------

    SDL_RenderCopy(renderer, m_tex, &SrcR, &DestR);
}
