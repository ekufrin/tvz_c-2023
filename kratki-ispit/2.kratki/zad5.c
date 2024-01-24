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
								   //p uzima adresu polja[2] te ga nakon toga povećava za 1
	do{
		if (*p < gg) gg = *p;	// 11 < 11 ? NE		| 10 < 11 ? DA , gg postaje 10		| Polje[4] je izvan granica te je to neki random broj, npr -8123818, -8123818 < 10 ? DA, gg postaje -8123818 , izlazimo iz funkcije
	} while (++i < n && p++);	//Povećavamo i za 1, povećavamo p za 1, p postaje polje[3] 	| Povećavamo i za 1, povećavamo p za 1, p postaje polje[4]

	return gg;
}
int main() {

	int polje[4] = {13, 12, 11, 10};
	printf("%d", arg(&polje[2], 3)); // Ispis je -8123818


	return 0;
}
