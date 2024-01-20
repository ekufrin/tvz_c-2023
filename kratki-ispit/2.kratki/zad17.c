/*
TEKST ZADATKA:
Što će se ispisati?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

int ispis(int k) {		// k=10
	if (k == 0) {		// uvjet nije zadovoljen
		return 1;
	}
	printf("%d", k);	// ispisujemo k
	ispis(k % 2);		// ponovo pozivamo funkciju, 10%2 = 0, uvjet k==0 je zadovoljen, funkcija ne ispisuje ništa
	printf("%d", k);	// nastavljamo dalje i ispisujemo opet k;
}

int main() {
	
	ispis(10);	// REZULTAT 1010

	return 0;
}
