/*Planirate letjeti i želite proći što jeftinije. U binarnoj datoteci "letovi.dat" se nalaze informacije o letovima i njihovim cijenama. Podaci o letu su definirani
strukturom na sljedeći način:
naziv grada iz kojeg se leti (30+1 znak)
naziv odredišta (30+1 znak)
sat polaska (int)
minuta polaska (int)
cijena (double)
Potrebno je sa standardnog ulaza učitati dva grada odvojena cricom (-) i ispisati kolika je cijena leta između ta dva grada, te poruku o tome kada let kreće
i podatke o presjedanju (ukoliko postoji).

Napomena: pristajete na najvise jedno presjedanje.

POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/980d6a0421831f192423450dc683308943737aef/tekstovi%20i%20test%20caseovi/Letovi.dat
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char polaziste[30 + 1];
char odrediste[30 + 1];
int sat;
int minuta;
double cijena;
}let;

int main()
{
char pol[30 + 1], odr[30 + 1];
char presjedanje[30+1] = "";
let popis[1000];
int index, br = 0, pres = 0;
double min = 1000000;
FILE* dat = NULL;

dat = fopen("Letovi.dat", "rb");

scanf("%30[^-]-%30[^\n]", pol, odr);

int velicina;
fseek(dat, 0, SEEK_END);
velicina = ftell(dat) / sizeof(let);
fseek(dat, 0, SEEK_SET);

fread(popis, sizeof(let), velicina, dat);


for (int i = 0; i < velicina; i++) {
    if (strcmp(pol, popis[i].polaziste) == 0 && strcmp(odr, popis[i].odrediste) == 0 && popis[i].cijena < min) {
        index = i;
        min = popis[i].cijena;
        pres = 0;
    }
}

for (int i = 0; i < velicina; i++) {
    if (strcmp(pol, popis[i].polaziste) == 0 && strcmp(odr, popis[i].odrediste) != 0) {
        for (int j = 0; j < velicina; j++) {
            if (strcmp(popis[i].odrediste, popis[j].polaziste) == 0 && strcmp(odr, popis[j].odrediste) == 0 &&
                popis[i].cijena + popis[j].cijena < min) {
                strcpy(presjedanje, popis[i].odrediste);
                index = i;
                min = popis[i].cijena + popis[j].cijena;
                pres = 1;
            }
        }
    }
}
if (pres == 1)
{
    if(popis[index].sat < 10)
        printf("Ukupno: %.2f\nPolazak u 0%d:%d\nPresjedanje: %s", min, popis[index].sat, popis[index].minuta, presjedanje);
    else
        printf("Ukupno: %.2f\nPolazak u %d:%d\nPresjedanje: %s", min, popis[index].sat, popis[index].minuta, presjedanje);
}
    
else
    printf("Ukupno: %.2f\nPolazak u %d:%d", min, popis[index].sat, popis[index].minuta);

fclose(dat);

return 0;
}
