// funciones.c
#include "funtzioak.h"

void lehioaMargotu(SDL_Renderer* renderizador, int g, int b, int u, int alpha)
{
    SDL_SetRenderDrawColor(renderizador, g, b, u, alpha);
    SDL_RenderClear(renderizador);
    //SDL_RenderPresent(renderizador); Hau kendu izan ere main.c-an egiten denez kendu
}

void jolastenHastekoBotoia(SDL_Renderer* renderizador, Boton* boton)
{
    SDL_RenderFillRect(renderizador, &(boton->rect));

}

int clicEnBoton(int x, int y, Boton* boton)
{
    return (x >= boton->rect.x && x <= boton->rect.x + boton->rect.w &&
        y >= boton->rect.y && y <= boton->rect.y + boton->rect.h);
}

void reproducirMusica(const char* ruta)
{
    Mix_Music* musica = Mix_LoadMUS(ruta);
    if (!musica)
    {
        fprintf(stderr, "Error al cargar la música '%s': %s\n", ruta, Mix_GetError());
        return;
    }

    if (Mix_PlayMusic(musica, 0) == -1)
    {
        fprintf(stderr, "Error al reproducir la música: %s\n", Mix_GetError());
        Mix_FreeMusic(musica);
        return;
    }
}
