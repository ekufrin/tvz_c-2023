/*
TEKST ZADATKA:
Što se ispisuje izvođenjem donjeg programskog odsječka ?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

	int k[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int* p = &k[2];		//p pokazuje na adresu 2, odnosno broj 3
	p++;				//povecavamo adresu pointera za 1, p pokazuje na broj 4
	(*p)++;				//povecavamo vrijednost pointera, p je sada 5
	printf("%d %d %d", p, *p, &p);	//REZULTAT: -1401619644 5 -1401619592
	return 0;
}
