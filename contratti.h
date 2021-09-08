#ifndef CONTRATTI_H
#define CONTRATTI_H

struct contratto {
	int id; //id del contratto
	char nome[35]; 
	int home; //numero di case
	int hotel; //1 se è presente l'hotel, 0 altrimenti
	struct contratto *next; //puntatore al prossimo contratto
};

typedef struct contratto* contratto;

#include "liste_contratti.h"
#include "caselle.h"


//funzioni contratti
void menu_contratto (posizioni* luoghi, player_list* giocatore, int dado); //verifica se il contratto su cui si trova il giocatore appartiene a qualcuno o è acquistabile

int menu_acquisto(posizioni* luoghi, player_list* giocatore); //permette di effettuare un acquisto al giocatore

void paga_aereoporto (posizioni* luoghi, player_list* giocatore); //paga l'utente proprietario dell'aereoporto

void paga_societa (posizioni* luoghi, player_list* giocatore, int dado); //paga l'utente proprietario della società

void paga_terreno(posizioni* luoghi, player_list* giocatore); //paga l'utente proprietario del terreno

void stampa_info_contratto (posizioni* luoghi, player_list* giocatore); //stampa le informazioni di un contratto

int acquisto_contratto (posizioni* luoghi, player_list* giocatore); //funzione per aggiungere il contratto al portafoglio del giocatore

void stampa_contratti (lista_contratti lista); //stampa i contratti posseduti

void libera_contratti(player_list* giocatore, posizioni* luoghi); //rende i contratti del giocatore eliminato nuovamente acquistabili

void cancella_contratti (lista_contratti list); //libera lo spazio dei contratti

#endif
