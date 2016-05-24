#include "Entity/EnemyThree.h"
#include "Constants/TextureEnemyConstants.h"

EnemyThree::EnemyThree(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x, unsigned int val_y)
: Enemy(tex, tile_size, val_x, val_y)
{
    m_speed = 100; //timer speed
    m_move_speed = m_move_speed *m_tile_size/32; //speed according to 32px tile size

    m_rotation_const = 7;
    m_enemy_size_w = TEXTURE_ENEMY_THREE_SIZE_W *tile_size/32;
    m_enemy_size_h = TEXTURE_ENEMY_THREE_SIZE_H *tile_size/32; //size according to 32px tile size
}

void EnemyThree::Draw(SDL_Renderer* renderer)
{
    SDL_Rect SrcR;
    SDL_Rect DestR;

    SrcR.y = TEXTURE_ENEMY_THREE_Y;
    SrcR.w = TEXTURE_ENEMY_THREE_SOURCE_W;
    SrcR.h = TEXTURE_ENEMY_THREE_SOURCE_H;

    if(m_status % m_rotation_const == 0)
    {
        SrcR.x = TEXTURE_ENEMY_THREE_X;
    }
    if(m_status % m_rotation_const == 1)
    {
        SrcR.x = TEXTURE_ENEMY_THREE_X + TEXTURE_ENEMY_THREE_TEXTURE_OFFSET;
    }
    if(m_status % m_rotation_const == 2)
    {
        SrcR.x = TEXTURE_ENEMY_THREE_X + 2*TEXTURE_ENEMY_THREE_TEXTURE_OFFSET;
    }
    if(m_status % m_rotation_const == 3)
    {
        SrcR.x = TEXTURE_ENEMY_THREE_X + 3*TEXTURE_ENEMY_THREE_TEXTURE_OFFSET;
    }
    if(m_status % m_rotation_const == 4)
    {
        SrcR.x = TEXTURE_ENEMY_THREE_X + 4*TEXTURE_ENEMY_THREE_TEXTURE_OFFSET;
    }
    if(m_status % m_rotation_const == 5)
    {
        SrcR.x = TEXTURE_ENEMY_THREE_X + 5*TEXTURE_ENEMY_THREE_TEXTURE_OFFSET;
    }
    if(m_status % m_rotation_const == 6)
    {
        SrcR.x = TEXTURE_ENEMY_THREE_X + 6*TEXTURE_ENEMY_THREE_TEXTURE_OFFSET;
    }

    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_enemy_size_w;
    DestR.h = m_enemy_size_h;

    SDL_RenderCopy(renderer, m_tex, &SrcR, &DestR);
}
