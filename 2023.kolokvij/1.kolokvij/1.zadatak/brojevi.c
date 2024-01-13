#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
/*
PRVI ZADATAK KOLOKVIJ
Zadatak: unos x y a b, ispisi brojeve u intervalu[x,y) koji su dijeljivi s a ili b ali ne oba istovremeno
*/

int main()
{
int x, y, a, b;
scanf("%d %d", &x, &y);
scanf("%d %d", &a, &b);
for (x; x < y; x++) {
if (x % a == 0 && x % b != 0) {
printf("%d\n", x);
}
else if (x % a != 0 && x % b == 0) {
printf("%d\n", x);
}
}
}
