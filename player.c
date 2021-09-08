#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "player.h"

//funzioni player
void stampa_info (player_list puntatori, posizioni* luoghi) {
	printf("%s\n%d€\nTi trovi su:%s(%d)\n\n\n",puntatori.current->username, puntatori.current->soldi, luoghi[puntatori.current->posizione].nome, (puntatori.current->posizione)+1);
}


int verifica_saldo_giocatori (leaderboard* classifica, player_list* giocatori,int turni, int *num_player,posizioni* luoghi) { //verifica che tutti i giocatori abbiano un saldo positivo e in caso contrario li elimina
	int i;
	int counter = *num_player;
	for (i=0;i<counter;i++) {
		if (verifica_saldo(giocatori)) {
			if (push_classifica(classifica, giocatori, turni, luoghi)) {
				return 1;
			}; //inserisce il giocatore eliminato nella classifica
			elimina_giocatore(giocatori); //il giocatore viene eliminato dalla struttura
			player* temp = giocatori->current;
			cicla_giocatore(giocatori);
			free(temp); //si libera lo spazio di temp
			*num_player -=1; //il numero dei giocatori viene decrementato
		}
		else {
			cicla_giocatore(giocatori);
		}
	}
	return 0; //torniamo 1 passa al giocatore successivo senza eliminare nessuno

}


int verifica_saldo(player_list* giocatore) {
	if (giocatore->current->soldi < 0) {
		return 1; //torna 1 se il giocatore ha finito i soldi
	}
	return 0; //torna 0 se il giocatore non ha finito i soldi
}


void elimina_giocatore(player_list* giocatori) {
	struct player* temp = giocatori->head; //puntatore temporale coincidente con head
	while (temp->next != giocatori->current) { //cicla finchè il puntatore temporale non arriva al precedente del giocatore da eliminare
		temp = temp->next;
	}
	temp->next = giocatori->current->next; //fa coincidere il precedente di current al successivo
	if (giocatori->current == giocatori->head) { //se viene eliminato il giocatore puntato da head, head dovrà puntare al giocatore successivo
		giocatori->head = giocatori->head->next; //head punterà il nuovo primo giocatore
	}
	else if (giocatori->current == giocatori->tail) { //se viene eliminato il giocatore puntato da tail, tail dovrà puntare al giocatore precedente
		while (giocatori->tail != temp) {
			giocatori->tail = giocatori->tail->next;
		}
	}
	printf("%s è stato eliminato\n\n", giocatori->current->username);
}


void cicla_giocatore (player_list* giocatore) {
	giocatore->current = giocatore->current->next;;
}


int genera_giocatori(player_list* giocatori, int *num_player) {
	*num_player = legge_numero_player();
	int i;
	for (i=0;i<*num_player;i++) { //cicla finchè non vengono creati tutti i giocatori
		if (crea_nuovo_giocatore(i, giocatori) == 1 || crea_lista_contratti(giocatori)==1) {
			return 1;
		}
	}
	giocatori->current = giocatori->current->next;
	clear();
	return 0; //ritorna 0 se non vi sono errori
}

int legge_numero_player (void) {
	int num;
	do {
       	printf("Player (2-4 giocatori): "); //chiede quanti giocatori vogliono partecipare
                scanf("%d",&num); //legge il numero di giocatori e lo salva nella variabile num_player
        }
        while (num>4 || num<2); //cicla finchè non si inserisce il numero di giocatori corretti
        clear();
	return num;
}

int crea_nuovo_giocatore(int counter, player_list* giocatori) {
	char username[15];
	printf("Inserisci l'username del player %d: ",counter+1); //chiede il nome dell'utente i
       	scanf("%s",username); //legge il nome
       	struct player* new_player = NULL; //creiamo un nuovo giocatore
     	new_player = (struct player* )malloc(sizeof(struct player));
     	if (new_player == NULL ) {
     		return 1; //torniamo 1 se il sistema non da la memoria
      	}
     	strcpy(new_player->username, username);
      	new_player->id = counter+1;
       	new_player->posizione = 0; //il giocatore partirà dalla prima casella
      	new_player->soldi = START_CASH; //il giocatore dovrà partire con un budget base
        new_player->portafoglio = NULL; //all'inizio il portafoglio dei contratti sarà vuoto
        new_player->dadi = 0;
        new_player->next = giocatori->head; //inizialmente non avrà nessun successivo
        new_player->prigione = 0;
      	if (!counter) { //se è il primo giocatore
          	giocatori->head = new_player; //head punterà a lui essendo il primo
                giocatori->tail = new_player; //tail punterà a lui essendo l'ultimo
 	}
       	else {
            	struct player* temp = giocatori->tail; //creiamo un puntatore d'appoggio e lo facciamo coincidere con l'ultimo giocatore
       	       	temp->next=new_player; //facciamo puntare il vecchio ultimo giocatore al nuovo ultimo
                giocatori->tail = new_player; //tail dovrà puntare al nuovo ultimo
	}
	giocatori->current = new_player;
}

int turno_player (int turni, player_list* giocatori,int *num_player, posizioni* luoghi,probabilita* pro,imprevisti* imp,leaderboard* classifica) {
	int scelta=-1;
	int dado;
	if (verifica_prigione(giocatori)) { //verifica se il giocatore si trova in prigione
		printf("%s non può tirare i dadi perchè è in prigione\n\n",giocatori->current->username);
		cicla_giocatore(giocatori);
		return 0;
	}
	while (true) {
		printf("Turno: %d\n",turni);
		stampa_info(*giocatori,luoghi);
		scelta = menu();
		switch (scelta) {
			case 0: //dadi
				clear();
				tira_dado(giocatori, turni, *num_player, luoghi, pro, imp);
				break;
			case 1: //contratti
				clear();
				stampa_liste_contratti(giocatori);
				break;
			case 2: //home
				clear();
				home(giocatori, luoghi);
				break;
			case 3: //hotel
				clear();
				hotel(giocatori, luoghi);
				break;
			case 4: //passa
				clear();
				if (passa_turno(giocatori)) {
					break;
				}
				verifica_saldo_giocatori(classifica, giocatori, turni, num_player, luoghi);
				return 0;
			case 5: //quit
				salva_caricamento(turni,*num_player,classifica, giocatori);
				return 1;
		}
	}
}

int verifica_prigione (player_list* giocatori) {
	if (giocatori->current->prigione == 1) {
		giocatori->current->prigione -=1; //finito il turno il giocatore esce dalla prigione
		return 1; //torna 1 se è in prigione
	}
	return 0; //0 se non lo è
}

int passa_turno (player_list* giocatori) {
	if (giocatori->current->dadi) { //verifica se il giocatore ha lanciato i dadi;
            	giocatori->current->dadi = 0;
            	cicla_giocatore(giocatori); 
                return 0;
       	}
        printf("Non puoi saltare il turno senza tirare i dadi\n\n");
	return 1; //torniamo 1 se il player non può saltare il turno
}

int cancella_lista_player (player_list* puntatori) {
	puntatori->current = puntatori->head;
	puntatori->tail->next = NULL;
	while (puntatori->current != NULL) {
		puntatori->head = puntatori->head->next;
		cancella_liste_contratti(puntatori);
		free(puntatori->current);
		puntatori->current = puntatori->head;
	}
	return 0;
}

int fai_pagare(player_list* giocatori, int soldi) {
        struct player* temp = giocatori->current;
        do {
                temp = temp->next;
                temp ->soldi -= soldi;
                giocatori->current->soldi += soldi;
        } while (giocatori->current != temp);
	return soldi;
}

int paga(player_list* giocatori, int soldi) {
        giocatori->current->soldi -= soldi;
	return soldi;
}

int avanza_a(player_list* giocatori, int posizione) {
        giocatori->current->posizione = posizione;
	return posizione;
}

int avanza_di(player_list* giocatori, int posizione) {
        giocatori->current->posizione = giocatori->current->posizione + posizione;
	return posizione;
}

void indennita_prigione (player_list* giocatori) {
        giocatori->current->prigione -= 1;
}

void prigione(player_list* giocatori) {
        giocatori->current->prigione += 1;
}

void paga_aereoporto (posizioni* luoghi, player_list* giocatore) {
       	struct player* temp = giocatore->head; //creiamo un puntatore temporale
     	while (temp->id != luoghi[giocatore->current->posizione].proprietario) {
        	temp = temp->next; //facciamo puntare il puntatore al giocatore proprietario
     	}
     	switch (verifica_num_contratti(0,temp)) {
           	case 1:
			giocatore->current->soldi -= luoghi[giocatore->current->posizione].affitto;
			temp->soldi += luoghi[giocatore->current->posizione].affitto;
			printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto, temp->username);
                       break;
            	case 2:
                        giocatore->current->soldi -= (luoghi[giocatore->current->posizione].affitto)*2;
                        temp->soldi += (luoghi[giocatore->current->posizione].affitto)*2;
                        printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto*2, temp->username);
    	                break;
             	case 3:
                   	giocatore->current->soldi -= (luoghi[giocatore->current->posizione].affitto)*4;
                        temp->soldi += (luoghi[giocatore->current->posizione].affitto)*4;
                        printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto*4, temp->username);
    	                break;
       		case 4:
            		giocatore->current->soldi -= (luoghi[giocatore->current->posizione].affitto)*8;
                        temp->soldi += (luoghi[giocatore->current->posizione].affitto)*8;
                        printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto*8, temp->username);
           		break;
    	}
	return;
}

void paga_societa (posizioni* luoghi, player_list* giocatore, int dado) {
	struct player* temp_player = giocatore->head; //puntatore temporale per i giocatori
	while (temp_player->id != luoghi[giocatore->current->posizione].proprietario) {
		temp_player = temp_player->next; //il puntatore punta al giocatore proprietario
	}
	switch(verifica_num_contratti(9, temp_player)) {
		case 1:
			giocatore->current->soldi -= dado*40000;
			temp_player->soldi += dado*40000;
			printf("Hai pagato %d a %s\n", dado*40000, temp_player->username);
			break;
		case 2:
			giocatore->current->soldi -= dado*100000;
                        temp_player->soldi += dado*100000;
                        printf("Hai pagato %d a %s\n", dado*100000, temp_player->username);
			break;
	}
	return;
}

void paga_terreno(posizioni* luoghi, player_list* giocatore) {
        struct player* temp = giocatore->head; //puntatore temporale per i giocatori
        while (temp->id != luoghi[giocatore->current->posizione].proprietario) {
                temp = temp->next; //il puntatore punta al giocatore proprietario
        }
	if (luoghi[giocatore->current->posizione].hotel) {
		giocatore->current->soldi -= luoghi[giocatore->current->posizione].affitto*75;
		temp->soldi += luoghi[giocatore->current->posizione].affitto*75;
		printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto*75,temp->username);
		return;
	}
	switch (luoghi[giocatore->current->posizione].home) {
		case 0:
			giocatore->current->soldi -= luoghi[giocatore->current->posizione].affitto;
        	        temp->soldi += luoghi[giocatore->current->posizione].affitto;
	                printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto,temp->username);
			break;
		case 1:
                        giocatore->current->soldi -= luoghi[giocatore->current->posizione].affitto*5;
                        temp->soldi += luoghi[giocatore->current->posizione].affitto*5;
                        printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto*5,temp->username);
			break;
		case 2:
                        giocatore->current->soldi -= luoghi[giocatore->current->posizione].affitto*12;
                        temp->soldi += luoghi[giocatore->current->posizione].affitto*12;
                        printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto*12,temp->username);
			break;
		case 3:
			giocatore->current->soldi -= luoghi[giocatore->current->posizione].affitto*37;
                        temp->soldi += luoghi[giocatore->current->posizione].affitto*37;
                        printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto*37,temp->username);
			break;
		case 4:
                        giocatore->current->soldi -= luoghi[giocatore->current->posizione].affitto*56;
                        temp->soldi += luoghi[giocatore->current->posizione].affitto*56;
                        printf("Hai pagato %d a %s\n",luoghi[giocatore->current->posizione].affitto*56,temp->username);
			break;
	}
	return;
}

int tira_dado (player_list* giocatori, int turni, int num_player, posizioni* luoghi, probabilita* pro, imprevisti* imp) {
        if (giocatori->current->dadi) {
                printf("Puoi tirare i dadi solo una volta\n\n");
                return 0;
        }
        int res = rand()%11+2;
        clear();
        printf("È uscito il numero: %d\n\n",res); //stampa il numero uscito
        int pos_0 = giocatori->current->posizione; //posizione prima di tirare i dadi
        (giocatori->current->posizione) = ((giocatori->current->posizione)+res)%40;
        if (pos_0 > giocatori->current->posizione) { //verifica se si passa dal via
        	giocatori->current->soldi += 2000000;
        }
        giocatori->current->dadi = 1;
        pos_0=giocatori->current->posizione; //posizione prima di verificare la casella (se la posizione del giocatore cambia dopo verifica_casella() bisogna fare un altro controllo)
        verifica_casella(&turni, num_player, giocatori, luoghi, pro, imp, res);
        if (pos_0 != giocatori->current->posizione) {
                verifica_casella(&turni, num_player, giocatori, luoghi, pro, imp,res);
        }
        return res;
}

