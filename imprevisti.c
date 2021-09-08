#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "imprevisti.h"


imprevisti* inizializza_imprevisti (void) {
	imprevisti* imp = (imprevisti* )malloc(sizeof(struct imprevisti)*5);
	if (imp == NULL) {
		return NULL;
	}
	//inizializza tutte gli imprevisti
	{
		strcpy (imp[0].descrizione, "Venite multati per eccesso di velocità. Pagate 150k");
		imp[0].paga = 150000;
		imp[0].posizione = 1;
		imp[0].retrocedi_a = false;
		imp[0].prigione = false;
	}
	{
		strcpy (imp[1].descrizione, "Non avete pagato la tassa della spazzatura. Pagate 500k");
		imp[1].paga = 500000;
		imp[1].posizione = 1;
		imp[1].retrocedi_a = false;
		imp[1].prigione = false;
	}
	{
		strcpy (imp[2].descrizione, "Venite scoperti durante un furto. Andate in prigione");
		imp[2].paga = 0;
		imp[2].posizione = 1;
		imp[2].retrocedi_a = false;
		imp[2].prigione = true;
	}
	{
		strcpy (imp[3].descrizione, "Pagate la retta universitaria. Sborsate 1M");
		imp[3].paga = 1000000;
		imp[3].posizione = 1;
		imp[3].retrocedi_a = false;
		imp[3].prigione = false;
	}
	{
		strcpy (imp[4].descrizione, "Trovate ingorgo per strada. Retrocedete di 3 caselle");
		imp[4].paga = 0;
		imp[4].posizione = -3;
		imp[4].retrocedi_a = false;
		imp[4].prigione = false;
	}
	return imp;
}

int pesca_imprevisto(player_list* giocatori, imprevisti* imp, int num_player) {
        int res = rand()%5; //estrae una probabilità random
        printf("Imprevisto\n");
        printf("%s\n\n", imp[res].descrizione); //stampa la descrizione
	if (imp[res].paga != 0) {
		paga(giocatori, imp[res].paga);
	}
        if (imp[res].posizione != 1) {
                if (imp[res].retrocedi_a) { //se retrocedi_a == 1 significa che il giocatore deve retrocedere in una specifica casella
                        avanza_a(giocatori, imp[res].posizione);
                }
                else { //se != 1 il giocatore deve retrocedere di n caselle
                        avanza_di(giocatori, imp[res].posizione);
                }
        }
        if (imp[res].prigione) {
                prigione(giocatori);
        }

}
