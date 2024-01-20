/*
TEKST ZADATKA:
Što ispisuje sljedeći programski odsječak?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>


int main() {
	
	int polje[3][2] = { 1,4,6,7 };	// Matrica izgleda ovako:
									//		j=0		j=1
									//i=0	1		4
									//i=1	6		7
									//i=2	0		0
	int a, b, i, j;
	a = b = polje[0][0];	// varijable a i b imaju vrijednost 1

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 2; j++) {
			if (a == b) {				// varijable jednake, uvjet zadovoljen			
				a = polje[i + 2][j + 2];	//a postaje a[2][2], to je izvan granica matrice, dodjeljujemo neku random adresu, npr a=-8237123
			}
			if (b > a) {				// b(1) je veci od a(-8237123), uvjet zadovoljen
				if (i > 3 || j > 2)		// i nije veci od 3, nit je j veci od 2, uvjet nije zadovoljen
					break;
				b = polje[i++][j++];	// b postaje b[0][0]=1, povecavamo j 2x:
										//										1.put zbog ovog b = polje[i++][j++];
										//										2.put jer je kraj for petlje
										// j postaje 2, 2 < 2 nije istina, for petlja se prekida
										// i povecavamo 2x:
										//					1.put zbog ovog b = polje[i++][j++];
										//					2.put jer se J for petlja zavrsila, pa krecemo ispocetka
										// i je 2, j je 0
										// a==b je netocno, b>a je tocno, b=polje[2][0]=0
										// povecavamo opet j dvostruko, 2 < 2 nije istina, for petlja se prekida
										// povecavamo i dvostruko, 4<3 nije istina, for petlja se prekida
			}							// ispisujemo REZULTAT -8237123 0
		}
	}
	printf("%d %d", a, b); // -8237123 0

	return 0;
}
