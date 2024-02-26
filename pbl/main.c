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

// ESTRUCTURAS
SDL sdl = { NULL, NULL, NULL, NULL};
SETTINGS settings = { 1280, 720, 50, false};

// VARIABLES
int game_is_running = false;


int main() 
{
	game_is_running = initialize_window(&sdl, &settings);
	do {

		render(sdl.renderer);
	} while (game_is_running);

	return 0;
}