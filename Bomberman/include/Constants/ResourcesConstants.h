#ifndef RESOURCESCONSTANTS_H_INCLUDED
#define RESOURCESCONSTANTS_H_INCLUDED

#include <string>

#ifdef _WIN32
static const std::string RESOURCES_BASE_PATH        = "resources\\";
static const std::string RESOURCES_LEVELS_PATH      = "resources\\levels\\";
#else // LINUX
static const std::string RESOURCES_BASE_PATH        = "resources/";
static const std::string RESOURCES_LEVELS_PATH      = "resources/levels/";
#endif

static const std::string RESOURCES_TEXTURES         = "textures.bmp";
static const std::string RESOURCES_FONT             = "Zabdilus.ttf";
static const std::string RESOURCES_MUSIC            = "bomberman.mp3";

static const std::string RESOURCES_LEVEL_MAP        = "level";
static const std::string RESOURCES_LEVEL_MAP_EXT    = ".txt";
static const std::string RESOURCES_LEVEL_ENEMY      = "enemy";
static const std::string RESOURCES_LEVEL_ENEMY_EXT  = ".txt";
static const std::string RESOURCES_LEVEL_PLAYER     = "player";
static const std::string RESOURCES_LEVEL_PLAYER_EXT = ".txt";
static const unsigned int RESOURCES_LEVEL_COUNT     = 2;

#endif // RESOURCESCONSTANTS_H_INCLUDED
