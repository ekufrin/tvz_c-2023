/*
Pala je kiša, i čeljad se nalazi na mostu. Most je širok 5m, i dugačak N metara. Svako dijete se nalazi na jednom metru mosta (gledajući po širini). Oni se nakon toga zatrče na drugi kraj mosta, i pobjednik je onaj koji ugazi u više lokvi. Svaki metar na mostu se nalazi lokva, koja može biti na 1., 2. 3. 4. ili 5. metru (ako gledamo širinu mosta - pogledati objašnjenje prvog test primjera).
Vaš zadatak je, na temelju informacija o lokvama na mostu, ispisati na koju širinu mosta je najbolje stati ako želimo pobijediti. Ukoliko ima više najboljih mjesta, potrebno je ispisati da će se pričekati iduća kiša jer samo pobjeda se priznaje - nikakvo neriješeno.

Test case #1
Most je dugačak 4 metra, i izgleda ovako (o lokva):
>0...
>.00.
>...0
>....
Primjer ulaza:
4
1223
Primjer izlaza:
Najbolje je stati na 2. metar, gazi se ukupno u 2 lokvi.

Test case #2
Primjer ulaza:
10
3232233432
Primjer izlaza:
Najbolje je stati na 3. metar, gazi se ukupno u 5 lokvi.

Test case #3
50
52413521435214352145321453421534125435
214351435245
Primjer izlaza:
Najbolje je stati na 5. metar, gazi se ukupno u 12 lokvi.

Test case #4
Primjer ulaza:
10
1234512345
Odaberi zadatak
Primjer izlaza:
Nema pobjednika, cekaj iducu kisu.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	int skup[100] = { 0 };
	int skup2[5] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%1d", &skup[i]);

	}
	for (int i = 0; i < N; i++) {
		if (skup[i] == 1) {
			skup2[0]++;

		}
		if (skup[i] == 2) {
			skup2[1]++;

		}
		if (skup[i] == 3) {
			skup2[2]++;

		}
		if (skup[i] == 4) {
			skup2[3]++;

		}
		if (skup[i] == 5) {
			skup2[4]++;

		}

	}
	
	
	//odredimo max od skup2
	int max = skup2[0];
	int najmetar = 1;
	for (int i = 1; i < 5; i++) {
		if (skup2[i] > max) {
			max=skup2[i];
			najmetar = i + 1;
		}
		
	}
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		if(skup2[i]==max){
			cnt++;
		}
	}
	if (cnt == 1) {

		printf("Najbolje je stati na %d. metar, gazi se ukupno u %d lokvi.", najmetar, max);
	}
	else {
		printf("Nema pobjednika, cekaj iducu kisu.");
	}
	
}
