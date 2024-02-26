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

bool keys[256] = { false };

void handle_key_down(SDL_Keycode key) {
    switch (key) {
    case SDLK_w:
        keys[UP] = true;
        break;
    case SDLK_s:
        keys[DOWN] = true;
        break;
    case SDLK_a:
        keys[LEFT] = true;
        break;
    case SDLK_d:
        keys[RIGHT] = true;
        break;
    case SDLK_e:
        keys[LETRAE] = true;
        break;
    case SDLK_f:
        keys[LETRAF] = true;
        break;
    case SDLK_1:
        keys[NUM1] = true;
        break;
    case SDLK_2:
        keys[NUM2] = true;
        break;
    case SDLK_3:
        keys[NUM3] = true;
        break;
    case SDLK_4:
        keys[NUM4] = true;
        break;
    case SDLK_5:
        keys[NUM5] = true;
        break;
    case SDLK_TAB:
        keys[TAB] = true;
        break;
    case SDLK_SPACE:
        keys[SPACE] = true;
        break;
    case SDLK_F11:
        keys[F11] = true;
        break;
    case SDLK_ESCAPE:
        keys[ESCAPE] = true;
        break;
    default:
        break;
    }
}

void handle_key_up(SDL_Keycode key) {
    switch (key) {
    case SDLK_w:
        keys[UP] = false;
        break;
    case SDLK_s:
        keys[DOWN] = false;
        break;
    case SDLK_a:
        keys[LEFT] = false;
        break;
    case SDLK_d:
        keys[RIGHT] = false;
        break;
    case SDLK_e:
        keys[LETRAE] = false;
        break;
    case SDLK_f:
        keys[LETRAF] = false;
        break;
    case SDLK_1:
        keys[NUM1] = false;
        break;
    case SDLK_2:
        keys[NUM2] = false;
        break;
    case SDLK_3:
        keys[NUM3] = false;
        break;
    case SDLK_4:
        keys[NUM4] = false;
        break;
    case SDLK_5:
        keys[NUM5] = false;
        break;
    case SDLK_TAB:
        keys[TAB] = false;
        break;
    case SDLK_SPACE:
        keys[SPACE] = false;
        break;
    case SDLK_F11:
        keys[F11] = false;
        break;
    case SDLK_ESCAPE:
        keys[ESCAPE] = false;
        break;
    default:
        break;
    }
}

int process_input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            handle_key_down(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            handle_key_up(event.key.keysym.sym);
            break;
        default:
            break;
        }
    }

    // Ahora verificamos el estado de las teclas presionadas
    if (keys[UP])
        return UP;
    else if (keys[DOWN])
        return DOWN;
    else if (keys[LEFT])
        return LEFT;
    else if (keys[RIGHT])
        return RIGHT;
    else if (keys[LETRAE])
        return LETRAE;
    else if (keys[LETRAF])
        return LETRAF;
    else if (keys[NUM1])
        return NUM1;
    else if (keys[NUM2])
        return NUM2;
    else if (keys[NUM3])
        return NUM3;
    else if (keys[NUM4])
        return NUM4;
    else if (keys[NUM5])
        return NUM5;
    else if (keys[TAB])
        return TAB;
    else if (keys[SPACE])
        return SPACE;
    else if (keys[F11])
        return F11;
    else if (keys[ESCAPE])
        return ESCAPE;

    return NONE;
}