/*
Napisati program koji učitava dimenzije matrice (dvodimenzionalnog polja) N i M, te nakon toga i njene cjelobrojne elemente.
Definirati da matrica smije biti maksimalne veličine 5x5. U slučaju da se za N i M unesu dimenzije izvan opsega zatražiti
ponovni unos dimenzija.
Program treba izračunati prosjek elemenata u svakom retku, te u novo jednodimenzionalno polje upisati samo one elemente
svakog retka koji su manji od izračunatog prosjeka za taj redak. Program treba ispisati matricu i tako dobiveno polje.


Test case #1
Prvo se unose dimenzije matrice N (retci) i M (stupci), a nakon toga elementi.
Primjer ulaza:
7
5
3
4
0 1 3 6 3 4 3 2 1 2 5 3

Ocekivani izlaz:
Dimenzije matrice ne odgovaraju rasponu!
Ponovo unesite dimenzije.

Ispis matrice:
0	1	3	6
3	4	3	2
1	2	5	3

Prosjek redaka: 2.50, 3.00, 2.75

Ispis 1D polja:
0, 1, 2, 1, 2


Test case #2
Prvo se unose dimenzije matrice N (retci) i M (stupci), a nakon toga elementi.
Primjer ulaza:
3
4
0 1 3 6 3 4 3 2 1 2 5 3

Ocekivani izlaz:
Ispis matrice:
0	1	3	6
3	4	3	2
1	2	5	3

Prosjek redaka: 2.50, 3.00, 2.75

Ispis 1D polja:
0, 1, 2, 1, 2


Test case #3
Prvo se unose dimenzije matrice N (retci) i M (stupci), a nakon toga elementi.
Primjer ulaza:
4
3
2 1 3 6 2 4 3 2 1 2 5 3

Ocekivani izlaz:
Ispis matrice:
2	1	3
6	2	4
3	2	1
2	5	3

Prosjek redaka: 2.00, 4.00, 2.00, 3.33

Ispis 1D polja:
1, 2, 1, 2, 3

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int N = 0, M = 0, br = 0;
	float prosjekRedaka[25] = {0};
	int polje2[25][25] = { 0 };
	int polje[50] = { 0 };

	scanf("%d", &N);
	scanf("%d", &M);

	if (N > 5 || M > 5) {
		printf("Dimenzije matrice ne odgovaraju rasponu!\nPonovo unesite dimenzije.\n");
		scanf("%d", &N);
		scanf("%d", &M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &polje2[i][j]);
			prosjekRedaka[i] += polje2[i][j];
		}
		prosjekRedaka[i] /= M;
	}

	printf("Ispis matrice:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d     ", polje2[i][j]);
			if (polje2[i][j] < prosjekRedaka[i]) {
				polje[br++] = polje2[i][j];
			}
		}
		printf("\n");
	}
	printf("Prosjek redaka: ");
	for (int i = 0; i < N; i++) {
		if (i != N - 1) {
			printf("%.2f, ", prosjekRedaka[i]);
		}
		else {
			printf("%.2f\n", prosjekRedaka[i]);
		}
		
	}

	printf("Ispis 1D polja:\n");
	for (int i = 0; i < br; i++) {
		if (i == br - 1) {
			printf("%d", polje[i]);
		}
		else {
			printf("%d, ", polje[i]);
		}
		
	}

	return 0;
}
