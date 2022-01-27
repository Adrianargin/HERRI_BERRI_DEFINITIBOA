#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"

typedef enum { MENUA, KREDITU, JOLASTEN, AJUSTEAK, JOKUKOAJUSTEAK, CASINOA , GORDE, TIENDA}EGOERA, AURREKOEGOERA, JOKUKOEGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;


typedef enum { EZDAGO, BADAGO } JARRITA;


int irudiKop;
int irudiaID;
int aurrekoEgoera;
float dirua;


int kasinoKop;
int tmpKasinoKop;

typedef struct {
	int id;
}JOKO_ELEMENTUA;

JOKO_ELEMENTUA hasierakoMenua,
				ajusteFondoa,
				prohibidoIrudia,
				kredituFondoa,
				dendaFondo,
				jokuaFondo,
				dendaBotoia,ajusteBotoia, gordeBotoia, menuaBotoia,
				batEdifizioa, biEdifizioa, hiruEdifizioa, lauEdifizioa, bostEdifizioa, seiEdifizioa, zazpiEdifizioa, zortziEdifizioa, bederatziEdifizioa, hamarEdifizioa,
				ekoBotoia,
				itzuliBotoia,
				gordeta,
				diruaFondo,
				batTxanpona, biTxanpona, hiruTxanpona, lauTxanpona, bostTxanpona, seiTxanpona,
				zeroDirua, batDirua, biDirua, hiruDirua, lauDirua, bostDirua, seiDirua, zazpiDirua, zortziDirua, bederatziDirua,
				kasinoSoinua;

#endif