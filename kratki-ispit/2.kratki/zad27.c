/*
TEKST ZADATKA:
Što ispisuje sljedeći programski odsječak?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	char znak = '1';
	while (znak < '9') {
		printf("%c-%c-%c-", znak, znak++, znak--);	//Ovo je trik zadatak, i svi bi ovdje krenuli računati sa lijeva na desno.
													// MEĐUTIM!!!!!!!!!!!!!
													//Kad ima više operacija unutar iste linije, u C-u, se kreće sa DESNA na LIJEVO!!!!
													//Printamo znak, zatim u sljedećem printu ga smanjujemo za 1, zatim u sljedećem printu povećavamo za 1
		znak++;										//Nakon svakog printa, povećavamo znak
	}

	//REZULTAT:
	//1-0-1-2-1-2-3-2-3-4-3-4-5-4-5-6-5-6-7-6-7-8-7-8-

	//Radi lakše vizualizacije, ovako bi izgledalo da na kraj svakog printf-a dodamo \n
	//1-0-1-
	//2-1-2-
	//3-2-3-
	//4-3-4-
	//5-4-5-
	//6-5-6-
	//7-6-7-
	//8-7-8-

	
	return 0;
}
