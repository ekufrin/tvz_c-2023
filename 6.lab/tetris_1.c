/*
TEKST ZADATKA:
Potrebno je za ulaznu matricu # i .(točka - prazno polje) procijeniti da li će tetris element uspješno "sjesti" na mjesto gdje
je pozicioniran. Tetris element koji je potrebno spustiti je uvijek istog oblika (pogledati test primjer).
Ulazni podaci sastoje se od 1 <= R, S <= 15, koji označavaju broj redaka i stupaca tetris polja. Nakon toga slijedi R
redaka po S znakova koji predstavljaju polje igre.
Kao rezultat je potrebno ispisati konačno stanje, te informaciju da li se element uspješno spustio na mjesto gdje je
pozicioniran.
Obvezno koristiti funkciju za ispis konačnog stanja, te koristiti funkciju za samu logiku spuštanja elementa.
Savjet: element možete privremeno označiti drugim znakovima, primjerice zvjezdicama (*) umjesto s #.




TEST CASEOVI:
Test case #1
Ulaz :
10 10
......###.
.......#..
..........
..........
..........
..........
..........
..........
#######.##
##########

Izlaz :
..........
..........
..........
..........
..........
..........
..........
......###.
##########
##########

Uspjesno spustanje!

Test case #2
8 10
....###...
.....#....
..........
..........
..........
..........
..........
..........

Izlaz :
..........
..........
..........
..........
..........
..........
....###...
.....#....

Neuspjesno spustanje!


*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

void logika(char* polje, int r, int s, int* x, int* y) {


	for (int j = 0; j < s; j++) {

		if (*(polje + 1 * s + j) == '#') {

			*x = 1;
			*y = j;

		}

	}
	//*(polje + x * s + y) || *(polje + (x - 1) * s + (y + 1)) || *(polje + (x - 1) * s + (y - 1))
	// trenutni elementi

	while (*x != r - 1) {
		if (*(polje + (*x + 1) * s + *y) == '#' || *(polje + *x * s + (*y + 1)) == '#' || *(polje + *x * s + (*y - 1)) == '#') {
			// sljedeci elementi
			break;
		}
		//indexi x, y trebaju mi u main u pa si ih zato sa * stavljao
		//*(polje + x * s + y) = '.';
		*(polje + (*x - 1) * s + (*y + 1)) = '.';
		*(polje + (*x - 1) * s + (*y - 1)) = '.';// trenutni na tocke
		*(polje + (*x - 1) * s + *y) = '.';

		*(polje + (*x + 1) * s + *y) = '#';
		*(polje + *x * s + (*y + 1)) = '#'; // sljedeci zamjenio za ljestve 
		*(polje + *x * s + (*y - 1)) = '#';

		*x += 1; //mjenjaj index svih, da se zna da si ih spustio
	}
}

void ispis(char* polje, int r, int s) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {

			printf("%c", *(polje + i * s + j));

		}
		printf("\n");
	}

}

int main() {

	int r, s;
	int x, y;

	scanf("%d %d\n", &r, &s);

	char* polje;
	polje = (char*)malloc(r * s * sizeof(char*));

	for (int i = 0; i < r; i++) {
		scanf(" ");
		for (int j = 0; j < s; j++) {

			scanf(" %c", (polje + i * s + j));

		}
	}


	logika(polje, r, s, &x, &y);


	ispis(polje, r, s);


	if (*(polje + x * s + y + 1) == '#' && *(polje + x * s + y - 1) == '#') {

		printf("Uspjesno spustanje!");
	}
	else {

		printf("Neuspjesno spustanje!");

	}

}
