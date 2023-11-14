/*
Ana ima niz kriterija prema kojima bira svog idealnog partnera. Vi ste tu da joj pomognete da si lakše i brže izabere svog idealnog partnera.

Na poèetku je potrebno uèitati Anine kriterije za izbor:
interval za visinu u centimetrima - dva cijela broja u intervalu (50, 250], te razlika veæeg i manjeg ne smije biti veæa od 35
interval za težinu u kilogramima - dva cijela broja u intervalu  [50, 100], te razlika veæeg i manjeg mora biti veæa od 5
interval za broj godina .- dva cijela broja u intervalu (15, 100), te razlika veæeg i manjeg mora biti toèno 5
Za svaki interval koji se uèitava potrebno je tražiti ponovni unos oba cijela broja iz intervala ukoliko gornja pravila nisu zadovoljena.

Nakon toga potrebno je uèitati cijeli broj N u intervalu (3, 20]. Takoðer tražiti ponovni unos ako broj nije u intervalu.

Zatim uèitati N podataka o potencijalnim partnerima: visinu, tezinu i broj godina.

Na kraju programa ispisati koliko partnera odgovara Aninim zahtjevima. Partner odgovara zahtjevima ako zadovoljava sva 3 uvjeta.

Test case #1
Voli visoke, mlade a tezina nije faktor.
Primjer ulaza:
50 85
220 250
50 100
15 20
16 20
16 21
4
225 75 22
225 75 17
219 101 15
175 80 17
Primjer izlaza:
Nepravilni unos visine!
Nepravilni unos godina!
Nepravilni unos godina!
Prolazi kriterije: 1 osoba.
Test case #2
Voli niske, deblje i sto starije. Takodjer, paziti ako je vise od 1 osobe, da padez odgovara.
Primjer ulaza:
45 100
50 90
55 90
49 101
50 101
70 71
95 100
90 100
17 23
95 100
94 99
3
4
225 75 22
55 90 94
55 95 95
57 99 99
Primjer izlaza:
Nepravilni unos visine!
Nepravilni unos visine!
Nepravilni unos tezine!
Nepravilni unos tezine!
Nepravilni unos tezine!
Nepravilni unos tezine!
Nepravilni unos godina!
Nepravilni unos godina!
Nepravilni unos broja partnera!
Prolazi kriterije: 3 osobe.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int n = 0, visina1=0, visina2=0, tezina1=0, tezina2=0, godine1=0, godine2 = 0;
	int brvisina = -1, brtezina = -1, brgodine = -1, brpartnera=-1, potencijalniPartneri=0;
	int visina[10] = { 0 }, tezina[10]={0}, godine[10]={0};

	do {
		//printf("UNESI VISINU \n");
		scanf("%d %d", &visina1, &visina2);
		brvisina++;
	} while (visina1 <= 50 || visina2 <= 50 || visina1>250 || visina2>250 || abs(visina2 - visina1) > 35);

	do {
		//printf("UNESI TEZINU \n");

		scanf("%d %d", &tezina1, &tezina2);
		brtezina++;
	} while (tezina1 < 50 || tezina2 < 50 || tezina1 >100 || tezina2 > 100 || abs(tezina2 - tezina1) <= 5);

	do {
		//printf("UNESI GODINE \n");

		scanf("%d %d", &godine1, &godine2);
		brgodine++;
	} while (godine1 <= 15 || godine2 <= 15 || godine1>=100 || godine2>=100 || abs(godine2 - godine1) != 5);

	do {
		//printf("UNESI BR PARTNERA \n");

		scanf("%d", &n);
		brpartnera++;
	} while (n <= 3 || n>20);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &visina[i], &tezina[i], &godine[i]);
		if(visina[i] >= visina1 && visina[i]<= visina2 && tezina[i] >= tezina1 && tezina[i] <= tezina2 && godine[i] >= godine1 && godine[i] <= godine2){
			potencijalniPartneri++;
		}
	}

	for (int i = 0; i < brvisina; i++) {
		printf("Nepravilni unos visine!\n");
	}

	for (int i = 0; i < brtezina; i++) {
		printf("Nepravilni unos tezine!\n");
	}
	for (int i = 0; i < brgodine; i++) {
		printf("Nepravilni unos godina!\n");
	}
	for (int i = 0; i < brpartnera; i++) {
		printf("Nepravilni unos broja partnera!\n");
	}

	if (potencijalniPartneri == 1) {
		printf("Prolazi kriterije: %d osoba.", potencijalniPartneri);
	}
	else {
		printf("Prolazi kriterije: %d osobe.", potencijalniPartneri);

	}

	return 0;
}