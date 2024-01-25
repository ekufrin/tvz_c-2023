/*
TEKST ZADATKA:
U glavnoj funkciji definirano je polje i poziv funkcije arg:
int polje[4] = {13};
printf("%d", arg (&polje[0],3));
Koju vrijednost vraća funkcija arg: 
int arg (int *b, int n) { 
	int i=0,gg=*b,*p=b;
do{
	if(*p<gg) gg=*p;
} while (++i<n && p++);
return gg;
}
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arg(int* b, int n) {
	int i = 0, gg = *b, * p = b;	//gg=13, p=polje[0]=13
	do {
		if (*p < gg) gg = *p;	// 13<13? NE			|	0<13? DA, gg=0			|	0<0? NE
	} while (++i < n && p++);	// i=1<3, p=polje[1]=0	|	i=2<3 , p=polje[2]=0	|	i=3<3 ? NE, prekidamo
	return gg;	//vracamo 0
}

int main() {
	int polje[4] = { 13 };
	printf("%d", arg(&polje[0], 3));	// REZULTAT: 0
	

	return 0;

}
