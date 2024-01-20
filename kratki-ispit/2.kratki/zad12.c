/*
TEKST ZADATKA:
Precizno napišite(uključujući sve znakove) što će sve ispisati sljedeći program prog, ako komandna linija glasi :
C: > prog 333 jos nije kraj akademske godine.
Teksta programa prog je :
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>



void main(int argc, char* argv[]) {
		char pom[40];
		char* ptr;
		strcpy(pom, argv[5] + 3);	//U niz pom kopiramo 5. element argv pomaknut za 3 slova u desno : akademske+3=demske
		printf("%s;", pom);			//demske;
		ptr = strchr(argv[6], 'd');	//U ptr kopiramo 6.element argv nakon što pronađemo prvi znak 'd' u njemu : godine = dine
		printf("%s;", ptr);			//dine;
		printf("%d.", argc);		//Ukupno ima 7 elemenata

		// KONACNI REZULTAT: demske;dine;7.

}
