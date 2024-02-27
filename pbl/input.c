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

bool keys[NUM_KEYS] = { false };

void handle_key_down(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_w: keys[UP] = true; break;
    case SDLK_s: keys[DOWN] = true; break;
    case SDLK_a: keys[LEFT] = true; break;
    case SDLK_d: keys[RIGHT] = true; break;
    case SDLK_e: keys[LETRAE] = true; break;
    case SDLK_f: keys[LETRAF] = true; break;
    case SDLK_1: keys[NUM1] = true; break;
    case SDLK_2: keys[NUM2] = true; break;
    case SDLK_3: keys[NUM3] = true; break;
    case SDLK_4: keys[NUM4] = true; break;
    case SDLK_5: keys[NUM5] = true; break;
    case SDLK_TAB: keys[TAB] = true; break;
    case SDLK_SPACE: keys[SPACE] = true; break;
    case SDLK_F11: keys[F11] = true; break;
    case SDLK_ESCAPE: keys[ESCAPE] = true; break;
    default: break;
    }
}

void handle_key_up(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_w: keys[UP] = false; break;
    case SDLK_s: keys[DOWN] = false; break;
    case SDLK_a: keys[LEFT] = false; break;
    case SDLK_d: keys[RIGHT] = false; break;
    case SDLK_e: keys[LETRAE] = false; break;
    case SDLK_f: keys[LETRAF] = false; break;
    case SDLK_1: keys[NUM1] = false; break;
    case SDLK_2: keys[NUM2] = false; break;
    case SDLK_3: keys[NUM3] = false; break;
    case SDLK_4: keys[NUM4] = false; break;
    case SDLK_5: keys[NUM5] = false; break;
    case SDLK_TAB: keys[TAB] = false; break;
    case SDLK_SPACE: keys[SPACE] = false; break;
    case SDLK_F11: keys[F11] = false; break;
    case SDLK_ESCAPE: keys[ESCAPE] = false; break;
    default: break;
    }
}

int process_input(MOUSE_COORDS* mouse_coords)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN: handle_key_down(event.key.keysym.sym); break;
        case SDL_KEYUP: handle_key_up(event.key.keysym.sym); break;
        case SDL_MOUSEMOTION:
            mouse_coords->x = event.motion.x;
            mouse_coords->y = event.motion.y;
            break;
        default: break;
        }
    }

    for (int i = UP; i <= ESCAPE; ++i)
    {
        if (keys[i]) return i;
    }

    return NONE;
}
