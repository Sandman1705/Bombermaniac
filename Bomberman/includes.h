#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

using namespace std;

#endif // INCLUDES_H_INCLUDED

#define DEBUG_OUTPUT

/*
Please not that if you use a later version of SDL you will need to update the linker directories and compiler directories under
Settings>Compiler>Search directories>Linker and Settings>Compiler>Search directories>compiler

The directories below are the ones that will need to be changed if you use a different version.

Under: settings>Search directories>Compiler
C:\SDL\SDL2-2.0.2\i686-w64-mingw32\include\SDL2
C:\SDL\SDL2_image-2.0.0\i686-w64-mingw32\include\SDL2

Under: settings>Search directories>Linker
C:\SDL\SDL2-2.0.2\i686-w64-mingw32\lib
C:\SDL\SDL2_image-2.0.0\i686-w64-mingw32\lib

My includes are
#include <SDL.h>
#include <SDL_image.h>

if you change
C:\SDL\SDL2-2.0.2\i686-w64-mingw32\include\SDL2
C:\SDL\SDL2_image-2.0.0\i686-w64-mingw32\include\SDL2
to
C:\SDL\SDL2-2.0.2\i686-w64-mingw32\include
C:\SDL\SDL2_image-2.0.0\i686-w64-mingw32\include
the include would need to be changed to
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
*/
