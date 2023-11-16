#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    
    int P=0, N=0, rezultat=0;
    char polje[50] = { 0 };
    int segmenti[50] = { 0 };

    scanf("%d", &P);
    for (int i = 0; i <= P; i++) {
        scanf("%c", &polje[i]);
    }

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &segmenti[i]);

    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= segmenti[i];j++){
            if (polje[j] == '.') {
                rezultat += 1;
            }
            else if (polje[j] == 'v') {
                rezultat += 2;
            }
            else if (polje[j] == 'x') {
                rezultat += 4;
            }
            
        }
        printf("%d. segment: Nakon %d dana\n", segmenti[i], rezultat);
        rezultat = 0;
    }

    return 0;
}
