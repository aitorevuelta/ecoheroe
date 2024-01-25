﻿#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "map.h"
#include "constants.h"
#include "texturemanager.h"

TextureInfo gameTextures[] = {
    {0, "grass2.png", NULL},
    {1, "water.png", NULL},
    {2, "topleft.png", NULL},
    {3, "bottomleft.png", NULL},
    {4, "topright.png", NULL},
    {5, "suelo.png", NULL},
    {6, "negro.png", NULL},
    {7, "bunkerwall.png" , NULL},
    {8, "bunkerwall2.png", NULL},
    {9, "paredbano.png", NULL},
    {10,"paredbano2.png", NULL},
    {11, "paredbano3.png", NULL},
    {12, "paredbano4.png", NULL},
    {13, "paredbano5.png", NULL},
    {14, "suelobano.png", NULL},
    {15, "paredbano6.png", NULL},
    {16, "paredbano7.png", NULL},
    {17, "bunkerwall.png", NULL},
    {18, "bunkerwall2.png", NULL},
    {19, "bunkerwall3.png", NULL},
    {20, "bunkerwall4.png", NULL},
    {21, "bunkerwall5.png", NULL},
    {22, "bunkerwall6.png", NULL},
    {23, "bunkerwall7.png", NULL},
    {24, "bunkerwall8.png", NULL},
    {25, "bunkerwall9.png", NULL},
    {26, "bunkerwall10.png", NULL},
    {27, "bunkerwall11.png", NULL},
    {28, "bunkerwall12.png", NULL},
    {29, "camino.png", NULL},
    {30, "camino0.png", NULL},
    {31, "camino1.png", NULL},
    {32, "camino2.png", NULL},
    {33, "camino3.png", NULL},
    {34, "camino4.png", NULL},
    {35, "camino5.png", NULL},
    {36, "camino6.png", NULL},
    {37, "camino7.png", NULL},
    {38, "camino8.png", NULL},
    {39, "camino9.png", NULL},
    {40, "camino10.png", NULL},
    {41, "camino11.png", NULL},
    {42, "camino12.png", NULL},
    {43, "camino13.png", NULL},
    {44, "camino14.png", NULL},
    {45, "camino15.png", NULL},
    {46, "camino16.png", NULL},
    {47, "arboles2.png", NULL},
    {48, "arboles3.png", NULL},
    {49, "arboles4.png", NULL},
    {50, "arboles5.png", NULL},
    {51, "grass", NULL},
    {52, "agujero1.png", NULL},
    {53, "agua1.jpg", NULL},
    {54, "bordeagua1.png", NULL},
    {55, "bordeagua2.png", NULL},
    {56, "bottomleft1.png", NULL},
    {57, "bottomright1.png", NULL},
    {58, "topleft1.png", NULL},
    {59, "topright1.png", NULL},
    {60, "topwater.png", NULL},
    {61, "bottomwater.png", NULL},
    {62, "carretera0.png", NULL},
    {63, "carretera1.png", NULL},
    {64, "carretera2.png", NULL},
    {65, "carretera3.png", NULL},
    {66, "carretera4.png", NULL},
    {67, "carretera5.png", NULL},
    {68, "carretera6.png", NULL},
    {69, "carretera7.png", NULL},
    {70, "carretera8.png", NULL},
    {71, "carretera9.png", NULL},
    {72, "carretera10.png", NULL},
    {73, "carretera11.png", NULL},
    {74, "carretera12.png", NULL},
    {75, "carretera13.png", NULL},
    {76, "carretera14.png", NULL},
    {77, "carretera15.png", NULL},
    {78, "puente1.png", NULL},
    {79, "puente2.png", NULL},
    {80, "puente3.png", NULL},
    {81, "puente4.png", NULL},
    {82, "grass3.png", NULL},
    {83, "water_berde.jpg", NULL},
    {84, "agua_arriba.png", NULL},
    {85, "agua_abajo.png", NULL},
    {86, "borde_izq.png", NULL},
    {87, "puentil.png", NULL},
    {88, "puentol.png", NULL},
    {89, "puenteagudo.png", NULL},
    {90, "puente_pokemon.png", NULL},
    {91, "camino_recto.png", NULL},
    {92, "suelo_andar.png", NULL},
    {93, "camino_hori.png", NULL},
    {94, "camino_raro.png", NULL},
    {95, "camino_raro_otro.png", NULL},
    {96, "camino_f.png", NULL},
    {97, "camino_l.png", NULL},
    {98, "camino_c.png", NULL},
    {99, "caminito.png", NULL},
    {100, "caminito_b.png", NULL},
    {101, "caminito_d.png", NULL},
    {102, "caminante.png", NULL},
    {103, "arena.png", NULL},
    {104, "asfalto.png", NULL},
    {105, "puente1.2.png", NULL},
    {106, "tierra.png", NULL},
    {107, "tierra_x.png", NULL},
    {108, "agua_abajo_curva.png", NULL},
    {109, "borde_izq_curva.png", NULL},
    {110, "puente_agua.png", NULL},
    {111, "borde_der_curva.png", NULL},
    {112, "borde_der_curva_arriba.png", NULL},
    {113, "agua_arriba_curva.png", NULL},
    {114, "borde_der.png", NULL },
};


int mapWidth = 45;
int mapHeight = 45;

int mapData1[] = {
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 23, 17, 17, 17, 17, 17, 17, 18, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 23, 17, 17, 17, 17, 17, 18, 6,  6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 20, 5, 5, 5, 5, 5, 5, 22, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 26, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 20, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 20, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 20, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 23, 17, 17, 17, 17, 17, 18, 6, 6, 6, 6,
    6, 21, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 20, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 20, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 20, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 26, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 26, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 20, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 20, 5, 5, 5, 22, 6, 6, 6, 6, 6, 6, 6, 21, 5, 5, 5, 5, 5, 28, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 20, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 25, 6, 18, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 26, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 23, 17, 17, 26, 5, 22, 17, 18, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 20, 5, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 28, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 20, 5, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 20, 5, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 20, 5, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 21, 5, 5, 5, 5, 5, 5, 28, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 16, 9, 9, 9, 10, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 14, 14, 14, 15, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 14, 14, 14, 14, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 13, 14, 14, 14, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 25, 6, 18, 6, 6, 6, 25, 6, 18, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 23, 26, 5, 22, 17, 17, 17, 26, 5, 22, 18, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 27, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 21, 5, 5, 5, 5, 5, 5, 5, 5, 5, 28, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 16, 9, 9, 9, 10, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 14, 14, 14, 15, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 12, 14, 14, 14, 14, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 13, 14, 14, 14, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
};

int mapData2[] = {
    49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49,
    47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 42, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43,
    0, 0, 29, 0, 0, 0, 46, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30,
    0, 0, 38, 31, 31, 31, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49,
    47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47,
};
int mapData3[] = {
      49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 0, 54, 53, 53, 55, 0, 49, 50, 49, 50, 49, 50, 49, 50, 49, 50, 49, 50,
    47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 0, 54, 53, 53, 55, 0, 47, 48, 47, 48, 47, 48, 47, 48, 47, 48, 47, 48,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54, 53, 53, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    31, 31, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54, 53, 53, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 29, 0, 0, 0, 0, 42, 43, 40, 0, 0, 0, 54, 53, 53, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 29, 0, 0, 0, 42, 30, 30, 30, 40, 0, 0, 54, 53, 53, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 32, 31, 31, 31, 30, 30, 30, 30, 30, 31, 31, 78, 79, 80, 81, 31, 31, 34, 31, 31, 34, 31, 31, 34, 35, 31, 34, 31,
    0, 0, 29, 0, 0, 0, 41, 30, 30, 30, 39, 0, 0, 54, 53, 53, 55, 0, 0, 73, 63, 63, 63, 63, 63, 63, 65, 63, 63, 63,
    0, 0, 29, 0, 58, 59, 0, 41, 30, 39, 0, 0, 0, 54, 53, 53, 55, 0, 0, 69, 74, 64, 64, 64, 64, 64, 65, 64, 64, 64,
    0, 0, 29, 0, 56, 57, 0, 0, 29, 0, 0, 0, 0, 54, 53, 53, 55, 0, 0, 69, 68, 0, 0, 0, 0, 0, 29, 0, 0, 0,
    0, 0, 29, 0, 0, 0, 52, 0, 29, 0, 0, 0, 0, 54, 53, 53, 55, 0, 0, 69, 68, 0, 0, 0, 0, 0, 29, 0, 0, 0,
    0, 0, 29, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 54, 53, 53, 55, 0, 0, 69, 68, 0, 0, 0, 0, 0, 29, 0, 0, 0,
    0, 0, 29, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 54, 53, 53, 55, 0, 0, 69, 68, 0, 0, 0, 0, 0, 29, 0, 0, 0,
    0, 0, 32, 31, 34, 31, 31, 31, 33, 0, 0, 0, 0, 54, 53, 53, 55, 66, 67, 62, 68, 0, 0, 0, 0, 0, 41, 31, 31, 40,
    0, 0, 29, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 54, 53, 53, 55, 66, 67, 62, 77, 63, 63, 63, 63, 63, 63, 63, 63, 65,
    0, 0, 29, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 54, 53, 53, 55, 66, 67, 62, 76, 64, 64, 64, 64, 64, 64, 71, 72, 65,
    0, 0, 29, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 54, 53, 53, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 69, 68, 29,
    0, 0, 32, 31, 31, 31, 34, 31, 34, 31, 31, 35, 31, 54, 53, 53, 55, 31, 35, 31, 31, 31, 31, 31, 31, 40, 0, 69, 68, 29,
    0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 29, 0, 69, 68, 29,
    0, 0, 29, 0, 58, 60, 60, 60, 60, 59, 0, 29, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 32, 31, 70, 70, 39,
    0, 0, 29, 0, 56, 61, 61, 61, 61, 57, 0, 29, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 29, 0, 69, 68, 0,
    0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 29, 0, 69, 68, 0,
    0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 54, 53, 53, 55, 0, 32, 31, 34, 31, 31, 34, 31, 33, 0, 69, 68, 0,
    0, 0, 46, 43, 43, 43, 43, 43, 43, 43, 43, 45, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 29, 0, 69, 68, 0,
    0, 0, 46, 30, 30, 30, 30, 30, 30, 30, 30, 45, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 29, 0, 69, 68, 0,
    0, 0, 46, 30, 30, 30, 30, 30, 30, 30, 30, 45, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 29, 0, 69, 68, 0,
    0, 0, 46, 30, 30, 30, 30, 30, 30, 30, 30, 45, 0, 54, 53, 53, 55, 0, 32, 31, 34, 31, 31, 34, 31, 33, 0, 69, 68, 0,
    0, 0, 46, 30, 30, 30, 30, 30, 30, 30, 30, 45, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 29, 0, 69, 68, 0,
    0, 0, 41, 44, 44, 44, 44, 44, 44, 44, 44, 39, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 29, 0, 69, 68, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54, 53, 53, 55, 0, 29, 0, 0, 0, 0, 0, 0, 29, 0, 69, 68, 0,
};
int mapData4[] = {
    82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82,
    93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 96, 82, 82, 82,
    82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 91, 82, 82, 82,
    82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 91, 82, 82, 82,
    84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 113, 87, 84, 84, 84,
    83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 88, 83, 83, 83,
    83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 89, 83, 83, 83,
    83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 112, 90, 110, 85, 85,
    83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    85, 85, 85, 85, 85, 108, 83, 83, 83, 83, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    82, 82, 82, 82, 82, 86, 83, 83, 83, 83, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    93, 96, 82, 82, 82, 86, 83, 83, 83, 83, 82, 91, 82, 82, 91, 82, 82, 82, 91, 82, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 86, 83, 83, 83, 83, 82, 91, 82, 82, 91, 82, 82, 82, 91, 82, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 86, 83, 83, 83, 83, 82, 91, 82, 82, 91, 82, 82, 82, 91, 82, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 86, 83, 83, 83, 83, 82, 98, 93, 93, 92, 93, 93, 93, 97, 82, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 86, 83, 83, 83, 83, 82, 82, 82, 82, 91, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 86, 83, 83, 83, 83, 82, 82, 82, 82, 105, 82, 82, 82, 82, 82, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 86, 83, 83, 83, 83, 83, 83, 83, 83, 88, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 86, 83, 83, 83, 83, 83, 83, 83, 83, 89, 83, 83, 83, 83, 83, 83, 83, 83, 83, 83, 114, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 109, 85, 85, 85, 85, 85, 85, 85, 85, 90, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 111, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 91, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 91, 82, 82, 103, 103, 103, 103, 103, 103, 103, 103, 103, 91, 82, 82, 82,
    82, 91, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 99, 92, 100, 82, 103, 103, 103, 103, 103, 103, 103, 103, 103, 91, 82, 82, 82,
    82, 95, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 92, 92, 92, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 94, 82, 82, 82,
    82, 91, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 102, 92, 101, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 91, 82, 82, 82,
    82, 91, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 82, 91, 82, 106, 107, 106, 107, 106, 107, 106, 107, 106, 106, 91, 82, 82, 82,
    82, 91, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 82, 91, 82, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 91, 82, 82, 82,
    82, 91, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 82, 91, 82, 106, 107, 106, 107, 106, 107, 106, 107, 106, 106, 91, 82, 82,
    82, 82, 91, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 82, 91, 82, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 91, 82, 82,
    82, 82, 91, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 82, 91, 82, 106, 107, 106, 107, 106, 107, 106, 107, 106, 106, 91, 82, 82,
    82, 82, 91, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 82, 91, 82, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 91, 82, 82,
    82, 82, 98, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 101, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 97, 82, 82,
    82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82,82,
};


int* mapData = mapData1;

void update_map(float camera_x, float camera_y)
{
    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            int tileValue = mapData[y * mapWidth + x];

            if (tileValue >= 0 && tileValue < sizeof(gameTextures) / sizeof(gameTextures[0]))
            {
                SDL_Texture* texture = gameTextures[tileValue].texture;

                if (texture == NULL)
                {
                    const char* imagePath = gameTextures[tileValue].imagePath;


                    gameTextures[tileValue].texture = load_texture(imagePath, renderer);
                    texture = gameTextures[tileValue].texture;
                }

                int screenX = round((x - camera_x) * TILE_SIZE);
                int screenY = round((y - camera_y) * TILE_SIZE);

                if (screenX + TILE_SIZE > 0 && screenX < windowWidth &&
                    screenY + TILE_SIZE > 0 && screenY < windowHeight)
                {
                    SDL_Rect dest_rect = { screenX, screenY, TILE_SIZE, TILE_SIZE };
                    SDL_RenderCopy(renderer, texture, NULL, &dest_rect);
                }
            }
        }
    }
}
