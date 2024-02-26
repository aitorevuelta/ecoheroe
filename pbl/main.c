#define _CRT_SECURE_NO_WARNINGS

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "SDL_mixer.h"
#include <stdio.h>
#include <stdbool.h>

#include "globals.h"
#include "initializer.h"
#include "render.h"
#include "input.h"

// ESTRUCTURAS
SDL sdl = { NULL, NULL, NULL, NULL};
SETTINGS settings = { 1280, 720, 50, true, 165};

// VARIABLES
int game_is_running = false;
int input = NONE;


int main() 
{
	game_is_running = initialize_window(&sdl, &settings);
	do {
		input = process_input();
		render(sdl.renderer, input);
	} while (game_is_running);

	return 0;
}