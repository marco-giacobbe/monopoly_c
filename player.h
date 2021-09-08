#ifndef PLAYER_H
#define PLAYER_H

#define START_CASH 10000000

//strutture
typedef struct player {
	int id; //id giocatore
        char username[15]; //username giocatore
        int posizione; //posizione giocatore
        int soldi; //soldi giocatore
	int dadi; //true se il giocatore ha tirato i dadi
	struct listacontratti* portafoglio; //lista dei contratti del giocatore
        struct player* next; //giocatore successivo
        int prigione; //1 se si è in prigione, 0 se non lo si è, -N con N numero di indennità
} player;

struct puntatori {
        player* head; //puntatore a struct player per indicare il primo giocatore
        player* tail; //puntatore a struct player per indicare l'ultimo igiocatore
        player* current; //puntatore a struct player per indicare il player corrente
};

typedef struct puntatori player_list;

#include "contratti.h"
#include "liste_contratti.h"
#include "game.h"
#include "caselle.h"
#include "classifica.h"
#include "probabilita.h"
#include "imprevisti.h"


//funzioni giocatori
void stampa_info (player_list puntatori, posizioni* luoghi); //stampa le info di un giocatore

int verifica_saldo_giocatori (leaderboard* classifica, player_list* giocatori, int turni, int *num_player, posizioni* luoghi); //verifica il saldo di tutti i giocatori

int verifica_saldo (player_list* giocatore); //verifica il saldo del singolo giocatore

void elimina_giocatore(player_list* giocatori); //cancella un giocatore dalla struttura

void cicla_giocatore (player_list* giocatore); //passa il puntatore current al giocatore successivo

int genera_giocatori (player_list *giocatori, int *num_player); //genera la struttura dei giocatori

int legge_numero_player (void); //legge quanti saranno i giocatori

int crea_nuovo_giocatore(int counter, player_list* giocatori);

int turno_player (int turni, player_list* giocatori,int *num_player, posizioni* luoghi,probabilita* pro,imprevisti* imp, leaderboard* classifica); //inizia il turno del giocatore

int verifica_prigione (player_list* giocatori); //verifica se il giocatore è in prigione

int passa_turno (player_list* giocatori); //passa il turno al giocatore successivo

int cancella_lista_player (player_list* puntatori); //elimina tutti i giocatori a fine gioco

int fai_pagare(player_list* giocatori, int soldi); //fa pagare tutti i giocatori

int paga(player_list* giocatori, int soldi); //paga il singolo giocatore

int avanza_a(player_list* giocatori, int posizione); //il giocatore avanza in una casella specifica

int avanza_di(player_list* giocatori, int posizione); //il giocatore avanza di N caselle

void indennita_prigione (player_list* giocatori); //da l'indennità al giocatore

void prigione(player_list* giocatori); //inserisce il giocatore in prigione

void paga_aereoporto (posizioni* luoghi, player_list* giocatore); //paga l'utente proprietario dell'aereoporto

void paga_societa (posizioni* luoghi, player_list* giocatore, int dado); //paga l'utente proprietario della società

void paga_terreno(posizioni* luoghi, player_list* giocatore); //paga l'utente proprietario del terreno

int tira_dado (player_list* giocatori, int turni, int num_player, posizioni* luoghi, probabilita* pro, imprevisti* imp); //tira il dado e aggiorna la posizione del giocatore

#endif
