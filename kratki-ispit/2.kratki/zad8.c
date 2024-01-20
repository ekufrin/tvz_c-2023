/*
TEKST ZADATKA:
Što se ispisuje izvođenjem donjeg programskog odsječka?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	int dva= 2, pet = 7;
	int* pDva= &pet;
	int* pSedam = &dva;
	*pDva= *pSedam * pet;
	printf("%d %d %d", *pDva, *pSedam, dva); // 14 2 2


	return 0;
}
