/*
TEKST ZADATKA:
Trebali smo isprogramirati pojednostavljenu verziju igre Super Mario. Na početku se učitava broj redaka i stupaca matrice, te matrica igre. U matrici znak 'M' označava Marija koji se može kretati u desno, prema kraju retka, zatim znak '#' označava zid, odnosno prepreku koju Mario ne može preskočiti niti zaobići, a znak '.' označava prazno polje po kojem se Mario može kretati. Na Marija djeluje gravitacija, pa on može propasti u redak ispod onog u kojem se nalazi (pogledati test caseove). Na kraju je potrebno ispisati trag kojim Mario kretao u matrici i je li uspio ili ne (uspio je ako je stigao do zadnjeg polja u retku).  Logiku igre je potrebno izvesti u minimalno 2 funkcije: jedna za logiku igre, a druga za ispis polja.

TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/6ba79d89102055aff606099c0cbb0f8ec1d81062/tekstovi%20i%20test%20caseovi/%5B6%5DSuper%20Mario.jpeg
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int provjera(char* polje, int n, int m) {
    for (int i = 0; i < m; i++) {
        if (*(polje + i * m + (m-1)) == 'M') {
            return 1;
        }
    }
    return 0;
}
int pomak(char* polje, int n, int m) {
    int redM = 0;
    int stupacM = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (*(polje + i * m + j) == 'M') {
                redM = i;
                stupacM = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == redM && j == stupacM) {
                if (*(polje + (i + 1) * m + j) == '#') {
                    *(polje + i * m + j + 1) = 'M';
                }
                else if (*(polje + (i + 1) * m + j) == '#' && *(polje + i * m + j + 1) == '#') {
                    return 1;
                }
                else {
                    *(polje + (i + 1) * m + j) = 'M';
                }
            }
            if (i == n - 1) {
                if (*(polje + i * m + j) == 'M') {
                    return 2;
                }
            }
        }
    }
    return 0;
}
int main() {
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);
    char* field = (char*)malloc(n * m * sizeof(char));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", (field + i * m + j));
        }
    }
    while (pomak(field, n, m) == 0) {
        pomak(field, n, m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", *(field + i * m + j));
        }
        printf("\n");
    }
    printf("\n");
    if (provjera(field,n, m) == 1) {
        printf("Uspjeh!");
    }
    else {
        printf("Fail.");
    }
    return 0;
}
