/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/c5eca6ce29a1d9d170d6d9807ed8a0b3c75fe585/tekstovi%20i%20test%20caseovi/%5B5%5DZvjezdica.u.nizu.2.pdf
*/

#include <stdio.h>
#define MAX 100

void ubaci(char niz[], int brojac, char a, char b);

int main() {
   
    char niz[MAX], a, b;
    int brojac = 0;
    
    do {
        scanf(" %c", &niz[brojac++]);   
    } while (niz[brojac - 1] != '#');

    scanf(" %c %c", &a, &b);   
    
    ubaci(niz, brojac, a, b);

    return 0;
}

void ubaci(char niz[], int brojac, char a, char b) {
    int sadrziPodniz = 0;
    
    for (int i = 0; i < brojac - 1; i++) {
        if (niz[i] == a && niz[i + 1] == b) {
            sadrziPodniz = 1;
            break;
        }
    }
    
    if (sadrziPodniz) {
        for (int i = 0; i < brojac - 1; i++)  {
            printf("%c", niz[i]);
            if (niz[i] == a && niz[i + 1] == b && sadrziPodniz == 1) {
                printf("*");
                sadrziPodniz = 0;
            }
        }
    } else {
        printf("Mirko ne voli ovaj niz.");
    }
}
