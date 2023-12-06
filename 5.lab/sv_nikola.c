/*Sv. Nikola je ove godine odlučio darivati djecu na malo drugačiji način - odlučio je uzeti u obzir veličinu očišćenih cipela u
prozoru i ovisno o tome koliki je zbroj znamenki u broju, ostaviti toliko darova. Da broj darova ipak ne bude prevelik,
ograničio se samo na jednoznamenkasti broj darova - ako je rezultat zbrajanja dvoznamenkasti broj, provodi ponovni
postupak zbrajanja znamenki sve dok ne dobije jednu znamenku.
Pomozite Sv.Nikoli da izračuna koliko mora ostaviti darova svakom djetetu tako da napišete program koji će na početku
tražiti unos broja djece N u nekoj zgradi ( u zgradi nema manje od 1 djeteta niti više od 25) i zatim u niz unositi N veličina
cipela.
Program ispisuje novi niz u kojem su zapisani brojevi poklona za svako dijete.
Provjera zadanog intervala mora se obaviti u jednoj funkciji, a izračun broja darova za svako dijete u drugoj funkciji.
Dozvoljeno je koristiti i više funkcija za ostale dijelove programa.

Test case #1
Primjer ulaza:
4
27 31 26 34

Primjer izlaza:
9 4 8 7

Test case #2
Primjer ulaza:
0
30
1
33

Primjer izlaza:
Nedozvoljeno
Nedozvoljeno
6

Test case #3
Primjer ulaza:
40
Nedozvoljeno
10
37 24 30 29 30 32 34 28 38 25

Primjer izlaza:
1 6 3 2 3 5 7 1 2 7
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 200

int zbrojZnamenki(int a) {
	int zbrZnm = 0;
	int temp = a;
	while (temp != 0) {
		zbrZnm += temp % 10;
		temp /= 10;
	}

	if (zbrZnm >= 10) {
		int temp = zbrZnm;
		zbrZnm = 0;
		while (temp != 0) {
			zbrZnm += temp % 10;
			temp /= 10;
		}
	}
	return zbrZnm;
}

int provjera(int a){
	int provj = 1;
	if (a < 1 || a > 25) {
		provj = 0;
	}
	return provj;
}

int main()
{
	int a, niz[MAX];
	scanf("%d", &a);
	int prov = provjera(a);
	while (provjera(a) == 0) {
		printf("Nedozvoljeno\n");
		scanf("%d", &a);
	}

	for (int i = 0; i < a; i++) {
		scanf("%d", &niz[i]);
		niz[i] = zbrojZnamenki(niz[i]);
	}

	for (int i = 0; i < a; i++) {
		printf("%d ", niz[i]);
	}
	return 0;
	
}
