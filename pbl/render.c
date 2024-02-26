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

void render_texture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height) 
{
    SDL_Rect dest_rect = { x - width / 2, y - height / 2, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
}

void render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Crear un rectángulo para el cuadrado
    SDL_Rect rect = { 100, 100, 50, 50 };

    // Dibujar el rectángulo
    SDL_RenderDrawRect(renderer, &rect);

    // Renderizar el cuadrado
    SDL_RenderPresent(renderer);
}
