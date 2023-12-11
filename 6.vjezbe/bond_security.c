/*
Na početku je potrebno učitati 1 <= N, M <= 50 koji predstavljaju broj redaka (N) i broj stupaca (M) kofera koji se skenira. Nakon toga učitavaju se znakovi koji mogu biti točka (.) ili nešto iz skupa znakova: +|-*#.

Nakon toga potrebno je učitati broj 1 <= K <= 10 koji predstavlja broj opasnih predmeta koji su evidentirani u sustavu. Svaki opasni predmet je također zadan kao matrica, ali fiskne visine i širine: 6x6.

Vaš zadatak je ispisati koji se opasni predmeti nalaze u koferu, a ako opasnih predmeta nema ispisati adekvatnu poruku. Napomena: predmeti mogu biti zarotirani za 90, 180 ili 270 stupnjeva, te i takve kombinacije treba provjeriti.

Postupak kako rijesiti zadatak (moraju se koristiti funkcije navedene dolje)

1.) Kreirati funkciju "char** trim(char mat[][6], int* rezN, int* rezM) (alternativno umjesto char** može biti char* ako se koristi 1D polje za spremanje matrice - slajd 47 u predavanjima) koja prima kao ulazni parametar matricu veličine 6x6 te alocira memoriju za novu matricu još nepoznate veličine, koja miče nepotrebne "točke" za svaki predmet koji se nalazi na popisu opasnih predmeta. Primjer:
ulaz:
..|...
..|...
..|...
..|...
.+++..
.|||..
izlaz:
.|.
.|.
.|.
.|.
+++
|||
Prije prelaska na korak 2) istestirati funkciju i utvrditi da radi kako treba tako da se isproba za sve predmete koji se nalaze na popisu. Preko parametara rezN i rezM se u pozivatelja vraćaju nove veličine matrice. Za gornji primjer, rezN će biti 6, a rezM će biti 3. Nepotrebne točke se miču na način da se odredi koliko je stupaca prazno i koliko je redaka potpuno prazno, te se oni izbace. Možete si pomoći da dodate funkciju koja provjerava je li neki redak ili stupac prazan.

2.) Napisati funkciju "char** rotate90(char** predmet, int n, int m)" (alternativno umjesto char** može biti char* ako se koristi 1D polje za spremanje matrice - slajd 47 u predavanjima) koja rotira ulaznu matricu za 90 stupnjeva i vraća novu alociranu matricu.
ulaz:
.|.
.|.
.|.
.|.
+++
|||
izlaz:
....+-
----+-
....+-
Prije prelaska na idući korak istestirati radi li funkcija dobro. Imati na umu da se onda vrijednosti 'n' i 'm' zamijene.

3.) U main programu, učitati glavnu matricu (kofer), te za svaki predmet:
Učitati predmet u matricu 6x6
Pozvati funkciju "trim" i spremiti vrijednosti koje vraća u nove varijable. Ispisati rezultat "trim" funkcije
Pozvat 3 puta za redom funkciju "rotate" i nakon svakog poziva ispisati i uvjeriti se da radi ispravno
4.) Napisati funkciju "int locate(char kofer[][MAX], int n, int m, char** predmet, int pN, int pM)" ili alternativno umjesto char** može biti char* ako se koristi 1D polje za spremanje matrice (slajd 47 u predavanjima) (kofer je glavna matrica koja predstavlja kofer, n i m su veličine kofera; char** predmet je matrica koja predstavlja jedan predmet nakon što je pozvana funkcija "trim" ili "rotate", a pN i pM je broj redaka i broj stupaca u matrici za predmet). Funkcija locate vraća 0 ili 1 ovisno o tome je li uspjela pronaći predmet u koferu. Kod pronalaska predmeta, bitno je da svi znakovi koji se nalaze u predmetu (a nisu točkice) se u istom redoslijedu nalaze na nekoj poziciji u koferu. Ostali znakovi u koferu oko predmeta se ignoriraju. Primjerice, ako je predmet:
.|.
-+-
.|.
a kofer:
#*|.
-+-
..|+
Tada se traženi predmet nalazi ovdje:
#|.
*-+-
..|+

5.) Spojiti sve skupa: u main funkciji, za svaki predmet, pozvati trim, zatim provjeriti sa "locate" nalazi li se predmet u koferu, nakon toga pozvati rotate90, pa opet locate, pa rotate90, pa locate, pa rotate90 pa locate. Ako bilo koji locate vrati "1", tada dodati predmet na listu pronadjenih predmeta (najbolje u posebni niz).
Upload koda:
Source
Test case #1
Prvo se učitava snimka kofera (4x8), a nakon toga 1 opasni predmet na popisu - taj opasni predmet je mač. Ako zarotiramo taj mač za 90° obrnuto od kazaljke na satu, možemo primjetiti kako se podudara sa mačem koji se nalazi u koferu, te se ispisuje obavijest upozorenja.
Primjer ulaza:
4 8
........
....|...
----+-..
....|...
1
.|....
.|....
.|....
.|....
-+-...
.|....
Primjer izlaza:
Opasni predmeti: 1
VODI GA!
Test case #2
Primjer ulaza:
6 15
....+-.....###.
----+-..|.#####
....+-.-+-.###.
.---....|.....
..###...|.....
.+..|.....
2
.....
.....
.....
.###..
#####.
.###..

..|...
..|...
..|...
..|...
.+++..
.|||..
Primjer izlaza:
Opasni predmeti: 1 2
VODI GA!
Test case #3
Primjer ulaza:
6 15
....+-.....###.
----+...|.#####
....+-.-+-.###.
.---....|.....
..###...|.....
.+.*.|......
2
.....
.....
.....
.###..
#####.
.###..

..|...
..|...
..|...
..|...
.+++..
.|||..
Primjer izlaza:
Mozete proci.
Test case #4
Primjer ulaza:
6 15
....+-.....###.
-##-+...-.##**#
|...+-.|+|.###|
|---.--.-.--.|
|.###...-....|
|+.*.-......
4
.....
.....
.....
.###..
#####.
.###..

..|...
..|...
..|...
..|...
.+++..
.|||..

......
.---+.
...|.
.##|.
.*..|.
.---+.

......
.----.
......
......
......
......
Primjer izlaza:
Opasni predmeti: 4
VODI GA!
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char** trim(char mat[][6], int* rezN, int* rezM) {
    int prazniR[6];
    int prazniS[6];
    int r = 0;
    int s = 0;
    char** trimMat = (char**)malloc(sizeof(char*) * (*rezN));

    for (int i = 0; i < *rezN; i++) {
        trimMat[i] = (char*)malloc(sizeof(char) * (*rezM));
    }

    //Provjera koji redovi se mogu kratiti

    for (int i = 0; i < (*rezN); i++) {

        int x = 0;

        for (int j = 0; j < (*rezM); j++) {
            if (mat[i][j] != '.') {
                x++;
            }
        }
        if (x == 0) {
            prazniR[i] = 1;
        }
        else {
            prazniR[i] = 0;
        }
    }

    //Provjera koji stupci se mogu kratiti

    for (int i = 0; i < (*rezM); i++) {

        int x = 0;

        for (int j = 0; j < (*rezN); j++) {
            if (mat[j][i] != '.') {
                x++;
            }
        }
        if (x == 0) {
            prazniS[i] = 1;
        }
        else {
            prazniS[i] = 0;
        }
    }

    int ks;

    for (int i = 0; i < (*rezN); i++) {
        s = 0;
        if (prazniR[i] == 0) {
            for (int j = 0; j < (*rezM); j++) {
                if (prazniS[j] == 0) {
                    trimMat[r][s] = mat[i][j];
                    s++;
                }
            }
        }
        if (s > 0) {
            ks = s;
            r++;
        }
    }
    if (r > 0) {
        (*rezN) = r;
        (*rezM) = ks;
    }

    return trimMat;

}

char** rotate90(char** predmet, int n, int m) {
    char** rotMat;

    rotMat = (char**)calloc(m, sizeof(char*));

    for (int i = 0; i < m; i++) {
        rotMat[i] = (char*)calloc(n, sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (predmet[i][j] == '|') {
                rotMat[m - 1 - j][i] = '-';
            }
            else if (predmet[i][j] == '-') {
                rotMat[m - 1 - j][i] = '|';
            }
            else {
                rotMat[m - 1 - j][i] = predmet[i][j];
            }
        }
    }

    return rotMat;
}

int locate(char kofer[][50], int n, int m, char** predmet, int pN, int pM) {
    int nT = 0;

    for (int i = 0; i < pN; i++) {
        for (int j = 0; j < pM; j++) {
            if (predmet[i][j] != '.') {
                nT++;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = 0;
            for (int r = 0; r < pN; r++) {
                for (int s = 0; s < pM; s++) {
                    if (predmet[r][s] != '.' && predmet[r][s] == kofer[r + i][s + j]) {
                        x++;
                    }
                }
            }
            if (x == nT) {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int rezN = 6;
    int rezM = 6;
    char mat[6][6];
    char kofer[50][50];

    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &kofer[i][j]);
        }
    }

    int brPredmeta;
    int niz[100] = { 0 };
    int da = 0;

    scanf("%d", &brPredmeta);

    for (int k = 0; k < brPredmeta; k++) {
        rezN = 6;
        rezM = 6;




        for (int i = 0; i < rezN; i++) {
            for (int j = 0; j < rezM; j++) {
                scanf(" %c", &mat[i][j]);
            }
        }


        // 0 stupnjeva
        char** trimMat = trim(mat, &rezN, &rezM);
        int x = locate(kofer, n, m, trimMat, rezN, rezM);

        if (x == 1) {
            niz[da] = k + 1;
            da++;
        }

        


        // 90 stupnjeva
        char** rotMat = rotate90(trimMat, rezN, rezM);
        x = locate(kofer, n, m, rotMat, rezM, rezN);

        if (x == 1) {
            niz[da] = k + 1;
            da++;
        }

        
        
        // 180 stupnjeva
        rotMat = rotate90(rotMat, rezM, rezN);
        x = locate(kofer, n, m, rotMat, rezN, rezM);

        if (x == 1) {
            niz[da] = k + 1;
            da++;
        }

        
        
        // 270 stupnjeva
        rotMat = rotate90(rotMat, rezN, rezM);
        x = locate(kofer, n, m, rotMat, rezM, rezN);

        if (x == 1) {
            niz[da] = k + 1;
            da++;
        }

        
        
        
        for (int i = 0; i < rezN; i++) {
            free(trimMat[i]);
        }
        free(trimMat);

        for (int i = 0; i < rezM; i++) {
            free(rotMat[i]);
        }
        free(rotMat);


    }

    if (niz[0] > 0) {
        printf("Opasni predmeti:");
        for (int i = 0; i < da; i++) {
            if (niz[i] != niz[i + 1]) {
                printf(" %d", niz[i]);
            }
        }
        printf("\nVODI GA!");
    }
    else {
        printf("Mozete proci.");
    }


    return 0;
}
