#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "probabilita.h"

//funzioni probabilità
probabilita* inizializza_probabilita (void) {
	probabilita* pro = (probabilita* )malloc(sizeof(struct probabilita)*10); //puntatore a probabilità
	if (pro == NULL) {
		return NULL;
	}
	//inizializza tutte le probabilità
	{
		strcpy (pro[0].descrizione, "Vincete un reality show. Incassate 100k");
		pro[0].guadagna = 100000;
		pro[0].perdono = 0;
		pro[0].posizione = -1;
		pro[0].avanza_a = false;
		pro[0].prigione = false;
	}
	{
		strcpy (pro[1].descrizione, "Ereditate 1M");
		pro[1].guadagna = 1000000;
		pro[1].perdono = 0;
		pro[1].posizione = -1;
		pro[1].avanza_a = false;
		pro[1].prigione = false;
	}
	{
		strcpy (pro[2].descrizione, "La vostra società decolla. Incassate 2M");
		pro[2].guadagna = 2000000;
		pro[2].perdono = 0;
		pro[2].posizione = -1;
		pro[2].avanza_a = false;
		pro[2].prigione = false;
	}
	{
		strcpy (pro[3].descrizione, "Affittate la casa ad alcuni colleghi. Incassate 100k da ogni giocatore");
		pro[3].guadagna = 100000;
		pro[3].perdono = 100000;
		pro[3].posizione = -1;
		pro[3].avanza_a = false;
		pro[3].prigione = false;
	}
	{
		strcpy (pro[4].descrizione, "Avanzate fino al via");
		pro[4].guadagna = 2000000;
		pro[4].perdono = 0;
		pro[4].posizione = 0;
		pro[4].avanza_a = true;
		pro[4].prigione = false;
	}
	{
		strcpy (pro[5].descrizione, "Ottenete un'indennità dalla prigione");
		pro[5].guadagna = 0;
		pro[5].perdono = 0;
		pro[5].posizione = -1;
		pro[5].avanza_a = false;
		pro[5].prigione = true;
	}
	{
		strcpy (pro[6].descrizione, "Avete vinto il primo premio della lotteria. Andate a Milano e ritirate 1M");
		pro[6].guadagna = 1000000;
		pro[6].perdono = 0;
		pro[6].posizione = 13;
		pro[6].avanza_a = true;
		pro[6].prigione = false;
	}
	{
		strcpy (pro[7].descrizione, "Ricevete un rimborso su alcune tasse. Incassate 500k");
		pro[7].guadagna = 500000;
		pro[7].perdono = 0;
		pro[7].posizione = -1;
		pro[7].avanza_a = false;
		pro[7].prigione = false;
	}
	{
		strcpy (pro[8].descrizione, "Un gentile signore vi offre un passaggio. Avanzate di 2 caselle");
		pro[8].guadagna = 0;
		pro[8].perdono = 0;
		pro[8].posizione = 2;
		pro[8].avanza_a = false;
		pro[8].prigione = false;
	}
	{
		strcpy (pro[9].descrizione, "Vi regalano un biglietto del bus. Avanzate di 1 caselle");
		pro[9].guadagna = 0;
		pro[9].perdono = 0;
		pro[9].posizione = 1;
		pro[9].avanza_a = false;
		pro[9].prigione = false;
	}
	return pro;
}

int pesca_probabilita(player_list* giocatori, probabilita* pro, int num_player) {
	int res = rand()%9+1; //estrae una probabilità random
	printf("Probabilità\n");
	printf("%s\n\n", pro[res].descrizione); //stampa la descrizione
	giocatori->current->soldi += pro[res].guadagna;
	if (pro[res].perdono != 0) { //verifica se gli altri giocatori devono pagare
		fai_pagare(giocatori, pro[res].perdono);
	}
	if (pro[res].posizione != -1) { 
		if (pro[res].avanza_a) { //se avanza_a == 1 significa che il giocatore deve avanzare in una specifica casella
			avanza_a(giocatori, pro[res].posizione);
		}
		else { //se != 1 il giocatore deve avanzare di n caselle
			avanza_di(giocatori, pro[res].posizione);
		}
	}
	if (pro[res].prigione) {
		indennita_prigione(giocatori);
	}
	return res;

}
