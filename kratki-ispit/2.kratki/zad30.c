/*
TEKST ZADATKA:
Napisati naredbe kojima ćete izračunati koliko linija unutar tekstualne datoteke je duže od 10 znakova.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
	
	char redak[1000];
	int br = 0;
	while (fscanf(ulaz, "%[^\n]", redak) != EOF) {
		if (strlen(redak) > 10) {
			br++;
		}
	}

	return 0;
}
