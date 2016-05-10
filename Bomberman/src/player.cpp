#include "player.h"

player::player()
{
    this->m_x = 0;
    this->m_y = 0;
}

player::player(unsigned int val_x, unsigned int val_y)
{
    this->m_x = val_x;
    this->m_y = val_y;
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

player::~player()
{
    //dtor
}
