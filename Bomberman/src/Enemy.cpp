#include "Enemy.h"

Enemy::Enemy(SDL_Texture* tex, unsigned int tile_size)
{
    this->m_x = 2*tile_size;
    this->m_y = tile_size;
    this->m_tex = tex;
    this->m_status = 0;
    this->m_tile_size = tile_size;
    this->m_direction = RIGHT;

    srand(time(NULL));

    m_timer.resetTimer();

    m_enemy_size_w = m_enemy_size_w *tile_size/32;
    m_enemy_size_h = m_enemy_size_h *tile_size/32; //size according to 32px tile size
    m_move_speed = m_move_speed *m_tile_size/32; //speed according to 32px tile size
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::update(Map *level)
{
    int r;

    if(m_walk_len <= 0)
    {
        m_walk_len = rand()%5 + 10;
        r = rand()%4;
        switch(r)
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

    m_walk_len--;



    if(m_timer.getTimeElapsed() > 100)
    {
        this->enemy_move(level);
        m_timer.resetTimer();
    }
}

void Enemy::Draw(SDL_Renderer *renderer)
{
    SDL_Rect SrcR;
    SDL_Rect DestR;

    unsigned int SHAPE_SIZE_x = 20;
    unsigned int SHAPE_SIZE_y = 25;

    unsigned int source_x = 1;
    unsigned int source_y = 183;
    unsigned int source_const = 5;
    unsigned int texture_offset = source_const + SHAPE_SIZE_x;

    SrcR.y = source_y;
    SrcR.w = SHAPE_SIZE_x;
    SrcR.h = SHAPE_SIZE_y;


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

    //----------------------
    DestR.x = m_x;
    DestR.y = m_y;
    DestR.w = m_enemy_size_w;
    DestR.h = m_enemy_size_h;
    //----------------------

    SDL_RenderCopy(renderer, m_tex, &SrcR, &DestR);
}

void Enemy::enemy_move(Map *level)
{
    unsigned int field_size = m_tile_size;

    if(m_direction == RIGHT) // MOVE RIGHT ------------
    {

        if( level->Walkable( m_y/field_size, (m_x+m_enemy_size_w+m_move_speed)/field_size )
                && level->Walkable( (m_y+m_enemy_size_h)/field_size, (m_x+m_enemy_size_w+m_move_speed)/field_size) )
        {
            m_x = m_x + m_move_speed;
        }
    }
    else if (m_direction == LEFT) // MOVE LEFT ------------
        {
            if(level->Walkable( m_y/field_size, (m_x-m_move_speed)/field_size )
                    && level->Walkable( (m_y+m_enemy_size_h)/field_size, (m_x-m_move_speed)/field_size) )
            {
                m_x = m_x - m_move_speed;
            }
        }
        else if(m_direction == DOWN) // MOVE DOWN ------------
            {

                if(level->Walkable( (m_y+m_enemy_size_h+m_move_speed)/field_size, m_x/field_size )
                    && level->Walkable( (m_y+m_enemy_size_h+m_move_speed)/field_size, (m_x+m_enemy_size_w)/field_size ) )
                {
                    m_y = m_y + m_move_speed;
                }
            }
            else if(m_direction == UP) // MOVE UP ------------
                {

                    if(level->Walkable( (m_y - m_move_speed)/field_size, m_x/field_size )
                        &&  level->Walkable( (m_y - m_move_speed)/field_size, (m_x+m_enemy_size_w)/field_size) )
                    {
                        m_y = m_y - m_move_speed;
                    }
                }
    m_status++;
    if(m_status > 2)
        m_status = 0;
}

unsigned int Enemy::Get_x() const
{
    return m_x;
}

void Enemy::Set_x(unsigned int val)
{
    m_x = val;
}

unsigned int Enemy::Get_y() const
{
    return m_y;
}

void Enemy::Set_y(unsigned int val)
{
    m_y = val;
}

unsigned int Enemy::Get_size_w() const
{
    return m_enemy_size_w;
}

unsigned int Enemy::Get_size_h() const
{
    return m_enemy_size_h;
}

unsigned int Enemy::Get_status() const
{
    return m_status;
}

void Enemy::Set_status(int s)
{
    m_status = s;
}
