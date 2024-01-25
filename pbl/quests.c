#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>

#include "constants.h"
#include "quests.h"
#include "player.h"
#include "enemies.h"
#include "update.h"
#include "main.h"
#include "render.h"
#include "notification.h"
#include "inventory.h"
#include "input.h"
#include "objects.h"
#include "ui.h"
#include "texturemanager.h"
#include "levelmanager.h"

int bunkerShadow = FALSE;
int contenedorError = FALSE;
int osoOndo = FALSE;

Quests quests[] = {
    { "BUNKERETIK IRTEN", 0, 0 },
    { "ZER DA HAU?", 1, 0},
    { "BIRZIKLATU", 2, 0 },
    { "ZUHAITZAK LANDATU", 3, 0 },
    { NULL, 4, 0 },
};

void quest_manager(Quests quests[])
{
    switch (walle.currentQuest)
    {
    case 0:
    {
        quest0();
        break;
    }
    case 1:
    {
        quest1();
        break;
    }
    case 2:
    {
        quest2();
        break;
    }
    case 3:
    {
        quest3();
        break;
    }
    }
    renderMissionProgress(quests);
}

void add_quest_progress(Quests quests[], int currentQuest, int progressQuantity)
{
    quests[currentQuest].progress += progressQuantity;
}

void renderMissionProgress(Quests quests[])
{
    int currentQuest = walle.currentQuest;
    int currentQuestProgressValue = quests[walle.currentQuest].progress;
    render_mission_text(quests, currentQuest);
    // Calcula la posici�n y dimensiones de la barra
    int bar_width = 235;
    int bar_height = 15;
    int bar_x = windowWidth - bar_width - 20;
    int bar_y = 80;

    // Dibuja el fondo de la barra (puedes ajustar el color)
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_Rect bar_rect = { bar_x, bar_y, bar_width, bar_height };
    SDL_RenderFillRect(renderer, &bar_rect);

    // Calcula la longitud de la barra seg�n un valor (0 a 100)
    int bar_fill_width = (int)((currentQuestProgressValue / 100.0) * (bar_width - 2)); // Resta 2 para el margen

    if (currentQuestProgressValue > 100)
    {
        currentQuestProgressValue = 100;
    }
    if (currentQuestProgressValue < 0)
    {
        currentQuestProgressValue = 0;
    }

    // Dibuja la parte llena de la barra (puedes ajustar el color)
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_Rect bar_fill_rect = { bar_x, bar_y, bar_fill_width, bar_height };
    SDL_RenderFillRect(renderer, &bar_fill_rect);
    render_texture(renderer, uiItems[7].texture, bar_x + bar_width / 2, bar_y + bar_height / 2, bar_width, bar_height);
}

void render_mission_text(Quests quests[], int currentMissionIndex)
{
    SDL_Color color = { 255, 255, 255 };
    char* text = quests[currentMissionIndex].questName;

    SDL_Surface* surface = TTF_RenderText_Solid(fontSmall, text, color);
    if (!surface)
    {
        fprintf(stderr, "Error al renderizar el texto: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture)
    {
        fprintf(stderr, "Error al crear la textura: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect destRect;
    destRect.w = surface->w;
    destRect.h = surface->h;
    destRect.x = windowWidth - destRect.w - 20;
    destRect.y = 50;

    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void quest0()
{
    if (bunkerShadow)
    {
        render_texture(renderer, uiItems[6].texture, walle.x - camera_x + 35, walle.y - camera_y + 50, 1920 * 2, 1080 * 2);
    }
    if (quests[0].progress == 0)
    {
        show_notification(0);
        if (!show)
        {
            add_quest_progress(quests, 0, 10);
        }
    }
    if (quests[0].progress == 10)
    {
        render_texture(renderer, gameItems[2].texture, 4630 - camera_x, 630 - camera_y - 50, 40, 40);
        if (calculateDistance(walle.x, walle.y, 4600, 660) <= 30)
        {
            render_texture(renderer, uiItems[4].texture, 4630 - camera_x, 660 - camera_y - 50, 40, 40);
            if (F)
            {
                add_quest_progress(quests, 0, 15);
                add_item(2, 1);
                levelInfo[10].IsClosed = FALSE;
                levelInfo[13].IsClosed = FALSE;
            }

        }
    }

    if (quests[0].progress == 25)
    {
        show_notification(3);
        if (!show)
        {
            add_quest_progress(quests, 0, 25);
        }
    }
    if (quests[0].progress == 50 && calculateDistance(walle.x, walle.y, 350, 1690) <= 30)
    {
        render_texture(renderer, uiItems[4].texture, 350 - camera_x, 1690 - camera_y - 50, 40, 40);
        if (F)
        {
            bunkerShadow = TRUE;
            add_quest_progress(quests, 0, 25);
        }
    }
    if (quests[0].progress == 75)
    {
        show_notification(6);
        if (!show)
        {
            add_quest_progress(quests, 0, 10);
        }
    }
    if (quests[0].progress == 85)
    {
        if (levelInfo[14].IsClosed)
            levelInfo[14].IsClosed = FALSE;
    }
    if (currentLevel == 2)
    {
        walle.currentQuest = 1;
        remove_item(2, 1);
    }
}

void quest1()
{
    if (quests[1].progress == 0)
    {
        show_notification(8);
        if (!show)
        {
            add_quest_progress(quests, 1, 10);
        }
    }
    if (quests[1].progress == 10)
    {
        if (calculateDistance(walle.x, walle.y, gameObjects[0].x + 30, gameObjects[0].y+10) <= 110)
        {
            render_texture(renderer, uiItems[4].texture, gameObjects[0].x + 40 - camera_x, gameObjects[0].y - camera_y - 50, 40, 40);
            if (F)
            {
                add_quest_progress(quests, 1, 15);
                gameObjects[0].texture = load_texture("cofreabierto.png", renderer);
                add_item(1, 1);
                add_item(3, 1);
                add_item(3, 1);
            }

        }
    }

    if (quests[1].progress == 25)
    {
        show_notification(10);
            if (!show)
            {
                add_quest_progress(quests, 1, 25);
            }
    }
    if (quests[1].progress == 50)
    {
        if (enemies[0].health <= 0)
        {
            add_quest_progress(quests, 1, 25);
        }
    }
    if (quests[1].progress == 75)
    {
        show_notification(14);
        if (!show)
        {
            add_quest_progress(quests, 1, 10);
            levelInfo[15].IsClosed = FALSE;
        }
    }
    if (currentLevel == 3)
    {
        walle.currentQuest = 2;
    }
}


void quest2()
{
    if (quests[2].progress == 0)
    {
        show_notification(15);
        if (!show)
        {
            add_quest_progress(quests, 2, 5);
        }
    }
    if (5 <= quests[2].progress && quests[2].progress < 95)
    {
        int i = 98;
        int barruan = FALSE;
        int basuraBarruan = FALSE;
        if (!show)
        {
        while (i <= 102 && !barruan) {
             if (calculateDistance(walle.x, walle.y, gameObjects[i].x + gameObjects[i].objectWidth/2, gameObjects[i].y + gameObjects[i].objectHeight / 3) <= 120)
            {
                barruan = TRUE;
            }
            i++;
        }
        if (barruan) {
            i -= 1;
            render_texture(renderer, uiItems[4].texture, gameObjects[i].x - camera_x + 50, gameObjects[i].y - camera_y - 50, 40, 40);
            if (F) {
                if (gameObjects[i].name == "contenedorverde") {
                    if (has_item(6))
                    {
                        remove_item(6, 1);
                        osoOndo = TRUE;
                        add_quest_progress(quests, 2, 3);
                    }
                    else
                    {
                        contenedorError = TRUE;
                    }

                }
                if (gameObjects[i].name == "contenedormarron")
                {
                    if (has_item(7))
                    {
                        remove_item(7, 1);
                        osoOndo = TRUE;
                        add_quest_progress(quests, 2, 3);
                    }
                    else
                    {
                        contenedorError = TRUE;
                    }

                }
                if (gameObjects[i].name == "contenedoramarillo")
                {
                    if (has_item(5))
                    {
                        remove_item(5, 1);
                        osoOndo = TRUE;
                        add_quest_progress(quests, 2, 3);
                    }
                    else
                    {
                        contenedorError = TRUE;
                    }

                }
                if (gameObjects[i].name == "contenedorazul")
                {
                    if (has_item(4))
                    {
                        remove_item(4, 1);
                        osoOndo = TRUE;
                        add_quest_progress(quests, 2, 3);
                    }
                    else
                    {
                        contenedorError = TRUE;
                    }
                }

                if (gameObjects[i].name == "contenedorgris")
                {
                    if (has_item(8))
                    {
                        remove_item(8, 1);
                        osoOndo = TRUE;
                        add_quest_progress(quests, 2, 3);
                    }
                    else
                    {
                        contenedorError = TRUE;
                    }
                }
            }
        }
        int j = 103;
        while (gameObjects[j].name != NULL && !basuraBarruan)
        {
            if (!gameObjects[j].isInvisible)
            {
                if (calculateDistance(walle.x, walle.y, gameObjects[j].x + gameObjects[j].objectWidth / 2, gameObjects[j].y + gameObjects[j].objectHeight / 3) <= 120)
                {
                    basuraBarruan = TRUE;
                }
            }
            j++;
        }
        if (basuraBarruan)
        {
            j -= 1;
            render_texture(renderer, uiItems[4].texture, gameObjects[j].x - camera_x + 25, gameObjects[j].y - camera_y - 50, 40, 40);
            if (F)
            {
                if (gameObjects[j].name == "papera")
                {
                    add_item(4, 1);
                }
                else if (gameObjects[j].name == "plastikoa")
                {
                    add_item(5, 1);
                }
                else if (gameObjects[j].name == "beira")
                {
                    add_item(6, 1);
                }
                else if (gameObjects[j].name == "organikoa")
                {
                    add_item(7, 1);
                }
                else if (gameObjects[j].name == "errefuxa")
                {
                    add_item(8, 1);
                }
                if (!inventory_full) {
                    gameObjects[j].isInvisible = TRUE;
                    gameObjects[j].hasCollision = FALSE;
                }
            }
        }
        }
    }
    if (quests[2].progress == 95)
    {
        show_notification(21);
        if (!show)
        {
            add_quest_progress(quests, 2, 5);
            levelInfo[16].IsClosed = FALSE;
        }
    }
    if (currentLevel == 4)
    {
        walle.currentQuest = 3;
    }
}

void quest3()
{
    if (quests[3].progress == 0)
    {
        show_notification(15);
        if (!show)
        {
            add_quest_progress(quests, 3, 10);
        }
    }
    if (quests[3].progress >= 10 && quests[3].progress < 40)
    {
        int i = 213;
        int barruan = FALSE;
        int basuraBarruan = FALSE;
        if (!show)
        {
            while (i <= 217 && !barruan) {
                if (calculateDistance(walle.x, walle.y, gameObjects[i].x + gameObjects[i].objectWidth / 2, gameObjects[i].y + gameObjects[i].objectHeight / 3) <= 120)
                {
                    barruan = TRUE;
                }
                i++;
            }
            if (barruan) {
                i -= 1;
                render_texture(renderer, uiItems[4].texture, gameObjects[i].x - camera_x + 50, gameObjects[i].y - camera_y - 50, 40, 40);
                if (F) {
                    if (gameObjects[i].name == "contenedorverde") {
                        if (has_item(6))
                        {
                            remove_item(6, 1);
                            osoOndo = TRUE;
                            add_quest_progress(quests, 3, 3);
                        }
                        else
                        {
                            contenedorError = TRUE;
                        }

                    }
                    if (gameObjects[i].name == "contenedormarron")
                    {
                        if (has_item(7))
                        {
                            remove_item(7, 1);
                            osoOndo = TRUE;
                            add_quest_progress(quests, 3, 3);
                        }
                        else
                        {
                            contenedorError = TRUE;
                        }

                    }
                    if (gameObjects[i].name == "contenedoramarillo")
                    {
                        if (has_item(5))
                        {
                            remove_item(5, 1);
                            osoOndo = TRUE;
                            add_quest_progress(quests, 3, 3);
                        }
                        else
                        {
                            contenedorError = TRUE;
                        }

                    }
                    if (gameObjects[i].name == "contenedorazul")
                    {
                        if (has_item(4))
                        {
                            remove_item(4, 1);
                            osoOndo = TRUE;
                            add_quest_progress(quests, 3, 3);
                        }
                        else
                        {
                            contenedorError = TRUE;
                        }
                    }

                    if (gameObjects[i].name == "contenedorgris")
                    {
                        if (has_item(8))
                        {
                            remove_item(8, 1);
                            osoOndo = TRUE;
                            add_quest_progress(quests, 3, 3);
                        }
                        else
                        {
                            contenedorError = TRUE;
                        }
                    }
                }
            }
            int j = 218;
            while (gameObjects[j].name != NULL && !basuraBarruan)
            {
                if (!gameObjects[j].isInvisible)
                {
                    if (calculateDistance(walle.x, walle.y, gameObjects[j].x + gameObjects[j].objectWidth / 2, gameObjects[j].y + gameObjects[j].objectHeight / 3) <= 120)
                    {
                        basuraBarruan = TRUE;
                    }
                }
                j++;
            }
            if (basuraBarruan)
            {
                j -= 1;
                render_texture(renderer, uiItems[4].texture, gameObjects[j].x - camera_x + 25, gameObjects[j].y - camera_y - 50, 40, 40);
                if (F)
                {
                    if (gameObjects[j].name == "papera")
                    {
                        add_item(4, 1);
                    }
                    else if (gameObjects[j].name == "plastikoa")
                    {
                        add_item(5, 1);
                    }
                    else if (gameObjects[j].name == "beira")
                    {
                        add_item(6, 1);
                    }
                    else if (gameObjects[j].name == "organikoa")
                    {
                        add_item(7, 1);
                    }
                    else if (gameObjects[j].name == "errefuxa")
                    {
                        add_item(8, 1);
                    }
                    if (!inventory_full) {
                        gameObjects[j].isInvisible = TRUE;
                        gameObjects[j].hasCollision = FALSE;
                    }
                }
            }
        }
    }
    if (quests[3].progress == 40) {
        show_notification(22);
        if (!show){
            add_quest_progress(quests, 3, 5);
           
        }
    }
    if (quests[3].progress == 45) {
        if (calculateDistance(walle.x, walle.y, gameObjects[0].x + 30, gameObjects[0].y + 10) <= 110)
        {
            render_texture(renderer, uiItems[4].texture, gameObjects[0].x + 40 - camera_x, gameObjects[0].y - camera_y - 50, 40, 40);
            if (F)
            {
                add_quest_progress(quests, 3, 5);
                gameObjects[0].texture = load_texture("cofreabierto.png", renderer);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
                add_item(9, 1);
            }

        }
    }
    if (quests[3].progress >= 50)
    {
        int i = 200;
        int barruan = FALSE;

        while (i <= 212 && !barruan)
        {
            if (calculateDistance(walle.x, walle.y, gameObjects[i].x, gameObjects[i].y) <= 80 && gameObjects[i].isInvisible == TRUE)
            {
                render_texture(renderer, uiItems[4].texture, gameObjects[i].x - camera_x + 25, gameObjects[i].y - camera_y - 50, 40, 40);
                barruan = TRUE;
            }
            i++;
        }

        i -= 1;

        if (barruan)
        {
            if (F)
                if (has_item(9))
                {
                    gameObjects[i].isInvisible = FALSE;
                    add_quest_progress(quests, 3, 4);
                    remove_item(9, 1);
                    osoOndo = TRUE;
                }
                else
                {
                    contenedorError = TRUE;
                }
            }
        }
    if (quests[3].progress >= 98) {
        show_notification(25);
        if (!show) {
            game_is_running = FALSE;
        }
    }
}