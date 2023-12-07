/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/eb91cc69777b76e48ae2a4cb424ff5b9ee27026d/tekstovi%20i%20test%20caseovi/%5B5%5DTransformacija%20znaka.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int provjera(char* niz, int size, int x, int y) {
    for (int i = 0; i < size; i++) {
        if (niz[i] + x < 'A' || niz[i] + x > 'Z' || niz[i] + y < 'A' || niz[i] + y < 'A') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char c = '.';
    int x = 0, y = 0;
    scanf(" %c %d %d", &c, &x, &y);
    while (c < 'A' || c > 'Z' || x < -20 || x > 20 || y < -20 || y > 20) {
        printf("Neispravan unos!");
        scanf(" %c %d %d", &c, &x, &y);
    }
    char niz[1000] = { '.' };
    int size = 1;
    char noviniz[1000];
    niz[0] = c;
    int koraci = 1;
    while (provjera(niz, size, x, y)) {
        int counter = 0;
        for (int i = 0; i < size; i++) {
            noviniz[counter++] = niz[i] + x;
            noviniz[counter++] = niz[i] + y;
        }
        size *= 2;
        for (int i = 0; i < size; i++) {
            niz[i] = noviniz[i];
        }
        printf("%d. korak: ", koraci);
        for (int i = 0; i < size; i++) {
            printf("%c", noviniz[i]);
        }
        printf("\n");
        koraci++;
    }
    printf("Konacni korak: ");
    for (int i = 0; i < size; i++) {
        printf("%c", noviniz[i]);
    }
    return 0;
}
