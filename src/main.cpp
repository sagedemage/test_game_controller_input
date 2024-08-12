#include "keybindings/keybindings.hpp"

#include <stdexcept>
#include <iostream>
#include <array>

#define LEVEL_WIDTH 744  // 750
#define LEVEL_HEIGHT 504 // 500

/* Frames per second */
const int miliseconds = 1000;   // 1000 ms equals 1s
const int gameplay_frames = 30; // amount of frames per second

void freeAndCloseResources(SDL_Window *win, SDL_GameController *gamecontroller,
		SDL_Joystick *joystick);

int main(__attribute__((unused)) int argc, __attribute__((unused)) char** argv) {
	
	
    /* Initialize SDL, window, audio, and renderer */
    int sdl_status = SDL_Init(
        SDL_INIT_VIDEO | SDL_INIT_JOYSTICK); // Initialize SDL library

    if (sdl_status == -1) {
        std::string debug_msg =
            "SDL_Init: " + static_cast<std::string>(SDL_GetError());
        std::runtime_error(debug_msg.c_str());
    }

    SDL_GameController *gamecontroller =
        SDL_GameControllerOpen(0); // Open Game Controller
	
	SDL_Joystick* joystick = SDL_JoystickOpen(0);

	if (joystick == NULL) {
		std::runtime_error("Joystick not open!");
	}

    // Create window
    SDL_Window *win =
        SDL_CreateWindow("Controller Input Recorder", SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, LEVEL_WIDTH, LEVEL_HEIGHT, 0);

    /* Gameplay Loop */
    bool quit = false; // gameplay loop switch

    while (!quit) { // gameplay loop
		/* Click Key Bindings */
        SDL_Event event; // Event handling

        while (SDL_PollEvent(&event) == 1) { // Events management
            // Click Keybindings
            quit = clickKeybindings(event);
        }
		std::string button_num = "None";
		std::array<int, 6> axes = {};

		if (SDL_JoystickGetButton(joystick, 0) == 1) {
			button_num = "0";
		}
		if (SDL_JoystickGetButton(joystick, 1) == 1) {
			button_num = "1";
		}
		if (SDL_JoystickGetButton(joystick, 2) == 1) {
			button_num = "2";
		}
		if (SDL_JoystickGetButton(joystick, 3) == 1) {
			button_num = "3";
		}
		if (SDL_JoystickGetButton(joystick, 4) == 1) {
			button_num = "4";
		}
		if (SDL_JoystickGetButton(joystick, 5) == 1) {
			button_num = "5";
		}
		if (SDL_JoystickGetButton(joystick, 6) == 1) {
			button_num = "6";
		}
		if (SDL_JoystickGetButton(joystick, 7) == 1) {
			button_num = "7";
		}
		if (SDL_JoystickGetButton(joystick, 8) == 1) {
			button_num = "8";
		}
		if (SDL_JoystickGetButton(joystick, 9) == 1) {
			button_num = "9";
		}
		if (SDL_JoystickGetButton(joystick, 10) == 1) {
			button_num = "10";
		}
		if (SDL_JoystickGetButton(joystick, 11) == 1) {
			button_num = "11";
		}
		if (SDL_JoystickGetButton(joystick, 12) == 1) {
			button_num = "12";
		}

		axes[0] = SDL_JoystickGetAxis(joystick, 0);
		axes[1] = SDL_JoystickGetAxis(joystick, 1);
		axes[2] = SDL_JoystickGetAxis(joystick, 2);
		axes[3] = SDL_JoystickGetAxis(joystick, 3);
		axes[4] = SDL_JoystickGetAxis(joystick, 4);
		axes[5] = SDL_JoystickGetAxis(joystick, 5);
		
		Uint8 hat_position = SDL_JoystickGetHat(joystick, 0);
		std::string hat_position_name = "";

		switch(hat_position) {
			case SDL_HAT_LEFT:
				hat_position_name = "JoyHat: SDL_HAT_LEFT";
				break;
			case SDL_HAT_RIGHT:
				hat_position_name = "JoyHat: SDL_HAT_RIGHT";
				break;
			case SDL_HAT_UP:
				hat_position_name = "JoyHat: SDL_HAT_UP";
				break;
			case SDL_HAT_DOWN:
				hat_position_name = "JoyHat: SDL_HAT_DOWN";
				break;
			case SDL_HAT_LEFTUP:
				hat_position_name = "JoyHat: SDL_HAT_LEFTUP";
				break;
			case SDL_HAT_LEFTDOWN:
				hat_position_name = "JoyHat: SDL_HAT_LEFTDOWN";
				break;
			case SDL_HAT_RIGHTUP:
				hat_position_name = "JoyHat: SDL_HAT_RIGHTUP";
				break;
			case SDL_HAT_RIGHTDOWN:
				hat_position_name = "JoyHat: SDL_HAT_RIGHTDOWN";
				break;
			default:
				hat_position_name = "JoyHat: SDL_HAT_CENTERED";
				break;	
		}

		// Print information
		std::cout << "----------------------------------" << std::endl;
		std::cout << " JoyHat: " + hat_position_name << std::endl;
		std::cout << " Button number: " + button_num << std::endl;
		std::cout << " Axis 0: " + std::to_string(axes[0]) << std::endl;
		std::cout << " Axis 1: " + std::to_string(axes[1]) << std::endl;
		std::cout << " Axis 2: " + std::to_string(axes[2]) << std::endl;
		std::cout << " Axis 3: " + std::to_string(axes[3]) << std::endl;
		std::cout << " Axis 4: " + std::to_string(axes[4]) << std::endl;
		std::cout << " Axis 5: " + std::to_string(axes[5]) << std::endl;
		std::cout << "----------------------------------" << std::endl;
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
		
		SDL_Delay(miliseconds / gameplay_frames); // Calculates to 60 fps
    }

    /* Free resources and close SDL and SDL mixer */
    freeAndCloseResources(win, gamecontroller, joystick);

	return 0;
}

void freeAndCloseResources(SDL_Window *win, SDL_GameController *gamecontroller, SDL_Joystick *joystick) {
    /* Free resources and close SDL */
    // Close Game Controller
    SDL_GameControllerClose(gamecontroller);
	SDL_JoystickClose(joystick);

	SDL_DestroyWindow(win);
    SDL_Quit();                // Quit SDL subsystems
}
