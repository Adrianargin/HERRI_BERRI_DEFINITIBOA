#include "hasierakoMenua.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define MENU_HASIERA_IMAGE ".\\img\\menu_hasiera.bmp"
#define KREDITUAK_IMAGE ".\\img\\kredituak.bmp"
#define AJUSTEAK_IMAGE ".\\img\\ajusteak.bmp"
#define PROHIBIDO_IMAGE ".\\img\\prohibido.bmp"

#define MENUA_MUSIKA ".\\sound\\Musica_De_Fondo.wav"

void pantallaAldaketa(int egoera) {
	do {
		switch (egoera) {
			case JOLASTEN:
				audioTerminate();
				egoera = jokatu();
				audioTerminate();
				aurrekoEgoera = JOLASTEN;
				bueltaKop = 0;
				audioInit();
				break;
			case KREDITU:
				egoera = kredituak();
				aurrekoEgoera = KREDITU;
				break;
			case MENUA:
				egoera = hasierakoMenuaSortu();
				aurrekoEgoera = MENUA;
				break;
			case AJUSTEAK:
				egoera = hasierakoAjusteak();
				aurrekoEgoera = AJUSTEAK;
				break;
			case JOKUKOAJUSTEAK:
				egoera = jokukoAjusteak();
				break;
			default:
				break;
		}
	} while (egoera != -1);
}

int saguarenKlickaHasierakoMenua(int ebentu, int egoera) {
	POSIZIOA arratoiarenPos;
	int i;

	arratoiarenPos = saguarenPosizioa();
	ebentu = ebentuaJasoGertatuBada();

	if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 435 && arratoiarenPos.x < 1053 && arratoiarenPos.y > 253 && arratoiarenPos.y < 416) {
		egoera = JOLASTEN;
	}
	else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 600 && arratoiarenPos.x < 910 && arratoiarenPos.y > 590 && arratoiarenPos.y < 688) {
		egoera = KREDITU;
	}
	else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 1184 && arratoiarenPos.x < 1400 && arratoiarenPos.y > 615 && arratoiarenPos.y < 691) {
		sgItxi();
	}
	else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 1281 && arratoiarenPos.x < 1375 && arratoiarenPos.y > 22 && arratoiarenPos.y < 115) {
		egoera = AJUSTEAK;
	}
	else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 603 && arratoiarenPos.x < 907 && arratoiarenPos.y > 494 && arratoiarenPos.y < 559) {
		remove("edifizioak.txt");
		for (i = 0; i < 101; i++) {
			posizioak[i].edifizio_mota = -1;
			posizioak[i].okupatuta = -1;
			posizioak[i].pos.x = NULL;
			posizioak[i].pos.y = NULL;
			kasinoKop = NULL;
			dirua = -1;
		}
		egoera = JOLASTEN;
	}

	return egoera;
}

EGOERA hasierakoMenuaSortu(void) {
	int ebentu = 0;
	POSIZIOA arratoiarenPos;
	EGOERA egoera = MENUA;
	int i = 0;

	if (debekatutaDago == 0) {
		if (bueltaKop != 1) {
			loadTheMusic(MENUA_MUSIKA);
			playMusic();
		}
		else {
			Mix_ResumeMusic();
		}
	}

	pantailaGarbitu();

	if (aurrekoEgoera == JOLASTEN) {
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
	}
	else if (aurrekoEgoera == KREDITU) {
		irudiaKendu(kredituFondoa.id);
	}
	else if (aurrekoEgoera == AJUSTEAK) {
		irudiaKendu(ajusteFondoa.id);
		if (debekatutaDago == 1) {
			irudiaKendu(prohibidoIrudia.id);
		}
	}
	bueltaKop = 1;
	hasierakoMenua.id = FONDOA_hasierakoMenukoIrudiaSortu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		egoera = saguarenKlickaHasierakoMenua(ebentu, egoera);
	} while (egoera == MENUA);

	return egoera;
}

EGOERA kredituak(void) {
	int ebentu = 0;
	EGOERA egoera = KREDITU;
	POSIZIOA arratoiarenPos;

	pantailaGarbitu();
	irudiaKendu(hasierakoMenua.id);
	kredituFondoa.id = FONDOA_kredituenIrudiaSortu();
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		arratoiarenPos = saguarenPosizioa();
		ebentu = ebentuaJasoGertatuBada();

		if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 20 && arratoiarenPos.x < 239 && arratoiarenPos.y > 40 && arratoiarenPos.y < 98) {
			egoera = MENUA;
		}
	} while (egoera == KREDITU);

	return egoera;
}

EGOERA hasierakoAjusteak(void) {
	int ebentu = 0;
	EGOERA egoera = AJUSTEAK;
	POSIZIOA arratoiarenPos;

	pantailaGarbitu();
	irudiaKendu(hasierakoMenua.id);

	ajusteFondoa.id = FONDOA_ajusteenIrudiaSortu();
	if (debekatutaDago == 1) {
		prohibidoIrudia.id = FONDOA_prohibidoIrudiaSortu();
	}
	irudiakMarraztu();
	pantailaBerriztu();

	do {
		do {
			arratoiarenPos = saguarenPosizioa();
			ebentu = ebentuaJasoGertatuBada();
		} while (ebentu != SAGU_BOTOIA_EZKERRA);

			if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 538 && arratoiarenPos.x < 860 && arratoiarenPos.y > 218 && arratoiarenPos.y < 280) {
				if (debekatutaDago == 0) {
					prohibidoIrudia.id = FONDOA_prohibidoIrudiaSortu();
					toggleMusic();
					debekatutaDago = 1;
				}
				else if (debekatutaDago == 1) {
					pantailaGarbitu();
					irudiaKendu(prohibidoIrudia.id);
					irudiaKendu(ajusteFondoa.id);
					ajusteFondoa.id = FONDOA_ajusteenIrudiaSortu();
					irudiakMarraztu();
					pantailaBerriztu();
					audioInit();
					loadTheMusic(MENUA_MUSIKA);
					playMusic();
					debekatutaDago = 0;
				}
			}
			else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 278 && arratoiarenPos.x < 693 && arratoiarenPos.y > 317 && arratoiarenPos.y < 399) {
				//ETORKIZUNEAN
			}
			else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 559 && arratoiarenPos.x < 793 && arratoiarenPos.y > 540 && arratoiarenPos.y < 607) {
				sgItxi();
			}
			if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 64 && arratoiarenPos.x < 260 && arratoiarenPos.y > 47 && arratoiarenPos.y < 95) {
				egoera = MENUA;
			}

	} while (egoera == AJUSTEAK);

	return egoera;
}

int FONDOA_hasierakoMenukoIrudiaSortu() {
	int hasieraFondoaId = -1;
	hasieraFondoaId = irudiaKargatu(MENU_HASIERA_IMAGE);
	return hasieraFondoaId;
}
int FONDOA_kredituenIrudiaSortu() {
	int kredituakId = -1;
	kredituakId = irudiaKargatu(KREDITUAK_IMAGE);
	return kredituakId;
}
int FONDOA_ajusteenIrudiaSortu() {
	int ajusteakId = -1;
	ajusteakId = irudiaKargatu(AJUSTEAK_IMAGE);
	return ajusteakId;
}
int FONDOA_prohibidoIrudiaSortu() {
	int prohibidoId = -1;
	prohibidoId = irudiaKargatu(PROHIBIDO_IMAGE);
	irudiaMugitu(prohibidoId, 763, 222);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return prohibidoId;
}

