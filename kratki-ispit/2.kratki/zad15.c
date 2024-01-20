/*
TEKST ZADATKA:
Definirana je struktura tocka prema sljedecem:
typedef struct{
int x;
int y;
}tocka;

Napisite odsječak programa u C u kojem treba deklarirati lokalne varijable a i b strukture tocka i učitati koordinate u ravnini x i y za obje točke.
Izračunati udaljenost d od tocke a do tocke b, i ispisati na standardnom izlazu.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
typedef struct {
	int x;
	int y;
}tocka;


int main() {
	
	tocka a, b;	//kreiramo varijable a i b 
	double d;
	scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);	//skeniramo x i y kordinate točke a i točke b
	d = (double)sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2)); // formula za udaljenost dvije točke glasi: korijen iz (a.x-b.x)^2 + (a.y-b.y)^2
	printf("%lf", d);

	return 0;
}
