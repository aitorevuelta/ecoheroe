#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>

#include "constants.h"
#include "initializer.h"
#include "map.h"
#include "render.h"
#include "update.h"
#include "input.h"
#include "texturemanager.h"
#include "ui.h"
#include "collision.h"
#include "levelmanager.h"
#include "inventory.h"
#include "player.h"
#include "funtzioak.h"



int game_is_running = FALSE;


void jokoa() {
    game_is_running = initialize_window();
    loadCharacterAnimations(renderer);
    loadEnemiesAnimations(renderer);
    load_ui_textures(renderer);
    load_object_textures(renderer);
    load_inventory_textures(renderer);
    setup();
    while (game_is_running) {
        process_input();
        update();
        render();
    }
    destroy_window();
}