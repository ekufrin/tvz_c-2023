/*
2. Napisati program koji deklarira dva polja p1 i p2 od po N cjelobrojnih elemenata (N je simbolička konstanta s vrijednošću 20) i učitava cijeli broj K sve dok se ne unese broj u intervalu [5,N].
Nakon toga učitati K elemenata za prvo polje iz intervala [3,25]. Ako učitani broj nije iz zadanog intervala zanemariti ga i nastaviti učitavanje sve dok se polje ne popuni brojevima iz zadanog intervala.
Napisati funkciju koja treba iz prvog polja prebaciti parne brojeve u drugo polje, bez upotrebe pomoćnog polja, tako da na njihovom mjestu u prvom polju stavi 0, a u drugom polju budu redom samo parni brojevi.
U glavnom programu ispisati prvo polje prije prebacivanja, i oba polja poslije prebacivanja, svako polje u svoj red s fiksnom širinom 3 mjesta za svaki element polja, ali tako da se od prvog polja ispisuju samo vrijednosti različite od nula.



Test case #1
Primjer ulaza:
5
6
7
8
9
10

Primjer izlaza:
	6	7	8	9	10
	7	9
	6	8	10

Test case #2
Primjer ulaza:
6
1
2
3
4
5
6
7
8
Primjer izlaza:
	3	4	5	6	7	8
	3	5	7
	4	6	8

Test case #3
Primjer ulaza:
22
9
1
2
3
10
11
12
14
16
18
20
24

Primjer izlaza:
	3	10	11	12	14	16	18	20	24
	3	11
	10	12	14	16	18	20	24


*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#define N 20

void zamijeni(int p1[], int p2[],int K, int*brojac) {
	for (int i = 0; i < K; i++) {
		if (p1[i] % 2 == 0) {
			p2[*brojac] = p1[i];
			*brojac += 1;
			p1[i] = 0;
		}
	}

}

int main() {

	int p1[N] = { 0 };
	int p2[N] = { 0 };
	int i = 0;
	int K = 0;
	int brojac = 0;
	

	do {
		scanf("%d", &K);
	} while (K<5 || K>N);

	do {
		scanf("%d", &p1[i++]);
		if (p1[i - 1] < 3 || p1[i - 1]>25) {
			i--;
		}
	} while (i < K);

	for (int j = 0; j < K; j++) {
		printf("%3d", p1[j]);
	}
	printf("\n");
	
	zamijeni(p1, p2,K,&brojac);

	for (int j = 0; j < K; j++) {
		if (p1[j] != 0) {
			printf("%3d", p1[j]);
		}
		
	}
	printf("\n");

	for (int j = 0; j < brojac; j++) {
			printf("%3d", p2[j]);
	}

	

	return 0;

}
