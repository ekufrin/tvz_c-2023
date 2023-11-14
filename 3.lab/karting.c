/*
Mia, Nixa, Šuco i Sanela vole iæi na karting. Za 45 kuna mogu odvoziti 5 minuta. Ovisno o tome koliko je tko brz naprave razlièiti broj krugova. Na stazi postoji timer koji mjeri vrijeme svakog kruga, te na kraju vožnje 4 prijatelja dobe ispis vremena svakog odvoženog kruga. Nitko od njih nije dobar u matematici, ali znaju programirati, pa su napravili program koji raèuna prosjeèno vrijeme svakog vozaèa i ispisuje tko je bio prosjeèno najbrži.
U 5 minuta vožnje nitko ne napravi više od 10 krugova i na stazi istovremeno ne može biti više od 7 vozaèa.
Primjer izvoðenja njihovog koda možete vidjeti u test caseu. 
Probajte i vi napraviti takav program.

Prvo se unosi podatak koliko vozaèa je bilo na stazi, te za svakog vozaèa njegova vremena po krugovima.
Program nakon toga ispisuje prosjeèna vremena svih vozaèa, te tko je bio najbrži.
Primjer ulaza:
1
7 32.322 32.454 32.111 33.567 32.985 60.231 35.233
60.231
35.233
Primjer izlaza:
Vozac 1: 36.986
Najbrzi je: vozac 1
Test case #2 Primjer ulaza:
3
7 32.322 32.454 32.111 33.567 32.985 60.231 35.233
8 34.543 34.675 35.654 35.234 34.675 33.123 34.433 34.122
5 55.432 55.121 50.985 49.321 49.543
Primjer izlaza:
Vozac 1: 36.986
Vozac 2: 34.557
Vozac 3: 52.080
Najbrzi je: vozac 2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int N = 0, krugovi = 0,najbrzi=0;
	float vrijeme[10] = { 0 }, prosjek[10] = { 0 };

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &krugovi);
		for (int j = 0; j < krugovi; j++) {
			scanf("%f", &vrijeme[j]);
			prosjek[i] += vrijeme[j];
		}
		prosjek[i] /= krugovi;
	}


	for (int i = 0; i < N; i++) {
		printf("Vozac %d: %.3f\n", i+1, prosjek[i]);
		if (prosjek[i] > prosjek[i + 1]) {
			najbrzi = i;
		}
	}

	printf("Najbrzi je: vozac %d", najbrzi);



	return 0;
}