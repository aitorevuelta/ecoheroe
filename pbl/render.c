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
#include "menu.h"

SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer)
{
    // Construye la ruta completa a la textura en la carpeta "assets"

    SDL_Surface* surface = IMG_Load(filename);
    if (!surface)
    {
        fprintf(stderr, "Error al cargar la imagen %s: %s\n", filename, IMG_GetError());
        return NULL;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        fprintf(stderr, "Error al crear la textura desde %s: %s\n", filename, SDL_GetError());
        return NULL;
    }

    return texture;
}

void render_texture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height) 
{
    SDL_Rect dest_rect = { x - width / 2, y - height / 2, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
}

void render(SDL_Renderer* renderer, SETTINGS settings)
{
    // Establecer el color de limpieza (fondo) antes de borrar la pantalla
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Color negro

    // Limpiar la pantalla con el color de limpieza
    SDL_RenderClear(renderer);
    render_menu(renderer, settings);

    // Renderizar el cuadrado
    SDL_RenderPresent(renderer);
}
