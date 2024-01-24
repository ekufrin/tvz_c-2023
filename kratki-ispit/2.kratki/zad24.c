/*
TEKST ZADATKA:
Datoteka studenti.txt je sturkturirana na način da se u svakom retku nalaze podaci o jednom studentu u ovom formatu: JMBAG Prezime, Ime: BROJ_BODOVA. 
Napisati fscanf naredbu kojom se ispravno učitava jedan redak datoteke u strukturu Student. 
Strukturu Student ne treba definirati, već samo varijablu za jednog studenta.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	Student s1;
	fscanf(ulaz, "%[^ ] %[^,] %[^:]: %d", s1.jmbag, s1.prezime, s1.ime, s1.broj_bodova);

	return 0;
}
