/*
TEKST ZADATKA:
Što se ispisuje izvođenjem donjeg programskog odsječka?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct {
	int len;
	char* str;
}*p,niz[4]={{3,"tri"},{5,"pet"},{6,"sest"}};

int main() {
   
	p = niz;
	do printf("%d%s;", p->len, p->str + 1); // Ispis bi bio: 3ri;5et;6est;
	while (p++ && p->len); //svaki put povecavamo adresu p (odnosno niza) za jedan, to jest, krecemo se po nizu dok ne izađemo izvan granica niza
	//p->len je pointer na int len u structu
	//p->str+1 je pointer na char* str u structu pomaknut za 1 slovo u desno;

	//1.ispis: niz[0].len je 3		|		niz[0].str+1 je tr
	//2.ispis: niz[1].len je 5		|		niz[1].str+1 je et
	//3.ispis: niz[2].len je 6		|		niz[2].str+1 je est


	return 0;
}
