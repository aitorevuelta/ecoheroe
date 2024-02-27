#ifndef RENDER_H
#define RENDER_H

SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);
void render_texture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height);
void render(SDL_Renderer* renderer, SETTINGS settings);

#endif 
