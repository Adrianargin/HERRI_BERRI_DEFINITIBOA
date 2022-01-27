#include "dirua.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "casinoa.h"
#include "text.h"
#include "soinua.h"
#include "edifizioak.h"
#include <stdio.h>
#include <windows.h>

#define DIRU_ZERO ".\\img\\ZERO.bmp"
#define DIRU_BAT ".\\img\\BAT.bmp"
#define DIRU_BI ".\\img\\BI.bmp"
#define DIRU_HIRU ".\\img\\HIRU.bmp"
#define DIRU_LAU ".\\img\\LAU.bmp"
#define DIRU_BOST ".\\img\\BOST.bmp"
#define DIRU_SEI ".\\img\\SEI.bmp"
#define DIRU_ZAZPI ".\\img\\ZAZPI.bmp"
#define DIRU_ZORTZI ".\\img\\ZORTZI.bmp"
#define DIRU_BEDERATZI ".\\img\\BEDERATZI.bmp"

void diruaMarraztu() {
	int diru = dirua;
	int hondarra = 0, kont = 0;

	while (diru > 0) {
		hondarra = diru % 10;
		diru = diru / 10;
		kont++;

		jokukoDiruaSortu(kont, hondarra);
	}
}
void jokukoDiruaSortu(int kont, int zenb) {

	if (kont == 1) {
		batTxanpona.id = diruaKargatu(zenb);
		irudiaMugitu(batTxanpona.id, 1340, 33);
	}
	if (kont == 2) {
		biTxanpona.id = diruaKargatu(zenb);
		irudiaMugitu(biTxanpona.id, 1320, 33);
	}
	if (kont == 3) {
		hiruTxanpona.id = diruaKargatu(zenb);
		irudiaMugitu(hiruTxanpona.id, 1300, 33);
	}
	if (kont == 4) {
		lauTxanpona.id = diruaKargatu(zenb);
		irudiaMugitu(lauTxanpona.id, 1280, 33);
	}
	if (kont == 5) {
		bostTxanpona.id = diruaKargatu(zenb);
		irudiaMugitu(bostTxanpona.id, 1260, 33);
	}
	if (kont == 6) {
		seiTxanpona.id = diruaKargatu(zenb);
		irudiaMugitu(seiTxanpona.id, 1240, 33);
	}
}
int diruaKargatu(int i) {
#define DIRU_ZERO ".\\img\\ZERO.bmp"
#define DIRU_BAT ".\\img\\BAT.bmp"
#define DIRU_BI ".\\img\\BI.bmp"
#define DIRU_HIRU ".\\img\\HIRU.bmp"
#define DIRU_LAU ".\\img\\LAU.bmp"
#define DIRU_BOST ".\\img\\BOST.bmp"
#define DIRU_SEI ".\\img\\SEI.bmp"
#define DIRU_ZAZPI ".\\img\\ZAZPI.bmp"
#define DIRU_ZORTZI ".\\img\\ZORTZI.bmp"
#define DIRU_BEDERATZI ".\\img\\BEDERATZI.bmp"

	int id = -1;

	switch (i) {
	case 0:
		zeroDirua.id = irudiaKargatu(DIRU_ZERO);
		id = zeroDirua.id;
		break;
	case 1:
		batDirua.id = irudiaKargatu(DIRU_BAT);
		id = batDirua.id;
		break;
	case 2:
		biDirua.id = irudiaKargatu(DIRU_BI);
		id = biDirua.id;
		break;
	case 3:
		hiruDirua.id = irudiaKargatu(DIRU_HIRU);
		id = hiruDirua.id;
		break;
	case 4:
		lauDirua.id = irudiaKargatu(DIRU_LAU);
		id = lauDirua.id;
		break;
	case 5:
		bostDirua.id = irudiaKargatu(DIRU_BOST);
		id = bostDirua.id;
		break;
	case 6:
		seiDirua.id = irudiaKargatu(DIRU_SEI);
		id = seiDirua.id;
		break;
	case 7:
		zazpiDirua.id = irudiaKargatu(DIRU_ZAZPI);
		id = zazpiDirua.id;
		break;
	case 8:
		zortziDirua.id = irudiaKargatu(DIRU_ZORTZI);
		id = zortziDirua.id;
		break;
	case 9:
		bederatziDirua.id = irudiaKargatu(DIRU_BEDERATZI);
		id = bederatziDirua.id;
		break;
	default:
		break;
	}

	return id;

}

void diruaEzabatu() {
	int diru = dirua;
	int hondarra = 0, kont = 0;

	while (diru > 0) {
		hondarra = diru % 10;
		diru = diru / 10;
		kont++;

		diruaDeskargatu(hondarra);
	}
}
void diruaDeskargatu(int i) {

	switch (i) {
		case 0:
			irudiaKendu(zeroDirua.id);
			break;
		case 1:
			irudiaKendu(batDirua.id);
			break;
		case 2:
			irudiaKendu(biDirua.id);
			break;
		case 3:
			irudiaKendu(hiruDirua.id);
			break;
		case 4:
			irudiaKendu(lauDirua.id);
			break;
		case 5:
			irudiaKendu(bostDirua.id);
			break;
		case 6:
			irudiaKendu(seiDirua.id);
			break;
		case 7:
			irudiaKendu(zazpiDirua.id);
			break;
		case 8:
			irudiaKendu(zortziDirua.id);
			break;
		case 9:
			irudiaKendu(bederatziDirua.id);
			break;
		default:
			break;
	}

}