/*
TEKST ZADATKA 404 :(

TEST CASEOVI:

TEST CASE #1
Most je dugačak 4 metra, i izgleda ovako (O = rupa, X = put kojim je išao pijanac - uočiti da pijanac kreće od sredine i u prvom koraku zatetura lijevo ili desno na most):
OO..
X...
>X.XOO
..X.
...X
Primjer ulaza:
4
LRRR 1133
Primjer izlaza:
Prezivio, na 5. metru sirine.

TEST CASE #2
Malo ga zanijelo...
.X...O...X
XOXOO...XO
XO.OX...XO.
....X.XO..
.....XO...
Primjer ulaza:
10
LLRRRRLLLL
3232215432
Primjer izlaza:
Prezivio, na 1. metru sirine.

TEST CASE #3
Primjer ulaza:
22
LRRLRLLRLRLRRRLRLLRLRL 5521543543512453145341
Primjer izlaza:
Steta pao u rupu na 10. metru mosta!

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX 100

int main() {

    int N;
    scanf("%d", &N);
    int niz1[MAX][MAX] = { 0 };

    char pomak;
    int brojacRED = 2;
    int brojacSTUPAC = 0;
  
    for (int i = 0; i < N; i++) {
        scanf(" %c", &pomak);
        if ((pomak == 'L' && brojacRED == 0) || (pomak == 'R' && brojacRED == 4)) {
            printf("Steta - pao preko ruba na %d. metru mosta!", brojacSTUPAC + 1);
            return;
        }
        else if (pomak == 'L') {
            brojacRED--;
            niz1[brojacRED][brojacSTUPAC] = 8;
        }
        else if (pomak == 'R') {
            brojacRED++;
            niz1[brojacRED][brojacSTUPAC] = 8;
        }
         
        brojacSTUPAC++;
    }

    char rupa;
    int brojacREDrupa = 0;
    int brojacSTUPACrupa = 0;

    for (int i = 0; i < N; i++) {
        scanf(" %c", &rupa);

        if (rupa == '1') {
            brojacREDrupa = 0;
            if (niz1[brojacREDrupa][brojacSTUPACrupa] == 8) {
                niz1[brojacREDrupa][brojacSTUPACrupa] = 1;
                printf("Steta - pao u rupu na %d. metru mosta!", brojacSTUPACrupa + 1);
                return;
            }
        }
        else if (rupa == '2') {
            brojacREDrupa = 1;
            if (niz1[brojacREDrupa][brojacSTUPACrupa] == 8) {
                niz1[brojacREDrupa][brojacSTUPACrupa] = 1;
                printf("Steta - pao u rupu na %d. metru mosta!", brojacSTUPACrupa + 1);
                return;
            }
        }
        else if (rupa == '3') {
            brojacREDrupa = 2;
            if (niz1[brojacREDrupa][brojacSTUPACrupa] == 8) {
                niz1[brojacREDrupa][brojacSTUPACrupa] = 1;
                printf("Steta - pao u rupu na %d. metru mosta!", brojacSTUPACrupa + 1);
                return;
            }
        }
        else if (rupa == '4') {
            brojacREDrupa = 3;
            if (niz1[brojacREDrupa][brojacSTUPACrupa] == 8) {
                niz1[brojacREDrupa][brojacSTUPACrupa] = 1;
                printf("Steta - pao u rupu na %d. metru mosta!", brojacSTUPACrupa + 1);
                return;
            }
        }
        else if (rupa == '5') {
            brojacREDrupa = 4;
            if (niz1[brojacREDrupa][brojacSTUPACrupa] == 8) {
                niz1[brojacREDrupa][brojacSTUPACrupa] = 1;
                printf("Steta - pao u rupu na %d. metru mosta!", brojacSTUPACrupa + 1);
                return;
            }
        }
        brojacSTUPACrupa++;
    }

    if (brojacSTUPAC == N && niz1[brojacRED][brojacSTUPAC - 1] == 8) {
        printf("Prezivio, na %d. metru sirine.", brojacRED + 1);
    }

    return 0;
}
