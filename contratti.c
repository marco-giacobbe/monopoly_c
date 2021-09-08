#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "contratti.h"

void menu_contratto (posizioni* luoghi, player_list* giocatore,int dado) {
	if (!luoghi[giocatore->current->posizione].proprietario) { //verifica se il contratto è acquistabile
		menu_acquisto(luoghi, giocatore);
	}
	else if (luoghi[giocatore->current->posizione].proprietario != giocatore->current->id){ //verifica se il contratto appartiene ad un giocatore
		if (!luoghi[giocatore->current->posizione].type) { //verifica se si tratta di un aereoporto
			paga_aereoporto(luoghi, giocatore);
		}
		else if (luoghi[giocatore->current->posizione].type == 9) { //verifica se si tratta di una società
			paga_societa(luoghi, giocatore,dado);
		}
		else {
			paga_terreno(luoghi, giocatore);
                }
	}
}

int menu_acquisto(posizioni* luoghi, player_list* giocatore) {
    	if (giocatore->current->soldi < luoghi[giocatore->current->posizione].compra) { //verifica se il giocatore ha il budget per acquistare
        	printf("Non hai abbastanza soldi per comprare il contratto\n\n");
            	return -1;
	}
	printf("vuoi acquistare %s?\n", luoghi[giocatore->current->posizione].nome);
	stampa_info_contratto(luoghi, giocatore);
	printf("Premi 'si' per acquistare, 'no' per proseguire: ");
	char scelta[100];
     	do {
        	scanf(" %s",scelta);
         	rem_case_sensitive(scelta);
    	} while (strcmp("si",scelta) !=0 && strcmp("no",scelta) != 0);
    	if (!strcmp("si",scelta)) {
 	     	clear();
    		printf("Hai acquistato %s\n\n", luoghi[giocatore->current->posizione].nome);
        	if (acquisto_contratto(luoghi, giocatore)) {
			return 1; //torna 1 in caso di errore
		}
	}
	clear();
	return 0;
}

void stampa_info_contratto (posizioni* luoghi, player_list* giocatore) {
	if (!luoghi[giocatore->current->posizione].type) { //stampa le info di un aereoporto
		printf("costo: %d\n\n",luoghi[giocatore->current->posizione].compra);
		printf("rendita con 1 aereoporto: %d\n",luoghi[giocatore->current->posizione].affitto);
                printf("rendita con 2 aereoporti: %d\n",luoghi[giocatore->current->posizione].affitto*2);
                printf("rendita con 3 aereoporti: %d\n",luoghi[giocatore->current->posizione].affitto*4);
                printf("rendita con 4 aereoporti: %d\n",luoghi[giocatore->current->posizione].affitto*8);
		return;
	}
	else if (luoghi[giocatore->current->posizione].type == 9) { //stampa le info di una società
        	printf("rendita con 1 società: 40.000xNumero dadi\nrendita con 2 società: 100.000xNumero dadi\n\n");
        	return;
    	}
	//stampa le info di un terreno
	printf("costo: %d\n\n",luoghi[giocatore->current->posizione].compra);
	printf("rendita solo terreno: %d\n",luoghi[giocatore->current->posizione].affitto);
	printf("rendita con 1 casa: %d\n",(luoghi[giocatore->current->posizione].affitto)*5);
	printf("rendita con 2 case: %d\n",(luoghi[giocatore->current->posizione].affitto)*12);
	printf("rendita con 3 case: %d\n",(luoghi[giocatore->current->posizione].affitto)*37);
	printf("rendita con 4 case: %d\n",(luoghi[giocatore->current->posizione].affitto)*56);
	printf("rendita con albergo: %d\n",(luoghi[giocatore->current->posizione].affitto)*75);
	printf("\nCosti di costruzione: %d\n",luoghi[giocatore->current->posizione].costruisci);
	return;
}

int acquisto_contratto (posizioni* luoghi, player_list* giocatore) {
	luoghi[giocatore->current->posizione].proprietario = giocatore->current->id; //la label del luogo sarà popolata dall'id del giocatore
	giocatore->current->soldi -= luoghi[giocatore->current->posizione].compra; //vengono presi i soldi del giocatore
	lista_contratti temp = giocatore->current->portafoglio; //puntatore alle liste di contratti
	scorri_liste(luoghi[giocatore->current->posizione].type, &temp);
	contratto new_contratto = (contratto) malloc(sizeof(struct contratto));
	if (new_contratto == NULL) {
		return 1;
	}
	//popolo il nuovo contratto
	new_contratto->id = giocatore->current->posizione;
	strcpy(new_contratto->nome, luoghi[giocatore->current->posizione].nome);
	new_contratto->home = 0;
	new_contratto->hotel = 0;
	new_contratto->next = NULL;
	if (incrementa_num_contratti(temp)==1) { //verifica se è il primo contratto da inserire
		temp->contratti = new_contratto; //il contratto sarà il primo della lista
		return 0;
	}
	struct contratto* temp_contratto = temp->contratti; //puntatore ai contratti
	while (temp_contratto->next != NULL) {
		temp_contratto = temp_contratto->next;
	}
	temp_contratto->next = new_contratto;
	return 0;
}

void stampa_contratti (lista_contratti lista) {
	struct contratto* temp_contratto = lista->contratti;
	while (temp_contratto != NULL) {
		if (lista->type == 0 || lista->type == 9) { //se i contratti sono aereoporti o società non deve stampare la dicitura delle case e hotel
			printf("\t%s (%d)\n", temp_contratto->nome, temp_contratto->id);
		}
		else {
			printf("\t%s (%d) case:%d    hotel:%d\n",temp_contratto->nome, temp_contratto->id, temp_contratto->home, temp_contratto->hotel);
		}
		temp_contratto = temp_contratto->next;
	}
	printf("\n");
	return;
}

//rende nuovamente acquistabili i contratti del giocatore eliminato
void libera_contratti(player_list* giocatore, posizioni* luoghi) {
        lista_contratti temp_lista = giocatore->current->portafoglio;
	for (int k=0;k<10;k++) {
		scorri_liste(k,&temp_lista);
                contratto temp_contratto=temp_lista->contratti;
                while (temp_contratto != NULL) {
                        luoghi[temp_contratto->id].proprietario = 0;
                        temp_contratto = temp_contratto->next;
                }
        }
	return;
}

//libera la memoria occupata dai contratti all'uscita del gioco
void cancella_contratti (lista_contratti list) { 
	contratto contratti = list->contratti; //primo puntatore per scorrere tra i contratti
     	contratto contratti2 = contratti; //secondo puntatore per scorrere tra i contratti
	while (contratti != NULL) {
             	contratti2 = contratti2->next;
              	free(contratti);
        	contratti = contratti2;
	}
	return;
}


