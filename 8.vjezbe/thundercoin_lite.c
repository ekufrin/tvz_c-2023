/*
Mirko Andabak zvani "Munja" ima dijete (Vanja) koji tek uči programiranje i želi mu zadati zadatak pomoću kojeg će ono provježbati i ispeglati svoje programerske sposobnosti.

Kako se Munja bavi kriptovalutama, imao je priruci datoteku sa transakcijama koja zove creepto.val, i sadrži sljedeće podatke:
kod transakcije: točno 20 znakova (plus 1 znak za kraj stringa)
iznos pomnožen sa 100: cjelobrojna vrijednost
dan: int
mjesec: int
godina: int
sat: int
minuta: int
sekunda: int
Munju zanima da kad unese nekoliko slova sa standardnog ulaza, da Vanjin program ispiše sve transakcije čiji kod sadrži sve navedene znakove (ne nužno u istom poretku),
poredane po satu, minuti, pa sekundi. Ukoliko postoje dvije transakcije s istim satom, minutom i sekundom, treba ih poredati po kodu abecedno (znamenka se nalazi abecedno
prije slova, a malo slovo 'a' se nalazi iza 'A', dok se malo slovo 'a' nalazi ispred velikog slova 'B').

POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/8a0bc2d36336fcf119fd75dc0866a442b457b739/tekstovi%20i%20test%20caseovi/creepto.val
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char kod[20 + 1];
int iznos;
int dan;
int mjesec;
int godina;
int sat;
int minuta;
int sekunda;
}kripto;

int main()
{
char ulaz[10];
kripto niz[1000];
kripto rez[500];
int br = 0, velicina = 0, pronaden = 0;

scanf("%s", ulaz);

FILE* dat;
dat = fopen("creepto.val", "rb");

fseek(dat, 0, SEEK_END);
velicina = ftell(dat);
fseek(dat, 0, SEEK_SET);
velicina = velicina / sizeof(kripto);

fread(niz, sizeof(kripto), velicina, dat);

for (int i = 0; i < velicina; i++)
{
    pronaden = 0;
    for (int j = 0; j < strlen(ulaz)+1; j++)
    {
        for (int k = 0; k < 20; k++)
        {
            if (ulaz[j] == niz[i].kod[k])
            {
                pronaden++;
                break;
            }
        }
        if (!pronaden)
        {
            break;
        }
    }
    if (pronaden == strlen(ulaz))
    {
        rez[br] = niz[i];
        br++;
    }
}

for (int i = 0; i < br; i++)
{
    for (int i = 0; i < br - 1; i++)
    {
        if (rez[i].sat > rez[i + 1].sat)
        {
            kripto tmp = rez[i];
            rez[i] = rez[i + 1];
            rez[i + 1] = tmp;
        }
        else if (rez[i].sat == rez[i + 1].sat)
        {
            if (rez[i].minuta > rez[i + 1].minuta)
            {
                kripto tmp = rez[i];
                rez[i] = rez[i + 1];
                rez[i + 1] = tmp;
            }
            else if (rez[i].minuta == rez[i + 1].minuta)
            {
                if (rez[i].sekunda > rez[i + 1].sekunda)
                {
                    kripto tmp = rez[i];
                    rez[i] = rez[i + 1];
                    rez[i + 1] = tmp;
                }
            }
        }
        else if (rez[i].sat == rez[i + 1].sat && rez[i].minuta == rez[i + 1].minuta && rez[i].sekunda == rez[i + 1].sekunda)
        {
            if (rez[i].kod[0] > rez[i + 1].kod[0])
            {
                kripto tmp = rez[i];
                rez[i] = rez[i + 1];
                rez[i + 1] = tmp;
            }
        }
    }
}

for (int i = 0; i < br; i++)
{
    if (rez[i].sat < 10 && rez[i].minuta < 10 && rez[i].sekunda < 10)
        printf("%s@0%d:0%d:0%d\n", rez[i].kod, rez[i].sat, rez[i].minuta, rez[i].sekunda);
    else if (rez[i].sat < 10 && rez[i].minuta < 10)
        printf("%s@0%d:0%d:%d\n", rez[i].kod, rez[i].sat, rez[i].minuta, rez[i].sekunda);
    else if (rez[i].minuta < 10 && rez[i].sekunda < 10)
        printf("%s@%d:0%d:0%d\n", rez[i].kod, rez[i].sat, rez[i].minuta, rez[i].sekunda);
    else if (rez[i].sat < 10)
        printf("%s@0%d:%d:%d\n", rez[i].kod, rez[i].sat, rez[i].minuta, rez[i].sekunda);
    else if(rez[i].minuta < 10)
        printf("%s@%d:0%d:%d\n", rez[i].kod, rez[i].sat, rez[i].minuta, rez[i].sekunda);
    else if(rez[i].sekunda < 10)
        printf("%s@%d:%d:0%d\n", rez[i].kod, rez[i].sat, rez[i].minuta, rez[i].sekunda);
    else
        printf("%s@%d:%d:%d\n", rez[i].kod, rez[i].sat, rez[i].minuta, rez[i].sekunda);
}

fclose(dat);

return 0;
}
