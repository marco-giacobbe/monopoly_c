#ifndef PROBABILITA_H
#define PROBABILITA_H

struct probabilita{
	char descrizione[150]; //descrizione della probabilità
	int guadagna; //cifra che il giocatore guadagna dal gioco
	int perdono; //cifra che il giocatore guadagna da ogni altro giocatore
	int posizione; //se la probabilità ti porta in una casella indica il numero di essa. -1 se non la indica
	bool avanza_a; //true se la propabilità ti fa avanzare in una posizione definita, false se ti fa avanzare di N posti o se non fa avanzare
	bool prigione; //true se fa uscire di prigione, false in caso contrario
};

typedef struct probabilita probabilita;

#include "player.h"

probabilita* inizializza_probabilita (void); //genera tutte le probabilità

int pesca_probabilita(player_list* giocatore, probabilita* pro, int num_player); //pesca una probabilità

#endif
