/*
TEKST ZADATKA:
Napisati naredbe kojima ćete učitati u niz od 5 elemenata zapise koji se nalaze od 70.-74. pozicije u datoteci. 
Pretpostavite da postoji definirana struktura Proizvod i varijabla Proizvod p[5], te otvorena datoteka FILE* fin.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>



int main() {
	
	fseek(fin, 70 * sizeof(struct Proizvod), SEEK_SET); //Postavljamo pointer u datoteci na 70-tu liniju.
	fread(p, sizeof(struct Proizvod), 5, fin); //U niz p ucitavamo 5 linija iz datoteke fin velicine strukture Proizvod

	// REZULTAT je ucitanih 5 zapisa od 70. do 74. u niz p

	return 0;
}
