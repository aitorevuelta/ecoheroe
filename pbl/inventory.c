#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "inventory.h"
#include "input.h"
#include "ui.h"
#include "player.h"
#include "constants.h"
#include "texturemanager.h"
#include "render.h"
#include "notification.h"


SDL_Point start_drag_position;
SDL_Rect dragged_item_rect;
SDL_Rect original_inventory_slot_rect;
int dragged_item_index = -1;
int inventorySlotSize = 80;
int inventorySpacing = 12;
int inventoryX;
int inventoryY;
int using_item;
int large_inventory_open = FALSE;
int currentItemSlot;
int currentItemIndex;
int inventory_full;

PlayerInventory playerInventory;

Item gameItems[] = {
    { NULL, NULL, NULL, NULL},
    {"sword", FALSE, "sword.png", NULL},
    {"key", FALSE, "key.png", NULL},
    {"medkit", TRUE, "medkit.png", NULL},
    {"papera", FALSE, "papera.png", NULL},
    {"plastiko", FALSE, "plastikoa.png", NULL},
    {"beira", FALSE, "beira.png", NULL},
    {"organikoa", FALSE, "organikoa.png", NULL},
    {"errefuxa", FALSE, "errefuxa.png", NULL},
    {"seed", FALSE, "seed.png", NULL},
    { NULL, NULL, NULL, NULL},
};

void render_inventory()
{
    if (!show)
    {
    int numSlots = large_inventory_open ? 15 : 5;
    int offsetY = large_inventory_open ? 2 * inventorySlotSize + 2 * inventorySpacing : 0;

    inventoryX = (windowWidth - (5 * (inventorySlotSize + inventorySpacing))) / 2;
    inventoryY = windowHeight - inventorySlotSize - 20 - offsetY;
    size_t numGameItems = sizeof(gameItems) / sizeof(gameItems[0]);
    for (int i = 0; i < numSlots; i++)
    {
        SDL_Rect inventorySlotRect = {
            inventoryX + (i % 5) * (inventorySlotSize + inventorySpacing),
            inventoryY + (i / 5) * (inventorySlotSize + inventorySpacing),
            inventorySlotSize,
            inventorySlotSize
        };
        if (dragged_item_index == -1)
        {
            original_inventory_slot_rect = inventorySlotRect;
        }
        if (playerInventory.slots[i].isSelected && dragged_item_index != i)
        {
            SDL_SetRenderDrawColor(renderer, 216, 162, 40, 250);
            if (playerInventory.slots[i].itemIndex >= 0 && playerInventory.slots[i].itemIndex < sizeof(gameItems) / sizeof(gameItems[0]) && gameItems[playerInventory.slots[i].itemIndex].usable)
            {
                render_texture(renderer, uiItems[0].texture, windowWidth / 2 - 5, inventoryY - 45, 45, 45);
            }
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 181, 121, 87, 255);
        }
        SDL_RenderFillRect(renderer, &inventorySlotRect);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &inventorySlotRect);

        render_texture(renderer, uiItems[5].texture, inventorySlotRect.x + 40, inventorySlotRect.y + 40, inventorySlotRect.w + 15, inventorySlotRect.h + 15);

        if (playerInventory.slots[i].quantity > 0)
        {
            int itemIndex = playerInventory.slots[i].itemIndex;
            if (itemIndex >= 0 && itemIndex < sizeof(gameItems) / sizeof(gameItems[0]))
            {
                SDL_Texture* itemTexture = gameItems[itemIndex].texture;
                if (itemTexture && dragged_item_index != i)
                {
                    SDL_RenderCopy(renderer, itemTexture, NULL, &inventorySlotRect);
                }
            }
        }
        else
        {
            playerInventory.slots[i].itemIndex = 0;
            playerInventory.slots[i].isSelected = FALSE;
        }
    }
    }
}

void handle_drag_and_drop(SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_MOUSEBUTTONDOWN:
        if (event->button.button == SDL_BUTTON_LEFT)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (has_item(1)) {
                attack = TRUE;
            }

            for (int i = 0; i < 15; i++)
            { 
                SDL_Rect inventorySlotRect = {
                    inventoryX + (i % 5) * (inventorySlotSize + inventorySpacing),
                    inventoryY + (i / 5) * (inventorySlotSize + inventorySpacing),
                    inventorySlotSize,
                    inventorySlotSize
                };

                if (mouseX >= inventorySlotRect.x && mouseX <= inventorySlotRect.x + inventorySlotRect.w &&
                    mouseY >= inventorySlotRect.y && mouseY <= inventorySlotRect.y + inventorySlotRect.h &&
                    playerInventory.slots[i].quantity > 0)
                {
                    start_drag_position.x = mouseX;
                    start_drag_position.y = mouseY;
                    dragged_item_index = i;
                    dragged_item_rect = inventorySlotRect;
                    playerInventory.slots[i].isSelected = FALSE;


                    if (playerInventory.slots[i].texture == NULL && playerInventory.slots[i].itemIndex != 0)
                    {
                        const char* imagePath = gameItems[playerInventory.slots[i].itemIndex].imagePath;
                        playerInventory.slots[i].texture = load_texture(imagePath, renderer);
                        if (!playerInventory.slots[i].texture)
                        {
                            fprintf(stderr, "Error al cargar la textura del objeto %s: %s\n", gameItems[playerInventory.slots[i].itemIndex].name, IMG_GetError());
                        }
                    }

                    attack = FALSE;
                    break;
                }
            }
        }
        break;

    case SDL_MOUSEMOTION:
        if (dragged_item_index != -1) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            dragged_item_rect.x = mouseX - (dragged_item_rect.w / 2);
            dragged_item_rect.y = mouseY - (dragged_item_rect.h / 2);

            start_drag_position.x = mouseX;
            start_drag_position.y = mouseY;
        }
        break;

    case SDL_MOUSEBUTTONUP:
        if (event->button.button == SDL_BUTTON_LEFT && dragged_item_index != -1) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            int slots = large_inventory_open ? 15 : 5;

            for (int i = 0; i < slots; i++) {  
                SDL_Rect inventorySlotRect = {
                    inventoryX + (i % 5) * (inventorySlotSize + inventorySpacing),
                    inventoryY + (i / 5) * (inventorySlotSize + inventorySpacing),
                    inventorySlotSize,
                    inventorySlotSize
                };

                if (mouseX >= inventorySlotRect.x && mouseX <= inventorySlotRect.x + inventorySlotRect.w &&
                    mouseY >= inventorySlotRect.y && mouseY <= inventorySlotRect.y + inventorySlotRect.h) {
  
                    InventorySlot temp = playerInventory.slots[i];
                    playerInventory.slots[i] = playerInventory.slots[dragged_item_index];
                    playerInventory.slots[dragged_item_index] = temp;

          
                    if (playerInventory.slots[i].texture == NULL && playerInventory.slots[i].itemIndex != 0) {
                        const char* imagePath = gameItems[playerInventory.slots[i].itemIndex].imagePath;
                        playerInventory.slots[i].texture = load_texture(imagePath, renderer);
                        if (!playerInventory.slots[i].texture) {
                            fprintf(stderr, "Error al cargar la textura del objeto %s: %s\n", gameItems[playerInventory.slots[i].itemIndex].name, IMG_GetError());
                        }
                    }

                    break;
                }
            }

            dragged_item_index = -1;  
        }
        break;
    }
}

void use_inventory() {
    static int use_inventory_counters[5] = { 0 };  
    static int tab_counter = 0; 
    static const int use_inventory_delay = 300;
    static const int tab_delay = 300;  

    int num_keys[] = { NUM1, NUM2, NUM3, NUM4, NUM5 };  


    tab_counter += FRAME_TARGET_TIME;  

    if (tab_counter >= tab_delay && TAB && !show) {
        large_inventory_open = !large_inventory_open;
        tab_counter = 0;  

  
        if (large_inventory_open) {
            for (int i = 0; i < 5; ++i) {
                playerInventory.slots[i].isSelected = FALSE;
            }
        }
    }


    for (int i = 0; i < 5; ++i) {
        use_inventory_counters[i] += FRAME_TARGET_TIME; 

        if (use_inventory_counters[i] >= use_inventory_delay) {
            if (num_keys[i] && playerInventory.slots[i].itemIndex != 0 && !large_inventory_open) {

                int toggleSelection = (playerInventory.slots[i].isSelected && num_keys[i]);

    
                for (int j = 0; j < 5; ++j) {
                    playerInventory.slots[j].isSelected = FALSE;
                }

                if (!toggleSelection) {
                    currentItemSlot = i;
                    currentItemIndex = playerInventory.slots[i].itemIndex;
                    playerInventory.slots[i].isSelected = TRUE;
                }
                use_inventory_counters[i] = 0;
            }
        }
    }
}

void use_item(int itemindex, int slot)
{
    if (LETRAE) {
        switch (itemindex) {
        case 3:
            health_value += 50;
            playerInventory.slots[slot].itemIndex = 0;
            playerInventory.slots[slot].quantity = 0;
            break;
        }
    }
}

void add_item(int index, int quantity) {
    int i = 0;
    int out = FALSE;
    while (i < 15 && !out) {
        if (playerInventory.slots[i].itemIndex == 0) {
            out = TRUE;
        }
        else {
            i++;
        }
    }
    if (out) {
        playerInventory.slots[i].itemIndex = index;
        playerInventory.slots[i].quantity = quantity;
    }
    else {
        inventory_full = TRUE;
    }
}

void remove_item(int index, int quantity)
{
    int i = 0;
    int out = FALSE;
    while (i < 15 && !out)
    {
        if (playerInventory.slots[i].itemIndex == index)
        {
            out = TRUE;
        }
        else
        {
            i++;
        }
    }
    if (out)
    {
        playerInventory.slots[i].itemIndex = 0;
        playerInventory.slots[i].quantity = 0;
    }
    else
    {
        printf("No tienes este objeto");
    }
}

int has_item(int index)
{
    int i = 0;
    int out = FALSE;
    while (i <= 15 && !out) 
    {
        if (playerInventory.slots[i].itemIndex == index)
        {
            out = TRUE;
        }
        i++; 
    }
    return out;
}
