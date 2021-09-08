#ifndef GAME_H
#define GAME_H

#include "classifica.h"
#include "caselle.h"
#include "player.h"
#include "probabilita.h"
#include "imprevisti.h"

//funzioni caricamento
int controlla_caricamenti (int *num_player, int *turni, leaderboard* classifica, posizioni* luoghi, player_list* giocatore); //verifica se c'è un caricamento

int carica_info (FILE *fp, int *turni, int *num_player); //carica il numero del turno, il numero dei giocatori e l'id del giocatore current

int carica_classifica(leaderboard* classifica); //carica la struttura classifica

int carica_giocatori(player_list* giocatore, posizioni* luoghi); //carica la struttura giocatori

int carica_contratti (FILE *fp, player_list* giocatore, posizioni* luoghi); //aggiunge i contratti ai giocatori

int crea_lista_contratti(player_list* giocatore); //Crea la lista dei contratti dei giocatori

int salva_caricamento (int turni, int num_player, leaderboard* classifica, player_list* giocatore); //chiama le funzioni per salvare il gioco

int salva_info(int turni, int num_player, player_list* giocatore); //salva il numero del turno, il numero dei giocatori e l'id del giocatore current

int salva_classifica(leaderboard* classifica); //salva la struttura classifica

int salva_player(player_list* giocatori); //salva la struttura dei giocatori

void salva_contratti(FILE *fp, player_list* giocatori); //salva i contratti

void remove_file(void); //cancella i file .txt

//funzioni varie 
int menu (void); //apre il menù

void clear (void); //pulisce lo schermo

int rem_case_sensitive(char* text); //rimuove il case sensitive

int quit_game(player_list* giocatori); //esce dal gioco se il giocatore ha usato il comando /quit

int exit_game(leaderboard* classifica, player_list* giocatori, int turni, posizioni* luoghi); //esce se si finisce la partita 
#endif
