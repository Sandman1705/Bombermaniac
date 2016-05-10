#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include"includes.h"
#include"Map.h"
#include"Player.h"
#include"Bomb.h"

class game
{
private:
    bool Running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event Event;
    Map* level;
    Player *bomberman;
    std::vector<std::string> resourcesPaths;
    std::vector<SDL_Surface*> bmpFiles;
    std::vector<SDL_Texture*> textures;

    //std::vector<Bomb*> bombs;

protected:
    bool GetResourcesPaths();

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
