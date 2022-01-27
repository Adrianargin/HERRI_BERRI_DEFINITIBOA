#ifndef EDIFIZIO_H
#define EDIFIZIO_H

#include "ourTypes.h"

typedef enum { EZ, BAI, URA } OKUPATUTA;
typedef enum { TORRE = 1, DENDA = 2, ELIZA = 3, BLOKEA = 4, GORRI = 5, TXALET = 6, KASINO = 7, POLIZIA = 8, EOLIKO = 9, ECO = 10 } EDIFIZIO_MOTA;

typedef struct edifizioa_sortu {
	POSIZIOA pos;
	EDIFIZIO_MOTA edifizio_mota;
	OKUPATUTA okupatuta;
}EDIFIZIO;

EDIFIZIO posizioak[100], kasinoak[100];

EDIFIZIO posizioa(int i);

#endif