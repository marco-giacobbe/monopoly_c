#ifndef LISTE_CONTRATTI_H
#define LISTE_CONTRATTI_H 

struct listacontratti {
        int type; //tipo di contratto
        int num_contratti; //numero di contratti che un tipo di casella possiede
        int num_contratti_posseduti; //numero di contratti posseduti di quella lista
        struct listacontratti *next; //puntatore alla prossima lista
        struct contratto *contratti; //puntatori ai contratti
};

typedef struct listacontratti* lista_contratti;

#include "caselle.h"
#include "player.h"

int crea_lista_contratti(player_list* giocatore); //Crea la lista dei contratti dei giocatori

void stampa_liste_contratti (player_list* giocatori); //stampa le liste di contratti

void cancella_liste_contratti (player_list* giocatore); //libera lo spazio dei contratti

int verifica_num_contratti(int type,player* giocatore); //verifica il numero dei contratti posseduti

int scorri_liste(int type, lista_contratti* lista); //scorre finchè non raggiunge la lista indicata da type

int incrementa_num_contratti(lista_contratti lista); //incrementa il numero di contratti nella lista
#endif

