/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/29787c78a508b8a98d438b1e60e528bdb6972db5/tekstovi%20i%20test%20caseovi/%5B5%5Dbranimir.i.rukomet.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX 150

int sumaZnamenki(int a, int b) {
    int sumaZnamenki = 0;
    for (int i = a; i <= b; i++) {
        int temp = i;
        while (temp) {
            sumaZnamenki += temp % 10;
            temp /= 10;
        }
    }
    return sumaZnamenki;
}

int brojDijelitelja(int a, int b) {
    int brojDijelitelja = 0;
    for (int i = a; i <= b; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                brojDijelitelja++;
            }
        }
    }
    return brojDijelitelja;
}

int main() {

    int n;
    scanf("%d", &n);

    int a, b, niz[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (brojDijelitelja(a, b) == 0) {
            niz[i] = 0;
        }
        else {
            niz[i] = sumaZnamenki(a, b) % brojDijelitelja(a, b);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (niz[j] > niz[i]) {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }

    printf("%d", niz[0]);
    for (int i = 1; i < n; i++) {
        printf(", %d", niz[i]);
    }

    return 0;
}
