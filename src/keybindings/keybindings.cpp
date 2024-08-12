#include "keybindings.hpp"
#include <iostream>
#include <array>

bool clickKeybindings(SDL_Event event) {
    bool quit = false;
	
    // Click Keybindings
    switch (event.type) {
    case SDL_QUIT: // close button
        quit = true;
        break;
    case SDL_KEYDOWN: // key press
        if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            quit = true;
        }
        break;
    default:
        break;
    }

    return quit;
}

