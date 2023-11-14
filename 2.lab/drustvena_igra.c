/*
Napišite C program koji računa pobjednika u nekoj društvenoj igri i traži najbolji krug. U igri sudjeluju dva tima, a igra traje N krugova
Od korisnika se traži unos broja krugova N, dok se ne upiše broj između 1 i 10. Nakon toga se od korisnika traži unos N rezultata krugova igre (po jedan broj za svaki tim).
Pobjednik je onaj tim s većim brojem bodova. Osim pobjednika, program treba ispisati i u kojem krugu je postignut najveći ukupni broj bodova i koliki je taj broj.
Ispis neka bude u obliku "Najveci broj bodova
postignut je u krugu, a ukupni pobjednik je_tim."
U slučaju da je broj bodova između timova izjednačen, potrebno je ispisati poruku u obliku "Najveci broj bodova postignut je u krugu. Timovi imaju jednake bodove."
Na crte treba ispisati odgovarajuće brojeve.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int N, tim1 = 0,tim2 = 0,runda=0,brojkruga=0,pobjednik=0,btim1=0,btim2=0;
	do {
		scanf("%d", &N);
	} while (N<1 || N > 10);

	for (int i = 1; i < N+1; i++) {
		scanf("%d %d", &tim1, &tim2);
		btim1 += tim1;
		btim2 += tim2;
		if (tim1 + tim2 > runda) {
			runda = tim1 + tim2;
			brojkruga = i;
		}
	}

	if (btim1 > btim2) {
		pobjednik = 1;
	}
	else if (btim1 < btim2) {
		pobjednik = 2;
	}
	else if (btim1 == btim2) {
		printf("Najveci broj bodova %d postignut je u %d. krugu. Timovi imaju jednake bodove.", runda, brojkruga);
		return 0;
	}

	printf("Najveci broj bodova %d postignut je u %d. krugu, a ukupni pobjednik je %d. tim.", runda, brojkruga, pobjednik);

	return 0;
}