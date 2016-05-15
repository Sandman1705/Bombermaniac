#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "includes.h"
#include "KeyboardInput.h"
#include "Map.h"
#include "ExplosionManager.h"
#include "BombManager.h"
#include "Player.h"
#include "Enemy.h"

class game
{
private:
    bool                Running;
    SDL_Window*         window;
    SDL_Renderer*       renderer;
    SDL_Event           Event;
    KeyboardInput*      keyboard_input;
    Map*                level;
    ExplosionManager*   explosion_manager;
    BombManager*        bomb_manager;
    Player*             bomberman;
    Enemy*              enemy;
    SDL_Texture*        texture;
    Timer               timer;

protected:

public:
    game();
    //virtual ~game();
    int OnExecute();
    bool OnInit();
    bool LoadContent();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void Cleanup();

};
#endif // GAME_H_INCLUDED
