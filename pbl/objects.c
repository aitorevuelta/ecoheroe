#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#include "objects.h"
#include "constants.h"
#include "update.h"

ObjectInfo gameObjects1[] = {

    //Habitacion 1
    {"cama", "cama2.png", TRUE, NULL, 325, 200, 125, 180, FALSE, FALSE},
    {"cama", "cama2.png", TRUE, NULL, 525, 200, 125, 180, FALSE, FALSE},
    {"cama", "cama2.png", TRUE, NULL, 725, 200, 125, 180, FALSE, FALSE},
    {"mesilla", "mesilla1.png", TRUE, NULL, 450, 200, 75, 100, FALSE, FALSE},
    {"mesilla", "mesilla1.png", TRUE, NULL, 650, 200, 75, 100, FALSE, FALSE},

    //PASILLO
    {"estanteria", "estanteria.png", TRUE, NULL, 2575, 150, 150, 150, FALSE, FALSE},
    {"estanteria", "estanteria.png", TRUE, NULL, 2925, 150, 150, 150, FALSE, FALSE},
    {"mesa", "mesa.png", TRUE, NULL, 2725, 206, 200, 75, FALSE, FALSE},
    {"mesilla", "mesilla.png", TRUE, NULL, 3025, 490, 75, 100, FALSE, FALSE},
    {"sofa", "sofa1.png", TRUE, NULL, 3000, 600, 125 ,250,FALSE,FALSE},

    //BAÑO1
    {"bañera", "banera.png", TRUE, NULL, 3725, 3300, 200, 150, FALSE, FALSE},
    {"lavamanos", "lavamanos.png", TRUE, NULL, 3980, 3300, 75, 75, FALSE, FALSE},
    {"retrete", "retrete.png", TRUE, NULL, 3720, 3600, 75, 100, FALSE, FALSE},
    //BAÑO2
    {"bañera", "banera.png", TRUE, NULL, 4325, 2240, 200, 150, FALSE, FALSE},
    {"lavamanos", "lavamanos.png", TRUE, NULL, 4580, 2230, 75, 75, FALSE, FALSE},
    {"retrete", "retrete.png", TRUE, NULL, 4315, 2528, 75, 100, FALSE, FALSE},

    //HABITACION 2 
    {"encimera", "encimera.png", TRUE, NULL, 4500, 560, 200, 100, FALSE, FALSE },
    {"encimera2", "encimera2.png", TRUE, NULL, 4700, 575, 100, 125, FALSE, FALSE },
    {"fogones", "fogones.png", TRUE, NULL, 4410, 560, 100, 100, FALSE, FALSE},
    {"mesa3", "mesa3.png", TRUE, NULL, 4600, 925, 150, 300, FALSE, FALSE},
    {"mesa3", "mesa3.png", TRUE, NULL, 4295, 925, 150, 300, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4555, 970, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4555, 1055, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4448, 970, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4448, 1055, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4230, 970, 50, 50, FALSE, FALSE},
    {"silla", "silla.png", TRUE, NULL, 4230, 1055, 50, 50, FALSE, FALSE},
    {"nevera", "nevera.png", TRUE, NULL, 4310, 490, 100, 200, FALSE, FALSE},

    //HABITACION 3
    {"generador", "generador.png", TRUE, NULL, 230, 1440, 250, 250, FALSE, FALSE},
    {"decoracion", "decoracionrota3.png", TRUE, NULL, 275, 1900, 250, 250, FALSE, FALSE},
    {"decoracion", "decoracionrota.png", TRUE, NULL, 880, 1550, 75, 75, FALSE, FALSE},
    {"decoracion", "decoracionrota.png", TRUE, NULL, 750, 1480, 125, 125, FALSE, FALSE},
    {"decoracion", "decoracionrota4.png", TRUE, NULL, 475, 1500, 125, 125, FALSE, FALSE},
    {"decoracion", "mesa1.png", TRUE, NULL, 770, 1775, 175, 125, FALSE, FALSE},

    //HABITACION SALIDA
    {"camara", "camara.png", FALSE, NULL, 385, 2910, 75, 75, FALSE, FALSE},
    {"camara", "camara2.png", FALSE, NULL, 1360, 2910, 75, 75, FALSE, FALSE},
    {"estanteria", "estanteria.png", TRUE, NULL, 655, 2900, 150, 150, FALSE, FALSE},
    {"estanteria", "estanteria.png", TRUE, NULL, 1000, 2900, 150, 150, FALSE, FALSE},
    {"reloj", "reloj.png", TRUE, NULL, 865, 2895, 75, 150, FALSE, FALSE},
    {"lampara", "lampara.png", TRUE, NULL, 795, 2950, 75, 100, FALSE, FALSE },
    {"perchero", "decoracion.png", TRUE, NULL, 945, 2920, 50, 125, FALSE, FALSE },
    {"sofa", "sofa3.png", TRUE, NULL, 405, 3200, 250, 150, FALSE, FALSE},
    {"sofa", "sofa3.png", TRUE, NULL, 1150, 3200, 250, 150, FALSE, FALSE},
    {"salida", "puertabunker.png", TRUE, NULL, 725, 3350, 350, 250, TRUE, 35},

    //PUERTAS
     {"puerta", "puerta.png", TRUE, NULL, 715, 695, 125, 150, TRUE, 35},
     {"puerta", "puerta.png", TRUE, NULL, 600, 1300, 125, 150, FALSE, FALSE},
     {"puerta", "puerta.png", TRUE, NULL, 715, 2135, 125, 150, TRUE, 35},
     {"puerta", "puerta.png", TRUE, NULL, 1198, 2750, 125, 150, FALSE, FALSE},
     {"puerta", "puerta.png", TRUE, NULL, 477, 2750, 125, 150, FALSE, FALSE},
     {"puerta", "puerta.png", TRUE, NULL, 2880, 1650, 125, 150, TRUE, 35},
     {"puerta", "puerta2.png", TRUE, NULL, 1075, 275, 25, 200, FALSE, FALSE},
     {"puerta", "puerta3.png", TRUE, NULL, 2390, 275, 25, 200, FALSE, FALSE},
     {"puerta", "puerta3.png", TRUE, NULL, 2620, 875, 25, 200, FALSE, FALSE},
     {"puerta", "puerta3.png", TRUE, NULL, 2620, 1352, 25, 200, FALSE, FALSE},
     {"puerta", "puerta3.png", TRUE, NULL, 4070, 755, 25, 200, FALSE, FALSE},
     {"puerta", "puerta2.png", TRUE, NULL, 3225, 1115, 25, 200, FALSE, FALSE},
     {"puerta", "puerta2.png", TRUE, NULL, 4794, 2315, 25, 200, FALSE, FALSE},
     {"puerta", "puerta2.png", TRUE, NULL, 4195, 3395, 25, 200, FALSE, FALSE},

    {NULL, NULL, FALSE, NULL, 0, 0, 0, 0, FALSE, 0}
};

ObjectInfo gameObjects2[] = {
    {"ChestClosed", "cofrecerrado.png", TRUE, NULL, 600, 520, 80, 80, FALSE, 0},
    {"Bunker", "bunker.png", TRUE, NULL, 30, 200, 550, 400, FALSE, NULL},
    {"tronco", "tronco.png", TRUE, NULL, 900, 270, 80, 60},
    {"señal", "senal.png", TRUE, NULL, 1650, 260, 80, 100},

    {NULL, NULL, FALSE, NULL, 0, 0, 0, 0, FALSE, 0}
};

ObjectInfo gameObjects3[] = {
    {"barandilla", "barandilla.png", TRUE, NULL, 1575, 790, 450, 50, TRUE, 5},
    {"puente roto", "puenteroto.png", TRUE, NULL, 1550, 2000, 525, 150, FALSE, FALSE},

    {"fuente", "fuente.png", TRUE, NULL, 900, 600, 250, 250, TRUE, 10},

    {"casa", "casa.png", TRUE, NULL, 380, 1260, 300, 300, TRUE, 20},
    {"casa", "casa2.png", TRUE, NULL, 625, 1740, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2300, 2340, 300, 300, TRUE, 20},
    {"casa", "casa2.png", TRUE, NULL, 2675, 2340, 300, 300, TRUE, 20},
    {"casa", "casa2.png", TRUE, NULL, 2300, 2815, 300, 300, TRUE, 20},
    {"casa", "casa3.png", TRUE, NULL, 2660, 2815, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2180, 420, 300, 300, TRUE, 20},
    {"casa", "casa3.png", TRUE, NULL, 2540, 420, 300, 300, TRUE, 20},
    {"casa", "casa.png", TRUE, NULL, 2900, 420, 300, 300, TRUE, 20},
    {"casa", "casa2.png", TRUE, NULL, 3260, 420, 300, 300, TRUE, 20},

    {"basura", "basura.png", TRUE, NULL, 995, 415, 80, 80, FALSE, FALSE},
    {"basura", "basura.png", TRUE, NULL, 825, 2800, 80, 80, FALSE, FALSE},
    {"basura", "basura.png", TRUE, NULL, 3315, 1495, 80, 80, FALSE, FALSE},

    {"banco", "banco.png", TRUE, NULL, 865, 415, 80, 60, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 1400, 655, 80, 60, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 1070, 415, 80, 60, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 475, 2800, 80, 60, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 650, 2800, 80, 60, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 925, 2800, 80, 60, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 1100, 2800, 80, 60, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 1100, 2800, 80, 60, FALSE, FALSE},
    {"banco", "banco.png", TRUE, NULL, 3420, 1495, 80, 60, FALSE, FALSE},

    {"señal", "senal.png", TRUE, NULL, 100, 260, 80, 100},
    {"tronco", "tronco.png", TRUE, NULL, 450, 300, 80, 60},
    {"arbol", "arbol.png", TRUE, NULL, 400, 400, 150, 200, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 500, 350, 250, 300, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 1375, 25, 150, 200, TRUE, 35},


    {"arbol", "arbol.png", TRUE, NULL, 1350, 420, 300, 200, TRUE, 35},
    {"arbol", "arbol2.png", TRUE, NULL, 85, 650, 150, 200, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 475, 1775, 150, 200, TRUE, 35},
    {"arbol", "arbol2.png", TRUE, NULL, 2750, 3250, 150, 200, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 1350, 1050, 150, 200, TRUE, 35},
    {"arbol", "arbol2.png", TRUE, NULL, 1245, 1325, 250, 200, TRUE, 35},
    {"arbol", "arbol2.png", TRUE, NULL, 1150, 1550, 150, 200, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 1355, 1775, 150, 200, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 75, 2350, 150, 200, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 0, 1650, 250, 200, TRUE, 35},
    {"arbol", "arbol2.png", TRUE, NULL, 2050, 1100, 250, 200, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 2425, 2050, 150, 200, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 2675, 2075, 250, 200, TRUE, 35},
    {"arbol", "arbol2.png", TRUE, NULL, 2425, 3250, 150, 200, TRUE, 35},

    {"arbol", "arbol2.png", TRUE, NULL, 540, 2390, 250, 300, TRUE, 35},
    {"arbol", "arbol.png", TRUE, NULL, 1065, 2475, 150, 200, TRUE, 35},


    {"piedra", "piedras.png", TRUE, NULL, 850, 2525, 150, 100, FALSE, FALSE},

    // eje x
    {"vayas", "vallax.png", TRUE, NULL, 350, 2110, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 475, 2110, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 600, 2110, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 725, 2110, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 850, 2110, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 975, 2110, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 1100, 2110, 125, 75, TRUE, 1},

    {"vayas", "vallax.png", TRUE, NULL, 350, 1625, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 475, 1625, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 600, 1625, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 725, 1625, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 850, 1625, 125, 75, TRUE, 1},

    {"vayas", "vallax.png", TRUE, NULL, 350, 650, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 475, 650, 125, 75, TRUE, 1},
    {"vayas", "vallax.png", TRUE, NULL, 600, 650, 125, 75, TRUE, 1},


    //eje y
    {"vayas", "vallay.png", TRUE, NULL, 350, 2150, 25, 150, FALSE, FALSE},
    {"vayas", "vallay.png", TRUE, NULL, 350, 2275, 25, 150, FALSE, FALSE},
    {"vayas", "vallay.png", TRUE, NULL, 350, 2400, 25, 150, FALSE, FALSE},
    {"vayas", "vallay.png", TRUE, NULL, 350, 2525, 25, 150, FALSE, FALSE},
    {"vayas", "vallay.png", TRUE, NULL, 350, 2650, 25, 150, FALSE, FALSE},

    {"vayas", "vallay.png", TRUE, NULL, 350, 1665, 25, 150, FALSE, FALSE},
    {"vayas", "vallay.png", TRUE, NULL, 350, 1790, 25, 150, FALSE, FALSE},

    {"farola", "farola.png", TRUE, NULL, 375, 2585, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 825, 2585, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1275, 2585, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 900, 1325, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 775, 375, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1225, 375, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 375, 1815, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1100, 1805, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 185, 285, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1225, 800, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 775, 800, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2075, 485, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2490, 485, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2845, 485, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 3210, 485, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2535, 925, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 3250, 1315, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 3125, 2030, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2955, 3050, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2955, 3050, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2280, 3050, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2535, 1445, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2535, 925, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 2280, 1970, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 1270, 1945, 50, 225, TRUE, 60},
    {"farola", "farola.png", TRUE, NULL, 360, 660, 50, 225, TRUE, 60},

    {"parque", "parque.png", TRUE, NULL, 475, 2875, 400, 300, TRUE, 40},
    {"columpio", "columpio.png", TRUE, NULL, 800, 3250, 250, 200, TRUE, 30},
    {"tobogan", "tobogan.png", TRUE, NULL, 1050, 2950, 200, 250, TRUE, 50 },

    // mision
    { "contenedorverde", "contenedorverde.png", TRUE, NULL, 2800, 1050, 100, 100, FALSE, FALSE },
    { "contenedormarron", "contenedormarron.png", TRUE, NULL, 3000, 1050, 100, 100, FALSE, FALSE },
    { "contenedoramarillo", "contenerdoramarillo.png", TRUE, NULL, 2600, 1050, 100, 100, FALSE, FALSE },

    { "contenedorazul", "contenedorazul.png", TRUE, NULL, 2600, 1450, 100, 100, FALSE, FALSE },
    { "contenedorgris", "contenedorgris.png", TRUE, NULL, 2800, 1450, 100, 100, FALSE, FALSE },


    //basura
    { "plastikoa", "plastikoa.png", TRUE, NULL, 2800, 750, 50, 50, FALSE, FALSE },
    { "papera", "papera.png", TRUE, NULL, 3000, 900, 50, 50, FALSE, FALSE },
    { "beira", "beira.png", TRUE, NULL, 2600, 800, 50, 50, FALSE, FALSE },
    { "organikoa", "organikoa.png", TRUE, NULL, 3300, 1000, 50, 50, FALSE, FALSE },
    { "errefuxa", "errefuxa.png", TRUE, NULL, 3300, 1200, 50, 50, FALSE, FALSE },

    { "plastikoa", "plastikoa.png", TRUE, NULL, 453, 874, 50, 50, FALSE, FALSE },
    { "papera", "papera.png", TRUE, NULL, 105, 525, 50, 50, FALSE, FALSE },
    { "beira", "beira.png", TRUE, NULL, 103, 1940, 50, 50, FALSE, FALSE },
    { "organikoa", "organikoa.png", TRUE, NULL, 955, 2960, 50, 50, FALSE, FALSE },
    { "errefuxa", "errefuxa.png", TRUE, NULL, 617, 3268, 50, 50, FALSE, FALSE },

    { "plastikoa", "plastikoa.png", TRUE, NULL, 432, 1710, 50, 50, FALSE, FALSE },
    { "papera", "papera.png", TRUE, NULL, 1505, 1283, 50, 50, FALSE, FALSE },
    { "beira", "beira.png", TRUE, NULL, 1144, 1113, 50, 50, FALSE, FALSE },
    { "organikoa", "organikoa.png", TRUE, NULL, 1285, 343, 50, 50, FALSE, FALSE },
    { "errefuxa", "errefuxa.png", TRUE, NULL, 3314, 1363, 50, 50, FALSE, FALSE },

    { "plastikoa", "plastikoa.png", TRUE, NULL, 3510, 2588, 50, 50, FALSE, FALSE },
    { "papera", "papera.png", TRUE, NULL, 2339, 3284, 50, 50, FALSE, FALSE },
    { "beira", "beira.png", TRUE, NULL, 90, 2938, 50, 50, FALSE, FALSE },
    { "organikoa", "organikoa.png", TRUE, NULL, 460, 2691, 50, 50, FALSE, FALSE },
    { "errefuxa", "errefuxa.png", TRUE, NULL, 1504, 2641, 50, 50, FALSE, FALSE },

    { "plastikoa", "plastikoa.png", TRUE, NULL, 2130, 1452, 50, 50, FALSE, FALSE },
    { "papera", "papera.png", TRUE, NULL, 2623, 1808, 50, 50, FALSE, FALSE },
    { "beira", "beira.png", TRUE, NULL, 2995, 1570, 50, 50, FALSE, FALSE },
    { "organikoa", "organikoa.png", TRUE, NULL, 3506, 1135, 50, 50, FALSE, FALSE },
    { "errefuxa", "errefuxa.png", TRUE, NULL, 3019, 2641, 50, 50, FALSE, FALSE },

    { "plastikoa", "plastikoa.png", TRUE, NULL, 2608, 2744, 50, 50, FALSE, FALSE },
    { "papera", "papera.png", TRUE, NULL, 2074, 2205, 50, 50, FALSE, FALSE },
    { "beira", "beira.png", TRUE, NULL, 3161, 3284, 50, 50, FALSE, FALSE },
    { "organikoa", "organikoa.png", TRUE, NULL, 1219, 2205, 50, 50, FALSE, FALSE },
    { "errefuxa", "errefuxa.png", TRUE, NULL, 1206, 1820, 50, 50, FALSE, FALSE },

    {NULL, NULL, FALSE, NULL, 0, 0, 0, 0, FALSE, 0}
};

ObjectInfo gameObjects4[] = {
    {"ChestClosed", "cofrecerrado.png", TRUE, NULL, 784, 2405, 80, 80, FALSE, 0},
    {"Arbol", "arbol.png", TRUE, NULL, 0, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 160, 0, 130, 130, TRUE, 35},
    {"arbusto", "arbusto.png", FALSE, NULL, 360, 340, 130, 100, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 360, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 560, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 760, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 960, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1160, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1360, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1560, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1760, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1960, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2160, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2360, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2560, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2760, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2960, 0, 130, 130, TRUE, 35},
    {"Basura", "basura.png", TRUE, NULL, 3240, 280, 80, 80, FALSE, FALSE},
    {"Basura", "basura.png", TRUE, NULL, 3240, 110, 80, 80, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 190, 80, 100, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 2600, 80, 100, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 2400, 80, 100, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 2200, 80, 100, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 1000, 80, 100, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 1200, 80, 100, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 1400, 80, 100, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 1600, 80, 100, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 1800, 80, 100, FALSE, FALSE},
    {"BancoBerti", "Banco_berti.png", TRUE, NULL, 3240, 2000, 80, 100, FALSE, FALSE},
    {"Arbol", "arbol.png", TRUE, NULL, 3160, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3300, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 0, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 360, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 960, 130, 130, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL,  -80, 1080, 190, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 110, 1080, 190, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 290, 1080, 190, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 480, 1080, 190, 110, TRUE, 35},
    {"Salt", "salt.png", TRUE, NULL, 3220, 340, 130, 130, TRUE, 35},
    {"Salt", "salt.png", TRUE, NULL, 3000, 340, 130, 130, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL,  -80, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 100, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 280, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 460, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 640, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 820, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1000, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1180, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1360, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1540, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1720, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1900, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 2080, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 2260, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 2440, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 2620, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 2800, 380, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1180, 860, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1360, 860, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1540, 860, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1720, 860, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1900, 860, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 2080, 860, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 2260, 860, 160, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1180, 1930, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1360, 1930, 180, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1540, 1930, 160, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1790, 1930, 210, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 1990, 1930, 210, 110, TRUE, 35},
    {"barras", "barras.png", TRUE, NULL, 2200, 1930, 200, 110, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 1160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 1360, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 1560, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 1760, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 1960, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 2160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 2360, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 2560, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 2760, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 2960, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 3160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 3360, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 3560, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 3760, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3460, 3960, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 0, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 160, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 360, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 560, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 760, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 960, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1160, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1360, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1560, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1760, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1960, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2160, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2360, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2560, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2760, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2960, 160, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3300, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 3100, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2900, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2700, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2500, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2300, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 2100, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1900, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1700, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1500, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1300, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 1100, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 900, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 700, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 500, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 300, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 100, 3850, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 10, 3760, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 10, 3560, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 10, 3360, 130, 130, TRUE, 35},
    {"Arbol", "arbol.png", TRUE, NULL, 10, 3160, 130, 130, TRUE, 35},
    { "Arbol", "arbol.png", TRUE, NULL, 10, 2960, 130, 130, TRUE, 35 },
    { "Arbol", "arbol.png", TRUE, NULL, 10, 2760, 130, 130, TRUE, 35 },
    { "Arbol", "arbol.png", TRUE, NULL, 10, 2560, 130, 130, TRUE, 35 },
    { "Arbol", "arbol.png", TRUE, NULL, 10, 2360, 130, 130, TRUE, 35 },
    { "Arbol", "arbol.png", TRUE, NULL, 10, 2160, 130, 130, TRUE, 35 },
    { "Arbol", "arbol.png", TRUE, NULL, 10, 1960, 130, 130, TRUE, 35 },
    { "Arbol", "arbol.png", TRUE, NULL, 10, 1760, 130, 130, TRUE, 35 },
    { "Arbol", "arbol.png", TRUE, NULL, 10, 1560, 130, 130, TRUE, 35 },
    { "Arbol", "arbol.png", TRUE, NULL, 10, 1360, 130, 130, TRUE, 35 },
    { "Arbol", "arbol.png", TRUE, NULL, 10, 1160, 130, 130, TRUE, 35 },
    {"SmallHouse", "small_house.png", TRUE, NULL, 1280, 1150, 200, 200, TRUE, 20},
    {"SmallHouse", "small_house.png", TRUE, NULL, 1630, 1150, 200, 200, TRUE, 20},
    {"SmallHouse", "small_house.png", TRUE, NULL, 2120, 1150, 200, 200, TRUE, 20},
    {"Banco", "banco.png", TRUE, NULL, 2020, 2350, 120, 100, FALSE, FALSE },
    {"Banco", "banco.png", TRUE, NULL, 2220, 2350, 120, 100, FALSE, FALSE },
    {"Banco", "banco.png", TRUE, NULL, 2620, 2350, 120, 100, FALSE, FALSE },
    {"Banco", "banco.png", TRUE, NULL, 2820, 2350, 120, 100, FALSE, FALSE },
    { "Banco", "banco.png", TRUE, NULL, 1360, 2350, 120, 100, FALSE, FALSE },
    { "Banco", "banco.png", TRUE, NULL, 1160, 2350, 120, 100, FALSE, FALSE },
    { "Banco", "banco.png", TRUE, NULL, 960, 2350, 120, 100, FALSE, FALSE },
    {"Valla", "madera_centro.png", TRUE, NULL, 2200, 2700, 180, 80, FALSE, FALSE },
    {"Valla", "madera_centro.png", TRUE, NULL, 2380, 2700, 180, 80, FALSE, FALSE },
    {"Valla", "madera_centro.png", TRUE, NULL, 2560, 2700, 180, 80, FALSE, FALSE },
    {"Valla", "madera_centro.png", TRUE, NULL, 2740, 2700, 180, 80, FALSE, FALSE },
    {"Valla", "madera_izq.png", TRUE, NULL, 2020, 2500, 180, 80, FALSE, FALSE },
    {"Valla", "madera_centro.png", TRUE, NULL, 2200, 2500, 180, 80, FALSE, FALSE },
    {"Valla", "madera_centro.png", TRUE, NULL, 2380, 2500, 180, 80, FALSE, FALSE },
    {"Valla", "madera_centro.png", TRUE, NULL, 2560, 2500, 180, 80, FALSE, FALSE },
    {"Valla", "madera_centro.png", TRUE, NULL, 2740, 2500, 180, 80, FALSE, FALSE },
    {"valla", "madera_der.png", TRUE, NULL, 2920, 2500, 200, 80, FALSE, FALSE },
    { "Valla", "madera_izq.png", TRUE, NULL, 2020, 2700, 180, 80, FALSE, FALSE },
    { "valla", "madera_der.png", TRUE, NULL, 2920, 2700, 200, 80, FALSE, FALSE },
    { "Puenteroto_der", "puenteroto_der.png", TRUE, NULL, 1100, 1640, 120, 120, FALSE, FALSE },
    { "Puenteroto_izq", "puenteroto_izq.png", TRUE, NULL, 640, 1640, 120, 120, FALSE, FALSE },
    { "Puenteroto_der", "puenteroto_der.png", TRUE, NULL, 2950, 1640, 120, 120, FALSE, FALSE },
    { "Puenteroto_izq", "puenteroto_izq.png", TRUE, NULL, 2400, 1640, 120, 120, FALSE, FALSE },
    { "roble", "roble.png", TRUE, NULL, 400, 2460, 60, 60, FALSE, FALSE },
    { "roble", "roble.png", TRUE, NULL, 400, 2260, 60, 60, FALSE, FALSE },
    { "roble", "roble.png", TRUE, NULL, 400, 1860, 60, 60, FALSE, FALSE },
    { "roble", "roble.png", TRUE, NULL, 400, 1660, 60, 60, FALSE, FALSE },
    { "roble", "roble.png", TRUE, NULL, 400, 1260, 60, 60, FALSE, FALSE },
    { "curz", "cruz.png", TRUE, NULL, 400, 3060, 80, 80, FALSE, FALSE },
    { "curz", "cruz.png", TRUE, NULL, 700, 3060, 80, 80, FALSE, FALSE },
    { "curz", "RIP.png", TRUE, NULL, 1000, 3060, 80, 80, FALSE, FALSE },
    { "curz", "cruz.png", TRUE, NULL, 1300, 3060, 80, 80, FALSE, FALSE },
    { "curz", "cruz.png", TRUE, NULL, 400, 3260, 80, 80, FALSE, FALSE },
    { "curz", "RIP.png", TRUE, NULL, 700, 3260, 80, 80, FALSE, FALSE },
    { "curz", "cruz.png", TRUE, NULL, 1000, 3260, 80, 80, FALSE, FALSE },
    { "curz", "cruz.png", TRUE, NULL, 1300, 3260, 80, 80, FALSE, FALSE },
    { "curz", "cruz.png", TRUE, NULL, 400, 3460, 80, 80, FALSE, FALSE },
    { "curz", "RIP.png", TRUE, NULL, 700, 3460, 80, 80, FALSE, FALSE },
    { "curz", "RIP.png", TRUE, NULL, 1000, 3460, 80, 80, FALSE, FALSE },
    { "curz", "cruz.png", TRUE, NULL, 1300, 3460, 80, 80, FALSE, FALSE },
    { "valla_cementerio", "valla_cementerio2.png", TRUE, NULL, 235, 3375, 10, 275, FALSE, FALSE },
    { "valla_cementerio", "valla_cementerio2.png", TRUE, NULL, 235, 3125, 10, 275, FALSE, FALSE },
    { "valla_cementerio", "valla_cementerio2.png", TRUE, NULL, 235, 2875, 10, 275, FALSE, FALSE },
    { "valla_cementerio", "valla_cementerio2.png", TRUE, NULL, 1555, 3375, 10, 275, FALSE, FALSE },
    { "valla_cementerio", "valla_cementerio2.png", TRUE, NULL, 1555, 3125, 10, 275, FALSE, FALSE },
    { "valla_cementerio", "valla_cementerio2.png", TRUE, NULL, 1555, 2875, 10, 275, FALSE, FALSE },
    { "sueloco_cementerio", "suelo_cementerio.png", TRUE, NULL, 500, 3060, 190, 80, FALSE, FALSE },
    { "sueloco_cementerio", "suelo_cementerio.png", TRUE, NULL, 800, 3060, 190, 80, FALSE, FALSE },
    { "sueloco_cementerio", "suelo_cementerio.png", TRUE, NULL, 1100, 3060, 190, 80, FALSE, FALSE },
    { "sueloco_cementerio", "suelo_cementerio.png", TRUE, NULL, 500, 3260, 190, 80, TRUE, 35 },
    { "sueloco_cementerio", "suelo_cementerio.png", TRUE, NULL, 800, 3260, 190, 80, TRUE, 35 },
    { "sueloco_cementerio", "suelo_cementerio.png", TRUE, NULL, 1100, 3260, 190, 80, TRUE, 35 },
    { "sueloco_cementerio", "suelo_cementerio.png", TRUE, NULL, 500, 3460, 190, 80, TRUE, 35 },
    { "sueloco_cementerio", "suelo_cementerio.png", TRUE, NULL, 800, 3460, 190, 80, TRUE, 35 },
    { "sueloco_cementerio", "suelo_cementerio.png", TRUE, NULL, 1100, 3460, 190, 80, TRUE, 35 },
    { "salt", "salt.png", TRUE, NULL, 520, 2930, 130, 130, FALSE, FALSE },
    { "salt", "salt.png", TRUE, NULL, 820, 2930, 130, 130, FALSE, FALSE },
    { "SALT", "salt.png", TRUE, NULL, 1120, 2930, 130, 130, FALSE, FALSE },
    { "RIP", "RIP.png", TRUE, NULL, 400, 2930, 80, 80, FALSE, FALSE },
    { "RIP", "RIP.png", TRUE, NULL, 700, 2930, 80, 80, FALSE, FALSE },
    { "RIP", "RIP.png", TRUE, NULL, 1000, 2930, 80, 80, FALSE, FALSE },
    { "RIP", "RIP.png", TRUE, NULL, 1300, 2930, 80, 80, FALSE, FALSE },
    { "PuertaCementerio", "entrada2.png", TRUE, NULL, 225, 3475, 1350, 260, FALSE, 0 },
    { "PuertaCementerio", "entrada.png", TRUE, NULL, 225, 2625, 1350, 260, TRUE, 100 },
    { "arbolplantado", "tree.png", TRUE, NULL, 2068, 3012, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2310, 3012, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2547, 3012, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2790, 3012, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2068, 3236, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2310, 3236, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2547, 3236, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2790, 3236, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2068, 3485, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2310, 3485, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2547, 3485, 50, 50, TRUE, 20, FALSE, TRUE },
    { "arbolplantado", "tree.png", TRUE, NULL, 2790, 3485, 50, 50, TRUE, 20, FALSE, TRUE },
    // mision
    { "contenedorverde", "contenedorverde.png", TRUE, NULL, 1180, 2650, 100, 100, FALSE, FALSE },
    { "contenedormarron", "contenedormarron.png", TRUE, NULL, 1300, 2650, 100, 100, FALSE, FALSE },
    { "contenedoramarillo", "contenerdoramarillo.png", TRUE, NULL, 1420, 2650, 100, 100, FALSE, FALSE },

    { "contenedorazul", "contenedorazul.png", TRUE, NULL, 1060, 2650, 100, 100, FALSE, FALSE },
    { "contenedorgris", "contenedorgris.png", TRUE, NULL, 940, 2650, 100, 100, FALSE, FALSE },

    //basura
    { "plastikoa", "plastikoa.png", TRUE, NULL, 3357, 2860, 50, 50, FALSE, FALSE },
    { "papera", "papera.png", TRUE, NULL, 1870, 2561, 50, 50, FALSE, FALSE },
    { "beira", "beira.png", TRUE, NULL, 1823, 3606, 50, 50, FALSE, FALSE },
    { "organikoa", "organikoa.png", TRUE, NULL, 700, 2546, 50, 50, FALSE, FALSE },
    { "errefuxa", "errefuxa.png", TRUE, NULL, 304, 2305, 50, 50, FALSE, FALSE },

    { "plastikoa", "plastikoa.png", TRUE, NULL, 524, 1759, 50, 50, FALSE, FALSE },
    { "papera", "papera.png", TRUE, NULL, 253, 1250, 50, 50, FALSE, FALSE },
    { "beira", "beira.png", TRUE, NULL, 1383, 1824, 50, 50, FALSE, FALSE },
    { "organikoa", "organikoa.png", TRUE, NULL, 1553, 1477, 50, 50, FALSE, FALSE },
    { "errefuxa", "errefuxa.png", TRUE, NULL, 2262, 1827, 50, 50, FALSE, FALSE },

    { NULL, NULL, FALSE, NULL, 0, 0, 0, 0, FALSE, 0 }
};


ObjectInfo* gameObjects = gameObjects1;

void render_objects(SDL_Renderer* renderer)
{
    int i = 0;
    while (gameObjects[i].name != NULL)
    {
        // Calculate the object coordinates relative to the camera
        int objectX = gameObjects[i].x - round(camera_x);
        int objectY = gameObjects[i].y - round(camera_y);

        // Check if the object is within the screen
        if (objectX + gameObjects[i].objectWidth > 0 && objectX < windowWidth &&
            objectY + gameObjects[i].objectHeight > 0 && objectY < windowHeight && !gameObjects[i].isInvisible)
        {

            int transparency = 255;
            if (gameObjects[i].isBehindUser)
            {
                transparency = 128;
            }
            SDL_SetTextureAlphaMod(gameObjects[i].texture, transparency);

            SDL_Rect objectRect;

            objectRect.x = objectX;
            objectRect.y = objectY;
            objectRect.w = gameObjects[i].objectWidth;
            objectRect.h = gameObjects[i].objectHeight;

            SDL_RenderCopy(renderer, gameObjects[i].texture, NULL, &objectRect);
        }
        i++;
    }
}
