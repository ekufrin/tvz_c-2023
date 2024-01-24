/*
TEKST ZADATKA:
Precizno napišite (uključujući sve znakove) što će sve ispisati program naziva „prog", ako komandna linija glasi:
C:>danas je utorak
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main(int argc, char* argv[]) {
	
	char pom[40]; 
	char* ptr;
	printf("%d;", argc);	//4;
	strcat(pom, argv[1]);	// kopiramo u niz pom 1.argument, danas
	printf("%s;", pom);		//danas;
	printf("%s;", strchr(argv[2], 'je'));	//ispisujemo pointer koji pokazuje na rijec je u 2.argumentu | ispis: e;
	printf("%s", strstr(argv[3], "utorak"));	//ispisujemo pointer koji pokazuje na rijec utorak u 3. argumentu	| ispis: utorak;

	//REZULTAT: 4;danas;e;utorak;

}
