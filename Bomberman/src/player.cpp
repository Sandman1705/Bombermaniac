#include "Player.h"


Player::Player(SDL_Texture* tex, unsigned int tile_size, BombManager *bomb_manager,
               KeyboardInput *keyboard_input, Map *level, unsigned int val_x, unsigned int val_y)
{
    if(val_x == 0 && val_y == 0)
    {
        this->m_x = tile_size;
        this->m_y = tile_size;
    }
    else
    {
        this->m_x = val_x;
        this->m_y = val_y;
    }

    this->m_tex = tex;
    this->m_direction = DOWN;
    this->m_status = 0;
    this->m_tile_size = tile_size;

    m_player_size_w = m_player_size_w *tile_size/32;
    m_player_size_h = m_player_size_h *tile_size/32; //size according to 32px tile size
    m_move_speed = m_move_speed *m_tile_size/32; //speed according to 32px tile size
    m_bomb_manager = bomb_manager;
    m_keyboard_input = keyboard_input;
    m_level = level;
}

void Player::update()
{
    if(m_keyboard_input->IsKeyOn(SDLK_UP))
    {
        this->player_move(0, -1, m_level);
    }
    else if(m_keyboard_input->IsKeyOn(SDLK_DOWN))
        {
            this->player_move(0, 1, m_level);
        }
        else if(m_keyboard_input->IsKeyOn(SDLK_LEFT))
            {
                this->player_move(-1, 0, m_level);
            }
            else if (m_keyboard_input->IsKeyOn(SDLK_RIGHT))
                 {
                    this->player_move(1, 0, m_level);
                 }
                 else if(m_keyboard_input->IsKeyOn(SDLK_SPACE))
                     {
                         m_bomb_ready = true;
                     }
                     if(!m_keyboard_input->IsKeyOn(SDLK_SPACE) && m_bomb_ready)
                     {
                         this->place_bomb();
                         m_bomb_ready = false;
                     }
}

void Player::place_bomb()
{
    m_bomb_manager->MakeBomb(5000,m_x,m_y,2.5); // TODO Fix testing values
}

void Player::Draw(SDL_Renderer *renderer)
{
    SDL_Rect SrcR;
    SDL_Rect DestR;

    unsigned int SHAPE_SIZE_x = 18;
    unsigned int SHAPE_SIZE_y = 32;

    unsigned int source_x = 3;
    unsigned int source_y = 4;
    unsigned int source_const = 4;
    unsigned int texture_offset = source_const + SHAPE_SIZE_x + 2;

    SrcR.y = source_y;
    SrcR.w = SHAPE_SIZE_x;
    SrcR.h = SHAPE_SIZE_y;

    switch(m_direction)
    {
    case UP:
        //POSTION OF BOMBERMAN
        if(m_status % 3 == 0)
        {
            SrcR.x = source_x + 3*texture_offset;
        }
        if(m_status % 3 == 1)
        {
            SrcR.x = source_x + 4*texture_offset;
        }
        if(m_status % 3 == 2)
        {
            SrcR.x = source_x + 5*texture_offset;
        }
        break;

    case DOWN:
        //POSTION OF BOMBERMAN
        if(m_status % 3 == 0)
        {
            SrcR.x = source_x;

        }
        if(m_status % 3 == 1)
        {
            SrcR.x = source_x + texture_offset;
        }
        if(m_status % 3 == 2)
        {
            SrcR.x = source_x + 2*texture_offset;
        }
        break;

    case LEFT:
        //POSTION OF BOMBERMAN
        if(m_status % 3 == 0)
        {
            SrcR.x = source_x + 6*texture_offset;
        }
        if(m_status % 3 == 1)
        {
            SrcR.x = source_x + 7*texture_offset;
        }
        if(m_status % 3 == 2)
        {
            SrcR.x = source_x + 8*texture_offset;
        }
        break;

    case RIGHT:
        //POSTION OF BOMBERMAN
        if(m_status % 3 == 0) //POSTION OF BOMBERMAN
        {
            SrcR.x = source_x + 9*texture_offset;
        }
        if(m_status % 3 == 1)
        {
            SrcR.x = source_x + 10*texture_offset;
        }
        if(m_status % 3 == 2)
        {
            SrcR.x = source_x + 11*texture_offset;
        }
        break;
    }

    //----------------------
    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_player_size_w;
    DestR.h = m_player_size_h;
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
