/*
TEKST ZADATKA:
Što se ispisuje izvođenjem sljedećeg programskog odsječka?
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>



int main() {


	int x = 4, y = 1;
	while (--x) {
		for (y = 2; y + 3 > x / 3; y -= x / 2 + 1) {
			printf("%d ", y);
		}
		printf("\n");
	}

	//x=3, Idemo 1.put kroz petlju, y(2) + 3 > x(3)/3 točno, printamo 2, y-=x(3)/2+1 , y-=2 y=2-2=0	| Idemo 2.put kroz petlju, y(0) + 3 > x(3)/3 točno, printamo 0, y-=x(3)/2+1 , y-=2 y=0-2=-2		|	y(-2)+3 > x(3)/3 netočno, izlazimo iz petlje	
	//x=2, Idemo 1.put kroz petlju, y(2) + 3 > x(2)/3 točno, printamo 2, y-=x(2)/2+1 , y-=2 y=2-2=0	| Idemo 2.put kroz petlju, y(0) + 3 > x(2)/3 točno, printamo 0, y-=x(2)/2+1 , y-=2 y=0-2=-2		|	Idemo 3.put kroz petlju, y(-2)+3>x(2)/3 točno, printamo -2, y-=x(2)/2+1, y-=2, y=-2-2=-4		|	Y(-4)+3 > x(2)/3 netočno, izlazimo iz petlje
	//x=1, Idemo 1.put kroz petlju, y(2) + 3 > x(1)/3 točno, printamo 2, y-=x(1)/2+1 , y-=1 y=2-1=1	| Idemo 2.put kroz petlju, y(1) + 3 > x(2)/3 točno, printamo 1, y-=x(1)/2+1 , y-=1 y=1-1=0		|	Idemo 3.put kroz petlju, y(0)+3>x(2)/3 točno, printamo 0, y-=x(1)/2+1, y-=1, y=0-1=-1			|	Idemo 4.put kroz petlju, y(-1)+3>x(2)/3 točno, printamo -1, y-=x(1)/2+1, y-=1, y=-1-1=-2	|	Idemo 5.put kroz petlju, y(-2)+3>x(2)/3 točno, printamo -2, y-=x(1)/2+1, y-=1, y=-2-1=-3	|	Y(-3)+3 > x(1)/3 netočno, izlazimo iz petlje

	//	REZULTAT:
	//	2 0
	//	2 0 -2
	//	2 1 0 -1 -2

	return 0;
}
