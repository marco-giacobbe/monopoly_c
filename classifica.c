#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "classifica.h"


int push_classifica(leaderboard* classifica, player_list* giocatore, int turno, posizioni* luoghi) { //inserisce un player nella classifica una volta che perde tutti i soldi
	leaderboard new_node = (leaderboard)malloc(sizeof(struct nodo_pila));
	if (new_node == NULL) {
		return 1;
	}
	//popolo il nuovo nodo
	strcpy(new_node->username, giocatore->current->username);
	new_node->turno = turno;
	new_node->next = NULL;
	new_node->soldi = giocatore->current->soldi;
	if (*classifica != NULL) {
		new_node->next = *classifica; //next punterà al giocatore precedente
	}
	*classifica = new_node; //la classifica punterà all'ultimo giocatore inserito
	libera_contratti(giocatore, luoghi);
	cancella_liste_contratti(giocatore);
	return 0;
}

void stampa_classifica(leaderboard* classifica) {
	//clear();
	int i=1; //contatore dei giocatori in classifica
	leaderboard temp = *classifica;
	while (temp != NULL) {
		switch (i) {
			case 1:
				printf("Primo classificato: %s con %d€ (turni giocati: %d)\n\n",temp->username, temp->soldi, temp->turno);
				break;
			case 2:
				printf("Secondo classificato: %s con %d€ (turni giocati: %d)\n\n",temp->username, temp->soldi, temp->turno);
				break;
			case 3:
				printf("Terzo classificato: %s con %d€ (turni giocati: %d)\n\n",temp->username, temp->soldi, temp->turno);
				break;
			case 4:
				printf("Quarto classificato: %s con %d€ (turni giocati: %d)\n\n",temp->username, temp->soldi, temp->turno);
				break;
			default:
				break;
		}
		temp = temp->next;
		i++;
	}
	return;
}

void cancella_classifica (leaderboard* classifica) {
	leaderboard temp = *classifica; //puntatore temporale ai nodi della classifica
	int i=0;
	while (*classifica != NULL) {
		temp = temp->next;
		free(*classifica);
		*classifica = temp;
		i++;
	}
	return;
}
