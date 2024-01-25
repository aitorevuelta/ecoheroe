#include <SDL.h>
#include <stdio.h>
#include "player.h"
#include "update.h"
#include "constants.h"
#include "collision.h"
#include "inventory.h"
#include "input.h"
#include "notification.h"
#include "map.h"
#include "enemies.h"


float camera_x;
float camera_y;
int last_frame_time = 0;
int lastValidDirection = 1;
int currentLevel = 1;

void update() {
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);

    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
        SDL_Delay(time_to_wait);
    }

    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0;
    last_frame_time = SDL_GetTicks();

    updateCharacterAnimation(&walle, delta_time);
    int speedMultipier = 5;
    if (attack) {
        speedMultipier = 2;
    }
    float speed = walle.height * speedMultipier * delta_time;

    int collision_up = is_collision(walle.x, walle.y - speed);
    int collision_down = is_collision(walle.x, walle.y + speed);
    int collision_left = is_collision(walle.x - speed, walle.y);
    int collision_right = is_collision(walle.x + speed, walle.y);


    if (UP && !collision_up && !show) {
        walle.y -= speed;
        walle.currentDirection = 1;
        lastValidDirection = walle.currentDirection;
    }
    else if (DOWN && !collision_down && !show) {
        walle.y += speed;
        walle.currentDirection = 2;
        lastValidDirection = walle.currentDirection;
    }
    else if (LEFT && !collision_left && !show) {
        walle.x -= speed;
        walle.currentDirection = 3;
        lastValidDirection = walle.currentDirection;
    }
    else if (RIGHT && !collision_right && !show) {
        walle.x += speed;
        walle.currentDirection = 4;
        lastValidDirection = walle.currentDirection;
    }
    else {
        if (walle.currentFrame != 0 && !attack)
        {
            walle.currentFrame = 0;
            walle.elapsedTime = 0.0f;
        }
    }
    if (walle.x < 0) {
        walle.x = 0;
    }
    if (walle.x > (mapWidth * TILE_SIZE - walle.width)) {
        walle.x = mapWidth * TILE_SIZE - walle.width;
    }
    if (walle.y < 0) {
        walle.y = 0;
    }
    if (walle.y > (mapHeight * TILE_SIZE - walle.height)) {
        walle.y = mapHeight * TILE_SIZE - walle.height;
    }
    camera_x = walle.x - (windowWidth / 2);
    camera_y = walle.y - (windowHeight / 2);
    if (camera_x < 0) {
        camera_x = 0;
    }
    if (camera_x > (mapWidth * TILE_SIZE - windowWidth)) {
        camera_x = mapWidth * TILE_SIZE - windowWidth;
    }
    if (camera_y < 0) {
        camera_y = 0;
    }
    if (camera_y > (mapHeight * TILE_SIZE - windowHeight)) {
        camera_y = mapHeight * TILE_SIZE - windowHeight;
    }

    updateEnemies(delta_time);

    use_inventory();
    if (dragged_item_index == -1 && playerInventory.slots[currentItemSlot].itemIndex != 0) {
        use_item(playerInventory.slots[currentItemSlot].itemIndex, currentItemSlot);
    }
}
float calculateDistance(int x1, int y1, int x2, int y2)
{
    float dx = x1 - x2;
    float dy = y1 - y2;
    float distance = sqrt(dx * dx + dy * dy);
    return distance;
}

void updateEnemies(float delta_time)
{
    for (size_t i = 0; i < 12; i++)
    {
        if (enemies[i].health > 0 && enemies[i].level == currentLevel)
        {
            float distance = calculateDistance(walle.x, walle.y, enemies[i].x, enemies[i].y);

            if (enemies[i].lastAttack <= 2)
            {
                enemies[i].lastAttack += 1 * delta_time;
            }

            if (distance <= 70)
            {
                if (enemies[i].lastAttack >= 2)
                {
                    health_value -= enemies[i].damage;
                    enemies[i].lastAttack = 0;
                }
            }

            if (enemies[i].range >= distance && distance >= 70)
            {
                float dx = walle.x - enemies[i].x;
                float dy = walle.y - enemies[i].y;

                if (dx > 0)
                {
                    if (!is_collision(enemies[i].x + (enemies[i].speed * delta_time), enemies[i].y))
                    {
                        enemies[i].x += (enemies[i].speed * delta_time);
                    }
                    else if (!is_collision(enemies[i].x - (enemies[i].speed * delta_time), enemies[i].y))
                    {
                        enemies[i].x -= (enemies[i].speed * delta_time);
                    }
                }
                else
                {
                    if (!is_collision(enemies[i].x - (enemies[i].speed * delta_time), enemies[i].y))
                    {
                        enemies[i].x -= (enemies[i].speed * delta_time);
                    }
                    else if (!is_collision(enemies[i].x + (enemies[i].speed * delta_time), enemies[i].y))
                    {
                        enemies[i].x += (enemies[i].speed * delta_time);
                    }
                }
                if (dy > 0)
                {
                    if (!is_collision(enemies[i].x, enemies[i].y + (enemies[i].speed * delta_time)))
                    {
                        enemies[i].y += (enemies[i].speed * delta_time);
                    }
                    else if (!is_collision(enemies[i].x, enemies[i].y - (enemies[i].speed * delta_time)))
                    {
                        enemies[i].y -= (enemies[i].speed * delta_time);
                    }
                }
                else
                {
                    if (!is_collision(enemies[i].x, enemies[i].y - (enemies[i].speed * delta_time)))
                    {
                        enemies[i].y -= (enemies[i].speed * delta_time);
                    }
                    else if (!is_collision(enemies[i].x, enemies[i].y + (enemies[i].speed * delta_time)))
                    {
                        enemies[i].y += (enemies[i].speed * delta_time);
                    }
                }
            }
        }
        }

}
