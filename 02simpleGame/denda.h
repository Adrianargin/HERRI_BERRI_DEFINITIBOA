#ifndef DENDA_H
#define DENDA_H

#include "ourTypes.h"
#include "edifizioak.h"

int dendaSortu(void);

void dendakoEdifizioakSortu(int dendaPantaila);
int JOKOA_Edifizioak_Kartak(int i);

int dendakoBatPantaila();
int dendakoBiPantaila();

int FONDOA_dendakoIrudiaSortu();
int FONDOA_ekoBotoiaSortu();
int FONDOA_itzuliBotoiaSortu();

int kostua;
int dendaPantaila;

#endif