/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/9aa1fcb7d54927fd5ed4f6b967f1d2d1bd882b2b/tekstovi%20i%20test%20caseovi/%5B8%5DNarudzba.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int sifra;
    char naziv[54 + 1];
    float cijena;
    int kolicina;
}artikl;

float narudzba(artikl popis[], FILE* dat2, int i, int kol);

int main()
{
    FILE* dat1 = fopen("katalog.dat", "rb");
    FILE* dat2 = fopen("narudzba.txt", "w");
    artikl popis[1000];
    int br = 0, sifrau, kol;
    float uk = 0;

    fseek(dat1, 0, SEEK_END);
    int vel = ftell(dat1) / sizeof(artikl);
    fseek(dat1, 0, SEEK_SET);
    fread(popis, sizeof(artikl), vel, dat1);

    while (1)
    {
        br = 0;
        scanf("%d", &sifrau);

        if (sifrau == 0)
            break;

        scanf("%d", &kol);

        for (int i = 0; i < vel; i++)
        {
            if (sifrau == popis[i].sifra)
            {
                uk += narudzba(popis, dat2, i, kol);
                br = 1;
            }
            else if (i == vel - 1 && br == 0)
            {
                fprintf(dat2, "Artikl ne postoji\n");
            }
        }
    }

    fprintf(dat2, "Ukupna vrijednost narucene robe %.2f", uk);

    fclose(dat1);
    fclose(dat2);

    return 0;
}

float narudzba(artikl popis[], FILE* dat2, int i, int kol)
{

    if (kol + popis[i].kolicina > 30)
        kol = 30 - popis[i].kolicina;

    float ukupno = popis[i].cijena * kol;

    fprintf(dat2, "%d|%s|%.2f|%d|%.2f\n", popis[i].sifra, popis[i].naziv, popis[i].cijena, kol, ukupno);

    return ukupno;
}
