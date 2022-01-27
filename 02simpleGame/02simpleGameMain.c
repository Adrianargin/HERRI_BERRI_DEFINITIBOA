/*#include "orokorrak.h"
#include "sarrera.h"
#include "errealitateFisikoa.h"
#include "jokoa.h"
#include "bukaera.h"*/

//---------------------------------------------------------------------------------
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
//---------------------------------------------------------------------------------

#include <stdio.h>

#include "ourTypes.h"
#include "game02.h"
#include "edifizioak.h"
#include "hasierakoMenua.h"

#define MENUA_MUSIKA ".\\sound\\Musica_De_Fondo.wav"

int main(int argc, char* str[]) {
    int jarraitu = 0;
    EGOERA egoera = MENUA;
    AURREKOEGOERA aurrekoEgoera = -1;
    int i = 0;
    FILE* fitx;


    if (sgHasieratu() == -1) {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    textuaGaitu();

    audioInit();
    loadTheMusic(MENUA_MUSIKA);

    pantallaAldaketa(egoera);

    sgItxi();

    return 0;
}
