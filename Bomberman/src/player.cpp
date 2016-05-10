#include "player.h"

player::player(SDL_Texture* tex)
{
    this->m_x = 32;
    this->m_y = 32;
    this->m_tex = tex;
}

player::player(SDL_Texture* tex, unsigned int val_x, unsigned int val_y)
{
    this->m_x = val_x;
    this->m_y = val_y;
    this->m_tex = tex;
}

void player::Draw(SDL_Renderer *renderer)
{
    SDL_Rect SrcR;
    SDL_Rect DestR;
    int SHAPE_SIZE = 32;

    SrcR.x = 7;
    SrcR.y = 5;
    SrcR.w = SHAPE_SIZE-14;
    SrcR.h = SHAPE_SIZE-10;
    //----------------------
    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_player_size_w;
    DestR.h = m_player_size_h;
    //----------------------

    //SDL_Texture *tex = textures[3];
    SDL_RenderCopy(renderer, m_tex, &SrcR, &DestR);
}

void player::player_move(int x, int y, Map *level)
{
    unsigned int field_size = 32;

    if(x == 1) // MOVE RIGHT ------------
    {
        if( level->Walkable( m_y/field_size, (m_x+m_player_size_w+m_move_speed)/field_size )
                && level->Walkable( (m_y+m_player_size_h)/field_size, (m_x+m_player_size_w+m_move_speed)/field_size) )
        {
            m_x = m_x + m_move_speed;
        }
    }
    else if (x == -1) // MOVE LEFT ------------
        {
            if(level->Walkable( m_y/field_size, (m_x-m_move_speed)/field_size )
                    && level->Walkable( (m_y+m_player_size_h)/field_size, (m_x-m_move_speed)/field_size) )
            {
                m_x = m_x - m_move_speed;
            }
        }
        else if(y == 1) // MOVE DOWN ------------
            {
                if(level->Walkable( (m_y+m_player_size_h+m_move_speed)/field_size, m_x/field_size )
                    && level->Walkable( (m_y+m_player_size_h+m_move_speed)/field_size, (m_x+m_player_size_w)/field_size ) )
                {
                    m_y = m_y + m_move_speed;
                }
            }
            else if(y == -1) // MOVE UP ------------
                {
                    if(level->Walkable( (m_y - m_move_speed)/field_size, m_x/field_size )
                        &&  level->Walkable( (m_y - m_move_speed)/field_size, (m_x+m_player_size_w)/field_size) )
                    {
                        m_y = m_y - m_move_speed;
                    }
                }
}

unsigned int player::Get_x() const
{
    return m_x;
}

void player::Set_x(unsigned int val)
{
    m_x = val;
}

unsigned int player::Get_y() const
{
    return m_y;
}

void player::Set_y(unsigned int val)
{
    m_y = val;
}

unsigned int player::Get_size_w() const
{
    return m_player_size_w;
}

unsigned int player::Get_size_h() const
{
    return m_player_size_h;
}

player::~player()
{
    //dtor
}
