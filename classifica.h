#ifndef CLASSIFICA_H
#define CLASSIFICA_H


struct nodo_pila {
	char username[15];
	int turno; //turni giocati dal giocatore
	int soldi; //soldi con cui un giocatore finisce di giocare
	struct nodo_pila* next; //puntatore al nodo successivo
};

typedef struct nodo_pila* leaderboard;

#include "player.h"

//funzioni classifica
int push_classifica(leaderboard* classifica, player_list* giocatore, int turno, posizioni* luoghi); //inserisce il giocatore nella classifica

void stampa_classifica(leaderboard* classifica); //stampa la classifica

void cancella_classifica (leaderboard* classifica); //libera la memoria occupata dalla classifica

#endif
