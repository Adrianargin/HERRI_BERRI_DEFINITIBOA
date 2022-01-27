#include "denda.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define FONDO_DENDA_IMAGE ".\\img\\dendaFondo.bmp"
#define ITZULI_BOTOIA ".\\img\\return.bmp"
#define EKO_BOTOIA ".\\img\\Eko_botoia.bmp"


int dendaSortu(void) {	
	int i, irudia = 0;

	dendaPantaila = 0;

	irudiaKendu(jokuaFondo.id);
	irudiaKendu(dendaBotoia.id);
	irudiaKendu(ajusteBotoia.id);
	irudiaKendu(gordeBotoia.id);
	irudiaKendu(menuaBotoia.id);
	i = 0;
	while (irudiKop > 0 && i < 100) {
		if (posizioak[i].okupatuta == BAI) {
			irudiaKendu(irudiaID);
		}
		i++;
	}

	do {
		do {
			switch (dendaPantaila) {
			case 0:
				irudia = dendakoBatPantaila();

				irudiaKendu(dendaFondo.id);
				irudiaKendu(batEdifizioa.id);
				irudiaKendu(biEdifizioa.id);
				irudiaKendu(hiruEdifizioa.id);
				irudiaKendu(lauEdifizioa.id);
				irudiaKendu(bostEdifizioa.id);
				irudiaKendu(seiEdifizioa.id);
				irudiaKendu(zazpiEdifizioa.id);
				irudiaKendu(zortziEdifizioa.id);
				irudiaKendu(ekoBotoia.id);
				irudiaKendu(itzuliBotoia.id);
				irudiaKendu(diruaFondo.id);
				diruaEzabatu();
				break;
			case 1:
				irudia = dendakoBiPantaila();

				irudiaKendu(dendaFondo.id);
				irudiaKendu(bederatziEdifizioa.id);
				irudiaKendu(hamarEdifizioa.id);
				irudiaKendu(itzuliBotoia.id);
				irudiaKendu(diruaFondo.id);
				diruaEzabatu();

				break;
			default:
				break;
			}
		} while (irudia == 0);

		if ((kostua > dirua) && (irudia >= 0)) {
			textuaGaitu();
			pantailaGarbitu();
			textuaIdatzi(550, 300, "EZ DUZU NAHIKOA DIRU");
			pantailaBerriztu();
			Sleep(1000);
			irudia = 0;
		}
		else if (kostua != 0) {
			dirua = dirua - kostua;
		}
		kostua = 0;
	} while (irudia == 0);

	return irudia;
}

int FONDOA_dendakoIrudiaSortu() {
	int dendaId = -1;
	dendaId = irudiaKargatu(FONDO_DENDA_IMAGE);
	return dendaId;
}
int FONDOA_ekoBotoiaSortu() {
	int ekoBotoiaId = -1;
	ekoBotoiaId = irudiaKargatu(EKO_BOTOIA);
	irudiaMugitu(ekoBotoiaId, 1200, 620);
	return ekoBotoiaId;
}
int FONDOA_itzuliBotoiaSortu() {
	int itzuliId = -1;
	itzuliId = irudiaKargatu(ITZULI_BOTOIA);
	return itzuliId;
}

void dendakoEdifizioakSortu(int dendaPantaila) {
	if (dendaPantaila == 0) {
		batEdifizioa.id = JOKOA_Edifizioak_Kartak(1);
		irudiaMugitu(batEdifizioa.id, 46, 23);

		biEdifizioa.id = JOKOA_Edifizioak_Kartak(2);
		irudiaMugitu(biEdifizioa.id, 339, 23);

		hiruEdifizioa.id = JOKOA_Edifizioak_Kartak(3);
		irudiaMugitu(hiruEdifizioa.id, 632, 23);

		lauEdifizioa.id = JOKOA_Edifizioak_Kartak(4);
		irudiaMugitu(lauEdifizioa.id, 925, 23);

		bostEdifizioa.id = JOKOA_Edifizioak_Kartak(5);
		irudiaMugitu(bostEdifizioa.id, 46, 365);

		seiEdifizioa.id = JOKOA_Edifizioak_Kartak(6);
		irudiaMugitu(seiEdifizioa.id, 339, 365);

		zazpiEdifizioa.id = JOKOA_Edifizioak_Kartak(7);
		irudiaMugitu(zazpiEdifizioa.id, 632, 365);

		zortziEdifizioa.id = JOKOA_Edifizioak_Kartak(8);
		irudiaMugitu(zortziEdifizioa.id, 925, 365);
	}
	else if (dendaPantaila == 1) {
		bederatziEdifizioa.id = JOKOA_Edifizioak_Kartak(9);
		irudiaMugitu(bederatziEdifizioa.id, 429, 120);

		hamarEdifizioa.id = JOKOA_Edifizioak_Kartak(10);
		irudiaMugitu(hamarEdifizioa.id, 752, 120);
	}
}

int JOKOA_Edifizioak_Kartak(int i) {
#define BAT_EDIFIZIOA_IMAGE ".\\img\\Torre_Karta.bmp"
#define BI_EDIFIZIOA_IMAGE ".\\img\\JanariDenda_Karta.bmp"
#define HIRU_EDIFIZIOA_IMAGE ".\\img\\Eliza_Karta.bmp"
#define LAU_EDIFIZIOA_IMAGE ".\\img\\EtxeBloke_Karta.bmp"
#define BOST_EDIFIZIOA_IMAGE ".\\img\\EtxeGorri_Karta.bmp"
#define SEI_EDIFIZIOA_IMAGE ".\\img\\Txalet_Karta.bmp"
#define ZAZPI_EDIFIZIOA_IMAGE ".\\img\\Kasino_Karta.bmp"
#define ZORTZI_EDIFIZIOA_IMAGE ".\\img\\Polizia_Karta.bmp"
#define BEDERATZI_EDIFIZIOA_IMAGE ".\\img\\Eolikoa_Karta.bmp"
#define HAMAR_EDIFIZIOA_IMAGE ".\\img\\Eco_Karta.bmp"

	int id = -1;

	if (i == 1) {
		id = irudiaKargatu(BAT_EDIFIZIOA_IMAGE);
	}
	if (i == 2) {
		id = irudiaKargatu(BI_EDIFIZIOA_IMAGE);
	}
	if (i == 3) {
		id = irudiaKargatu(HIRU_EDIFIZIOA_IMAGE);
	}
	if (i == 4) {
		id = irudiaKargatu(LAU_EDIFIZIOA_IMAGE);
	}
	if (i == 5) {
		id = irudiaKargatu(BOST_EDIFIZIOA_IMAGE);
	}
	if (i == 6) {
		id = irudiaKargatu(SEI_EDIFIZIOA_IMAGE);
	}
	if (i == 7) {
		id = irudiaKargatu(ZAZPI_EDIFIZIOA_IMAGE);
	}
	if (i == 8) {
		id = irudiaKargatu(ZORTZI_EDIFIZIOA_IMAGE);
	}
	if (i == 9) {
		id = irudiaKargatu(BEDERATZI_EDIFIZIOA_IMAGE);
	}
	if (i == 10) {
		id = irudiaKargatu(HAMAR_EDIFIZIOA_IMAGE);
	}

	return id;
}

int dendakoBatPantaila() {
	int ebentu = 0, irudia = 0;
	POSIZIOA arratoiarenPos;

	dendaPantaila = 0;

	pantailaGarbitu();
	dendaFondo.id = FONDOA_dendakoIrudiaSortu();
	dendakoEdifizioakSortu(dendaPantaila);
	ekoBotoia.id = FONDOA_ekoBotoiaSortu();
	diruaFondo.id = JOKOA_diruMarkadoreaSortu();
	itzuliBotoia.id = FONDOA_itzuliBotoiaSortu();
	irudiaMugitu(itzuliBotoia.id, 1325, 75);
	
	diruaMarraztu();
	
	irudiakMarraztu();
	pantailaBerriztu();
	
	do {
		do {
			arratoiarenPos = saguarenPosizioa();
			ebentu = ebentuaJasoGertatuBada();
		} while (ebentu != SAGU_BOTOIA_EZKERRA);

		if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 46 && arratoiarenPos.x < 288 && arratoiarenPos.y > 23 && arratoiarenPos.y < 335) {
			irudia = 1;
			kostua = 1700;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 339 && arratoiarenPos.x < 581 && arratoiarenPos.y > 23 && arratoiarenPos.y < 335) {
			irudia = 2;
			kostua = 400;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 632 && arratoiarenPos.x < 874 && arratoiarenPos.y > 23 && arratoiarenPos.y < 335) {
			irudia = 3;
			kostua = 1100;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 925 && arratoiarenPos.x < 1167 && arratoiarenPos.y > 23 && arratoiarenPos.y < 335) {
			irudia = 4;
			kostua = 900;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 46 && arratoiarenPos.x < 288 && arratoiarenPos.y > 365 && arratoiarenPos.y < 677) {
			irudia = 5;
			kostua = 250;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 339 && arratoiarenPos.x < 581 && arratoiarenPos.y > 365 && arratoiarenPos.y < 677) {
			irudia = 6;
			kostua = 1100;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 632 && arratoiarenPos.x < 874 && arratoiarenPos.y > 365 && arratoiarenPos.y < 677) {
			irudia = 7;
			kostua = 1000;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 925 && arratoiarenPos.x < 1167 && arratoiarenPos.y > 365 && arratoiarenPos.y < 677) {
			irudia = 8;
			kostua = 600;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 1200 && arratoiarenPos.x < 1400 && arratoiarenPos.y > 620 && arratoiarenPos.y < 700) {
			dendaPantaila = 1;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 1325 && arratoiarenPos.x < 1400 && arratoiarenPos.y > 75 && arratoiarenPos.y < 150) {
			irudia = -1;
		}
	} while (irudia == 0 && dendaPantaila == 0);

	return irudia;
}
int dendakoBiPantaila() {
	int ebentu = 0, irudia = 0;
	POSIZIOA arratoiarenPos;

	dendaPantaila = 1;

	pantailaGarbitu();
	dendaFondo.id = FONDOA_dendakoIrudiaSortu();
	dendakoEdifizioakSortu(dendaPantaila);
	itzuliBotoia.id = FONDOA_itzuliBotoiaSortu();
	diruaFondo.id = JOKOA_diruMarkadoreaSortu();

	diruaMarraztu();

	irudiakMarraztu();
	pantailaBerriztu();

	do {
		do {
			arratoiarenPos = saguarenPosizioa();
			ebentu = ebentuaJasoGertatuBada();
		} while (ebentu != SAGU_BOTOIA_EZKERRA);

		if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 429 && arratoiarenPos.x < 671 && arratoiarenPos.y > 120 && arratoiarenPos.y < 432) {
			irudia = 9;
			kostua = 1100;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 752 && arratoiarenPos.x < 994 && arratoiarenPos.y > 120 && arratoiarenPos.y < 432) {
			irudia = 10;
			kostua = 2000;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 0 && arratoiarenPos.x < 64 && arratoiarenPos.y > 0 && arratoiarenPos.y < 64) {
			dendaPantaila = 0;
		}
	} while (irudia == 0 && dendaPantaila == 1);

	return irudia;
}