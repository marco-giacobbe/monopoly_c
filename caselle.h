#ifndef CASELLE_H
#define CASELLE_H

struct posizione{
        char nome[35]; //nome luogo
        int id; //posizione del luogo
        int type; //tipo di casella
        int paga; //pagamento al passaggio (tassa)
        int guadagna; //guadagno al passaggio
        bool prigione; //true se si va in prigione
        bool probabilita; //true se si pesca una probabilità
        bool imprevisto; //true se si pesca un imprevisto
        bool contratto; //true se si tratta di un contratto
        int proprietario; //id proprietario (0 se non ha un proprietario)
	int affitto; //pagamento affitto
	int compra; //prezzo per acquistare il contratto
	int costruisci; //prezzo per acquistare una casa
	int home; //numero delle case
	bool hotel; //true se vi è un hotel
};

typedef struct posizione posizioni;

#include "player.h"
#include "probabilita.h"
#include "imprevisti.h"

posizioni* inizializza_caselle (void); //genera le caselle

void verifica_casella (int *turni, int num_player,player_list* giocatori,posizioni* luoghi, probabilita* pro, imprevisti* imp, int dado); //verifica su che casella si trova il giocatore

//funzioni home-hotel
int hotel (player_list* giocatori, posizioni* luoghi); //comando /hotel

int stampa_contratti_hotel (int contratti[], player_list* giocatori, posizioni* luoghi); //stampa i contratti edificabili da hotel

int home (player_list* giocatori, posizioni* luoghi); //comando /home

int stampa_contratti_home(int contratti[], player_list* giocatori, posizioni* luoghi); //stampa i contratti edificabili da case

int scelta_contratto(int contratti[], posizioni* luoghi, player_list* giocatori, int i); //fa scegliere il contratto su cui costruire al giocatore

void costruisci_hotel (int scelta, posizioni* luoghi,player_list* giocatore); //costruisce l'hotel

void costruisci_home (int scelta, posizioni* luoghi,player_list* giocatore); //costruisce la casa


#endif
