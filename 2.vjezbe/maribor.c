/*
Boštjan izraðuje aplikaciju za pametni kalendar. Kao jednu od osnovnih funkcionalnosti, potrebno je napraviti modul za izraèun toènog datuma u odnosu na zadani trenutak u vremenu.

Kao prvi parametar, potrebno je uèitati brojeve D, M, G H, m i s, koji predstavljaju dan, mjesec, godinu, sat, minutu i sekundu. Ukoliko je godina manja od 1900 ili veæa od 2015, potrebno je ponoviti upis. Nakon toga potrebno je ucitati prirodni broj K.

Kao rezultat, potrebno je ispisati toèan datum (dan, mjesec, godinu i vrijeme) uveæan za K sekundi u odnosu na poèetni datum.

Primjerice, ukoliko se unese datum 10.09.2015 15:45:30, i za uneseni broj sekundi K = 45, rezultat bi bio 10.09.2015 15:46:15 (poèetni datum uveæan za 1min i 15s).
svi datumi æe biti u ispravnom formatu (osim možda godine, koja ako ne spada u gore navedeni interval, treba ponoviti upis - pogledati test primjere za pojašnjenje)
za broj sekundi vrijedi, 0 < K < 232
priprema sadrži 10 test primjera, od kojih su 2 skrivena test primjera. Za dobivanje boda, potrebno je da kod radi za 80% primjera. Za prisustvo vježbi potrebno je da priprema radi za 20% primjera
potrebno je samostalno istražiti pravila prijestupne godine

Test case #1
Datum je: 23.10.2015 10:52:11. Broj K = 567, te nas zanima koji je toèan datum i vrijeme nakon što proðe 567 sekundi.
Primjer ulaza:
23 10 2015 10 52 11
567

Primjer izlaza:
23.10.2015. 11:01:38
Test case #2
Prvotno uèitana godina = 2016, što je izvan dopuštenog intervala. Nakon toga je uèitana godina 176 koja je isto izvan dopuštenog intervala.
Primjer ulaza:
23 10 2016 10 52 11
23 10 176 10 52 11
1 1 1952 10 00 00
992

Primjer izlaza:
1.1.1952. 10:16:32
Test case #3
Primjer ulaza:
15 2 2011 11 05 05
32432

Primjer izlaza:
15.2.2011. 20:05:37
Test case #4
Primjer ulaza:
31 12 2014 23 59 59
1

Primjer izlaza:
1.1.2015. 00:00:00
Test case #5
Primjer ulaza:
31 12 2013 23 59 59
31536001

Primjer izlaza:
1.1.2015. 00:00:00
Test case #6
Primjer ulaza:
2 2 1967 23 11 59
3227692765

Primjer izlaza:
15.5.2069. 12:31:24
Test case #7
Primjer ulaza:
1 1 1900 0 0 0
3987692765

Primjer izlaza:
13.5.2026. 20:26:05
Test case #8
Primjer ulaza:
5 7 1904 5 5 5
675876789

Primjer izlaza:
4.12.1925. 20:38:14

*/


// ZADATAK RADI SAMO ZA DIO TEST CASEOVA / NIJE DOVRŠEN !!!!!!!!!

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	long long int D, M, G, H, m, s;
	long long int K;
	int MjesecParan = 0;

	do {
		scanf("%lld %lld %lld %lld %lld %lld", &D, &M, &G, &H, &m, &s);
	} while (G < 1900 || G>2015);

	scanf("%lld", &K);

	while (K > 0) {
		
		if (s <= 60) {
			s++;
			K--;
			if (s == 60) {
				m++;
				s = 0;
				if (m == 60) {
					H++;
					m = 0;
				}
				if (H == 24) {
					if (D != 31) {
						D++;
						H = 0;
					}
					else {
						H = 0;
						
					}
					
				}
				if (D == 31) {
					if (M != 12) {
						M++;
						D = 0;
					}
					else {
						D = 0;
					}
					
				}
				if (M == 12) {
					if (G % 100 == 0 && G % 400 == 0) {
						D++;
						printf("OVA GODINA JE PRIJESTUPNA!!! \N \N");
					}
					G++;
					M = 0;
					
				}
				
			}
			
		}
	}

	if (D == 0) {
		D = 1;
	}
	if (M == 0) {
		M = 1;
	}

	printf("%lld.%lld.%lld. %.2lld:%.2lld:%.2lld",D,M,G, H, m, s);



	return 0;
}