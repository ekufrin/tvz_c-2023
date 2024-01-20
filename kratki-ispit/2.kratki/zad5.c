/*
TEKST ZADATKA:
U glavnoj funkciji definirano je polje i poziv funkcije arg
Koju vrijednost vraća funkcija arg?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int arg(int* b, int n) {
	int i = 0, gg = *b, * p = b++; //gg poprima vrijednost polja[2], broj 11
								   //p uzima adresu polja[2] te ga nakon toga povećava za 1, p postaje polje[3] odnosno broj 10
	do{
		if (*p < gg) gg = *p;	// 10 < 11 ? DA		| gg postaje 10
	} while (++i < n && p++);	//Povećavamo i za 1, povećavamo p za 1, p postaje polje[4] , izasli smo izvan granica polja.

	return gg;
}
int main() {

	int polje[4] = {13, 12, 11, 10};
	printf("%d", arg(&polje[2], 3)); // Ispis je 10


	return 0;
}
