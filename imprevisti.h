#ifndef IMPREVISTI_H
#define IMPREVISTI_H

struct imprevisti {
	char descrizione[150]; //descrizione dell'imprevisto
	int paga; //prezzo da pagare
	int posizione; //se la probabilità ti porta in una casella indica il numero di essa. -1 se non la indica
	bool retrocedi_a; //true se l'imprevisto ti fa precedere in una posizione definita, false se ti fa retrocedere di N posti o se non fa retrocedere
	bool prigione; //true se ti porta in prigione
};

typedef struct imprevisti imprevisti;

#include "player.h"

imprevisti* inizializza_imprevisti (void); //genera tutti gli imprevisti

int pesca_imprevisto(player_list* giocatore, imprevisti* imp, int num_player); //pesca un imprevisto

#endif
