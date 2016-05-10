#ifndef WALLDESTROYER_H
#define WALLDESTROYER_H

#include "Map.h"

class WallDestroyer
{
    public:
        WallDestroyer(Map* level,
                      unsigned int start_x,
                      unsigned int start_y,
                      unsigned int tile_size,
                      double intensity);

        // Row = i; Column = j
        void Spread(int row, int col, int direction_row, int direction_col);
        void Destroy(int row, int col);

    protected:

    private:
        Map*            m_level;
        unsigned int    m_start_x;
        unsigned int    m_start_y;
        unsigned int    m_tile_size;
        double          m_intensity;

};

#endif // WALLDESTROYER_H
