#include "jokukoMenua.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define JOKOA_SOUND ".\\sound\\jokuAudio.wav"

void jokukoAjusteak(void) {
	int ebentu = 0, badago = 0;
	EGOERA egoera = JOKUKOAJUSTEAK;
	POSIZIOA arratoiarenPos;
	int i = 0;

	pantailaGarbitu();
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
				loadTheMusic(JOKOA_SOUND);
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
			egoera = JOLASTEN;
		}
	} while (egoera == JOKUKOAJUSTEAK);

	return egoera;
}