// texturemanager.h
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <SDL_image.h>  // Aseg�rate de incluir la biblioteca SDL_image

extern SDL_Texture* characterTextures[4][11];
extern SDL_Texture* enemiesTextures[4][11];

SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);
extern void load_inventory_textures(SDL_Renderer* renderer);
extern void load_object_textures(SDL_Renderer* renderer);
extern void load_ui_textures(SDL_Renderer* renderer);
extern void loadCharacterAnimations(SDL_Renderer* renderer);
extern void loadEnemiesAnimations(SDL_Renderer* renderer);
extern void destroy_object_textures();

#endif // TEXTUREMANAGER_H
