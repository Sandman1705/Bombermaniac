#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#include <SDL_keycode.h>
#include <map>

class KeyboardInput
{
    public:
        KeyboardInput();

        void TurnKeyOn(SDL_Keycode key);
        void TurnKeyOff(SDL_Keycode key);
        bool IsKeyOn(SDL_Keycode key);

    protected:

    private:
        std::map<SDL_Keycode,bool> m_keys_pressed;
};

#endif // KEYBOARDINPUT_H
