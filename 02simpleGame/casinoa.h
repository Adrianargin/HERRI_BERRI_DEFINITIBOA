#ifndef CASINOA_H
#define CASINOA_H

#include "ourTypes.h"
#include "hasierakoMenua.h"

int kasinoaSortu(void);

void tragaperras(int zenb[]);

void animazioa(int buelta);

int sariaBegiratu(int zenb[]);

void iconoakKargatu(int zenb, int buelta);

void iconoakAukeratu(int zenb[], int buelta);

int FONDOA_kasinokoIrudiaSortu();
int FONDOA_kasinokoIrudiaMartxanSortu();

int FONDOA_BihotzaIrudiaSortu(int buelta);
int FONDOA_kanpaiIrudiaSortu(int buelta);
int FONDOA_diamanteIrudiaSortu(int buelta);
int FONDOA_sandiaIrudiaSortu(int buelta);
int FONDOA_keizaIrudiaSortu(int buelta);
int FONDOA_limoiaIrudiaSortu(int buelta);

typedef struct {
	int id;
}CASINO_ELEMENTUA;

CASINO_ELEMENTUA casinoa[10];

#endif