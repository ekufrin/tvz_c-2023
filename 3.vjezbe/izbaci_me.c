/*
Potrebno je učitati prirodni broj N i broj K, te u idućoj liniji N cijelih brojeva. Kao rješenje potrebno je ispisati niz:
Bez izbačenih najvećih K brojeva
Bez izbačenih najmanjih K brojeva

Primjer ulaza:
5 1
1 3 5 6 3
Primjer izlaza:
1 3 5 3
3 5 6 3

Primjer ulaza:
10 3
7 5 -4 6 8 44 3 1 -1 4
Primjer izlaza:
5 -4 6 3 1 -1 4
7 5 6 8 44 3 4

Primjer ulaza:
2 1
1 2
Primjer izlaza:
1
2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int n, k, niz[100] = {};

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }

    int maxBrojac = n, maxNiz[100] = {}, maxIndex[100] = {};
    for (int i = 0; i < n; i++) {
        maxNiz[i] = niz[i];
    }
    for (int i = 0; i < k; i++) {
        int max = -1000;
        for (int j = 0; j < maxBrojac; j++) {
            if (maxNiz[j] > max) {
                max = maxNiz[j];
                maxIndex[i] = j;
            }
        }
        for (int w = maxIndex[i]; w < maxBrojac - 1; w++) {
            maxNiz[w] = maxNiz[w + 1];
        }
        maxBrojac--;
    }
    for (int i = 0; i < maxBrojac; i++) {
        printf("%d ", maxNiz[i]);
    }
    printf("\n");

    int minBrojac = n, minNiz[100] = {}, minIndex[100] = {};
    for (int i = 0; i < n; i++) {
        minNiz[i] = niz[i];
    }
    for (int i = 0; i < k; i++) {
        int min = 1000;
        for (int j = 0; j < minBrojac; j++) {
            if (minNiz[j] < min) {
                min = minNiz[j];
                minIndex[i] = j;
            }
        }
        for (int w = minIndex[i]; w < minBrojac - 1; w++) {
            minNiz[w] = minNiz[w + 1];
        }
        minBrojac--;
    }
    for (int i = 0; i < minBrojac; i++) {
        printf("%d ", minNiz[i]);
    }

    return 0;
}
