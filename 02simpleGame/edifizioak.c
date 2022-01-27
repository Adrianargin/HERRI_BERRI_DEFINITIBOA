#include "edifizioak.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

EDIFIZIO posizioa(int i) {
	int ebentu = 0, n = 0, bert = 0, pos = 1;

	posizioak[0].pos.x = -26;
	posizioak[0].pos.y = 235;

	while (bert < 10) {
		n = 0;
		while (n < 9) {
			posizioak[pos].pos.x = posizioak[pos - 1].pos.x + 70;
			posizioak[pos].pos.y = posizioak[pos - 1].pos.y - 35;
			pos++;
			n++;
		}

		posizioak[pos].pos.x = posizioak[pos - 1].pos.x - 560;
		posizioak[pos].pos.y = posizioak[pos - 1].pos.y + 349;
		pos++;
		bert++;
	}

	return posizioak[i];
}