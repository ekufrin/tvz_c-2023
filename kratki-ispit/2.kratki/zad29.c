/*
TEKST ZADATKA:
Što ispisuje sljedeći programski odsječak?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
	
	const char* tekst = "Danas je utorak!", * p = tekst;	//Pointer pokazuje na slovo D
	for (int i = 0; i < 2; i++) {
		p = p + (strlen(tekst) / 3 + 1);	//0.iteracija D + 16/3 + 1 | D + 5 + 1	| D + 6	| p pokazuje na slovo j
											//1.iteracija j + 16/3 + 1 | j + 5 + 1  | j + 6 | p pokazuje na slovo r
		printf("%s", p);	// ispisujemo: je utorak!		|	ispisujemo: rak!
	}
	
	//REZULTAT: je utorak!rak!

	return 0;
}
