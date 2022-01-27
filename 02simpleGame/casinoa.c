#include "denda.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "casinoa.h"
#include <stdio.h>
#include <windows.h>

#define FONDO_KASINOA_IMAGE ".\\img\\kasinoGoixan.bmp"
#define FONDO_KASINOA_MARTXAN ".\\img\\kasinoBeian.bmp"
#define BIHOTZA_KASINOA_IMAGE ".\\img\\bihotz.bmp"
#define KEIZA_KASINOA_IMAGE ".\\img\\keiza.bmp"
#define DIAMANTEA_KASINOA_IMAGE ".\\img\\diamante.bmp"
#define KANPAIA_KASINOA_IMAGE ".\\img\\kanpai.bmp"
#define SANDIA_KASINOA_IMAGE ".\\img\\sandia.bmp"
#define LIMOIA_KASINOA_IMAGE ".\\img\\limoia.bmp"

#define KASINOA_MUSIKA ".\\sound\\kasinoMusika.wav"
#define KASINO_IRABAZI ".\\sound\\kasinoIrabazi.wav"


int kasinoaSortu(void) {
	CASINO_ELEMENTUA casinoa[10];
	int ebentu = 0;
	int egoera = CASINOA;
	int  saria = 0, sariaKop = 0;
	int zenb[100];
	int i = 0;
	POSIZIOA arratoiarenPos;

	audioInit();
	if (debekatutaDago == 0) {
		loadTheMusic(KASINOA_MUSIKA);
		playMusic();
	}

	srand(time(NULL));

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

	pantailaGarbitu();
	casinoa[0].id = FONDOA_BihotzaIrudiaSortu(0);
	casinoa[1].id = FONDOA_diamanteIrudiaSortu(1);
	casinoa[2].id = FONDOA_kanpaiIrudiaSortu(2);
	casinoa[6].id = FONDOA_kasinokoIrudiaSortu();

	do {

		itzuliBotoia.id = FONDOA_itzuliBotoiaSortu();
		irudiakMarraztu();
		pantailaBerriztu();
		
		do {
			arratoiarenPos = saguarenPosizioa();
			ebentu = ebentuaJasoGertatuBada();

		} while (ebentu != SAGU_BOTOIA_EZKERRA);

		saria = 0;

		irudiaKendu(itzuliBotoia.id);

		if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 980 && arratoiarenPos.x < 1040 && arratoiarenPos.y > 210 && arratoiarenPos.y < 260) {
			casinoa[7].id = FONDOA_kasinokoIrudiaMartxanSortu();
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(250);
			irudiaKendu(casinoa[7].id);
			pantailaBerriztu();

			tragaperras(zenb);
			saria = sariaBegiratu(zenb);
			if (saria == 1) {
				if (debekatutaDago == 0) {
					kasinoSoinua.id = loadSound(KASINO_IRABAZI);
					playSound(kasinoSoinua.id);
				}
				dirua += 500;
			}
			else {
				dirua -= 50;
			}
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 0 && arratoiarenPos.x < 64 && arratoiarenPos.y > 0 && arratoiarenPos.y < 64) {
			pantailaGarbitu();
			irudiaKendu(casinoa[0].id);
			irudiaKendu(casinoa[2].id);
			irudiaKendu(casinoa[1].id);
			irudiaKendu(casinoa[6].id);
			egoera = JOLASTEN;
		}
	} while (egoera == CASINOA);
	
	return egoera;
}

int FONDOA_kasinokoIrudiaSortu() {
	int casinoaId = -1;
	casinoaId = irudiaKargatu(FONDO_KASINOA_IMAGE);
	return casinoaId;
}
int FONDOA_kasinokoIrudiaMartxanSortu() {
	int casinoaId = -1;
	casinoaId = irudiaKargatu(FONDO_KASINOA_MARTXAN);
	return casinoaId;
}

void tragaperras(int zenb[]) {
	int buelta = 0;

	do {
		while (buelta < 3) {
			irudiaKendu(casinoa[buelta].id);
			zenb[buelta] = (rand() % 3);
			animazioa(buelta);
			iconoakKargatu(zenb, buelta);
			buelta++;
		}
	} while (buelta < 3);
	irudiaKendu(casinoa[3].id);
	casinoa[6].id = FONDOA_kasinokoIrudiaSortu();
	irudiakMarraztu();
	pantailaBerriztu();
}

void animazioa(int buelta) {
	int i, j;

	for (i = 0; i < 1; i++) {
		for (j = 0; j < 6; j++) {
			irudiaKendu(casinoa[6].id);
			casinoa[0].id = FONDOA_BihotzaIrudiaSortu(buelta);
			casinoa[6].id = FONDOA_kasinokoIrudiaSortu();
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(20);
			irudiaKendu(casinoa[0].id);
			irudiaKendu(casinoa[6].id);
			casinoa[1].id = FONDOA_kanpaiIrudiaSortu(buelta);
			casinoa[6].id = FONDOA_kasinokoIrudiaSortu();
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(20);
			irudiaKendu(casinoa[1].id);
			irudiaKendu(casinoa[6].id);
			casinoa[2].id = FONDOA_keizaIrudiaSortu(buelta);
			casinoa[6].id = FONDOA_kasinokoIrudiaSortu();
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(20);
			irudiaKendu(casinoa[2].id);
			irudiaKendu(casinoa[6].id);
			casinoa[3].id = FONDOA_limoiaIrudiaSortu(buelta);
			casinoa[6].id = FONDOA_kasinokoIrudiaSortu();
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(20);
			irudiaKendu(casinoa[3].id);
			irudiaKendu(casinoa[6].id);
			casinoa[4].id = FONDOA_diamanteIrudiaSortu(buelta);
			casinoa[6].id = FONDOA_kasinokoIrudiaSortu();
			irudiakMarraztu();
			pantailaBerriztu();
			Sleep(20);
			irudiaKendu(casinoa[4].id);
			irudiaKendu(casinoa[6].id);
			casinoa[5].id = FONDOA_sandiaIrudiaSortu(buelta);
			casinoa[6].id = FONDOA_kasinokoIrudiaSortu();
			irudiakMarraztu();
			pantailaBerriztu();
			irudiaKendu(casinoa[5].id);
		}
	}
}

int sariaBegiratu(int zenb[]) {
	int saria = 0, i = 0;

	if (zenb[0] == zenb[1] && zenb[0] == zenb[2] && zenb[1] == zenb[2]) {
		saria = 1;
	}

	return saria;
}

void iconoakKargatu(int zenb, int buelta) {
	if (buelta == 0) {
		iconoakAukeratu(zenb, buelta);
	}
	else if (buelta == 1) {
		iconoakAukeratu(zenb, buelta);
	}
	else if (buelta == 2) {
		iconoakAukeratu(zenb, buelta);
	}
}

void iconoakAukeratu(int zenb[], int buelta) {
	if (zenb[buelta] == 0) {
		casinoa[buelta].id = FONDOA_BihotzaIrudiaSortu(buelta);
	}
	else if (zenb[buelta] == 1) {
		casinoa[buelta].id = FONDOA_kanpaiIrudiaSortu(buelta);
	}
	else if (zenb[buelta] == 2) {
		casinoa[buelta].id = FONDOA_diamanteIrudiaSortu(buelta);
	}
}

int FONDOA_BihotzaIrudiaSortu(int buelta) {
	int bihotzaId = -1;
	
	bihotzaId = irudiaKargatu(BIHOTZA_KASINOA_IMAGE);
	
	if (buelta == 0) {
		irudiaMugitu(bihotzaId, 530, 310);
	}
	else if (buelta == 1) {
		irudiaMugitu(bihotzaId, 650, 310);
	}
	else if (buelta == 2) {
		irudiaMugitu(bihotzaId, 770, 310);
	}

	return bihotzaId;
}
int FONDOA_kanpaiIrudiaSortu(int buelta) {
	int kanpaiId = -1;

	kanpaiId = irudiaKargatu(KANPAIA_KASINOA_IMAGE);
	
	if (buelta == 0) {
		irudiaMugitu(kanpaiId, 530, 310);
	}
	else if (buelta == 1) {
		irudiaMugitu(kanpaiId, 650, 310);
	}
	else if (buelta == 2) {
		irudiaMugitu(kanpaiId, 770, 310);
	}
	
	return kanpaiId;
}
int FONDOA_diamanteIrudiaSortu(int buelta) {
	int diamanteId = -1;
	
	diamanteId = irudiaKargatu(DIAMANTEA_KASINOA_IMAGE);
	
	if (buelta == 0) {
		irudiaMugitu(diamanteId, 530, 310);
	}
	else if (buelta == 1) {
		irudiaMugitu(diamanteId, 650, 310);
	}
	else if (buelta == 2) {
		irudiaMugitu(diamanteId, 770, 310);
	}

	return diamanteId;
}
int FONDOA_sandiaIrudiaSortu(int buelta) {
	int sandiaId = -1;

	sandiaId = irudiaKargatu(SANDIA_KASINOA_IMAGE);
	
	if (buelta == 0) {
		irudiaMugitu(sandiaId, 530, 310);
	}
	else if (buelta == 1) {
		irudiaMugitu(sandiaId, 650, 310);
	}
	else if (buelta == 2) {
		irudiaMugitu(sandiaId, 770, 310);
	}

	return sandiaId;
}
int FONDOA_keizaIrudiaSortu(int buelta) {
	int keizaId = -1;
	
	keizaId = irudiaKargatu(KEIZA_KASINOA_IMAGE);
	if (buelta == 0) {
		irudiaMugitu(keizaId, 530, 310);
	}
	else if (buelta == 1) {
		irudiaMugitu(keizaId, 650, 310);
	}
	else if (buelta == 2) {
		irudiaMugitu(keizaId, 770, 310);
	}

	return keizaId;
}
int FONDOA_limoiaIrudiaSortu(int buelta) {
	int limoiaId = -1;

	limoiaId = irudiaKargatu(LIMOIA_KASINOA_IMAGE);
	if (buelta == 0) {
		irudiaMugitu(limoiaId, 530, 310);
	}
	else if (buelta == 1) {
		irudiaMugitu(limoiaId, 650, 310);
	}
	else if (buelta == 2) {
		irudiaMugitu(limoiaId, 770, 310);
	}

	return limoiaId;
}