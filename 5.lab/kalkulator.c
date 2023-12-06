/*
Napisati funkciju kalkulator koja za zadane brojeve i oznaku matematičke operacije ('+', '-', '*' ili '/'') računa odgovarajuću
vrijednost. U glavnoj funkciji potrebno je s tipkovnice unositi brojeve i spremiti ih u jednodimenzionalno polje, te učitati
oznaku matematičke operacije. Prije samog unosa elemenata potrebno je od korisnika zatražiti podatak o tome koliko
brojeva želi unijeti. Ovisno o unesenom operatoru u funkciji obaviti odgovarajuću matematičku operaciju nad unesenim
brojevima i vratiti rezultat glavnoj funkciji. Ispisati rezultat. Postupak se ponavlja sve dok se za oznaku matematičke
operacije ne unese znak koji ne predstavlja jednu od gore navedenih matematičkih operacija.

1. Test case

Prvo se unosi aritmetička operacija, zatim broj elemenata, te vrijednosti elemenata.

Ulaz:
+
5
5 3 -4 6 12
T

Izlaz:
22



2. Test case

Prvo se unosi aritmetička operacija, zatim broj elemenata, te vrijednosti elemenata.

Ulaz:
+
5
5 3 -4 6 12
-
3
2 -3 12
T

Izlaz:
22
-7



3. Test case

Prvo se unosi aritmetička operacija, zatim broj elemenata, te vrijednosti elemenata.

Ulaz:
+
5
5 3 -4 6 12
-
3
2 -3 12
*
3
3 -3 1
/
3
22 3 -4
T

Izlaz:
22
-7
-9
-1.83
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

float kalkulator(int niz[], char operacija, int n) {
	int zbroj = 0, razlika = 0, mnozenje = 1, brojacD = 0;
	float djeljenje = 1;
for(int i=0;i<n;i++){
	if (operacija == '+') {
		zbroj += niz[i];
	}
	else if (operacija == '-') {
		if (i != 0) {
			razlika -= niz[i];
		}
		else {
			razlika = niz[i];
		}

	}
	else if (operacija == '*') {
		mnozenje *= niz[i];
	}
	else if (operacija == '/') {
		if (i != 0) {
			djeljenje /= niz[i];
		}
		else {
			djeljenje = niz[i];
		}
	}
}

	if (operacija == '+') {
		return zbroj;
	}
	else if (operacija == '-') {
		return razlika;
	}
	else if (operacija == '*') {
		return mnozenje;
	}
	else if (operacija == '/') {
		return djeljenje;
	}
}


int main() {

	char operacija='+';
	int niz[20] = { 0 };
	int n = 0;

	while (operacija == '+' || operacija == '-' || operacija == '*' || operacija == '/') {
		scanf(" %c", &operacija);
		if (operacija == '+' || operacija == '-' || operacija == '*' || operacija == '/') {
			scanf("%d", &n);
			for (int i = 0; i < n; i++) {
				scanf("%d", &niz[i]);
			}
			if (operacija == '/') {
				printf("%.2f\n",kalkulator(niz, operacija, n));
			}
			else {
				printf("%d\n", (int)kalkulator(niz, operacija, n));
			}
		}
		else {
			return 0;
		}

	}

	return 0;

}
