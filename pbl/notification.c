#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

#include "notification.h"
#include "constants.h"
#include "ui.h"
#include "render.h"
#include "string.h"

messages GameMessages[] = {
   { 1, "Bunker batean zaude eta alde egin behar duzu", 3},
   { 2, "Itzaili argia segurtasun sistema desaktibatzeko", 3},
   { 3, "Bilatu bunkerreko diferentziala.", 3},
   { 4, "Elektrizitate-gelako giltza aurkitu duzu", 5},
   { 5, "Aurkitu elektrizitate gela eta moztu elektrizitatea", 5},
   { 6, "Atea itxita", 6},
   { 7, "Elektrizitatea moztuta", 8},
   { 8, "Segurtasun sistemak deskonektatuta daude", 8},
   { 9, "Bunkerra utzi duzu", 10},
   { 10, "Gora begiratzen duzunean kutxa bat aurkitzen duzu", 10},
   { 11, "Ezpata bat jaso duzu", 14},
   { 12, "Egin klick ezkerro klickarekin", 14},
   { 13, "Eskuinean etsai bat dago", 14},
   { 14, "Eliminatu", 14},
   { 15, "Etsaia eliminatu duzu. Jarraitu eskuinerantz", 15},
   { 16, "Dena zaborrez beteta dago", 18},
   { 17, "Ezin dut horrela utzi", 18},
   { 18, "Zabor guztia birziklatu beharko dut", 18},
   { 19, "Oso ondo, jarraitu  horrela", 19},
   { 20, "Ez daukazu beharrezko objektua", 20},
   { 21, "Ederki! Jarraitu goiko errepidea", 21},
   { 22, "Inbentarioa beteteta", 22},
   { 23, "Kutxa bat dago zure gainean", 24},
   { 24, "Joan begiratzera zer dagoen", 24},
   { 25, "Haziak jaso dituzu. Joan landatzera", 25},
   { 26, "Zorionak! Mundua salbatu duzu", 26},
};

int currentMessageIndex;
int show = FALSE;

void show_notification(int num)
{
    static Uint32 lastSpacePressTime = 0;
    static int initialized = FALSE;
    static int numparam;
    if (!initialized)
    {
        currentMessageIndex = num;
        initialized = TRUE;
        numparam = num;
        show = TRUE;
    }
    if (SPACE) {
        Uint32 currentTime = SDL_GetTicks();
        if (currentTime - lastSpacePressTime > 500) {
            lastSpacePressTime = currentTime;

            if (GameMessages[currentMessageIndex].till == GameMessages[currentMessageIndex].num) {
                show = FALSE;
                currentMessageIndex = 0;
                initialized = FALSE;
            }
            else {
                currentMessageIndex++;
            }
        }
    }
    if (show) {
        int x = windowWidth / 2;
        int y = windowHeight - 120;
        int boxwidth = 530;
        int boxheight = 240;
        SDL_Color color = { 0, 0, 0 }; 
        char* text = GameMessages[currentMessageIndex].message;


        SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
        if (!surface) {
            fprintf(stderr, "Error al renderizar el texto: %s\n", TTF_GetError());
            return;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (!texture) {
            fprintf(stderr, "Error al crear la textura: %s\n", SDL_GetError());
            SDL_FreeSurface(surface);
            return;
        }

        render_texture(renderer, uiItems[3].texture, x, y, boxwidth, boxheight);

        int textWidth = surface->w;
        int textHeight = surface->h;

        int lineHeight = 0;
        int i = 0;
        while (i < strlen(text)) {
            int characters = 0;
            char lineMessage[21]; // 20 characters + '\0'
            while (characters < 20 && text[i] != '\0') {
                lineMessage[characters] = text[i];
                characters++;
                i++;
            }
            lineMessage[characters] = '\0'; // Null-terminate the string

            SDL_Surface* lineSurface = TTF_RenderText_Solid(font, lineMessage, color);
            SDL_Texture* lineTexture = SDL_CreateTextureFromSurface(renderer, lineSurface);

            // Calcular posici�n de la l�nea
            SDL_Rect destRect = { x - 160, y - 50 + lineHeight, lineSurface->w, lineSurface->h };
            SDL_RenderCopy(renderer, lineTexture, NULL, &destRect);

            // Liberar recursos de la l�nea
            SDL_FreeSurface(lineSurface);
            SDL_DestroyTexture(lineTexture);

            // Mover a la siguiente l�nea
            lineHeight += textHeight;
        }

        // Liberar recursos del texto original
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}