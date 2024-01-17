/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/1b3b163a202823bb84841efeaaba6f80442b69b2/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DOtpad%202.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char kategorija[15];
    int masa;
    char ime[20];
    char prezime[20];
    int dan;
    int mjesec;
    int godina;
    char sifra[15];
} smece;

int main()
{
    char vrsta[15] = { 0 };
    int kolicina;

    scanf("%s %d", vrsta, &kolicina);

    FILE* ulaz = fopen("otpad.txt", "r");

    smece otpad[MAX];
    int br = 0;
    while (fscanf(ulaz, "%s %d %[^,], %[^#]#%d.%d.%d %s%*c", otpad[br].kategorija, &otpad[br].masa, otpad[br].prezime, otpad[br].ime, &otpad[br].dan, &otpad[br].mjesec, &otpad[br].godina, otpad[br].sifra) != EOF) {
        br++;
    }

    for (int i = 0; i < br; i++) {
        for (int j = i + 1; j < br; j++) {
            if (otpad[j].masa > otpad[i].masa || (otpad[j].masa == otpad[i].masa && (otpad[j].godina < otpad[i].godina || (otpad[j].godina == otpad[i].godina && (otpad[j].mjesec < otpad[i].mjesec || (otpad[j].mjesec == otpad[i].mjesec && otpad[j].dan < otpad[i].dan)))))) {
                smece temp = otpad[i];
                otpad[i] = otpad[j];
                otpad[j] = temp;
            }
        }
    }

    int i = 0, j = 0;
    while (j < 10 && i < br) {
        if (strcmp(otpad[i].kategorija, vrsta) == 0 && otpad[i].masa > kolicina) {
            printf("%s %s %d.%d.%d: %d\n", otpad[i].ime, otpad[i].prezime, otpad[i].dan, otpad[i].mjesec, otpad[i].godina, otpad[i].masa);
            j++;
        }
        i++;
    }

    fclose(ulaz);

    return 0;
}
