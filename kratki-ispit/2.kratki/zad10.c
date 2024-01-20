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

	char c = 'A' + 1;	//B
	char d = 'a' + 2;	//c
	char* pC = &c;	//Pointer pokazuje na B
	char* pD = &d;	//Pointer pokazuje na c
	char** ppX = &pD; //Pointer pokazuje na c
	**ppX = *pD + 2; //c+2 = e

	printf("%c %c %c", *(*ppX), *pC, *pD); // e B e


	return 0;
}
