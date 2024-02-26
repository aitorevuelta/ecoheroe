#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "SDL_mixer.h"
#include <stdio.h>
#include <stdbool.h>

#include "globals.h"
#include "initializer.h"


int initialize_window(SDL* sdl, SETTINGS* settings)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "SDL error.\n");
        return false;
    }

    sdl->window = SDL_CreateWindow("Eco heroe 33", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, settings->window_width, settings->window_height, settings->fullscreen);
    if (!sdl->window) {
        fprintf(stderr, "Error creating SDL window.\n");
        return false;
    }

    sdl->renderer = SDL_CreateRenderer(sdl->window, -1, 0);
    if (!sdl->renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return false;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        fprintf(stderr, "Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return false;
    }

    if ((IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG) {
        fprintf(stderr, "Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return false;
    }

    if (TTF_Init() != 0) {
        fprintf(stderr, "Error al inicializar SDL_ttf: %s\n", TTF_GetError());
        SDL_Quit();
        return false;
    }

    sdl->font = TTF_OpenFont("font/pixelart.ttf", 24);
    if (!sdl->font) {
        fprintf(stderr, "Error al cargar la fuente: %s\n", TTF_GetError());
        SDL_Quit();
        return false;
    }
    sdl->font_small = TTF_OpenFont("font/pixelart.ttf", 20);
    if (!sdl->font_small)
    {
        fprintf(stderr, "Error al cargar la fuente: %s\n", TTF_GetError());
        SDL_Quit();
        return false;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        fprintf(stderr, "Error al inicializar SDL Mixer: %s\n", Mix_GetError());
        SDL_Quit();
        return false;
    }
    return true;
}

void toggle_fullscreen(SDL_Window* window, int* window_width, int* window_height) 
{
    if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN) {
        SDL_SetWindowFullscreen(window, 0);
        SDL_SetWindowSize(window, 1280, 720);
        SDL_GetWindowSize(window, window_width, window_height);
    }
    else {
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        SDL_GetWindowSize(window, window_width, window_height);
        SDL_GetWindowSize(window, window_width, window_height);
    }
}