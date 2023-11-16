/*
Potrebno je učitati prirodni broj N, te u idućoj liniji N cijelih brojeva. Nakon toga učitava se broj X, te slijedi X linija gdje se učitava broj Ai i Bi. Za svaki par Ai i Bi, treba broj Ai ubaciti na mjesto Bi u nizu (broji se od 1 ne od 0 - pogledati test primjere), te ispisati niz.
Primjer ulaza:  
5               
1 3 5 6 3
2
9 1
99 7
Primjer izlaza:
9 1 3 5 6 3
9 1 3 5 6 3 99

Primjer ulaza:
10
7 5 -4 6 8 44 3 1 -1 4
5
1 1
1 1
1 6
1 7
1 8
Primjer izlaza:
1 7 5 -4 6 8 44 3 1 -1 4
1 1 7 5 -4 6 8 44 3 1 -1 4
1 1 7 5 -4 1 6 8 44 3 1 -1 4
1 1 7 5 -4 1 1 6 8 44 3 1 -1 4
1 1 7 5 -4 1 1 1 6 8 44 3 1 -1 4
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int main() {
    
    int n, niz[MAX] = {}, x, ai, bi;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
    
    scanf("%d", &x);
    for (int i = 0; i < x; i++) { 
        n++;                  
        scanf("%d %d", &ai, &bi); 
        for (int j = n - 1; j >= bi; j--) { 
            niz[j] = niz[j - 1]; 
        }
        niz[bi - 1] = ai;
        for (int k = 0; k < n; k++) {
            printf("%d ", niz[k]);
        }
        printf("\n");
    }

    return 0;
}
