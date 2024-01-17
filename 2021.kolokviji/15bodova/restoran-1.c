/*
TEKST ZADATKA,  I POTREBNE DATOTEKE ISTE KAO ZA: https://github.com/emanuelkufrin/tvz_c-2023/blob/8e19afd4eb3a7d0d4b8be73344b3d7f0c1316bdb/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DRestoran%202.zip

RAZLIKA U ZADATKU JE DA U OVOM ZADATKU TREBA PROVJERITI JE LI KOLIČINA DOVOLJNA ZA NAPRAVITI NEKO JELO, AKO NIJE, TREBA ISPISATI U DATOTEKU KOLIKO ČEGA FALI.

TEST CASEOVI:
TEST CASE #1:
Ulaz:
spageti
1
luk
1
soja sos
1
0

Izlaz:
Ne treba kupiti nista.


TEST CASE #2:
ulaz:
mljeveno meso
15
luk
10
cesnjak
7
ljuta paprika
4
pelati rajcice
12
grah
17
0

izlaz:
pelati rajcice#povrce#10

TEST CASE #3:
Ulaz:
tortilje
8
mljeveno meso
1
grah
2
luk
1
kukuruz
1
tabasco
1
0

Izlaz:
tortilje#tjestenina#6
kukuruz#povrce#1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char ime[30 + 1];
    char rok_trajanja[30 + 1];
    char vrsta[30 + 1];
    int kolicina;
    float cijena;
}namirnice;


void provjera(FILE* izlaz, namirnice popis[], int vel, char namirnica[], int kolicina);

int main()
{
    FILE* ulaz = fopen("ostava.dat", "rb");
    FILE* izlaz = fopen("lista.txt", "w");

    namirnice popis[100];

    char namirnica[50];
    int kolicina;

    fseek(ulaz, 0, SEEK_END);
    int vel = ftell(ulaz) / sizeof(namirnice);
    fseek(ulaz, 0, SEEK_SET);


    fread(popis, sizeof(namirnice), vel, ulaz);

    while (1) {
        scanf("%[^\n]%*c", &namirnica);
        if (strcmp(namirnica, "0") == 0) {
            break;
        }
        scanf("%d%*c", &kolicina);
        provjera(izlaz, popis, vel, namirnica, kolicina);

    }

    if (ftell(izlaz) == 0) {
        fprintf(izlaz, "Ne treba kupiti nista.");
    }

    fclose(ulaz);
    fclose(izlaz);

    return 0;
}
void provjera(FILE* izlaz, namirnice popis[], int vel, char namirnica[], int kolicina) {
    for (int i = 0; i < vel; i++) {
        if (strcmp(namirnica, popis[i].ime) == 0) {
            if (kolicina > popis[i].kolicina) {
                fprintf(izlaz, "%s#%s#%d\n", popis[i].ime, popis[i].vrsta, kolicina-popis[i].kolicina);
            }
        }
    }

}
