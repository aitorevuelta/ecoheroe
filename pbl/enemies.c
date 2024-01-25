#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "enemies.h"
#include "constants.h"
#include "update.h"
#include "texturemanager.h"

void renderEnemies(Enemies* enemies, SDL_Renderer* renderer) {
    for (int i = 0; i < 12; i++) {
        if (enemies[i].level == currentLevel && enemies[i].health > 0) {
            SDL_Rect enemyRect = {
                round(enemies[i].x - camera_x),
                round(enemies[i].y - camera_y),
                enemies[i].width,
                enemies[i].height
            };
            SDL_RenderCopy(renderer, enemiesTextures[enemies[i].currentDirection - 1][enemies[i].currentFrame], NULL, &enemyRect);
            renderEnemiesHealthBar(enemies, renderer);
            renderEnemiesAttackBar(enemies, renderer);
        }
    }
}


Enemies enemies[] = {
    {1200, 400, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 10, 200, 2, 100, 2},

    {805, 1400, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 3, 100, 2},
    {94, 980, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 3, 100, 2},
    {286, 3341, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 3, 100, 2}, 
    {1493, 2432, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 3, 100, 2},
    {2294, 974, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 3, 100, 2},
    {2834, 1283, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 3, 100, 2},
    {3342, 2687, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 3, 100, 2},

    {1054, 132, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 4, 100, 2},
    {3152, 144, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 4, 100, 2},
    {3150, 1503, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 4, 100, 2}, 
    {1715, 2783, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 4, 100, 2},
    {379, 2051, 60, 80, 2, 1, 10, 0.1, 0.0, 400, 5, 200, 4, 100, 2},
};

void renderEnemiesHealthBar(Enemies* enemies, SDL_Renderer* renderer)
{
    for (int i = 0; i < 12; i++)
    {
        if (enemies[i].level == currentLevel && enemies[i].health != 100 && enemies[i].health > 0)
        {
            int bar_x = enemies[i].x - camera_x - 10;
            int bar_y = enemies[i].y - camera_y - 30;
            int bar_width = 70;
            int bar_height = 10;

            SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
            SDL_Rect bar_rect = { bar_x, bar_y, bar_width, bar_height };
            SDL_RenderFillRect(renderer, &bar_rect);

            int bar_fill_width = (int)((enemies[i].health / 100.0) * (bar_width));

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            SDL_Rect bar_fill_rect = { bar_x, bar_y, bar_fill_width, bar_height };
            SDL_RenderFillRect(renderer, &bar_fill_rect);
        }
    }
}

void renderEnemiesAttackBar(Enemies* enemies, SDL_Renderer* renderer)
{
    {
        for (int i = 0; i < 12; i++)
        {
            if (enemies[i].level == currentLevel && enemies[i].health > 0 && enemies[i].lastAttack <= 2)
            {
                int bar_x = enemies[i].x - camera_x + 10;
                int bar_y = enemies[i].y - camera_y - 10;
                int bar_width = 35;
                int bar_height = 7;

                SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
                SDL_Rect bar_rect = { bar_x, bar_y, bar_width, bar_height };
                SDL_RenderFillRect(renderer, &bar_rect);

                int bar_fill_width = (int)((enemies[i].lastAttack/2) * (bar_width));

                SDL_SetRenderDrawColor(renderer, 101, 177, 184, 255);
                SDL_Rect bar_fill_rect = { bar_x, bar_y, bar_fill_width, bar_height };
                SDL_RenderFillRect(renderer, &bar_fill_rect);
            }
        }
    }

}