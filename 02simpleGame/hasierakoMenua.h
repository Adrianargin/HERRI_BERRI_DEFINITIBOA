#ifndef HASIERAKOMENUA_H
#define HASIERAKOMENUA_H

#include "ourTypes.h"
#include "edifizioak.h"
#include "game02.h"

EGOERA hasierakoMenuaSortu(void);

void pantallaAldaketa(int egoera);

int saguarenKlickaHasierakoMenua(int ebentu, int egoera);

EGOERA kredituak(void);
EGOERA hasierakoAjusteak(void);
int FONDOA_hasierakoMenukoIrudiaSortu();
int FONDOA_kredituenIrudiaSortu();
int FONDOA_ajusteenIrudiaSortu();
int FONDOA_prohibidoIrudiaSortu();

int bueltaKop;
int debekatutaDago;

#endif