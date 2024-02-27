#ifndef MENU_H
#define MENU_H

#define NUM_TEXTURES 6

typedef struct MENU_ITEMS_S {
    char image_path[32];
    SDL_Texture* texture;
} MENU_ITEMS;

typedef enum MENU_TEXTURES_e {BACKGROUND, CONTROLS_B, CREDITS_B, PLAY_B, RETURN_B, CONTROLS, CREDITS } MENU_TEXTURES;

void init_menu_textures(SDL_Renderer* renderer);
void render_menu(SDL_Renderer* renderer, SETTINGS settings);

#endif