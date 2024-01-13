/*DRUGI ZADATAK KOLOKVIJ
Zadatak: Prijatelji su odigrali partiju drustvene strateske igre u kojoj broj bodova ovisi o ramjestaju figura na ploci. Napisite program koji racuna
pobjednika u svakoj partiji, ako su pravila igre sljedeca: Igraju dva igraca, C crni i B bijeli sa po tri figurice svaki. Svaka figurica nosi 1 bod.
Ploca je velicine nxm, pri cemo se broj n unosi na pocetku programa. Osim figurica igraca, postoje jos dvije dodatne figurice - Z zmaj koji ponistava bodove i
V vitez koji donosi dvostruke bodove. U onom retku i stupcu u kojem se nalazi zmaj, figurice igraca ne donose nikakve bodove, a vitez donosi dvostruke bodove
svakoj figurici igraca koja se nalazi u istom retku ili stupcu s njim.
Program ispisuje pobjednika za zadanju ulaznu plocu s postavljenim figuricama.
Test case #1: Test case #2: Test case #3:
Ulaz: Ulaz: Ulaz:
4 5 5
CCC. .C..C .C..C
V..Z BB..Z BB..Z
B... B..C. B..C.
BB.. ..... .....
Izlaz: V.... .V...
Pobjednik: B Izlaz: Izlaz:
Bodova: 5 Nema pobjednika. Pobjednik: C
Bodova: 3
*/
int main() {
int N;
char ploca[10][10];
scanf("%d", &N);
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
scanf(" %c", &ploca[i][j]);
}
}

int redviteza = 0, stupacviteza = 0;
int redzmaja = 0, stupaczmaja = 0;
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        if (ploca[i][j] == 'V') {
            redviteza = i;
            stupacviteza = j;
        }
        else if (ploca[i][j] == 'Z') {
            redzmaja = i;
            stupaczmaja = j;
        }
    }
}
int bodoviB = 0, bodoviC = 0;
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        if (ploca[i][j] == 'B') {
            if (i == redzmaja || j == stupaczmaja) {
                continue;
            }
            else if (i == redviteza || j == stupacviteza) {
                bodoviB += 2;
            }
            else {
                bodoviB++;
            }
        }
        if (ploca[i][j] == 'C') {
            if (i == redzmaja || j == stupaczmaja) {
                continue;
            }
            else if (i == redviteza || j == stupacviteza) {
                bodoviC += 2;
            }
            else {
                bodoviC++;
            }

        }
    }
}
if (bodoviB > bodoviC) {
    printf("Pobjednik: B\nBodova: %d", bodoviB);
}
else if (bodoviC > bodoviB) {
    printf("Pobjednik: C\nBodova: %d", bodoviC);
}
else {
    printf("Nema pobjednika");
}
return 0;
}
