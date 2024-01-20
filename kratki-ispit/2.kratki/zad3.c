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
	printf("%d%s;", p->len, p->str + 1); // Ispis bi bio: 3ri;

	//p->len je pointer na int len u structu, sto za niz[0] iznosi 3
	//p->str+1 je pointer na char* str u structu, sto za niz[0] iznosi tri, ali posto je +1 znaci da preskacemo prvo slovo i ispisujemo samo tr



	return 0;
}
