/*
. Napisite C program koji ce ucitati matricu brojeva (gdje je svaki broj manji od 100000000), te provesti x operacija nad matricom. Svaka operacija ce zamjeniti svaki broj u matrici zbrojem njegovih znamenki. Nakon zavrsetka potrebno je ispisati najmanji i najveci broj koji se nalaze u matrici, zajedno s retkom i stupcem u kojem se nalaze. Ukoliko ima vise istih brojeva, potrebno je ispisati onog koji se nalazi u manjem retku. Ukoliko se dva broja nalaze u istom retku, ispisati onaj koji se nalazi u manjem stupcu.

Na pocetku se ucitavaju prirodni brojevi n i m koji oznacavaju broj redaka i broj stupaca matrice, te broj x koji oznacava broj transformacija koje je potrebno provesti nad matricom. Potom je potrebno ucitati matricu i na kraju ispisati trazeni rezultat.

Nema test case-ova
*/

#include <stdio.h>

#define MAX 10

int zbrojZnamenki(int broj) {
    int zbrojZnamenki = 0;
    while (broj > 0) {
        zbrojZnamenki += broj % 10;
        broj /= 10;
    }
    
    return zbrojZnamenki;
}

int main() {

    int n, m, x;
    
    scanf("%d %d", &n, &m);
    int matrica[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrica[i][j]);
        }
        printf("\n");
    }
    
    scanf("%d", &x);
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                matrica[j][k] = zbrojZnamenki(matrica[j][k]);
                printf("%d ", matrica[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    int min = 1000, max = 0, minRedak = 0, maxRedak = 0, minStupac = 0, maxStupac = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrica[i][j] > max) {
                    max = matrica[i][j];
                    maxRedak = i + 1;
                    maxStupac = j + 1;
                } 
            else if (matrica[i][j] == max) {
                    if (i + 1 < maxRedak) {
                        max = matrica[i][j];
                        maxRedak = i + 1;
                        maxStupac = j + 1;
                    } else if (j + 1 < maxStupac) {
                        max = matrica[i][j];
                        maxRedak = i + 1;
                        maxStupac = j + 1;
                    }
                }
            else if (matrica[i][j] < min) { 
                    min = matrica[i][j];
                    minRedak = i + 1;
                    minStupac = j + 1;
                }
            else if (matrica[i][j] == max) {
                    if (i + 1 < maxRedak) {
                        max = matrica[i][j];
                        maxRedak = i + 1;
                        maxStupac = j + 1;
                    } else if (j + 1 < maxStupac) {
                        max = matrica[i][j];
                        maxRedak = i + 1;
                        maxStupac = j + 1;
                    }
                }
        }
    }
    
    printf("Najveci element matrice je %d i nalazi se u %d. redu i %d. stupcu.\n", max, maxRedak, maxStupac);
    printf("Najmanji element matrice je %d i nalazi se u %d. redu i %d. stupcu.", min, minRedak, minStupac);
    
    
    return 0;
}
