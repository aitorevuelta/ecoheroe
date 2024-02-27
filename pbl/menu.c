#define _CRT_SECURE_NO_WARNINGS

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "SDL_mixer.h"
#include <stdio.h>
#include <stdbool.h>

#include "globals.h"
#include "render.h"
#include "input.h"
#include "menu.h"

MENU_ITEMS menu_items[] = {
    {"fotos/fondo.png", NULL},
    {"fotos/kontrolak.png", NULL},
    {"fotos/kredituak.png", NULL},
    {"fotos/play.png", NULL},
    {"fotos/volver.png", NULL},
    {"fotos/controls.png", NULL},
    {"fotos/credits.png", NULL},
};

void init_menu_textures(SDL_Renderer* renderer)
{
    int i;
    for (i = 0; i < NUM_TEXTURES; i++)
    {
        menu_items[i].texture = load_texture(menu_items[i].image_path, renderer);
    }
}

void render_menu(SDL_Renderer* renderer, SETTINGS settings)
{
    int window_width = settings.window_width;
    int window_height = settings.window_height;

    render_texture(renderer, menu_items[BACKGROUND].texture, window_width/2, window_height/2, window_width, window_height);
}