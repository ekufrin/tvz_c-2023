/*U datoteci sinonimi.txt se nalazi popis riječi i njihovih sinonima, u obliku da se na početku linije nalazi pojam, zatim dvotočka te niz zarezom odvojenih sinonima
(moguce je da neki sinonim ima dvije ili vise rijeci). Jedan zapis moze izgledati ovako:
lako: lagano, jednostavno, trivijalno, s lakocom

Nakon toga potrebno je ucitati rečenicu sa standardnog ulaza, te ispisati sve varijacije te rečenice na način da se prva riječ koja ima sinonim zamijeni svim mogućim sinonimima.
Primjerice, za rečenicu:

Pero je lako.

Rezultat će biti:
Pero je lagano.
Pero je jednostavno.
Pero je trivijalno.
Pero je s lakocom.

Rezultat je potrebno ispisati u datoteku Kombinacije.txt.

Napomena: Ulazni podaci neće biti takvi da se u ulaznim podacima nalaze dvije riječi koje imaju sinonim (primjerice, neće biti ulaz Pero je lako, ali kamen nije lako dici). 

POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/20f5e9b550434a46d6081edc8389452b792b4284/tekstovi%20i%20test%20caseovi/sinonimi.txt
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char rijec[20 + 1];
char komb[100 + 1];
}recenica;

int main()
{
int broj_sinonima = 13;
FILE* dat1 = NULL;
FILE* dat2 = NULL;
char rec[100 + 1];
recenica recc[50];

dat1 = fopen("sinonimi.txt", "r");
dat2 = fopen("Kombinacije.txt", "w");

scanf("%[^\n]", rec);

for (int i = 0; i < broj_sinonima; i++)
    fscanf(dat1, "%[^:]: %[^\n]\n", recc[i].rijec, recc[i].komb);

char* tmp = NULL;
int nasao = 0, index =0;
char tmp2[20 + 1], kopija[100 + 1], rijeci_prije[100 + 1] = { 0 }, rijeci_poslije[100 + 1] = { 0 };
strcpy(kopija, rec);

tmp = strtok(kopija, ". ");       //trazimo koja rijec ima sinonime iz ulazne recenice
while (tmp != NULL)
{
    for (int i = 0; i < broj_sinonima; i++)
    {
        if (strcmp(tmp, recc[i].rijec) == 0)
        {
            strcpy(tmp2, tmp);
            nasao = 1;
            index = i;
            break;
        }
    }
    if (nasao == 0)
    {
        strcat(rijeci_prije, tmp);
        strcat(rijeci_prije, " ");
    }
    else if (nasao == 1 && strcmp(tmp, recc[index].rijec) != 0)
    {
        strcat(rijeci_poslije, tmp);
        strcat(rijeci_poslije, " ");
    }
    tmp = strtok(NULL, ". ");
}
if (nasao == 0)
{
    fprintf(dat2, "NEMA SINONIMA.");
    fclose(dat1);
    fclose(dat2);
    return 0;
}
char rez[500] = { 0 };
int brr = 0;
for (int i = 0; i < broj_sinonima; i++)
{
    if (strcmp(recc[i].rijec, tmp2) == 0)
    {
        tmp = strtok(recc[i].komb, ",");
        while (tmp != NULL)
        {
            if (brr > 0)
            {
                char* kopijaa = (char*)calloc(strlen(tmp), sizeof(char));       //micemo razmak na pocetku stringa
                for (int i = 0; i < strlen(tmp) - 1; i++)
                {
                    kopijaa[i] = tmp[i + 1];
                }
                strcat(rez, rijeci_prije);
                strcat(rez, kopijaa);
                if(strlen(rijeci_poslije) != 0)
                    strcat(rez, " ");
                strncat(rez, rijeci_poslije, strlen(rijeci_poslije) - 1);
                strcat(rez, ".");
            }
            else
            {
                strcat(rez, rijeci_prije);
                strcat(rez, tmp);
                if (strlen(rijeci_poslije) != 0)
                    strcat(rez, " ");
                strncat(rez, rijeci_poslije, strlen(rijeci_poslije)-1);
                strcat(rez, ".");
            }
            fprintf(dat2, "%s\n", rez);
            rez[0] = NULL;
            brr++;
            tmp = strtok(NULL, ",");
        }
        break;
    }
}

fclose(dat1);
fclose(dat2);

return 0;
}
