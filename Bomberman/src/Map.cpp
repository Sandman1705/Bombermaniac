#include "Map.h"

#include <stdio.h>      /*  NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Map::Map()
    : m_height(0), m_width(0)
{
}

Map::Map(int height, int width)
    : m_height(height), m_width(width), m_layout(m_height, std::vector<char>(m_width))
{
    //for ( auto i = m_layout.begin() ; i != m_layout.end() ; ++i )
    //     (*i).resize(width);
}

Map::~Map()
{
}

bool Map::loadLayout()
{
    srand (time(NULL));
    for (unsigned i=0; i<m_height; ++i)
    {
        for (unsigned j=0; j<m_width; ++j)
        {
            m_layout[i][j]=rand() % 4;
        }
    }
    return true;
}
