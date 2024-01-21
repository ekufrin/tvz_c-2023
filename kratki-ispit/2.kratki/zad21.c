/*
TEKST ZADATKA:
Što se ispisuje izvođenjem donjeg programskog odsječka?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>



int main() {

	char* b = "Vani pada snijeg", * p = b++;

	for (*p++; *p++; putchar(*p++));

	// *p je "Vani pada snijeg", b uvećavamo za 1, *p pokazuje na [0] slovo odnosno slovo  V.
	// 1.iteracija, *p++ pokazivati će na slovo "a", zatim opet *p++ će pokazivati na "n", sa putchar spremamo slovo "n" u string;
	// 2.iteracija, *p pokazuje na "n", povećavamo za 1, pokazuje na i, opet povećavamo za 1, pokazuje na space, spremamo space u string;
	// 3.iteracija, *p pokazuje na space, povećavamo za 1, pokazuje na p, opet povećavamo za 1, pokazuje na a, spremamo "a" u string;
	// 4.iteracija, *p pokazuje na "a", povećavamo za 1, pokazuje na d, opet povećavamo za 1, pokazuje na a, spremamo "a" u string;
	// 5.iteracija, *p pokazuje na "a", povećavamo za 1, pokazuje na space, opet povećavamo za 1, pokazuje na s, spremamo "s" u string;
	// 6.iteracija, *p pokazuje na "s", povećavamo za 1, pokazuje na n, opet povećavamo za 1, pokazuje na i, spremamo "i" u string;
	// 7.iteracija, *p pokazuje na "i", povećavamo za 1, pokazuje na j, opet povećavamo za 1, pokazuje na e, spremamo "e" u string;
	// 8.iteracija, *p pokazuje na "e", povećavamo za 1, pokazuje na g, opet povećavamo za 1, izlazimo iz granica polja, prekidamo petlju.

	// REZULTAT: n aasie

	return 0;

}
