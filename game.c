#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "game.h"
#include "classifica.h"
#include "liste_contratti.h"

int controlla_caricamenti (int *num_player,int *turni, leaderboard* classifica, posizioni* luoghi, player_list* giocatore) {
	FILE *p_data;
	p_data = fopen("data.txt","r"); //apre il file in lettura
	if (p_data == NULL) { //verifica se il file non esiste
		return 0; //torna 0 se non esiste il caricamento di una partita
	}
	char scelta[100];
	do {
		printf("È stata trovata una partita... Vuoi caricarla?\nPremi (si) per caricarla (no) per continuare\n");
		scanf("%s",scelta);
		rem_case_sensitive(scelta);
		if (!strcmp(scelta, "no")) {
		       	fclose(p_data);
			return 0; //torna 0 se il giocatore vuole iniziare una nuova partita
		}
		else if(!strcmp(scelta, "si")) {
			int id_cur; //id del giocatore current
			id_cur = carica_info(p_data, turni, num_player); 
			carica_classifica(classifica);
			carica_giocatori(giocatore, luoghi);
                        while (giocatore->current->id != id_cur) {
				giocatore->current = giocatore->current->next; //il puntatore current punterà sul player a cui toccava giocare
              		}
			clear();
			return 1;
		}
	} while (strcmp(scelta,"si")!=0 && strcmp(scelta,"no"));
}

//legge le informazioni sulla partita e torna l'id del giocatore a cui spetta il turno
int carica_info (FILE *fp, int *turni, int *num_player) {
	int id;
	fscanf(fp, "%d %d %d", turni, num_player, &id);
	fclose(fp);
	return id;
}

int carica_classifica(leaderboard* classifica) {
	FILE *fp;
	int soldi, turno;
	char username[15];
        fp = fopen("classifica.txt","r"); //apre il file in lettura
     	if (fp == NULL) { //verifica se il file non esiste
                return 2; //torna 2 se non esiste una classifica
        }
	while (fscanf(fp,"%d %s %d ", &soldi, username, &turno)!=EOF) {
		leaderboard new_node; //creiamo un nuovo nodo
		new_node = (leaderboard)malloc(sizeof(struct nodo_pila));
		if (new_node == NULL) {
			return 1;
		}
		strcpy(new_node->username,username); //popoliamo il nodo con il nome del player
		new_node->turno = turno; //popoliamo il nodo con i turni giocati dal player
		new_node->next = *classifica; //il nuovo nodo punterà al precedente
		new_node->soldi = soldi; //popoliamo il nodo con i soldi del giocatore
		if (*classifica == NULL) { //verifica se la classifica è nulla
			new_node->next = NULL; //next non punterà a niente in quanto non esistono giocatori precedenti
		}
		else {
			new_node->next = *classifica; //next punterà al giocatore precedente
		}
		*classifica = new_node; //la classifica punterà all'ultimo giocatore inserito
	}
	fclose(fp);
	return 0; //torna 1 se viene caricata la classifica
}

int carica_giocatori(player_list* giocatore, posizioni* luoghi) {
	FILE *fp;
	fp = fopen("player.txt", "r");
	if (fp == NULL) {
		return 2; //torna 2 se il file non esiste
	}
	int soldi, pos, id_player, prigione, dadi;
	bool primo_giocatore = true;
	char username[15];
	while (fscanf(fp,"%d %s %d %d %d %d ", &soldi, username, &pos, &id_player, &prigione, &dadi)!=EOF) {
		struct player* new_player = (struct player* )malloc(sizeof(struct player));
		if (new_player == NULL) {
			return 1;
		}
                if (primo_giocatore) {
 	        	giocatore->head = new_player; //head punterà a lui essendo il primo
                        giocatore->tail = new_player; //tail punterà a lui essendo l'ultimo 
         	        primo_giocatore = false;
                }
                else {
                        struct player* temp = giocatore->tail; //creiamo un puntatore d'appoggio e lo facciamo coincidere con l'ultimo giocatore
                        temp->next=new_player; //facciamo puntare il vecchio ultimo giocatore al nuovo ultimo
                        giocatore->tail = new_player; //tail dovrà puntare al nuovo ultimo
                }
                giocatore->current = new_player;
		//popolo il nuovo nodo
		strcpy(new_player->username, username);
		new_player->id = id_player;
                new_player->posizione = pos;
		new_player->soldi = soldi;
		new_player->portafoglio = NULL;
		new_player->next = giocatore->head;
		new_player->prigione = prigione;
		new_player->dadi = dadi;
		crea_lista_contratti(giocatore);
		carica_contratti(fp, giocatore, luoghi); //carico i contratti del giocatore
	}
	fclose(fp);
	return 0;
}

int carica_contratti (FILE *fp, player_list* giocatore, posizioni* luoghi) {
	int id_pos, home, hotel;		
	do {
	       	fscanf(fp, "%d", &id_pos);
		if (id_pos != -10) { //se legge -10 non sono presenti informazioni riguardo i contratti
			int counter = 0;
			fscanf(fp, "%d %d", &home, &hotel);
			lista_contratti temp = giocatore->current->portafoglio;
			scorri_liste(luoghi[id_pos].type , &temp);
			contratto new_contratto = (contratto) malloc(sizeof(struct contratto));
			if (new_contratto == NULL) {
				return 1;
			}
			//popolo il nuovo contratto
			new_contratto->id = id_pos; 
			strcpy(new_contratto->nome, luoghi[id_pos].nome);
			new_contratto->home = home;
			new_contratto->hotel = hotel;
			new_contratto->next = NULL;
			//verifica se il contratto è il primo
			if (incrementa_num_contratti(temp)==1) { 
				temp->contratti = new_contratto;
			}
			else {
				struct contratto* temp_contratto = temp->contratti; //puntatore temporaneo per scorrere tra i contratti
				while (temp_contratto->next != NULL) {
					temp_contratto = temp_contratto->next;
				}
				temp_contratto->next = new_contratto;
			}
			luoghi[id_pos].proprietario = giocatore->current->id;
			luoghi[id_pos].home = home;
			if (!hotel) {
				luoghi[id_pos].hotel = false;
			}
			else if (hotel) {
				luoghi[id_pos].hotel = true;
			}
		}
	} while (id_pos != -10);		
	return 0;
}

int salva_caricamento (int turni,int num_player,leaderboard* classifica, player_list* giocatore) {
	if (salva_info(turni, num_player, giocatore) == 1 || salva_classifica(classifica) == 1 || salva_player(giocatore) == 1) {
		return 1;
	}
	return 0;
}

int salva_info(int turni, int num_player, player_list* giocatore) {
	FILE *fp;
	fp = fopen("data.txt","w"); //apre il file in scrittura
	if (fp == NULL) {
		return 1;
	}
	fprintf(fp, "%d %d %d\n", turni, num_player,giocatore->current->id);
	fclose(fp);
	return 0;
}

int salva_classifica(leaderboard* classifica) {
        FILE *fp;
        fp = fopen("classifica.txt","w"); //apre il file in scrittura
        if (fp == NULL) {
                return 1;
        }
        leaderboard temp_classifica = *classifica;
        while (temp_classifica!=NULL) {
      	      	fprintf(fp, "%d %s %d ", temp_classifica->soldi, temp_classifica->username, temp_classifica->turno);
		temp_classifica = temp_classifica->next;
        }
	fclose(fp);
	return 0;
}

int salva_player(player_list* giocatori) {
	FILE *fp;
	fp = fopen("player.txt", "w");
	if (fp == NULL) {
		return 1;
	}
	giocatori->current = giocatori->head;
        do {
                fprintf(fp, "%d %s %d %d %d %d ", giocatori->current->soldi, giocatori->current->username, giocatori->current->posizione, giocatori->current->id, giocatori->current->prigione, giocatori->current->dadi);
		salva_contratti(fp, giocatori);
		giocatori->current = giocatori->current->next;
        } while (giocatori->current != giocatori->head);
        fclose(fp);
	return 0;
}

void salva_contratti(FILE *fp, player_list* giocatori) {
	lista_contratti temp = giocatori->current->portafoglio;
	int i;
	for (i=0;i<10;i++) {
		scorri_liste(i, &temp);
		contratto temp_contratto = temp->contratti;
		while (temp_contratto != NULL) {
			fprintf(fp ,"%d %d %d ", temp_contratto->id, temp_contratto->home, temp_contratto->hotel);
			temp_contratto = temp_contratto->next;
		}
	}
	fprintf(fp, "-10 ");
}


void remove_file(void) {
	remove("data.txt");
	remove("player.txt");
	remove("classifica.txt");
}

int menu (void) {
	printf("Cosa vuoi fare?\n");
	printf("/dado        -> Tira i dadi\n");
	printf("/contratti   -> Guarda i tuoi contratti\n");
	printf("/home        -> Costruisci una casa\n");
	printf("/hotel       -> Costruisci un hotel\n");
	printf("/passa       -> Passa il turno\n");
	printf("/quit        -> Salva la partita ed esci\n\n");
	char scelta[100];
	do {
		scanf("%s",scelta);
		rem_case_sensitive(scelta);
		if (!strcmp("/dado",scelta)) {
			return 0; //codice 0
		}
		else if (!strcmp("/contratti",scelta)) {
			return 1; //codice 1
		}
		else if (!strcmp("/home",scelta)) {
			return 2; //codice 2
		}
		else if (!strcmp("/hotel", scelta)) {
			return 3; //codice 3
		}
		else if (!strcmp("/passa", scelta)) {
			return 4; //codice 4
		}
		else if (!strcmp("/quit",scelta)) {
			return 5; //codice 5
		}
	} while (true); //ciclo infinito (esce solo se si rispetta una condizione)
}

void clear (void) {
        system("clear");
}

//rimuove le maiuscole nelle stringhe
int rem_case_sensitive(char* text) {
        int len = strlen(text);
        int i;
        for (i=0; i<len; i++) {
                text[i] = tolower(text[i]);
        }
	return len;
}

//se il gioco finisce per il comando /quit
int quit_game(player_list* giocatori) {
        cancella_lista_player(giocatori);
	clear();
	printf("Il gioco è stato salvato correttamente\n");
	return 0;
}

//se il gioco finisce perchè resta un solo giocatore
int exit_game(leaderboard* classifica, player_list* giocatori, int turni, posizioni* luoghi) {
	if (push_classifica(classifica, giocatori, turni, luoghi)) {
		return 1;
	}
	free(giocatori->current);
        stampa_classifica(classifica);
	remove_file(); //se la partita finisce vanno cancellati i salvataggi
	return 0;
}
