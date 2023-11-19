/*
Uselili ste u novu kuću koja na 3 kata, s podrumom. Sve je pregledano i namješteno, jedino još nemate hrabrosti pregledati stari i dugo godina nekorišteni podrum. Došli ste na ideju da si pomognete na način da napravite sondu koja će sići u podrum i sa nekih specifičnih koordinata odaslati informacije o tlocrtu podruma.

Sonda funkcionira na način da stane na neku cjelobrojnu koordinatu (x, y) i pošalje informaciju o tome koliko je udaljen zid sjeverno, istočno, južno i zapadno od njene trenutne lokacije (cijeli brojevi brojevi s,i,j,z). Vaš zadatak je da na temelju podataka koje je sonda poslala, odredite tlocrt podruma.

Podrum se sastoji od nekoliko soba povezanih vratima a odvojenih zidovima debljine 1. Sonda nikad neće slati signale kraj vrata (signal neće prolaziti kroz vrata i na taj način dati lažnu informaciju). Svaka soba ima oblik pravokutnika

U prvoj liniji ulaznih podataka nalazi se broj N (N < 100) - broj očitanja sonde. U svakom sljedećem retku nalaze se brojevi x, y, s, i, j, z (x,y,s,i,j,z < 100), odvojeni razmacima. Neće biti nemogućih ulaznih podataka.

TEST CASE:

Test case #1
Jednostavni primjer - sonda se nalazi u červrtastoj sobi i očitavanje izgleda ovako:
#######
#.|...#
#-S---#
#.|...#
#######
x - redni broj lokacije od lijeva na desno
y - redni broj lokacije odozgo dolje
Primjer ulaza:
1
3 3 1 3 1 1
Primjer izlaza:
#######
#.....#
#.....#
#.....#
#######
Test case #2
Može biti više očitanja u istoj sobi
Primjer ulaza:
2
2 2 0 4 2 0
6 4 2 0 0 4
Primjer izlaza:
#######
#.....#
#.....#
#.....#
#######
Test case #3
Dvije sobe, po jedno očitanje u svakoj. Lokaciju vrata nije moguće dobiti iz podataka, pa ih ne treba niti ucrtavati.
Primjer ulaza:
2
2 2 0 4 2 0
8 3 1 1 1 0
Primjer izlaza:
##########
#.....#..#
#.....#..#
#.....#..#
##########
Test case #4
Primjer ulaza:
9
2 2 0 0 0 0
2 4 0 0 0 0
2 6 0 0 0 0
4 2 0 3 0 0
4 4 0 3 0 0
4 6 0 3 0 0
7 2 0 0 0 3
6 4 0 1 0 2
5 6 0 2 0 1
Primjer izlaza:
########
#.#....#
########
#.#....#
########
#.#....#
########
Test case #5
Mogu biti i više očitanja s istog mjesta
Primjer ulaza:
3
2 2 0 0 0 0
2 2 0 0 0 0
2 2 0 0 0 0
Primjer izlaza:
###
#.#
###
Test case #6
Primjer ulaza:
11
33 2 0 16 0 31
18 4 0 3 0 16
23 4 0 26 0 0
9 6  0 1 0 7
22 6 0 3 0 10
31 6 0 4 0 4
14 9 1 21 0 12
44 8 2 5 1 7
2 11 0 47 0 0
2 13 0 19 0 0
23 13 0 26 0 0
Primjer izlaza:
##################################################
#................................................#
##################################################
#....................#...........................#
##################################################
#.........#..............#.........#.............#
####################################.............#
#..................................#.............#
#..................................#.............#
##################################################
#................................................#
##################################################
#....................#...........................#
##################################################
Test case #7
Primjer ulaza:
4
2 2 0 2 1 0
10 2 0 0 2 4
3 5 0 1 1 1
10 6 0 0 0 4
Primjer izlaza:
###########
#...#.....#
#...#.....#
#####.....#
#...#######
#...#.....#
###########
Test case #8
Primjer ulaza:
3
2 2 0 8 4 0
3 3 1 7 3 1
4 4 2 6 2 2
Primjer izlaza:
###########
#.........#
#.........#
#.........#
#.........#
#.........#
###########
Test case #9
Primjer ulaza:
3
2 3 1 0 1 0
4 2 0 1 0 0
4 4 0 1 0 0
Primjer izlaza:
######
#.#..#
#.####
#.#..#
######
Test case #10
Primjer ulaza:
4
2 2 0 0 0 0
4 2 0 0 0 0
4 4 0 0 0 0
2 4 0 0 0 0
Primjer izlaza:
#####
#.#.#
#####
#.#.#
#####

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, i, j, k;
    int x, y, sjever, istok, jug, zapad;
    int min_col = 1000, min_row = 1000, max_col = 0, max_row = 0;

    int ocitanja[100][6];
    char podrum[1000][1000];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++)
            scanf("%d", &ocitanja[i][j]);
    }

    for (i = 0; i < n; i++) {
        x = ocitanja[i][0];
        y = ocitanja[i][1];
        sjever = ocitanja[i][2];
        istok = ocitanja[i][3];
        jug = ocitanja[i][4];
        zapad = ocitanja[i][5];

        for (j = y - sjever - 2; j < y + jug + 1; j++) {
            for (k = x - zapad - 2; k < x + istok + 1; k++) {
                if (j == y - sjever - 2 || j == y + jug || k == x - zapad - 2 || k == x + istok) {
                    podrum[j][k] = '#';
                }
                else {
                    podrum[j][k] = '.';
                }

                if (j < min_row) min_row = j;
                if (j > max_row) max_row = j;
                if (k < min_col) min_col = k;
                if (k > max_col) max_col = k;
            }
        }
    }

    for (i = min_row; i <= max_row; i++) {
        for (j = min_col; j <= max_col; j++) {
            printf("%c", podrum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
