/*
Odlazite na city-break u grad Nully, u Francuskoj, i s obzirom da želite obiæi sve znamenitosti u jednom danu, imate vrlo ogranièen prostor u ruksaku.
Samim time, morate se odluèiti što želite ponijeti sa sobom. Stvarima koje želite ponijeti ste izmjerili težinu, i ocijenili koliko vam vrijede.
Primjerice,
- krema za sunèanje je teška 1kg, ali vrijedi 50 jedinica
- štit od Captain America je težak 4kg (plastièni) a vrijedi vam 75 jedinica
- sendviè od buðole je težak 2kg, i vrijedi 60 jedinica
- luft madrac je težak 1kg, ali vrijedi 10 jedinica

Pošto možete ponijeti samo 5kg, najoptimalnije je izabrati kremu za sunèanje i štit Captain America koji vrijede zajedno 125 jedinica. Druga opcija je da ponesete kremu, sendviè i luftiæ, i to vrijedi 120 jedinica. Što je zakljuèak? Neæete izgoriti i lijepo æete izgledati na slikama sa štitom, ali æete biti gladni.

S ulaza je potrebno uèitati dva broja K i N. K oznaèava koliko možete kilograma ponijeti u ruksaku, a N oznaèava broj dostupnih stvari od kojih morate izabrati
Nakon toga slijedi N redaka, a u svakom retku se nalazi broj T i V, gdje je T težina pojedine stvari a V je njena vrijednost.
Na kraju je potrebno ispisati jedan broj: koja je najveæa vrijednost koju je moguæe ponijeti.

Vrijedi: 1 <= K <= 1000, 1 <= N <= 1000, 0 <= T <= 1000, 0 <= V <= 1000.


Test case #1
Primjer iz teksta - mozemo ponijeti 5kg, imamo 4 stvari na izbor. Najbolje rjesenje se postize sa 125 jedinica vrijednosti.
Primjer ulaza:
5 4
1 50
4 75
2 60
1 10
Primjer izlaza:
125
Test case #2
Stane samo jedna stvar
Primjer ulaza:
5 5
3 20
4 30
5 40
3 50
4 10
Primjer izlaza:
50

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int K, N;
	int T[1000], V[1000];
	int Bodovi = 0;
	int Kilaza = 0;

	scanf("%d %d", &K, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &T[i], &V[i]);
	}

	for (int i = 0; i < N; i++) {
		if (Kilaza != K) {
			if (V[i] > Bodovi) {
				Bodovi += V[i];
				Kilaza += T[i];
			}
		}
	}

	printf("%d", Bodovi);


	return 0;
}