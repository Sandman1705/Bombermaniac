#include "Player.h"

Player::Player(SDL_Texture* tex, unsigned int tile_size)
{
    this->m_x = tile_size;
    this->m_y = tile_size;
    this->m_tex = tex;
    this->m_direction = DOWN;
    this->m_status = 0;
    this->m_tile_size = tile_size;

    m_move_speed = m_move_speed *m_tile_size/32;
}

Player::Player(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x, unsigned int val_y)
{
    this->m_x = val_x;
    this->m_y = val_y;
    this->m_tex = tex;
    this->m_direction = DOWN;
    this->m_status = 0;
    this->m_tile_size = tile_size;
}

Player::~Player()
{
    //dtor
}

void Player::Draw(SDL_Renderer *renderer)
{
    SDL_Rect SrcR;
    SDL_Rect DestR;
    unsigned int SHAPE_SIZE = 32;

    switch(m_direction)
    {
    case UP:
        //POSTION OF BOMBERMAN
        if(m_status % 3 == 0)
        {
            SrcR.x = 7 + 2*SHAPE_SIZE;
            SrcR.y = 5;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        if(m_status % 3 == 1)
        {
            SrcR.x = 7 + 2*SHAPE_SIZE;
            SrcR.y = 5 + SHAPE_SIZE;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        if(m_status % 3 == 2)
        {
            SrcR.x = 7 + 2*SHAPE_SIZE;
            SrcR.y = 5 + 2*SHAPE_SIZE;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        break;

    case DOWN:
        //POSTION OF BOMBERMAN
        if(m_status % 3 == 0)
        {
            SrcR.x = 7;
            SrcR.y = 5;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        if(m_status % 3 == 1)
        {
            SrcR.x = 7;
            SrcR.y = 5 + SHAPE_SIZE;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        if(m_status % 3 == 2)
        {
            SrcR.x = 7;
            SrcR.y = 5 + 2*SHAPE_SIZE;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        break;

    case LEFT:
        //POSTION OF BOMBERMAN
        if(m_status % 3 == 0)
        {
            SrcR.x = 7 + SHAPE_SIZE;
            SrcR.y = 5;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        if(m_status % 3 == 1)
        {
            SrcR.x = 7 + SHAPE_SIZE;
            SrcR.y = 5 + SHAPE_SIZE;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        if(m_status % 3 == 2)
        {
            SrcR.x = 7 + SHAPE_SIZE;
            SrcR.y = 5 + 2*SHAPE_SIZE;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        break;

    case RIGHT:
        //POSTION OF BOMBERMAN
        if(m_status % 3 == 0) //POSTION OF BOMBERMAN
        {
            SrcR.x = 7 + 3*SHAPE_SIZE;
            SrcR.y = 5;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        if(m_status % 3 == 1)
        {
            SrcR.x = 7 + 3*SHAPE_SIZE;
            SrcR.y = 5 + SHAPE_SIZE;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        if(m_status % 3 == 2)
        {
            SrcR.x = 7 + 3*SHAPE_SIZE;
            SrcR.y = 5 + 2*SHAPE_SIZE;
            SrcR.w = SHAPE_SIZE-14;
            SrcR.h = SHAPE_SIZE-10;
        }
        break;
    }

    //----------------------
    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_player_size_w * m_tile_size/32;
    DestR.h = m_player_size_h * m_tile_size/32;
    //----------------------

    SDL_RenderCopy(renderer, m_tex, &SrcR, &DestR);
}

void Player::player_move(int x, int y, Map *level)
{
    unsigned int field_size = m_tile_size;

    if(x == 1) // MOVE RIGHT ------------
    {
        m_direction = RIGHT;
        if( level->Walkable( m_y/field_size, (m_x+m_player_size_w+m_move_speed)/field_size )
                && level->Walkable( (m_y+m_player_size_h)/field_size, (m_x+m_player_size_w+m_move_speed)/field_size) )
        {
            m_x = m_x + m_move_speed;
        }
    }
    else if (x == -1) // MOVE LEFT ------------
        {
            m_direction = LEFT;
            if(level->Walkable( m_y/field_size, (m_x-m_move_speed)/field_size )
                    && level->Walkable( (m_y+m_player_size_h)/field_size, (m_x-m_move_speed)/field_size) )
            {
                m_x = m_x - m_move_speed;
            }
        }
        else if(y == 1) // MOVE DOWN ------------
            {
                m_direction = DOWN;
                if(level->Walkable( (m_y+m_player_size_h+m_move_speed)/field_size, m_x/field_size )
                    && level->Walkable( (m_y+m_player_size_h+m_move_speed)/field_size, (m_x+m_player_size_w)/field_size ) )
                {
                    m_y = m_y + m_move_speed;
                }
            }
            else if(y == -1) // MOVE UP ------------
                {
                    m_direction = UP;
                    if(level->Walkable( (m_y - m_move_speed)/field_size, m_x/field_size )
                        &&  level->Walkable( (m_y - m_move_speed)/field_size, (m_x+m_player_size_w)/field_size) )
                    {
                        m_y = m_y - m_move_speed;
                    }
                }
    m_status++;
    if(m_status > 2)
        m_status = 0;
}

unsigned int Player::Get_x() const
{
    return m_x;
}

void Player::Set_x(unsigned int val)
{
    m_x = val;
}

unsigned int Player::Get_y() const
{
    return m_y;
}

void Player::Set_y(unsigned int val)
{
    m_y = val;
}

unsigned int Player::Get_size_w() const
{
    return m_player_size_w;
}

unsigned int Player::Get_size_h() const
{
    return m_player_size_h;
}

unsigned int Player::Get_status() const
{
    return m_status;
}

void Player::Set_status(int s)
{
    m_status = s;
}

unsigned int Player::Get_direction() const
{
    return m_direction;
}

void Player::Set_direction(int d)
{
    switch(d)
    {
        case 0:
            m_direction = LEFT;
            break;
        case 1:
            m_direction = RIGHT;
            break;
        case 2:
            m_direction = UP;
            break;
        case 3:
            m_direction = DOWN;
            break;
        default:
            m_direction = DOWN;
    }
}
