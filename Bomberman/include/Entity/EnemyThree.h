#ifndef ENEMYTHREE_H
#define ENEMYTHREE_H


#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "Utility/Relay.h"
#include "Utility/Timer.h"
#include "Entity/Player.h"
#include "Entity/Enemy.h"

class EnemyThree : public Enemy
{
    public:
        EnemyThree(SDL_Texture* tex, unsigned int tile_size, unsigned int val_x = 1, unsigned int val_y = 1);

        void Draw(SDL_Renderer* renderer);
    protected:

    private:
};

#endif // ENEMYTHREE_H
