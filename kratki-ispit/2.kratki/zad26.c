/*
TEKST ZADATKA:
Želite napraviti program koji se pokreće iz komandne linije, te mu proslijeđujete dva parametra - cijele jednoznamenkaste brojeve A i B. 
Primjerice, ako se program pokreće iz konzole, to izgleda ovako: > program.exe 2 5
Napišite main funkciju i odsječak koda koji sprema brojeve A i B u varijable int a i int b i ispisuje njihov zbroj.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(int argc, char* argv[]) {
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("%d", a + b);
}
