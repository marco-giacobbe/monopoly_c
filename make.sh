gcc -c -g caselle.c
gcc -c -g classifica.c
gcc -c -g player.c
gcc -c -g contratti.c
gcc -c -g liste_contratti.c
gcc -c -g probabilita.c
gcc -c -g imprevisti.c
gcc -c -g game.c
gcc -c main.c
gcc -o monopoly caselle.o classifica.o player.o contratti.o liste_contratti.o probabilita.o imprevisti.o game.o main.o
rm caselle.o classifica.o contratti.o probabilita.o player.o liste_contratti.o imprevisti.o game.o main.o

