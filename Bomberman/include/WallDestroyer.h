#ifndef WALLDESTROYER_H
#define WALLDESTROYER_H

/**
 *  \file WallDestroyer.h
 *
 *  Defines class WallDestroyer which is to calculate the effects of bomb
 *  explosions and makes changes to the map.
 */

#include "Map.h"

/** \class WallDestroyer
 *  \brief class for destroying walls on the map
 *  \details This class is used to calculate the effects of bomb explosions and
 *           makes changes to the map in the game.
 */
class WallDestroyer
{
    public:
        /**
         *  \brief Constructor for WallDestroyer
         *
         *  Makes an object of class WallDestroyer according to given attributes
         *  \param level pointer to object Map to which it will make changes
         *  \param start_x x coordinate of explosion
         *  \param start_y y coordinate of explosion
         *  \param tile_size pixel size of one tile on the map
         *  \param intensity real value of explosion's size and effect it will
         *         make (1.0 is radius of one tile size of the map)
         */
        WallDestroyer(Map* level,
                      unsigned int start_x,
                      unsigned int start_y,
                      unsigned int tile_size,
                      double intensity);

    protected:

        void Spread(int row, int col, int direction_row, int direction_col);
        void Destroy(int row, int col);

    private:
        Map*            m_level;
        unsigned int    m_start_x;
        unsigned int    m_start_y;
        unsigned int    m_tile_size;
        double          m_intensity;

};

#endif // WALLDESTROYER_H
