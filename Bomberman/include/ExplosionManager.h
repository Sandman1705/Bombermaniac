#ifndef EXPLOSIONMANAGER_H
#define EXPLOSIONMANAGER_H

#include <list>
#include "Explosion.h"

class ExplosionManager
{
    public:
        ExplosionManager(SDL_Texture* texture, unsigned int tile_size);
        ~ExplosionManager();
        //TODO Copy Constructor
        //TODO Operator =

        void AddExplosion(Explosion *explosion);
        void MakeExplosion(unsigned int duration,
                           unsigned int x_center,
                           unsigned int y_center,
                           double intensity);
        void Update();
        void Draw(SDL_Renderer* renderer) const;

    protected:

    private:
        std::list<Explosion*>   m_explosions;
        SDL_Texture*            m_texture;
        unsigned int            m_tile_size;
        SDL_Rect                m_start_SrcR;
};

#endif // EXPLOSIONMANAGER_H
