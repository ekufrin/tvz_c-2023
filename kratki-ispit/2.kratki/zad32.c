/*
TEKST ZADATKA:
Napisati koju vrijednost vraća funkcija "arg":
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arg(int* b, int n) {
	int i = 6, gg = *b, * p = b + 3;	//gg=10	, p=40
	do {
		if (*p > gg) {					//40>10	? DA						|	50>41 ? DA
			gg = *p + 1;				//gg=41;							|   gg=51;
		}
	} while (++i < (n + 3) && p++);	//i=7 < 5+3 && p++ pokazuje na broj 50	|	i=8 < 5+3 NE, prekidamo petlju
	return gg;	// vraćamo 51
}


int main() {
	
	int polje[10] = { 10,20,30,40,50,60,70,80,90,100 };
	printf("%d", arg(&polje[0], 5));	//REZULTAT: 51
	

	return 0;

}
