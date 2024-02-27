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
#include "update.h"
#include "menu.h"

// GENERAL
SDL sdl = { NULL, NULL, NULL, NULL};
SETTINGS settings = { 1280, 720, false, 165, 50};

// VARIABLES
int game_is_running = false;

// INPUT
int key_input = NONE;
MOUSE_COORDS mouse_coords = { 0 , 0 };


int main(int argc, char* args[])
{
	game_is_running = initialize_window(&sdl, &settings);
	init_menu_textures(sdl.renderer);
	do {
		key_input = process_input(&mouse_coords);
		update(key_input, mouse_coords);
		render(sdl.renderer, settings);
	} while (game_is_running);

	return 0;
}