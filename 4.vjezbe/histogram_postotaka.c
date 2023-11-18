/*
Napraviti histogram za uneseni niz brojeva.

Brojevi mogu biti u intervalu [0, 150].
Ispis treba u svakom retku za svaki broj bodova ispisati onoliko "iskića" koliko se u postocima (zaokruženo na najbliži cijeli broj) nalazi tih bodova u ukupnom nizu.

Primjer:
Za unos N = 5, i podatke 1, 2, 3, 4, 4, prvi retci bi izgledali ovako:
0: 
1: xxxxxxxxxxxxxxxxxxxx
2: xxxxxxxxxxxxxxxxxxxx
3: xxxxxxxxxxxxxxxxxxxx
4: xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

Objasnjenje: ima 20% "jedinica", 20% "dvojki", 40% "četvorki". 

TEST CASEOVI:

Test case #1
Ne ispisuju se sve vrijednosti ako je najveća vrijednost = 4. Samo se ispisuju vrijednosti od [0, 4] u tom slučaju.
Primjer ulaza:
5
1
2
3
4
4
Primjer izlaza:
0: 
1: xxxxxxxxxxxxxxxxxxxx
2: xxxxxxxxxxxxxxxxxxxx
3: xxxxxxxxxxxxxxxxxxxx
4: xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
Test case #2
Brojevi mogu biti uneseni bilokako
Primjer ulaza:
8
0    0 0 0
1 1         1 1
Primjer izlaza:
0: xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
1: xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
Test case #3
Primjer ulaza:
20
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
18
18
Primjer izlaza:
0: 
1: xxxxx
2: xxxxx
3: xxxxx
4: xxxxx
5: xxxxx
6: xxxxx
7: xxxxx
8: xxxxx
9: xxxxx
10: xxxxx
11: xxxxx
12: xxxxx
13: xxxxx
14: xxxxx
15: xxxxx
16: xxxxx
17: xxxxx
18: xxxxxxxxxxxxxxx


*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define MAX 100

int main() {
    
    int niz[150][150];
    int N;
    scanf("%d", &N);

    int max = -1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &niz[i][0]);
        if (niz[i][0] > max) {
            max = niz[i][0];
        }
    }

    double broj = 0;
    double postotak;

    for (int i = 0; i <= max; i++) {
        broj = 0;

        for (int j = 0; j < N; j++) {
            if (niz[j][0] == i) {
                broj++;
            }
        }

        postotak = round(broj / N * 100);

        if (i <= max) {
            printf("%d: ", i);
            for (int j = 0; j < postotak; j++) {
                printf("x");
            }
            printf("\n");
        }
    }


    return 0;
}
