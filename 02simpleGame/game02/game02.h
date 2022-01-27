#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"
#include "edifizioak.h"
#include "hasierakoMenua.h"

EGOERA jokatu(void);

int JOKOA_Edifizioak(int i);

EDIFIZIO edifizioaKokatu(int irudia, EDIFIZIO posizioak[]);

void okupatuakSartu();

int JOKOA_fondoIrudiaSortu();
int JOKOA_dendaIrudia();
int JOKOA_ajusteIrudiaSortu();
int JOKOA_gordeIrudia();
int JOKOA_gordeKonfirmatuIrudia();
int JOKOA_diruMarkadoreaSortu();
int JOKOA_menuraIrudia();

#endif