#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_mixer.h"
#include "funtzioak.h"

int main(int argc, char* args[])
{
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error al inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Inicializar SDL_image
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        fprintf(stderr, "Error al inicializar SDL_image: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    int altuera;
    int zabalera;
    // Lehioa sortu
    SDL_Window* lehioa = SDL_CreateWindow("Menu",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_GetWindowSize(lehioa, &zabalera, &altuera);


    if (!lehioa)
    {
        fprintf(stderr, "Error al crear la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderizador;

    renderizador = SDL_CreateRenderer(lehioa, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Inicializar SDL Mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        fprintf(stderr, "Error al inicializar SDL Mixer: %s\n", Mix_GetError());
        SDL_DestroyRenderer(renderizador);
        SDL_DestroyWindow(lehioa);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    // Reproducir la música al inicio
    reproducirMusica("sonidos/musica.mp3");

    SDL_Texture* imagenfondo = IMG_LoadTexture(renderizador, "fotos/fondo.png");
    SDL_Texture* imagenlogo = IMG_LoadTexture(renderizador, "fotos/EcoHero.png");
    // Crear un botón y establecer su posición y tamaño
    Boton botoia;
    botoia.rect.w = zabalera * 0.2;
    botoia.rect.h = altuera * 0.2;
    botoia.rect.x = zabalera * 0.4;
    botoia.rect.y = altuera * 0.4;
    botoia.visible = 1;

    // Cargar textura de la imagen para el primer botón
    SDL_Texture* textura1 = IMG_LoadTexture(renderizador, "fotos/play.png");

    // Crear un segundo botón y establecer su posición y tamaño
    Boton KontrolenBotoia;
    KontrolenBotoia.rect.w = zabalera * 0.2;
    KontrolenBotoia.rect.h = altuera * 0.2;
    KontrolenBotoia.rect.x = zabalera * 0.16;
    KontrolenBotoia.rect.y = altuera * 0.65;
    KontrolenBotoia.visible = 1;

    // Cargar textura de la imagen para el nuevo botón
    SDL_Texture* textura2 = IMG_LoadTexture(renderizador, "fotos/kontrolak.png");

    // Crear un tercer botón y establecer su posición y tamaño
    Boton KredituenBotoia;
    KredituenBotoia.rect.w = zabalera * 0.2;
    KredituenBotoia.rect.h = altuera * 0.2;
    KredituenBotoia.rect.x = zabalera * 0.644;
    KredituenBotoia.rect.y = altuera * 0.65;
    KredituenBotoia.visible = 1;

    // Cargar textura de la imagen para el tercer botón
    SDL_Texture* textura3 = IMG_LoadTexture(renderizador, "fotos/kredituak.png");

    // Textura para cuando se le de al botón de kontrolak
    SDL_Texture* textura4 = IMG_LoadTexture(renderizador, "fotos/controls.png");

    // Textura para cuando se le de al botón de kredituak
    SDL_Texture* textura5 = IMG_LoadTexture(renderizador, "fotos/credits.png");

    // Crear un botón condicional y establecer su posición y tamaño
    Boton itzultzekoBotoia;
    itzultzekoBotoia.rect.w = zabalera * 0.05;
    itzultzekoBotoia.rect.h = altuera * 0.075;
    itzultzekoBotoia.rect.x = zabalera * 0.05;
    itzultzekoBotoia.rect.y = altuera * 0.05;
    itzultzekoBotoia.visible = 0; // Inicialmente no visible

    // Cargar textura de la imagen para el botón condicional fuera del bucle
    SDL_Texture* texturaItzultzekoBotoia = IMG_LoadTexture(renderizador, "fotos/volver.png");

    // Bucle principal
    int jokoa_martxan_dabil = 1;
    int pantalla_completa = 0;
    int kontrolenBotoiaClicked = 0;
    int kredituenBotoiaClicked = 0;
    int mostrarItzultzekoBotoia = 0; // Nueva variable para controlar la visibilidad del botón de volver

    while (jokoa_martxan_dabil)
    {
        SDL_Event ebentoa;
        while (SDL_PollEvent(&ebentoa))
        {
            switch (ebentoa.type)
            {
            case SDL_QUIT:
                jokoa_martxan_dabil = 0;
                break;
            case SDL_KEYDOWN:
                if (ebentoa.key.keysym.sym == SDLK_ESCAPE)
                    jokoa_martxan_dabil = 0;

                break;

            case SDL_MOUSEBUTTONDOWN:
                if (clicEnBoton(ebentoa.button.x, ebentoa.button.y, &botoia))
                {
                    if (botoia.visible && textura1 && textura2 && textura3)
                    {
                        // Establecer las texturas a NULL
                        SDL_DestroyTexture(textura1);
                        SDL_DestroyTexture(textura2);
                        SDL_DestroyTexture(textura3);
                        textura1 = NULL;
                        textura2 = NULL;
                        textura3 = NULL;
                        imagenfondo = NULL;
                        imagenlogo = NULL;
                        Mix_CloseAudio();
                        SDL_DestroyWindow(lehioa);
                        jokoa();
                        SDL_Quit();
                        return 0;
                    }
                }
                else if (clicEnBoton(ebentoa.button.x, ebentoa.button.y, &KredituenBotoia))
                {
                    if (botoia.visible && textura1 && textura2 && textura3)
                    {
                        // Establecer las texturas a NULL
                        SDL_DestroyTexture(textura1);
                        SDL_DestroyTexture(textura2);
                        SDL_DestroyTexture(textura3);
                        textura1 = NULL;
                        textura2 = NULL;
                        textura3 = NULL;
                        // Textura para cuando se le de al botón de kontrolak
                        textura5 = IMG_LoadTexture(renderizador, "fotos/credits.png");
                        kredituenBotoiaClicked = 1; // Marcar que se hizo clic en el botón de créditos
                        mostrarItzultzekoBotoia = 1; // Mostrar el botón de volver
                    }
                }
                else if (clicEnBoton(ebentoa.button.x, ebentoa.button.y, &KontrolenBotoia))
                {
                    if (botoia.visible && textura1 && textura2 && textura3)
                    {
                        // Establecer las texturas a NULL
                        SDL_DestroyTexture(textura1);
                        SDL_DestroyTexture(textura2);
                        SDL_DestroyTexture(textura3);
                        textura1 = NULL;
                        textura2 = NULL;
                        textura3 = NULL;
                        textura4 = IMG_LoadTexture(renderizador, "fotos/controls.png");
                        kontrolenBotoiaClicked = 1;
                        mostrarItzultzekoBotoia = 1; // Mostrar el botón de volver
                    }
                }
                else if (clicEnBoton(ebentoa.button.x, ebentoa.button.y, &itzultzekoBotoia))
                {
                    // Se hizo clic en el botón de volver
                    if (kontrolenBotoiaClicked || kredituenBotoiaClicked)
                    {
                        // Si venimos de KontrolenBotoia o KredituenBotoia, reiniciar las variables
                        kontrolenBotoiaClicked = 0;
                        kredituenBotoiaClicked = 0;
                    }
                    // Restablecer la visibilidad del botón de volver
                    mostrarItzultzekoBotoia = 0;

                    // Restablecer las texturas y la visibilidad de los botones iniciales
                    if (!textura1)
                    {
                        textura1 = IMG_LoadTexture(renderizador, "fotos/play.png");
                    }

                    if (!textura2)
                    {
                        textura2 = IMG_LoadTexture(renderizador, "fotos/kontrolak.png");
                    }

                    if (!textura3)
                    {
                        textura3 = IMG_LoadTexture(renderizador, "fotos/kredituak.png");
                    }

                    // Restablecer la visibilidad de los botones
                    botoia.visible = 1;
                    KontrolenBotoia.visible = 1;
                    KredituenBotoia.visible = 1;

                    // Restablecer la posición de los botones según sea necesario
                    // ...
                }
                break;
            }
        }

        // Dibujar la interfaz sin renderizar las texturas si son NULL
        lehioaMargotu(renderizador, 0, 0, 0, 0);

        // Renderizar la textura de fondo
        SDL_RenderCopy(renderizador, imagenfondo, NULL, NULL);

        // Calcular las coordenadas X e Y para el centro de la pantalla
        int centroX = (zabalera - 400) / 2;
        int centroY = altuera * 0.1;  // Ajusta el valor para la posición vertical


        // Renderizar la imagen del logo en la parte superior centrada de la pantalla
        SDL_RenderCopy(renderizador, imagenlogo, NULL, &(SDL_Rect){centroX, centroY, 400, 200});

        // Renderizar textura4 si KontrolenBotoia ha sido clicado
        if (kontrolenBotoiaClicked && textura4)
        {
            SDL_RenderCopy(renderizador, textura4, NULL, NULL);
            // Renderizar el botón condicional
            if (mostrarItzultzekoBotoia && texturaItzultzekoBotoia)
            {
                SDL_RenderCopy(renderizador, texturaItzultzekoBotoia, NULL, &(itzultzekoBotoia.rect));
            }
        }
        // Renderizar textura5 si KredituenBotoia ha sido clicado
        else if (kredituenBotoiaClicked && textura5)
        {
            SDL_RenderCopy(renderizador, textura5, NULL, NULL);
            // Renderizar el botón condicional
            if (mostrarItzultzekoBotoia && texturaItzultzekoBotoia)
            {
                SDL_RenderCopy(renderizador, texturaItzultzekoBotoia, NULL, &(itzultzekoBotoia.rect));
            }
        }
        else
        {
            // Renderizar botones si no se ha clicado KontrolenBotoia o KredituenBotoia
            if (textura1 && botoia.visible)
            {
                SDL_RenderCopy(renderizador, textura1, NULL, &(botoia.rect));
            }
            else if (botoia.visible)
            {
                jolastenHastekoBotoia(renderizador, &botoia);
            }

            if (textura2 && KontrolenBotoia.visible)
            {
                SDL_RenderCopy(renderizador, textura2, NULL, &(KontrolenBotoia.rect));
            }

            if (textura3 && KredituenBotoia.visible)
            {
                SDL_RenderCopy(renderizador, textura3, NULL, &(KredituenBotoia.rect));
            }

            // Renderizar el botón condicional
            if (mostrarItzultzekoBotoia && texturaItzultzekoBotoia)
            {
                SDL_RenderCopy(renderizador, texturaItzultzekoBotoia, NULL, &(itzultzekoBotoia.rect));
            }
        }

        SDL_RenderPresent(renderizador);
    }

    // Liberar recursos antes de salir
    if (textura1)
    {
        SDL_DestroyTexture(textura1);
    }

    if (textura2)
    {
        SDL_DestroyTexture(textura2);
    }

    if (textura3)
    {
        SDL_DestroyTexture(textura3);
    }

    if (textura4)
    {
        SDL_DestroyTexture(textura4);
    }

    if (textura5)
    {
        SDL_DestroyTexture(textura5);
    }

    // Cerrar SDL Mixer, ventana y SDL
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(lehioa);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
