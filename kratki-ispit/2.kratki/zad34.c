/*
TEKST ZADATKA:
U glavnoj funkciji definirano je polje i poziv funkcije f:
int polje[10] = {99};
printf("%d %d", f(&polje[6],2), f(&polje[0],7));

Koju vrijednost vraća funkcija arg: 
int f (int *a, int n) { 
	if(n==0){
		return 0;
	}
	return *a + f(a+1,n-1);
}
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f(int* a, int n) {	// a=0, n=2			|	a=99,n=7
	if (n == 0) {		//n je 2			
		return 0;
	}
	return *a + f(a + 1, n - 1); //0 + polje[7] je isto 0, n=1 + polje[8] je isto 0, n=0 zadovoljava if, prekidamo funkciju i vracamo broj 0 (0+0+0);
								 //99 + polje[1] je 0, n=6 i tako redom dok opet n ne bude 0 i zadovolji if uvjet, 99 + 0 + 0 + 0 + 0 + 0 + 0, prekidamo funkciju i vracamo broj 99
}

int main() {
	int polje[10] = { 99 };
	//polje[6] je 0
	//polje[0] je 99
	printf("%d %d", f(&polje[6], 2), f(&polje[0], 7)); // REZULTAT: 0 99
	
	
	

	return 0;

}
