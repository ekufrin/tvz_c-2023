/*
TEKST ZADATKA:
Što ce se ispisati?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>


int main() {

	char c = 'a' + (short)5; //a+5 = f
	int x = c - 'A' + 10; // f(ASCII 102) - A(ASCII 65) = 37+10 = 47
	char d = ++x + c--; // d=48+102= 150	| x postaje 48	| c postaje slovo e

	printf("%d %c %d", x,c,d); // 48 e -106


	return 0;
}
