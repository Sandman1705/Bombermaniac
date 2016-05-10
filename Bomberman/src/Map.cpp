#include "Map.h"

#include <stdio.h>      /*  NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>      /* fstream open close */

#include <iostream>     /* FOR DEBUR   REMOVE LATER */

//random map
Map::Map(int height, int width)
    : m_height(height), m_width(width), m_layout(m_height, std::vector<int>(m_width))
{
    srand (time(NULL));
    for (unsigned i=0; i<m_height; ++i)
    {
        for (unsigned j=0; j<m_width; ++j)
        {
            m_layout[i][j]=rand() % 3;
        }
    }
}


Map::Map(std::string path_to_file)
{
    std::fstream fs;
    fs.open (path_to_file, std::fstream::in);

    if (!fs.is_open())
    {
        std::cout << "Error opening file " << path_to_file << std::endl;
        exit(EXIT_FAILURE);
    }

    fs >> m_height >> m_width;

    m_layout.resize(m_height);
    for (unsigned i=0; i<m_height; ++i)
        m_layout[i].resize(m_width);

    for (unsigned i=0; i<m_height; ++i)
        for (unsigned j=0; j<m_width; ++j)
            fs >> m_layout[i][j];

    fs.close();
}

bool Map::Walkable(unsigned int i,unsigned int j)
{
    if (m_layout[i][j] == 0)
        return true;
    else
        return false;
}

