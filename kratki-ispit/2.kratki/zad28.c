/*
TEKST ZADATKA:
Što ispisuje sljedeći programski odsječak?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int funkcija(int a, int* p) {
	return a++ + *(--p - a);
}

int main() {
	
	int polje[] = { 10,9,8,7,6,5,4,3,2,1 };

	for (int i = 1; i < 8; i++) {
		printf("%d ", funkcija(i, (polje + 8)));
	}

	//1.iteracija, i je 1, polje+8 pokazuje na broj 2
	//	1 + (--p pokazuje na adresu 7 - 1 mjesto)	| p pokazuje na adresu 6, broj 4 |	4+1=5
	//1.rezultat: 5

	//2.iteracija, i je 2, polje+8 pokazuje na broj 2
	// 2 +  (--p pokazuje na adresu 7 - 2 mjesta)	| p pokazuje na adresu 5, broj 5 |	5+2=7
	//2.rezultat: 7

	//3.iteracija, i je 3, polje+8 pokazuje na broj 2
	// 3 + (--p pokazuje na adresu 7 - 3 mjesta)	| p pokazuje na adresu 4, broj 6 |	6+3=9
	//3.rezultat: 9

	//......
	//Iz ovoga možemo shvatiti pattern, svaki put se rezultat povećava za 2, pa riješenje zadatka glasi:

	//REZULTAT: 5 7 9 11 13 15 17 

	
	return 0;
}
