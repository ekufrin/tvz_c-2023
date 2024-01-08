/*U datoteci Rjecnik.txt se nalazi niz hrvatskih pojmova te njihov prijevod na engleski jezik. Podaci su u sljedećem formatu:

pojam: prijevod
pojam: prijevod
...

Potrebno je za neki engleski pojam unesen sa standardnog ulaza (stdin) ispisati u datoteku Prijevod.txt ispisati u kojim se sve hrvatskih pojmovima rijec spominje,
i to na nacin da se ispise kontekst u kojem se rijec pojavljuje. Primjerice, ukoliko ulazna datoteka sadrži pojam:

olovka: pen, item which is used to write text on paper

a unesena engleska riječ je "text"; tada je potrebno ispisati:
olovka: ... to write TEXT on paper ...

Kontekst se sastoji od dvije rijeci prije i dvije rijeci poslije, te naglasavanjem trazene rijeci. Ukoliko se trazena rijec nalazi na pocetku ili na kraju, ili ima
manje od dvije rijeci do kraja, maknuti "tri tockice" kod ispisa. Primjerice, za isti unos, za malo drukciji pojam:

pisaca masina: machine to type text

Ispis treba biti:
pisaca masina: ... to type TEXT

Napomena: za spremanje svih rijeci iz rjecnika koristiti polje struktura. U opisima pojmova se neće koristiti ništa osim malih slova eng. abecede, zareza te razmaka.


POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/cfcc86784b63e771e5f06e7148a8fc1a18d13fe6/tekstovi%20i%20test%20caseovi/Rjecnik.txt
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
char rijec[30 + 1];
char opis[100 + 1];
}rjecnik;

int main()
{
FILE* dat1 = NULL;
FILE* dat2 = NULL;
char ulaz[30 + 1], ULAZ[30+1];
int index[15] = { 0 }, br = 0, j = 0, index_rijeci[15], rijec = 0;
rjecnik popis[20];
char* tmp, * posljednja = "", * prethodna = "", * prva = "", * druga = "";

scanf("%s", ulaz);

dat1 = fopen("Rjecnik.txt", "r");
dat2 = fopen("Prijevod.txt", "w");

while (fscanf(dat1, "%[^:]: %[^\n]\n", popis[br].rijec, popis[br].opis) == 2)
    br++;

for (int i = 0; i < br; i++)        //pronalazak indexa u kojem retku je rijec, i na kojoj poziciji se nalazi
{
    if (tmp = strstr(popis[i].opis, ulaz))
    {
        if (tmp != NULL)
        {
            index[j] = i;
            index_rijeci[j] = tmp - popis[i].opis;
            j++;
        }
    }
}

if (index[0] == 0)
{
    fprintf(dat2, "NE POSTOJI RIJEC!");
    fclose(dat2);
    fclose(dat1);
    return 0;
}
int k = 0;
for (k = 0; k < strlen(ulaz); k++)
{
    ULAZ[k] = toupper(ulaz[k]);
}
ULAZ[k] = '\0';
for (int i = 0; i < j; i++)
{
    fprintf(dat2, "%s: ", popis[index[i]].rijec);
    if (index_rijeci[i] == 0)       //prva rijec je trazena rijec
    {
        fprintf(dat2, "%s ", ULAZ);
        char* tmp = strtok(popis[index[i]].opis, " ");
        tmp = strtok(NULL, " ");
        while (tmp != NULL)
        {
            if (br == 2)
                break;
            fprintf(dat2, "%s ", tmp);
            tmp = strtok(NULL, " ");
            br++;
        }
     
    }
    else if (index_rijeci[i] + strlen(ulaz) < strlen(popis[index[i]].opis) + strlen(popis[index[i]].rijec))        //ako da, postoje rijeci nakon trazene rijeci
    {
        char* tmp = strtok(popis[index[i]].opis, " ");
        rijec = 0;
        while (tmp != NULL)
        {
            if (strcmp(ulaz, tmp) == 0)
            {
                if(prethodna == "")
                    fprintf(dat2, "%s %s", posljednja, ULAZ);
                else
                    fprintf(dat2, "... %s %s %s", prethodna, posljednja, ULAZ);
                rijec = 1;
            }
            else if(rijec == 0)
            {
                prethodna = posljednja;
                posljednja = tmp;
            }
            else if (rijec == 1)
            {
                fprintf(dat2, " %s", tmp);
                rijec++;
            }
            else if (rijec == 2)
            {
                fprintf(dat2, " %s ...", tmp);
                rijec++;
            }

            tmp = strtok(NULL, " ");
        }
    }
    else if (index_rijeci[i] + strlen(ulaz) == strlen(popis[index[i]].opis) + strlen(popis[index[i]].rijec))         //trazena rijec je zadnja rijec u recenici
    {
        char* tmp = strtok(popis[index[i]].opis, " ");

        while (tmp != NULL)
        {
            if (strcmp(ulaz, tmp) == 0)
                break;
            prethodna = posljednja;
            posljednja = tmp;
            tmp = strtok(NULL, " ");
        }

        fprintf(dat2, "... %s %s %s", prethodna, posljednja, ULAZ);
    }


    fprintf(dat2, "\n");
}
fclose(dat2);
fclose(dat1);
return 0;
}
