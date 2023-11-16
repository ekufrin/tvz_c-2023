/*
Mala Anica nikako ne može naučiti tablicu množenja, te je odlučila zamoliti svoje prijatelje s TVZ-a (Vas) koji uče programirati u C-u da joj napišu program koji će joj za određeni broj K ispisati rezultate množenja svih parnih brojeva od 1 do N sa zadanim brojem. Anica je načula od svojih prijatelja iz škole da će ju učiteljica pitati tablicu množenja tako da zadani broj pomnoži samo s parnim brojevima i izrecitira rezultate na način da prvih X i posljednjih Y brojeva kaže normalnim redoslijedom, a one u sredini obrnutim redoslijedom. 

Potrebno je učitati brojeve N, K, X i Y, te ispisati rezultate u traženom formatu.

X+Y će biti manji od N/2, tj., vrijedi X+Y < N/2.

Primjer ulaza:
10 7
1 2
Primjer izlaza:
14
42
28
56
70

Primjer ulaza:
20 2
5 3
Primjer izlaza:
4
8
12
16
20
28
24
32
36
40
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int n, k, x, y;
    int broj[100] = {};

    scanf("%d %d", &n, &k);
    do {
        scanf("%d %d", &x, &y);
    } while (x + y >= n / 2);

    int brojevi = 0;
    for (int i = 2; i <= n; i += 2) {
        broj[brojevi] = i * k;
        brojevi++;
    }
                                                              
    for (int i = 0; i < (brojevi - x - y) / 2; i++) {  
        int temp = broj[x + i]; 
        broj[x + i] = broj[brojevi - y - i - 1]; 
        broj[brojevi - y - i - 1] = temp; 
    }

    for (int i = 0; i < brojevi; i++) {
        printf("%d\n", broj[i]);
    }

    return 0;
}
