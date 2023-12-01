/*
Napisati C program koji s tipkovnice učitava prirodne brojeve sve dok se ne unese 0 ili dva uzastopna ista broja. Ako je unesen broj koji ne spada u skup prirodnih brojeva, zanemaruje se. Program ispisuje koliko je bilo unosa i koliko je od toga bilo brojeva čija je suma znamenki jednoznamenkasti broj.

TEST CASEOVI:

Test case #1 
Primjer ulaza:
24
2048
378
5
0
Primjer izlaza:
Bilo je 4 ispravnih unosa, od toga 2 ciji je zbroj znamenki jednoznamenkast.

Test case #2
Prije završetka programa, oba dvostruka un osa se provjeravaju da li zadovoljavaju uvjete zadatka.
Primjer ulaza:
113
113
Primjer izlaza:
Bilo je 2 ispravnih unosa, od toga 2 ciji je zbroj znamenki jednoznamenkast.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int a = 1,mat[100],b,i=0;
    while (a != 0) {
        scanf("%d", &b);
        if (a == b) {
            mat[i] = b;
            i += 1;
            break;
        }
        if (b== 0) break;
        if (b > 0) {
            mat[i] = b;
            i += 1;
        }
        else continue;
        a = b;
    }
    int broj,z,s=0,br=0;
    for (int j = 0; j < i; j++) {
        broj = mat[j];
        while (broj > 0) {
            z = broj % 10;
            s += z;
            broj = broj / 10;
        }
        if (s < 10) br += 1;
        s = 0;
    }
    printf("Bilo je %d ispravnih unosa, od toga %d ciji je zbroj znamenki jednoznamenkast.", i, br);
    return 0;
}
