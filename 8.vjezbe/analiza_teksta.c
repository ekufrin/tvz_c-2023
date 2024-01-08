/*Analiza osjećaja iz nečije poruke može nam dati korisne informacije o tome što prijatelji, kolege, korisnici ili klijenti misle o nekoj temi, proizvodu ili usluzi,
a može pomoći i npr. kod automatiziranja cenzure govora mržnje.
U datoteci Sentiment.txt se nalazi niz engleskih riječi čije korištenje poistovjećujemo s pozitivnim ili negativnim emocijama. Podaci su dani u sljedećem formatu:

riječ: POZ
riječ: POZ
riječ: NEG
...
Potrebno je za neku englesku rečenicu, unesenu sa standardnog ulaza (stdin), u datoteku RezultatAnalize.txt ispisati tu rečenicu, sve detektirane riječi i rezultat analize.
Rečenicu smatramo negativnom ako ima više negativnih riječi, pozitivnu ako ima više pozitivnih i neutralnom ako ima jednak broj pozitivnih i negativnih riječi
(ili ako nema niti jedne detektirane riječi).

Napomena: za spremanje svih rijeci s popisa koristiti polje struktura.

POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/3597c8e471a91a246bdd1e799c4868f01ab593c6/tekstovi%20i%20test%20caseovi/Sentiment.txt
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char rijec[20 + 1];
char osobnost[3 + 1];
}rijeci;

int main()
{
char rec[100 + 1];
FILE* dat = NULL;
FILE* dat2 = NULL;
int broj_rijeci = 34, i = 0, lose=0, dobre=0;
rijeci popis[100];
char* tmp = NULL;

tmp = (char*)calloc(15, sizeof(char));

dat = fopen("Sentiment.txt", "r");
dat2 = fopen("RezultatAnalize.txt", "w");

for (int i = 0; i < broj_rijeci; i++)
    fscanf(dat, "%[^:]: %[^\n]\n", popis[i].rijec, popis[i].osobnost);

scanf("%[^\n]", rec);

fprintf(dat2, "%s\n", rec);

tmp = strtok(rec, "!., ");
while (tmp != NULL)
{
    for (int i = 0; i < broj_rijeci; i++)
    {
        if (strcmp(popis[i].rijec, tmp) == 0)
        {
            fprintf(dat2, "%s\n", tmp);
            if (strcmp(popis[i].osobnost, "POZ") == 0)
                dobre++;
            else if (strcmp(popis[i].osobnost, "NEG") == 0)
                lose++;
        }
    }
    tmp = strtok(NULL, "!., ");
}

if (dobre > lose)
    fprintf(dat2, "Analiza: pozitivna");
else if (lose > dobre)
    fprintf(dat2, "Analiza: negativna");
else
    fprintf(dat2, "Analiza: neutralna");

fclose(dat);
fclose(dat2);

return 0;
}
