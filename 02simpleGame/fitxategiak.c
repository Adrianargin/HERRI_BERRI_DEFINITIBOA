#include "fitxategiak.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

void fitxategiaIrakurri() {
	FILE* fitx;
	int fitxEgoera;
	int i = 0;

	fitx = fopen("edifizioak.txt", "r");

	if (fitx > 0) {
		printf("Fitxategia ondo zabaldu da!\n");
		fitxEgoera = fscanf(fitx, "%f\n", &dirua);
		fitxEgoera = fscanf(fitx, "%d\n", &kasinoKop);
		do {
			fitxEgoera = fscanf(fitx, "%d %d %d %d\n", &posizioak[i].pos.x,
				&posizioak[i].pos.y,
				&posizioak[i].edifizio_mota,
				&posizioak[i].okupatuta);
			i++;
		} while (fitxEgoera > 0 && i < 100);

	}
	else {
		printf("[ERROREA] Ezin da fitxategia zabaldu.\n");
	}

	if (fitx > 0) fclose(fitx);
}

void fitxategiaIdatzi() {
	FILE* fitx;
	int fitxEgoera;
	int i = 0;

	fitx = fopen("edifizioak.txt", "w");

	if (fitx > 0) {
		i = 0;
		fitxEgoera = fprintf(fitx, "%f\n", dirua);
		fitxEgoera = fprintf(fitx, "%d\n", kasinoKop);
		while (i < 100 && fitxEgoera > 0) {
			fitxEgoera = fprintf(fitx, "%d %d %d %d\n", posizioak[i].pos.x,
				posizioak[i].pos.y,
				posizioak[i].edifizio_mota,
				posizioak[i].okupatuta);
			i++;
		}

		pantailaGarbitu();
		gordeta.id = JOKOA_gordeKonfirmatuIrudia();
		irudiakMarraztu();
		pantailaBerriztu();
		Sleep(2000);
		irudiaKendu(gordeta.id);
		pantailaBerriztu();
	}
	else {
		printf("Ezin izan da zabaldu fitxategia");
	}
	
	if (fitx > 0) fclose(fitx);
}

