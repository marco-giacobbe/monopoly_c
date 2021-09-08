#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "liste_contratti.h"

int crea_lista_contratti(player_list* giocatore) {
        int i;
        lista_contratti temp = NULL;
        for (i=0;i<10;i++) {
                lista_contratti new_list = (lista_contratti) malloc(sizeof(struct listacontratti)); //nuova lista
                if (new_list == NULL) {
                        return 1;
                }
                //popolo la lista
                new_list->type = i;
                new_list->next = NULL;
                new_list->contratti = NULL;
                new_list->num_contratti_posseduti = 0;
                //in base al tipo di contratto definisco il numero di contratti esistenti
                switch (i) {
                        case 0: 
                                new_list->num_contratti=4;
                                break;
                        case 1: 
                        case 8:
                        case 9:
                                new_list->num_contratti=2;
                                break;
                        default:
                                new_list->num_contratti=3;
                                break;
                }
                if (!i) { //se è la prima lista il puntatore portafoglio punterà ad essa
                        giocatore->current->portafoglio = new_list;
                }
                else {
                        temp->next = new_list;
                }
                temp = new_list;
        }
        return 0;
}

void stampa_liste_contratti (player_list* giocatori) {
	lista_contratti temp = giocatori->current->portafoglio;
	for (int k=0;k<10;k++) { //k indica il tipo di contratto che si deve stampare
		scorri_liste(k,&temp);
          	switch (k) {
                  	case 0:
                           	printf("%s (%d/%d)\n","Aereoporti", temp->num_contratti_posseduti, temp->num_contratti);
				stampa_contratti(temp);
	                        break;
                   	case 1:
                                printf("%s (%d/%d)\n","Marroni",temp->num_contratti_posseduti, temp->num_contratti);
                                stampa_contratti(temp);
				break;
                     	case 2:
                             	printf("%s (%d/%d)\n","Bianchi",temp->num_contratti_posseduti, temp->num_contratti);
                             	stampa_contratti(temp);
                             	break;
                  	case 3:
                      		printf("%s (%d/%d)\n","Viola",temp->num_contratti_posseduti, temp->num_contratti);
                                stampa_contratti(temp);
                                break;
                      	case 4:
                                printf("%s (%d/%d)\n","Arancioni",temp->num_contratti_posseduti, temp->num_contratti);
                                stampa_contratti(temp);
                                break;
                     	case 5:
                           	printf("%s (%d/%d)\n","Rossi",temp->num_contratti_posseduti, temp->num_contratti);
                                stampa_contratti(temp);
                                break;
                 	case 6:
                           	printf("%s (%d/%d)\n","Gialli",temp->num_contratti_posseduti, temp->num_contratti);
                             	stampa_contratti(temp);
                           	break;
                   	case 7:
                       		printf("%s (%d/%d)\n","Verdi",temp->num_contratti_posseduti, temp->num_contratti);
                                stampa_contratti(temp);
                  	        break;
                      	case 8:
                        	printf("%s (%d/%d)\n","Blu",temp->num_contratti_posseduti, temp->num_contratti);
                                stampa_contratti(temp);
				break;
			case 9:
                            	printf("%s (%d/%d)\n","Società",temp->num_contratti_posseduti, temp->num_contratti);
                           	stampa_contratti(temp);
                            	break;
		}
	}
   	printf("/back per tornare indietro:");
   	char back[100];
      	do {
        	scanf("%s",back);
     	} while (strcmp("/back",back) != 0); //esce inviando il comando /back
    	clear();
	return;
}

//libera la memoria allocata dalle liste dei contratti
void cancella_liste_contratti (player_list* giocatore) {
        lista_contratti list = giocatore->current->portafoglio; //primo puntatore per scorrere tra le liste dei contratti
        lista_contratti list2 = list; //secondo puntatore per scorrere tra le liste dei contratti
        while (list != NULL) { //avanza finchè il puntatore punta una lista
		list2 = list2->next; //list2 avanza alla lista successiva
		cancella_contratti(list);
                free(list); //libero la memoria puntata da list
                list = list2; //list raggiunge list2
        }
        return;
}

//controlla quanti sono i contratti di una determinata lista posseduti
int verifica_num_contratti (int type, player* giocatore) {
	lista_contratti lista = giocatore->portafoglio; //puntatore temporaneo alle liste di contratti
        scorri_liste(type,&lista);
        //while (lista->type != type) {
        //        lista = lista->next;
        //}
	return lista->num_contratti_posseduti;
}

int scorri_liste(int type, lista_contratti* lista) {
        while ((*lista)->type != type) {
                *lista = (*lista)->next;
        }
	return (*lista)->type;
}

//incrementa di 1 il numero dei contratti posseduti della lista e torna il valore
int incrementa_num_contratti(lista_contratti lista) {
        lista->num_contratti_posseduti+=1;
	return lista->num_contratti_posseduti;
}

