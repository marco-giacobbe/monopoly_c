#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "contratti.h"
#include "liste_contratti.h"
#include "caselle.h"
#include "classifica.h"
#include "probabilita.h"
#include "imprevisti.h"
#include "player.h"
#include "game.h"




int main () {
	srand(time(0));
        int num_player, turni=1;
        player_list giocatori;
        posizioni* luoghi = inizializza_caselle();
        probabilita* pro = inizializza_probabilita();
	imprevisti* imp = inizializza_imprevisti();
	if (luoghi == NULL || pro == NULL || imp == NULL) {
		return 1;
	}
	leaderboard classifica = NULL;
	if (!controlla_caricamenti(&num_player, &turni, &classifica, luoghi,&giocatori)) { //se coontrolla_caricamento==0 deve iniziare un nuovo gioco
		genera_giocatori(&giocatori, &num_player);
	}
	while (num_player > 1) { //il gioco continua finchè il numero dei giocatori è maggiore di 1
		if (turno_player(turni,&giocatori,&num_player,luoghi, pro, imp, &classifica)) {
			quit_game(&giocatori); //o finchè non viene eseguito il comando /quit
			break;
		};
		turni++;
	}
	if (num_player == 1) { //la classifica verrà elaborata solo se il gioco è terminato
		exit_game(&classifica, &giocatori, turni, luoghi);
	}
	cancella_classifica(&classifica);
	free(luoghi);
	free(pro);
	free(imp);
}
