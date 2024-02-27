#ifndef INPUT_H
#define INPUT_H

#define NUM_KEYS 15

typedef struct MOUSE_COORDS_s {
    int x;
    int y;
} MOUSE_COORDS;

typedef enum KEYS_e {NONE = -1, UP, DOWN, LEFT, RIGHT, LETRAE, LETRAF, NUM1, NUM2, NUM3, NUM4, NUM5, TAB, SPACE, F11, ESCAPE} KEYS;

int process_input(MOUSE_COORDS* mouse_coords);
void handle_key_down(SDL_Keycode key);
void handle_key_up(SDL_Keycode key);

#endif 
