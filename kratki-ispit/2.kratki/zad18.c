/*
TEKST ZADATKA:
Napisati naredbe kojima ćete učitati u niz 5 elemenata koji se nalaze na zadnjih pet pozicija u datoteci, u niz počevši sa 70. mjestom. 
Pretpostavite da postoji definirana struktura Proizvod i varijabla Proizvod p[100], te otvorena datoteka FILE* fin
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>



int main() {
	
	int br = 70;
	fseek(fin, -5 * sizeof(struct Proizvod), SEEK_END);
	fread(&p[br++], sizeof(struct Proizvod), 1, fin);

	return 0;
}
