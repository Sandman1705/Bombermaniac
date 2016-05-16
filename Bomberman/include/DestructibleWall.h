#ifndef DESTRUCTIBLEWALL_H
#define DESTRUCTIBLEWALL_H

/**
 *  \file DestructibleWall.h
 *
 *  Defines class DestructibleWall which represents MapObject which is of type
 *  MapObject::DESTRUCTIBLE_WALL
 *
 */

#include "MapObject.h"

/** \class DestructibleWall
 *  \brief class which represents an MapObject which is a destructible wall.
 *  \details This class inherits class MapObject and adds functionalities for
 *           keeping track of damage done to a wall.
 */
class DestructibleWall : public MapObject
{
    public:
        /**
         *  \brief Constructor for DestructibleWall.
         *
         *  Makes an object of class DestructibleWall according to given
         *  attributes.
         *  \param texture pointer to SDL_texture object from which the texture
         *         will be taken for method Draw()
         *  \param SrcR location and size of texture on given SLD_Texture
         */
        DestructibleWall(SDL_Texture *texture, SDL_Rect SrcR);

        /**
         *  \brief Tells if the wall is destroyed
         *
         *  If the integrity of wall is at 0 the it returns true which means
         *  that this object should be deleted.
         *  \return true if the wall should be destroyed
         */
        bool IsDestroyed() const;
        /**
         *  \brief Decreases the integrity of the wall according to damage taken
         *
         *  Given parameter represents the damage in percentages to the wall
         *  that it should take. Percentages given represents a portion of
         *  maximum integrity not current.
         *  \return void
         */
        void DecreaseIntegrity(int value);

    protected:

    private:
        int                 m_integrity;
        static const int    S_MAX_INTEGRITY = 100;

};

#endif // DESTRUCTIBLEWALL_H
