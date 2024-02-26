#ifndef GLOBALS_H
#define GLOBALS_H

typedef struct SDL_s
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
	TTF_Font* font_small;
} SDL;

typedef struct SETTINGS_S
{
	int window_width;
	int window_height;
	float volume;
	int fullscreen;
	int fps;
} SETTINGS;

#endif 

