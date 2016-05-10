#include "MapObject.h"

MapObject::MapObject(unsigned int id, SDL_Texture *texture)
    : m_id(id), m_texture(texture)
{

}

void MapObject::Draw(SDL_Renderer* renderer, const int tile_size, const SDL_Rect *DestR)
{
    SDL_Rect SrcR;

    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = tile_size;
    SrcR.h = tile_size;

    SDL_RenderCopy(renderer, m_texture, &SrcR, DestR);
}
