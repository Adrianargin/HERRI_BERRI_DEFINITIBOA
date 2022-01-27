#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "casinoa.h"
#include "text.h"
#include "soinua.h"
#include "edifizioak.h"
#include <stdio.h>
#include <windows.h>

//--------------------------------------------------------------------------------
#define JOKOA_SOUND ".\\sound\\jokuAudio.wav"
//--------------------------------------------------------------------------------

#define FONDO_IMAGE ".\\img\\hiria_mapa.bmp"
#define DENDA_IMAGE ".\\img\\denda.bmp"
#define JOKUKO_AJUSTEAK_IMAGE ".\\img\\ajustes.bmp"
#define GORDE_IMAGE ".\\img\\save.bmp"
#define GORDETA_IMAGE ".\\img\\gordeDa.bmp"
#define MENURA_IMAGE ".\\img\\menura.bmp"

#define DIRU_MARKADOREA ".\\img\\diruPantaila.bmp"

EGOERA jokatu(void) {
	int mugitu = 0; //boolean
	EGOERA egoera = JOLASTEN;
	int ebentu = 0;
	int irudia = 0, fondoID = 0, pos = 0, okupatuta = 0, i = 0;
	POSIZIOA arratoiarenPos;
	int irudiMota = 0;
	JOKUKOEGOERA jokukoEgoera = JOLASTEN;
	int k = 0;
	time_t hasiera = 0, amaiera = 0;
	int diferentzia = 0;
	time(&hasiera);



	fitxategiaIrakurri();

	if (dirua == -1) {
		dirua = 10000;
	}

	audioInit();
	if (debekatutaDago == 0) {
		loadTheMusic(JOKOA_SOUND);
		playMusic();
	}

	pantailaGarbitu();
	irudiaKendu(hasierakoMenua.id);
	jokuaFondo.id = JOKOA_fondoIrudiaSortu();
	dendaBotoia.id = JOKOA_dendaIrudia();
	ajusteBotoia.id = JOKOA_ajusteIrudiaSortu();
	gordeBotoia.id = JOKOA_gordeIrudia();
	menuaBotoia.id = JOKOA_menuraIrudia();

	for (i = 0; i < 100; i++) {
		if (posizioak[i].okupatuta == BAI) {
			pantailaGarbitu();
			irudiMota = posizioak[i].edifizio_mota;
			irudiaID = JOKOA_Edifizioak(irudiMota);
			irudiaMugitu(irudiaID, posizioak[i].pos.x, posizioak[i].pos.y);
		}
	}

	irudiakMarraztu();
	pantailaBerriztu();
	
	for (i = 0; i < 100; i++) //Arraya funtziotik ateratzeko
	{
		posizioak[i] = posizioa(i);
	}

	okupatuakSartu(posizioak);

	do {
		do {

			time(&amaiera);
			diferentzia = amaiera - hasiera;

			arratoiarenPos = saguarenPosizioa();
			ebentu = ebentuaJasoGertatuBada();

			if (diferentzia >= 10) {
				for (i = 0; i < 100; i++) {
					if (posizioak[i].okupatuta == BAI) {
						if (posizioak[i].edifizio_mota == TORRE) { dirua += 2; }
						else if (posizioak[i].edifizio_mota == DENDA) { dirua += 1.6; }
						else if (posizioak[i].edifizio_mota == ELIZA) { dirua += 3.3; }
						else if (posizioak[i].edifizio_mota == BLOKEA) { dirua += 2.5; }
						else if (posizioak[i].edifizio_mota == GORRI) { dirua += 0.8; }
						else if (posizioak[i].edifizio_mota == TXALET) { dirua += 3.3; }
						else if (posizioak[i].edifizio_mota == POLIZIA) { dirua += 5.8; }
						else if (posizioak[i].edifizio_mota == EOLIKO) { dirua += 8.3; }
						else if (posizioak[i].edifizio_mota == ECO) { dirua += 8.3; }
					}
				}

				hasiera = amaiera;
			}
		} while (ebentu != SAGU_BOTOIA_EZKERRA);

		irudia = 0;
		k = 0;


		i = 0;
		tmpKasinoKop = kasinoKop;

		while (i <= 100 && tmpKasinoKop != 0) {
			if (posizioak[i].edifizio_mota == KASINO) {
				kasinoak[kasinoKop - 1].pos.x = posizioak[i].pos.x + 48;
				kasinoak[kasinoKop - 1].pos.y = posizioak[i].pos.y + 58;
				kasinoak[kasinoKop - 1].edifizio_mota = posizioak[i].edifizio_mota;
				kasinoak[kasinoKop - 1].okupatuta = posizioak[i].okupatuta;
				tmpKasinoKop--;
			}
			i++;
		}
		
		jokukoEgoera = JOLASTEN;

		if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 42 && arratoiarenPos.x < 142 && arratoiarenPos.y > 568 && arratoiarenPos.y < 668) {
			jokukoEgoera = TIENDA;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 40 && arratoiarenPos.x < 110 && arratoiarenPos.y > 485 && arratoiarenPos.y < 555) {
			jokukoEgoera = MENUA;
			i = 0;
			while (irudiKop > 0 && i < 100) {
				if (posizioak[i].okupatuta == BAI) {
					irudiaKendu(irudiaID);
				}
				i++;
			}
			for (int i = 0; i < 100; i++) {
				posizioak[i].edifizio_mota = -1;
				posizioak[i].okupatuta = -1;
				posizioak[i].pos.x = NULL;
				posizioak[i].pos.y = NULL;
				dirua = -1;
				kasinoKop = NULL;
			}
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 1300 && arratoiarenPos.x < 1380 && arratoiarenPos.y > 600 && arratoiarenPos.y < 680) {
			jokukoEgoera = GORDE;
		}
		else if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > 40 && arratoiarenPos.x < 140 && arratoiarenPos.y > 20 && arratoiarenPos.y < 120) {
			jokukoEgoera = JOKUKOAJUSTEAK;
		}
		while (k < kasinoKop) {
			if (ebentu == SAGU_BOTOIA_EZKERRA && arratoiarenPos.x > kasinoak[k].pos.x && arratoiarenPos.x < kasinoak[k].pos.x + 60 && arratoiarenPos.y > kasinoak[k].pos.y && arratoiarenPos.y < kasinoak[k].pos.y + 70) {
				jokukoEgoera = CASINOA;
			}
			k++;
		}

		switch (jokukoEgoera) {
			case TIENDA:
				irudia = dendaSortu();

				if (irudia == 7) { kasinoKop++; }

				jokuaFondo.id = JOKOA_fondoIrudiaSortu();
				for (i = 0; i <= 100; i++) {
					if (posizioak[i].okupatuta == BAI) {
						pantailaGarbitu();
						irudiMota = posizioak[i].edifizio_mota;
						irudiaID = JOKOA_Edifizioak(irudiMota);
						irudiaMugitu(irudiaID, posizioak[i].pos.x, posizioak[i].pos.y);
					}
				}
				break;
			case MENUA:
				egoera = jokukoEgoera;
				break;
			case GORDE:
				fitxategiaIdatzi();
				break;
			case JOKUKOAJUSTEAK:
				egoera = jokukoAjusteak();
				pantailaGarbitu();
				jokuaFondo.id = JOKOA_fondoIrudiaSortu();
				dendaBotoia.id = JOKOA_dendaIrudia();
				ajusteBotoia.id = JOKOA_ajusteIrudiaSortu();
				gordeBotoia.id = JOKOA_gordeIrudia();
				menuaBotoia.id = JOKOA_menuraIrudia();

				irudiaKendu(ajusteFondoa.id);
				if (debekatutaDago == 1) {
					irudiaKendu(prohibidoIrudia.id);
				}
				for (i = 0; i <= 100; i++) {
					if (posizioak[i].okupatuta == BAI) {
						pantailaGarbitu();
						irudiMota = posizioak[i].edifizio_mota;
						irudiaID = JOKOA_Edifizioak(irudiMota);
						irudiaMugitu(irudiaID, posizioak[i].pos.x, posizioak[i].pos.y);
					}
				}
				break;
			case CASINOA:
				audioTerminate();
				egoera = kasinoaSortu();
				audioInit();
				if (debekatutaDago == 0) {
					loadTheMusic(JOKOA_SOUND);
					playMusic();
				}

				jokuaFondo.id = JOKOA_fondoIrudiaSortu();
				dendaBotoia.id = JOKOA_dendaIrudia();
				ajusteBotoia.id = JOKOA_ajusteIrudiaSortu();
				gordeBotoia.id = JOKOA_gordeIrudia();
				menuaBotoia.id = JOKOA_menuraIrudia();
				for (i = 0; i <= 100; i++) {
					if (posizioak[i].okupatuta == BAI) {
						pantailaGarbitu();
						irudiMota = posizioak[i].edifizio_mota;
						irudiaID = JOKOA_Edifizioak(irudiMota);
						irudiaMugitu(irudiaID, posizioak[i].pos.x, posizioak[i].pos.y);
					}
				}
				break;
			default:
				break;
		}

		irudiakMarraztu();
		pantailaBerriztu();

		if (irudia != 0) {
			if (irudia != -1 && irudia != -2) {
				edifizioaKokatu(irudia, posizioak);
			}
			dendaBotoia.id = JOKOA_dendaIrudia();
			ajusteBotoia.id = JOKOA_ajusteIrudiaSortu();
			gordeBotoia.id = JOKOA_gordeIrudia();
			menuaBotoia.id = JOKOA_menuraIrudia();

			irudiakMarraztu();
			pantailaBerriztu();
		}
	} while (egoera == JOLASTEN);

	return egoera;
}

int JOKOA_Edifizioak(int i) {
#define BAT_EDIFIZIOA_IMAGE ".\\img\\Torre.bmp"
#define BI_EDIFIZIOA_IMAGE ".\\img\\JanariDenda.bmp"
#define HIRU_EDIFIZIOA_IMAGE ".\\img\\Eliza.bmp"
#define LAU_EDIFIZIOA_IMAGE ".\\img\\EtxeBloke.bmp"
#define BOST_EDIFIZIOA_IMAGE ".\\img\\EtxeGorri.bmp"
#define SEI_EDIFIZIOA_IMAGE ".\\img\\Txalet.bmp"
#define ZAZPI_EDIFIZIOA_IMAGE ".\\img\\Kasino.bmp"
#define ZORTZI_EDIFIZIOA_IMAGE ".\\img\\Polizia.bmp"
#define BEDERATZI_EDIFIZIOA_IMAGE ".\\img\\Eoliko.bmp"
#define HAMAR_EDIFIZIOA_IMAGE ".\\img\\Eco.bmp"

	int id = -1;

	if (i == 1) {
		id = irudiaKargatu(BAT_EDIFIZIOA_IMAGE);
	}
	else if (i == 2) {
		id = irudiaKargatu(BI_EDIFIZIOA_IMAGE);
	}
	else if (i == 3) {
		id = irudiaKargatu(HIRU_EDIFIZIOA_IMAGE);
	}
	else if (i == 4) {
		id = irudiaKargatu(LAU_EDIFIZIOA_IMAGE);
	}
	else if (i == 5) {
		id = irudiaKargatu(BOST_EDIFIZIOA_IMAGE);
	}
	else if (i == 6) {
		id = irudiaKargatu(SEI_EDIFIZIOA_IMAGE);
	}
	else if (i == 7) {
		id = irudiaKargatu(ZAZPI_EDIFIZIOA_IMAGE);
	}
	else if (i == 8) {
		id = irudiaKargatu(ZORTZI_EDIFIZIOA_IMAGE);
	}
	else if (i == 9) {
		id = irudiaKargatu(BEDERATZI_EDIFIZIOA_IMAGE);
	}
	else if (i == 10) {
		id = irudiaKargatu(HAMAR_EDIFIZIOA_IMAGE);
	}

	return id;
}

int JOKOA_fondoIrudiaSortu() {
	int fondoIrudiaId = -1;
	fondoIrudiaId = irudiaKargatu(FONDO_IMAGE);
	return fondoIrudiaId;
}
int JOKOA_dendaIrudia() {
	int dendaId = -1;
	dendaId = irudiaKargatu(DENDA_IMAGE);
	irudiaMugitu(dendaId, 42, 568);
	return dendaId;
}
int JOKOA_ajusteIrudiaSortu() {
	int ajusteakId = -1;
	ajusteakId = irudiaKargatu(JOKUKO_AJUSTEAK_IMAGE);
	irudiaMugitu(ajusteakId, 40, 20);
	return ajusteakId;
}
int JOKOA_gordeIrudia() {
	int gordeId = -1;
	gordeId = irudiaKargatu(GORDE_IMAGE);
	irudiaMugitu(gordeId, 1300, 600);
	return gordeId;
}
int JOKOA_gordeKonfirmatuIrudia() {
	int gordetaId = -1;
	gordetaId = irudiaKargatu(GORDETA_IMAGE);
	irudiaMugitu(gordetaId, 464, 260);
	return gordetaId;
}
int JOKOA_diruMarkadoreaSortu() {
	int diruaId = -1;
	diruaId = irudiaKargatu(DIRU_MARKADOREA);
	irudiaMugitu(diruaId, 1180, 20);
	return diruaId;
}
int JOKOA_menuraIrudia() {
	int dendaId = -1;
	dendaId = irudiaKargatu(MENURA_IMAGE);
	irudiaMugitu(dendaId, 40, 485);
	return dendaId;
}

EDIFIZIO edifizioaKokatu(int irudia, EDIFIZIO posizioak[]) {
	int ebentu = 0, irudiaID = -1, pos = 0, i = irudia;
	int posX = -26, posY = 235;
	int kont = 0;

	pantailaGarbitu();
	irudiaID = JOKOA_Edifizioak(i);
	
	while (posizioak[pos].okupatuta == BAI) {
		if (kont < 9) {
			posX += 70;
			posY += -35;
			kont++;
		}
		else {
			posX -= 560;
			posY += 349;
			kont = 0;
		}

		pos++;
	}

	irudiaMugitu(irudiaID, posX, posY);
	irudiakMarraztu();
	pantailaBerriztu();

	do
	{
		do {
			ebentu = ebentuaJasoGertatuBada();
		} while (ebentu != TECLA_UP && ebentu != TECLA_DOWN && ebentu != TECLA_RIGHT && ebentu != TECLA_LEFT && ebentu != TECLA_RETURN);

		if (ebentu == TECLA_LEFT){
			if (pos != 0 && pos != 10 && pos != 20 && pos != 30 && pos != 40 && pos != 50 && pos != 60 && posizioak[pos - 1].okupatuta != URA && posizioak[pos - 1].okupatuta != BAI) {
				pos--;
			}
		}
		else if (ebentu == TECLA_RIGHT) {
			if (pos != 9 && pos != 19 && pos != 29 && pos != 39 && pos != 49 && pos != 59 && pos != 69 && pos != 79 && pos != 89 && pos != 99 && posizioak[pos + 1].okupatuta != URA && posizioak[pos + 1].okupatuta != BAI) {
				pos++;
			}
		}
		else if (ebentu == TECLA_DOWN) {
			if (pos < 90 && posizioak[pos + 10].okupatuta != URA && posizioak[pos + 10].okupatuta != BAI) {
				pos = pos + 10;
			}
		}
		else if (ebentu == TECLA_UP) {
			if (posizioak[pos - 10].okupatuta != URA && posizioak[pos - 10].okupatuta != BAI && pos > 9) {
				pos = pos - 10;
			}
		}

		while (posizioak[pos].okupatuta == BAI || posizioak[pos].okupatuta == URA) {
			if (ebentu == TECLA_RIGHT) {
				pos++;
			}
			else if (ebentu == TECLA_LEFT) {
				pos--;
			}
		}

		pantailaGarbitu();
		irudiaKendu(irudiaID);
		irudiaID = JOKOA_Edifizioak(i);
		irudiaMugitu(irudiaID, posizioak[pos].pos.x, posizioak[pos].pos.y);
		irudiakMarraztu();
		pantailaBerriztu();

	} while (ebentu != TECLA_RETURN);

	if (posizioak[pos].okupatuta != BAI) {
		irudiaKendu(irudiaID);
		pantailaGarbitu();
		irudiaID = JOKOA_Edifizioak(i);
		irudiaMugitu(irudiaID, posizioak[pos].pos.x, posizioak[pos].pos.y);
		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();

		posizioak[pos].okupatuta = BAI;
	}

	if (irudia == 1) { posizioak[pos].edifizio_mota = TORRE; }
	else if (irudia == 2) { posizioak[pos].edifizio_mota = DENDA; }
	else if (irudia == 3) { posizioak[pos].edifizio_mota = ELIZA; }
	else if (irudia == 4) { posizioak[pos].edifizio_mota = BLOKEA; }
	else if (irudia == 5) { posizioak[pos].edifizio_mota = GORRI; }
	else if (irudia == 6) { posizioak[pos].edifizio_mota = TXALET; }
	else if (irudia == 7) { posizioak[pos].edifizio_mota = KASINO; }
	else if (irudia == 8) { posizioak[pos].edifizio_mota = POLIZIA; }
	else if (irudia == 9) { posizioak[pos].edifizio_mota = EOLIKO; }
	else if (irudia == 10) { posizioak[pos].edifizio_mota = ECO; }
}

void okupatuakSartu() {
	posizioak[46].okupatuta = URA;
	posizioak[47].okupatuta = URA;
	posizioak[56].okupatuta = URA;
	posizioak[57].okupatuta = URA;
	posizioak[66].okupatuta = URA;
	posizioak[67].okupatuta = URA;
	posizioak[70].okupatuta = URA;
	posizioak[71].okupatuta = URA;
	posizioak[72].okupatuta = URA;
	posizioak[80].okupatuta = URA;
	posizioak[81].okupatuta = URA;
	posizioak[82].okupatuta = URA;
	posizioak[83].okupatuta = URA;
	posizioak[90].okupatuta = URA;
	posizioak[91].okupatuta = URA;
	posizioak[92].okupatuta = URA;
	posizioak[93].okupatuta = URA;
}
