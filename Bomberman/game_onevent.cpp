#include"game.h"

//#define DEBUG_OUTPUT

#ifdef DEBUG_OUTPUT
#include<cstdio>
void PrintKeyInfo( SDL_KeyboardEvent *key );
#endif // DEBUG_OUTPUT

void game::OnEvent(SDL_Event* Event)
{
    if(Event->type == SDL_QUIT)
    {
        Running = false;
    }

    switch( Event->type )
    {

    case SDL_KEYDOWN:
        switch( Event->key.keysym.sym )
        {
        case SDLK_UP:
            bomberman->player_move(0, -1, level);
            break;

        case SDLK_DOWN:
            bomberman->player_move(0, 1, level);
            break;

        case SDLK_LEFT:
            bomberman->player_move(-1, 0, level);
            break;

        case SDLK_RIGHT:
            bomberman->player_move(1, 0, level);
            break;
        }

        break;

    case SDL_KEYUP:
        bomberman->Set_status(0);
        #ifdef DEBUG_OUTPUT
        PrintKeyInfo( &(Event->key) );
        #endif // DEBUG_OUTPUT
        switch( Event->key.keysym.sym )
        {
        case SDLK_SPACE:
            bomberman->place_bomb();
            break;
        case SDLK_f: // mostly for testing
            //level->DestroyWall(1,7);
            //SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
            break;
        default:
            break;
        }
        break;

    /* SDL_QUIT event (window close) */
    case SDL_QUIT:
        Running = false;
        break;

    default:
        break;
    }


}

#ifdef DEBUG_OUTPUT
void PrintKeyInfo( SDL_KeyboardEvent *key )
{
    /* Is it a release or a press? */
    if( key->type == SDL_KEYUP )
        printf( "Release:- " );
    else
        printf( "Press:- " );

    /* Print the hardware scancode first */
    printf( "Scancode: 0x%02X", key->keysym.scancode );
    /* Print the name of the key */
    printf( ", Name: %s", SDL_GetKeyName( key->keysym.sym ) );
    /* We want to print the unicode info, but we need to make */
    /* sure its a press event first (remember, release events */
    /* don't have unicode info                                */
    if( key->type == SDL_KEYDOWN )
    {
        /* If the Unicode value is less than 0x80 then the    */
        /* unicode value can be used to get a printable       */
        /* representation of the key, using (char)unicode.    */
        printf(", Unicode: " );
        if( key->keysym.sym < 0x80 && key->keysym.sym > 0 )
        {
            printf( "%c (0x%04X)", (char)key->keysym.sym,
                    key->keysym.sym );
        }
        else
        {
            printf( "? (0x%04X)", key->keysym.sym );
        }
    }
    printf( "\n" );
    /* Print modifier info */
    //PrintModifiers( key->keysym.mod );
}

/* Print modifier info */
/*
void PrintModifiers( Unit16 mod )
{
    printf( "Modifers: " );

    // If there are none then say so and return //
    if( mod == KMOD_NONE )
    {
        printf( "None\n" );
        return;
    }

    // Check for the presence of each SDLMod value //
    // This looks messy, but there really isn't    //
    // a clearer way.                              //
    if( mod & KMOD_NUM ) printf( "NUMLOCK " );
    if( mod & KMOD_CAPS ) printf( "CAPSLOCK " );
    if( mod & KMOD_LCTRL ) printf( "LCTRL " );
    if( mod & KMOD_RCTRL ) printf( "RCTRL " );
    if( mod & KMOD_RSHIFT ) printf( "RSHIFT " );
    if( mod & KMOD_LSHIFT ) printf( "LSHIFT " );
    if( mod & KMOD_RALT ) printf( "RALT " );
    if( mod & KMOD_LALT ) printf( "LALT " );
    if( mod & KMOD_CTRL ) printf( "CTRL " );
    if( mod & KMOD_SHIFT ) printf( "SHIFT " );
    if( mod & KMOD_ALT ) printf( "ALT " );
    printf( "\n" );
}
*/
#endif // DEBUG_OUTPUT
