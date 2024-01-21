/*
TEKST ZADATKA:
Što ispisuje donji programski odsječak?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>



int main() {
	
	char c = 'F';
	while (c-- < 'P') {	// F<P, smanjujemo c za 1, postaje E	|	G<P, smanjujemo c za 1, postaje F		| H<P,smanjujemo c za 1, postaje G		| J<P,smanjujemo c za 1, postaje I		| M<P, smanjujemo c za 1, postaje L		| Q<P, netočno, izlazimo iz petlje
		printf("%c", c);// EFGIL
		c += (c - 'A') / 2;// E+(E-'A')/2 = E+4/2 = E+2=G		|	F+(F-'A')/2 = F+5/2= F+2 = H			| G+(G-'A')/2 = H+6/2 = G+3 = J			| I+(I-'A')/2 = I+8/2 = I+4 = M			| L+(L-'A')/2 = L+11/2 = L+5 = Q
	}

	// REZULTAT: EFGIL

	return 0;
}
