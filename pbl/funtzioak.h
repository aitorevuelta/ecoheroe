#include <stdio.h>
#include "string.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#define TILE_SIZE 32 // Cambia el valor según el tamaño de tus tiles

//konstanteak
#ifndef FUNTZIOAK_H
#define FUNTZIOAK_H

#define FALSE 0
#define TRUE 1

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800


//estruct-ak
typedef struct Boton_S
{
    SDL_Rect rect;
    int visible;
}Boton;

//funtzioak
void lehioaMargotu(SDL_Renderer* renderizador, int g, int b, int u, int alpha);
void jolastenHastekoBotoia(SDL_Renderer* renderizador, Boton* boton);
int clicEnBoton(int x, int y, struct Boton* boton);
void reproducirMusica(const char* rutaMusica);

#endif // FUNCIONES_H
