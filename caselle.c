#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "caselle.h"


posizioni* inizializza_caselle (void) {
	posizioni* luoghi = (posizioni* )malloc(sizeof(posizioni)*40);
	if (luoghi == NULL) {
		return NULL;
	}
	//popolo le caselle
	{
		strcpy (luoghi[0].nome, "Via");
		luoghi[0].id = 0;
		luoghi[0].type = 10;
		luoghi[0].paga=0;
		luoghi[0].guadagna=0;
		luoghi[0].prigione = false;
		luoghi[0].probabilita = false;
		luoghi[0].imprevisto = false;
		luoghi[0].contratto = false;
		luoghi[0].proprietario = 0;
		luoghi[0].affitto = 0;
		luoghi[0].compra = 0;
		luoghi[0].costruisci = 0;
		luoghi[0].home=0;
		luoghi[0].hotel=false;
	}
	{
        	strcpy (luoghi[1].nome, "Teramo");
	        luoghi[1].id = 1;
	        luoghi[1].type = 1;
	        luoghi[1].paga=0;
	        luoghi[1].guadagna=0;
	        luoghi[1].prigione = false;
	        luoghi[1].probabilita = false;
	        luoghi[1].imprevisto = false;
	        luoghi[1].contratto = true;
	        luoghi[1].proprietario = 0;
		luoghi[1].affitto = 20000;
		luoghi[1].compra = 600000;
		luoghi[1].costruisci = 500000;
	        luoghi[1].home=0;
	        luoghi[1].hotel=false;

	}
	{
	        strcpy (luoghi[2].nome, "Probabilità");
	        luoghi[2].id = 2;
	        luoghi[2].type = 10;
	        luoghi[2].paga=0;
	        luoghi[2].guadagna=0;
	        luoghi[2].prigione = false;
	        luoghi[2].probabilita = true;
	        luoghi[2].imprevisto = false;
	        luoghi[2].contratto = false;
	        luoghi[2].proprietario = 0;
		luoghi[2].affitto = 0;
		luoghi[2].compra = 0;
		luoghi[2].costruisci = 0;
	        luoghi[2].home=0;
	        luoghi[2].hotel=false;
	}
	{
	        strcpy (luoghi[3].nome, "Sanremo");
	        luoghi[3].id = 3;
	        luoghi[3].type = 1;
	        luoghi[3].paga=0;
	        luoghi[3].guadagna=0;
	        luoghi[3].prigione = false;
	        luoghi[3].probabilita = false;
	        luoghi[3].imprevisto = false;
	        luoghi[3].contratto = true;
	        luoghi[3].proprietario = 0;
		luoghi[3].affitto = 40000;
		luoghi[3].compra = 600000;
		luoghi[3].costruisci = 500000;
	        luoghi[3].home=0;
	        luoghi[3].hotel=false;
	}
	{
	        strcpy (luoghi[4].nome, "Tassa patrimoniale");
	        luoghi[4].id = 4;
	        luoghi[4].type = 10;
	        luoghi[4].paga=2000000;
	        luoghi[4].guadagna=0;
	        luoghi[4].prigione = false;
	        luoghi[4].probabilita = false;
	        luoghi[4].imprevisto = false;
	        luoghi[4].contratto = false;
		luoghi[4].proprietario = 0;
		luoghi[4].affitto = 0;
		luoghi[4].compra = 0;
	        luoghi[4].proprietario = 0;
		luoghi[4].costruisci = 0;
	        luoghi[4].home=0;
	        luoghi[4].hotel=false;
	}
	{
	        strcpy (luoghi[5].nome, "Aereoporto di Napoli Capodichino");
	        luoghi[5].id = 5;
	        luoghi[5].type = 0;
	        luoghi[5].paga=0;
	        luoghi[5].guadagna=0;
	        luoghi[5].prigione = false;
	        luoghi[5].probabilita = false;
	        luoghi[5].imprevisto = false;
	        luoghi[5].contratto = true;
	        luoghi[5].proprietario = 0;
                luoghi[5].affitto = 250000;
                luoghi[5].compra = 2000000;
                luoghi[5].costruisci = 0;
	        luoghi[5].home=0;
	        luoghi[5].hotel=false;
	}
	{
	        strcpy (luoghi[6].nome, "L'acquila");
	        luoghi[6].id = 6;
	        luoghi[6].type = 2;
	        luoghi[6].paga=0;
	        luoghi[6].guadagna=0;
	        luoghi[6].prigione = false;
	        luoghi[6].probabilita = false;
	        luoghi[6].imprevisto = false;
	        luoghi[6].contratto = true;
	        luoghi[6].proprietario = 0;
                luoghi[6].affitto = 60000;
                luoghi[6].compra = 1000000;
                luoghi[6].costruisci = 500000;
	        luoghi[6].home=0;
	        luoghi[6].hotel=false;
	}
	{
	        strcpy (luoghi[7].nome, "Imprevisti");
	        luoghi[7].id = 7;
	        luoghi[7].type = 10;
	        luoghi[7].paga=0;
	        luoghi[7].guadagna=0;
	        luoghi[7].prigione = false;
	        luoghi[7].probabilita = false;
	        luoghi[7].imprevisto = true;
	        luoghi[7].contratto = false;
	        luoghi[7].proprietario = 0;
                luoghi[7].affitto = 0;
                luoghi[7].compra = 0;
                luoghi[7].costruisci = 0;
	        luoghi[7].home=0;
	        luoghi[7].hotel=false;
	}
	{
	        strcpy (luoghi[8].nome, "Trani");
	        luoghi[8].id = 8;
	        luoghi[8].type = 2;
	        luoghi[8].paga=0;
	        luoghi[8].guadagna=0;
	        luoghi[8].prigione = false;
	        luoghi[8].probabilita = false;
	        luoghi[8].imprevisto = false;
	        luoghi[8].contratto = true;
	        luoghi[8].proprietario = 0;
                luoghi[8].affitto = 60000;
                luoghi[8].compra = 1000000;
                luoghi[8].costruisci = 500000;
	        luoghi[8].home=0;
	        luoghi[8].hotel=false;
	}
	{
		strcpy (luoghi[9].nome, "Torino");
	        luoghi[9].id = 9;
	        luoghi[9].type = 2;
	        luoghi[9].paga=0;
	        luoghi[9].guadagna=0;
	        luoghi[9].prigione = false;
	        luoghi[9].probabilita = false;
	        luoghi[9].imprevisto = false;
	        luoghi[9].contratto = true;
	        luoghi[9].proprietario = 0;
                luoghi[9].affitto = 80000;
                luoghi[9].compra = 1200000;
                luoghi[9].costruisci = 500000;
	        luoghi[9].home=0;
	        luoghi[9].hotel=false;
	}
	{
		strcpy (luoghi[10].nome, "Transito");
		luoghi[10].id = 10;
		luoghi[10].type = 10;
		luoghi[10].paga=0;
		luoghi[10].guadagna=0;
		luoghi[10].prigione = false;
		luoghi[10].probabilita = false;
		luoghi[10].imprevisto = false;
		luoghi[10].contratto = false;
		luoghi[10].proprietario = 0;
		luoghi[10].home=0;
		luoghi[10].hotel=false;
	}
	{
		strcpy (luoghi[11].nome, "Cosenza");
	        luoghi[11].id = 11;
	        luoghi[11].type = 3;
	        luoghi[11].paga=0;
	        luoghi[11].guadagna=0;
	        luoghi[11].prigione = false;
	        luoghi[11].probabilita = false;
	        luoghi[11].imprevisto = false;
	        luoghi[11].contratto = true;
	        luoghi[11].proprietario = 0;
                luoghi[11].affitto = 100000;
		luoghi[11].compra = 1400000;
                luoghi[11].costruisci = 1000000;
	        luoghi[11].home=0;
	        luoghi[11].hotel=false;
	}
        {
                strcpy (luoghi[12].nome, "Società telefonica");
                luoghi[12].id = 12;
                luoghi[12].type = 9;
                luoghi[12].paga=0;
                luoghi[12].guadagna=0;
                luoghi[12].prigione = false;
                luoghi[12].probabilita = false;
                luoghi[12].imprevisto = false;
                luoghi[12].contratto = true;
                luoghi[12].proprietario = 0;
                luoghi[12].affitto = 0;
                luoghi[12].compra = 1500000;
                luoghi[12].costruisci = 0;
                luoghi[12].home=0;
                luoghi[12].hotel=false;
        }
        {
                strcpy (luoghi[13].nome, "Milano");
                luoghi[13].id = 13;
                luoghi[13].type = 3;
                luoghi[13].paga=0;
                luoghi[13].guadagna=0;
                luoghi[13].prigione = false;
                luoghi[13].probabilita = false;
                luoghi[13].imprevisto = false;
                luoghi[13].contratto = true;
                luoghi[13].proprietario = 0;
                luoghi[13].affitto = 100000;
                luoghi[13].compra = 1400000;
                luoghi[13].costruisci = 1000000;
                luoghi[13].home=0;
                luoghi[13].hotel=false;
        }
        {
                strcpy (luoghi[14].nome, "Viareggio");
                luoghi[14].id = 14;
                luoghi[14].type = 3;
                luoghi[14].paga=0;
                luoghi[14].guadagna=0;
                luoghi[14].prigione = false;
                luoghi[14].probabilita = false;
                luoghi[14].imprevisto = false;
                luoghi[14].contratto = true;
                luoghi[14].proprietario = 0;
                luoghi[14].affitto = 120000;
                luoghi[14].compra = 1600000;
                luoghi[14].costruisci = 1000000;
                luoghi[14].home=0;
                luoghi[14].hotel=false;
        }
        {
                strcpy (luoghi[15].nome, "Aereoporto di Catania Fontanarossa");
                luoghi[15].id = 15;
                luoghi[15].type = 0;
                luoghi[15].paga=0;
                luoghi[15].guadagna=0;
                luoghi[15].prigione = false;
                luoghi[15].probabilita = false;
                luoghi[15].imprevisto = false;
                luoghi[15].contratto = true;
                luoghi[15].proprietario = 0;
                luoghi[15].affitto = 250000;
                luoghi[15].compra = 2000000;
                luoghi[15].costruisci = 0;
                luoghi[15].home=0;
                luoghi[15].hotel=false;
        }
        {
                strcpy (luoghi[16].nome, "Terni");
                luoghi[16].id = 16;
                luoghi[16].type = 4;
                luoghi[16].paga=0;
                luoghi[16].guadagna=0;
                luoghi[16].prigione = false;
                luoghi[16].probabilita = false;
                luoghi[16].imprevisto = false;
                luoghi[16].contratto = true;
                luoghi[16].proprietario = 0;
                luoghi[16].affitto = 140000;
                luoghi[16].compra = 1800000;
                luoghi[16].costruisci = 1000000;
                luoghi[16].home=0;
                luoghi[16].hotel=false;
        }
        {
                strcpy (luoghi[17].nome, "Probabilità");
                luoghi[17].id = 17;
                luoghi[17].type = 10;
                luoghi[17].paga=0;
                luoghi[17].guadagna=0;
                luoghi[17].prigione = false;
                luoghi[17].probabilita = true;
                luoghi[17].imprevisto = false;
                luoghi[17].contratto = false;
                luoghi[17].proprietario = 0;
                luoghi[17].affitto = 0;
                luoghi[17].compra = 0;
                luoghi[17].costruisci = 0;
                luoghi[17].home=0;
                luoghi[17].hotel=false;
        }
        {
                strcpy (luoghi[18].nome, "Messina");
                luoghi[18].id = 18;
                luoghi[18].type = 4;
                luoghi[18].paga=0;
                luoghi[18].guadagna=0;
                luoghi[18].prigione = false;
                luoghi[18].probabilita = false;
                luoghi[18].imprevisto = false;
                luoghi[18].contratto = true;
                luoghi[18].proprietario = 0;
                luoghi[18].affitto = 140000;
                luoghi[18].compra = 1800000;
                luoghi[18].costruisci = 1000000;
                luoghi[18].home=0;
                luoghi[18].hotel=false;
        }
        {
                strcpy (luoghi[19].nome, "Foggia");
                luoghi[19].id = 19;
                luoghi[19].type = 4;
                luoghi[19].paga=0;
                luoghi[19].guadagna=0;
                luoghi[19].prigione = false;
                luoghi[19].probabilita = false;
                luoghi[19].imprevisto = false;
                luoghi[19].contratto = true;
                luoghi[19].proprietario = 0;
                luoghi[19].affitto = 160000;
                luoghi[19].compra = 2000000;
                luoghi[19].costruisci = 1000000;
                luoghi[19].home=0;
                luoghi[19].hotel=false;
        }
        {
                strcpy (luoghi[20].nome, "Parcheggio gratuito");
                luoghi[20].id = 20;
                luoghi[20].type = 10;
                luoghi[20].paga=0;
                luoghi[20].guadagna=0;
                luoghi[20].prigione = false;
                luoghi[20].probabilita = false;
                luoghi[20].imprevisto = false;
                luoghi[20].contratto = false;
                luoghi[20].proprietario = 0;
                luoghi[20].affitto = 0;
                luoghi[20].compra = 0;
                luoghi[20].costruisci = 0;
                luoghi[20].home=0;
                luoghi[20].hotel=false;
        }
        {
                strcpy (luoghi[21].nome, "Caserta");
                luoghi[21].id = 21;
                luoghi[21].type = 5;
                luoghi[21].paga=0;
                luoghi[21].guadagna=0;
                luoghi[21].prigione = false;
                luoghi[21].probabilita = false;
                luoghi[21].imprevisto = false;
                luoghi[21].contratto = true;
                luoghi[21].proprietario = 0;
                luoghi[21].affitto = 180000;
                luoghi[21].compra = 2200000;
                luoghi[21].costruisci = 1500000;
                luoghi[21].home=0;
                luoghi[21].hotel=false;
        }
        {
                strcpy (luoghi[22].nome, "Imprevisti");
                luoghi[22].id = 22;
                luoghi[22].type = 10;
                luoghi[22].paga=0;
                luoghi[22].guadagna=0;
                luoghi[22].prigione = false;
                luoghi[22].probabilita = false;
                luoghi[22].imprevisto = true;
                luoghi[22].contratto = false;
                luoghi[22].proprietario = 0;
                luoghi[22].affitto = 0;
                luoghi[22].compra = 0;
                luoghi[22].costruisci = 0;
                luoghi[22].home=0;
                luoghi[22].hotel=false;
        }
        {
                strcpy (luoghi[23].nome, "Brindisi");
                luoghi[23].id = 23;
                luoghi[23].type = 5;
                luoghi[23].paga=0;
                luoghi[23].guadagna=0;
                luoghi[23].prigione = false;
                luoghi[23].probabilita = false;
                luoghi[23].imprevisto = false;
                luoghi[23].contratto = true;
                luoghi[23].proprietario = 0;
                luoghi[23].affitto = 180000;
                luoghi[23].compra = 2200000;
                luoghi[23].costruisci = 1500000;
                luoghi[23].home=0;
                luoghi[23].hotel=false;
        }
        {
                strcpy (luoghi[24].nome, "Ischia");
                luoghi[24].id = 24;
                luoghi[24].type = 5;
                luoghi[24].paga=0;
                luoghi[24].guadagna=0;
                luoghi[24].prigione = false;
                luoghi[24].probabilita = false;
                luoghi[24].imprevisto = false;
                luoghi[24].contratto = true;
                luoghi[24].proprietario = 0;
                luoghi[24].affitto = 200000;
                luoghi[24].compra = 2400000;
                luoghi[24].costruisci = 1500000;
                luoghi[24].home=0;
                luoghi[24].hotel=false;
        }
        {
                strcpy (luoghi[25].nome, "Aereoporto di Milano Malpensa");
                luoghi[25].id = 25;
                luoghi[25].type = 0;
                luoghi[25].paga=0;
                luoghi[25].guadagna=0;
                luoghi[25].prigione = false;
                luoghi[25].probabilita = false;
                luoghi[25].imprevisto = false;
                luoghi[25].contratto = true;
                luoghi[25].proprietario = 0;
                luoghi[25].affitto = 250000;
                luoghi[25].compra = 2000000;
                luoghi[25].costruisci = 0;
                luoghi[25].home=0;
                luoghi[25].hotel=false;
        }
        {
                strcpy (luoghi[26].nome, "Monopoli");
                luoghi[26].id = 26;
                luoghi[26].type = 6;
                luoghi[26].paga=0;
                luoghi[26].guadagna=0;
                luoghi[26].prigione = false;
                luoghi[26].probabilita = false;
                luoghi[26].imprevisto = false;
                luoghi[26].contratto = true;
                luoghi[26].proprietario = 0;
                luoghi[26].affitto = 220000;
                luoghi[26].compra = 2600000;
                luoghi[26].costruisci = 1500000;
                luoghi[26].home=0;
                luoghi[26].hotel=false;
        }
        {
                strcpy (luoghi[27].nome, "Ascoli Piceno");
                luoghi[27].id = 27;
                luoghi[27].type = 6;
                luoghi[27].paga=0;
                luoghi[27].guadagna=0;
                luoghi[27].prigione = false;
                luoghi[27].probabilita = false;
                luoghi[27].imprevisto = false;
                luoghi[27].contratto = true;
                luoghi[27].proprietario = 0;
                luoghi[27].affitto = 220000;
                luoghi[27].compra = 2600000;
                luoghi[27].costruisci = 1500000;
                luoghi[27].home=0;
                luoghi[27].hotel=false;
        }
        {
                strcpy (luoghi[28].nome, "Società telematica");
                luoghi[28].id = 28;
                luoghi[28].type = 9;
                luoghi[28].paga=0;
                luoghi[28].guadagna=0;
                luoghi[28].prigione = false;
                luoghi[28].probabilita = false;
                luoghi[28].imprevisto = false;
                luoghi[28].contratto = true;
                luoghi[28].proprietario = 0;
                luoghi[28].affitto = 0;
                luoghi[28].compra = 1500000;
                luoghi[28].costruisci = 0;
                luoghi[28].home=0;
                luoghi[28].hotel=false;
        }
        {
                strcpy (luoghi[29].nome, "Isola d'Elba");
                luoghi[29].id = 29;
                luoghi[29].type = 6;
                luoghi[29].paga=0;
                luoghi[29].guadagna=0;
                luoghi[29].prigione = false;
                luoghi[29].probabilita = false;
                luoghi[29].imprevisto = false;
                luoghi[29].contratto = true;
                luoghi[29].proprietario = 0;
                luoghi[29].affitto = 240000;
                luoghi[29].compra = 2800000;
                luoghi[29].costruisci = 1500000;
                luoghi[29].home=0;
                luoghi[29].hotel=false;
        }
        {
                strcpy (luoghi[30].nome, "In prigione");
                luoghi[30].id = 30;
                luoghi[30].type = 10;
                luoghi[30].paga=0;
                luoghi[30].guadagna=0;
                luoghi[30].prigione = true;
                luoghi[30].probabilita = false;
                luoghi[30].imprevisto = false;
                luoghi[30].contratto = false;
                luoghi[30].proprietario = 0;
                luoghi[30].affitto = 0;
                luoghi[30].compra = 0;
                luoghi[30].costruisci = 0;
                luoghi[30].home=0;
                luoghi[30].hotel=false;
        }
        {
                strcpy (luoghi[31].nome, "Andria");
                luoghi[31].id = 31;
                luoghi[31].type = 7;
                luoghi[31].paga=0;
                luoghi[31].guadagna=0;
                luoghi[31].prigione = false;
                luoghi[31].probabilita = false;
                luoghi[31].imprevisto = false;
                luoghi[31].contratto = true;
                luoghi[31].proprietario = 0;
                luoghi[31].affitto = 260000;
                luoghi[31].compra = 3000000;
                luoghi[31].costruisci = 2000000;
                luoghi[31].home=0;
                luoghi[31].hotel=false;
        }
        {
                strcpy (luoghi[32].nome, "Barletta");
                luoghi[32].id = 32;
                luoghi[32].type = 7;
                luoghi[32].paga=0;
                luoghi[32].guadagna=0;
                luoghi[32].prigione = false;
                luoghi[32].probabilita = false;
                luoghi[32].imprevisto = false;
                luoghi[32].contratto = true;
                luoghi[32].proprietario = 0;
                luoghi[32].affitto = 260000;
                luoghi[32].compra = 3000000;
                luoghi[32].costruisci = 2000000;
                luoghi[32].home=0;
                luoghi[32].hotel=false;
        }
        {
                strcpy (luoghi[33].nome, "Probabilità");
                luoghi[33].id = 33;
                luoghi[33].type = 10;
                luoghi[33].paga=0;
                luoghi[33].guadagna=0;
                luoghi[33].prigione = false;
                luoghi[33].probabilita = true;
                luoghi[33].imprevisto = false;
                luoghi[33].contratto = false;
                luoghi[33].proprietario = 0;
                luoghi[33].affitto = 0;
                luoghi[33].compra = 0;
                luoghi[33].costruisci = 0;
                luoghi[33].home=0;
                luoghi[33].hotel=false;
        }
        {
                strcpy (luoghi[34].nome, "Catanzaro");
                luoghi[34].id = 34;
                luoghi[34].type = 7;
                luoghi[34].paga=0;
                luoghi[34].guadagna=0;
                luoghi[34].prigione = false;
                luoghi[34].probabilita = false;
                luoghi[34].imprevisto = false;
                luoghi[34].contratto = true;
                luoghi[34].proprietario = 0;
                luoghi[34].affitto = 280000;
                luoghi[34].compra = 3200000;
                luoghi[34].costruisci = 2000000;
                luoghi[34].home=0;
                luoghi[34].hotel=false;
        }
        {
                strcpy (luoghi[35].nome, "Aereoporto di Roma Fiumicino");
                luoghi[35].id = 35;
                luoghi[35].type = 0;
                luoghi[35].paga=0;
                luoghi[35].guadagna=0;
                luoghi[35].prigione = false;
                luoghi[35].probabilita = false;
                luoghi[35].imprevisto = false;
                luoghi[35].contratto = true;
                luoghi[35].proprietario = 0;
                luoghi[35].affitto = 250000;
                luoghi[35].compra = 2000000;
                luoghi[35].costruisci = 0;
                luoghi[35].home=0;
                luoghi[35].hotel=false;
        }
        {
                strcpy (luoghi[36].nome, "Imprevisti");
                luoghi[36].id = 36;
                luoghi[36].type = 10;
                luoghi[36].paga=0;
                luoghi[36].guadagna=0;
                luoghi[36].prigione = false;
                luoghi[36].probabilita = false;
                luoghi[36].imprevisto = true;
                luoghi[36].contratto = false;
                luoghi[36].proprietario = 0;
                luoghi[36].affitto = 0;
                luoghi[36].compra = 0;
                luoghi[36].costruisci = 0;
                luoghi[36].home=0;
                luoghi[36].hotel=false;
        }
        {
                strcpy (luoghi[37].nome, "Reggio Calabria");
                luoghi[37].id = 37;
                luoghi[37].type = 8;
                luoghi[37].paga=0;
                luoghi[37].guadagna=0;
                luoghi[37].prigione = false;
                luoghi[37].probabilita = false;
                luoghi[37].imprevisto = false;
                luoghi[37].contratto = true;
                luoghi[37].proprietario = 0;
                luoghi[37].affitto = 350000;
                luoghi[37].compra = 3500000;
                luoghi[37].costruisci = 2000000;
                luoghi[37].home=0;
                luoghi[37].hotel=false;
        }
        {
                strcpy (luoghi[38].nome, "Tassa di Lusso");
                luoghi[38].id = 38;
                luoghi[38].type = 10;
                luoghi[38].paga=1000000;
                luoghi[38].guadagna=0;
                luoghi[38].prigione = false;
                luoghi[38].probabilita = false;
                luoghi[38].imprevisto = false;
                luoghi[38].contratto = false;
                luoghi[38].proprietario = 0;
                luoghi[38].affitto = 0;
                luoghi[38].compra = 0;
                luoghi[38].proprietario = 0;
                luoghi[38].costruisci = 0;
                luoghi[38].home=0;
                luoghi[38].hotel=false;
        }
        {
                strcpy (luoghi[39].nome, "Chieti");
                luoghi[39].id = 39;
                luoghi[39].type = 8;
                luoghi[39].paga=0;
                luoghi[39].guadagna=0;
                luoghi[39].prigione = false;
                luoghi[39].probabilita = false;
                luoghi[39].imprevisto = false;
                luoghi[39].contratto = true;
                luoghi[39].proprietario = 0;
                luoghi[39].affitto = 500000;
                luoghi[39].compra = 4000000;
                luoghi[39].costruisci = 2000000;
                luoghi[39].home=0;
                luoghi[39].hotel=false;
        }
	return luoghi;
}

//verifica il tipo di casella su cui il giocatore si trova
void verifica_casella (int *turni,int num_player,player_list* giocatori,posizioni* luoghi, probabilita* pro, imprevisti* imp, int dado) {
        if (luoghi[giocatori->current->posizione].prigione) {
                prigione(giocatori);
        }
        else if (luoghi[giocatori->current->posizione].probabilita) {
                pesca_probabilita(giocatori, pro, num_player );
        }
        else if (luoghi[giocatori->current->posizione].imprevisto) {
                pesca_imprevisto(giocatori, imp, num_player);
        }
        else if (luoghi[giocatori->current->posizione].contratto) {
                menu_contratto(luoghi, giocatori, dado);
        }
        else if (luoghi[giocatori->current->posizione].paga >0) {
                paga(giocatori, luoghi[giocatori->current->posizione].paga);
                printf("Hai dovuto pagare %d€\n\n",luoghi[giocatori->current->posizione].paga);
        }
        return;
}

int hotel (player_list* giocatori, posizioni* luoghi) {
	int *contratti = (int*) calloc(22,sizeof(int)); //lista degli id dei contratti
	if (stampa_contratti_hotel(contratti, giocatori, luoghi)) { //verifica se l'utente può costruire hotel
		clear();
		printf("Non hai terreni edificabili (Per costruire un hotel devi prima possedere 4 case in un singolo terreno)\n\n");
		free(contratti);
		return 1;
	}
	scelta_contratto(contratti, luoghi, giocatori, 1); //passiamo 1 per costruire un hotel
	free(contratti);
	return 0;
}

//stampa i contratti costruibili e aggiorna l'array contenente gli id
int stampa_contratti_hotel (int contratti[], player_list* giocatori, posizioni* luoghi) {
	int j=0;
	lista_contratti temp_lista = giocatori->current->portafoglio;
	for (int k=1;k<9;k++) {
		scorri_liste(k,&temp_lista);
                contratto temp_contratto = temp_lista->contratti; //il puntatore temporaneo ai contratti punterà al primo contratto
                while (temp_contratto != NULL) { //cicla finchè non si arriva all'ultimo contratto
                	if (temp_contratto->home == 4 && temp_contratto->hotel==0) { //se ci sono 4 case e non ci sono hotel è possibile costruire
        	                printf("%s (%d) hotel:%d    costo di costruzione:%d\n", temp_contratto->nome, temp_contratto->id, temp_contratto->hotel, luoghi[temp_contratto->id].costruisci);
                              	contratti[j] = temp_contratto->id; //nell'array degli id viene aggiunto l'id del terreno edificabile
                                j++;
                        }
			temp_contratto = temp_contratto->next; //passa al contratto successivo
        	}
	}
	if (!j) {
		return 1; //torniamo 1 se l'utente non può costruire hotel
	}
	return 0;
}

int home (player_list* giocatori, posizioni* luoghi) {
	int *contratti = (int*) calloc(22,sizeof(int)); //lista degli id dei contratti
	if (stampa_contratti_home(contratti, giocatori, luoghi)) {
	      	clear();
        	printf("Non hai terreni edificabili (Per costruire una casa devi prima possedere tutti i terreni dello stesso tipo)\n\n");
        	free(contratti);
    		return 1;
        }
        scelta_contratto(contratti, luoghi, giocatori, 0); //passiamo 0 per costruire una casa
        free(contratti);
	return 0;
}

int stampa_contratti_home(int contratti[], player_list* giocatori, posizioni* luoghi) {
	int i=0;
	lista_contratti temp_lista = giocatori->current->portafoglio;
	for (int k=1;k<9;k++) {
		scorri_liste(k,&temp_lista);
                if (verifica_num_contratti(k,giocatori->current) == temp_lista->num_contratti) { //verifica che un giocatore possiede tutti i contratti dello stesso tipo
                	contratto temp_contratto = temp_lista->contratti; //il puntatore temporaneo ai contratti punterà al primo contratto
                	while (temp_contratto != NULL) { //cicla finchè non si arriva all'ultimo contratto
                        	printf("%s (%d) case:%d    costo di costruzione:%d  \n",temp_contratto->nome, temp_contratto->id, temp_contratto->home, luoghi[temp_contratto->id].costruisci); //stampa le informazioni del singolo contratto
                            	if (temp_contratto->home <4) { //verifica se il contratto ha meno di 4 case            
					contratti[i] = temp_contratto->id; //il contratto viene aggiunto all'array dei terreni edificabili
                                        i++; //incrementa il contatore di 1
				}
                                temp_contratto = temp_contratto->next; //passa la contratto successivo
                        }
                        printf("\n");
                }
        }
	if (!i) {
		return 1; //torna 1 se l'utente non può costruire case
	}
	return 0;
}

int scelta_contratto(int contratti[], posizioni* luoghi, player_list* giocatori, int i) {
	printf("Premi il numero del contratto nel quale vuoi costruire o 0 per tornare indietro:");
        int scelta,j;
        do {
                scanf(" %d",&scelta);
                j=0;
                while (contratti[j] != 0 && j<22) { //cicla finchè non finiscono i contratti nell'array o finchè non si sceglie un contratto
                        if (scelta == contratti[j]) {
				clear();
				if (giocatori->current->soldi < luoghi[scelta].costruisci) { //verifica se l'utente ha il budget per costuire
					printf("Non hai abbastanza soldi per costruire\n\n");
					return 1;
				}
				if (!i) {
					costruisci_home(scelta, luoghi, giocatori);
					return 0;

				}
                                costruisci_hotel(scelta, luoghi, giocatori);
				return 0;
                        }
			else if (!scelta) { //inserendo 0 si torna indietro
				clear();
				return 1; //torna 1 se l'utente non vuole costruire
			}
                        j++;
                }
                printf("Inserisci un numero valido: "); //se l'id non è valido stampiamo un messaggio
        } while (true); //il programma chiede l'id finchè l'utente non ne inserisce uno valido
}

void costruisci_hotel (int scelta, posizioni* luoghi,player_list* giocatore) {
        luoghi[scelta].hotel = true; //aggiorna la label hotel della casella 
        lista_contratti temp_lista = giocatore->current->portafoglio;
	scorri_liste(luoghi[scelta].type,&temp_lista);
        contratto temp_contratto = temp_lista->contratti;
        while (temp_contratto->id != luoghi[scelta].id) {
                temp_contratto = temp_contratto->next;
        }
        temp_contratto->hotel++; //aggiorna la label hotel del contratto
        giocatore->current->soldi -= luoghi[scelta].costruisci;

}

void costruisci_home (int scelta, posizioni* luoghi,player_list* giocatore) {
	luoghi[scelta].home++; //aggiorna la label home della casella
	lista_contratti temp_lista = giocatore->current->portafoglio;
	scorri_liste(luoghi[scelta].type,&temp_lista);
	contratto temp_contratto = temp_lista->contratti;
	while (temp_contratto->id != luoghi[scelta].id) {
		temp_contratto = temp_contratto->next;
	}
	temp_contratto->home++; //aggiorna la label home del contratto
	giocatore->current->soldi -= luoghi[scelta].costruisci;
}
