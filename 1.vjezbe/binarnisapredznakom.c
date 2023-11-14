//Napišite program koji učitava 5 znakova(5 podataka tipa char) koje interpretiramo kao binarni prikaz cijelog broja s predznakom(signed int).Ako ulazni niz sadrži samo binarne znamenke(0 ili 1), program treba ispisati dekadski zapis tog broja, prema pravilu da prvi učitani znak označava predznak broja(0 je + , a 1 je −).
//
//Ostatak niza interpretiramo ovisno o predznaku :
//
//nenegativni(uključena je i 0) brojevi imaju uobičajeni prikaz
//negativni brojevi se prikazuju dvojnim komplementom
//
//
//Ako ulazni niz sadrži barem jedan znak koji nije binarna znamenka, treba ispisati poruku „Pogresan unos!“ i prekinuti izvođenje programa.


//Test case #1
//Primjer pogresnog unosa.
//Primjer ulaza :
//00123
//Primjer izlaza :
//Pogresan unos!
//Test case #2
//Primjer ulaza :
//00000
//Primjer izlaza :
//0
//Test case #3
//Primjer ulaza :
//11111
//Primjer izlaza :
//-1
//Test case #4
//Primjer ulaza :
//00011
//Primjer izlaza :
//3


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	char polje[5];
	int broj = 0;
	int jedinice = 0;
	int nule = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%c", &polje[i]);
		if (polje[i] != '1' && polje[i] != '0') {
			printf("Pogresan unos!");
			return 0;
		}
		if (polje[i] == '1') {
			jedinice++;
		}
		if (polje[i] == '0') {
			nule++;
		}
	}

	if (polje[0] == '1') {
		for (int i = 1; i < jedinice; i++) {
			++nule;
			--jedinice;
		}
		for (int i = 0; i < nule; i++) {
			broj += 0 * 2 ^ (nule - 1);
			--nule;
		}
		for (int i = 1; i < jedinice; i++) {
			broj += 1 * 2 ^ (jedinice - 1);
			--jedinice;
		}
		printf("-%d", broj);
	}
	else {
		for (int i = 0; i < jedinice; i++) {
			broj += 1*2 ^ (jedinice - 1);
			--jedinice;
		}

		printf("%d", broj);
	}




	return 0;

}