/*Napisati program koji preko tipkovnice učitava niz znakova, te ih zapisuje u tekstualnu datoteku. Da stvar ne bi bila prejednostavna, naravno, ti nizovi znakova
u datoteku se upisuju prema posebnim pravilima.

Ukoliko se preko tipkovnice unese neka od slijedećih sekvenci znakova potrebno je napraviti navedene zamjene:
usklicnik – u datoteku se upisuje znak '!'
novi red – u datoteku se upisuje znak '\n'
veliko prvo slovo – u datoteku se ne unosi ovaj niz, nego slijedeći učitani niz i to na način da se u datoteku upisuje s velikim početnim slovom, te se na kraj tako dobivenog
niza dodaje razmak
obrni - u datoteku se ne unosi ovaj niz, nego slijedeći učitani niz i to na način da se prije upisa u datoteku obrne raspored njegovih znakova
kraj – prekida se učitavanje znakovnih nizova

Ukoliko se unosi niz koji nije neki od navedenih sekvenci koje treba zamijeniti, u datoteku ga se upisuje onako kako je unesen, ali mu se na kraj dodaje razmak.

test case:
ulaz:
veliko prvo slovo
ove godine na
veliko prvo slovo
superbowlu
komentator
je
veliko prvo slovo
surface
proglasio iPadom
usklicnik
kraj

izlaz:
Ove godine na Superbowlu komentator je Surface proglasio iPadom !
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
FILE* dat = NULL;
char rec = NULL, znak;
int promjena[20] = { 0 };
rec = (char)calloc(20, sizeof(char*));
for (int i = 0; i < 20; i++)
{
rec[i] = (char*)calloc(100, sizeof(char));
}

dat = fopen("upis.txt", "w");

int i = 0;
while (1) {
    scanf("%[^\n]%*c", rec[i]);
    if (strcmp(rec[i], "kraj") == 0) {
        break; 
    }
    i++;
}

for (int i = 0; i < 20; i++)
{
    promjena[i] = 0;
    if (strcmp(rec[i], "usklicnik") == 0)
        fprintf(dat, "! ");
    else if (strcmp(rec[i], "novi red") == 0)
        fprintf(dat, "\n");
    else if (strcmp(rec[i], "veliko prvo slovo") == 0)
    {
        rec[i + 1][0] = toupper(rec[i + 1][0]);
        fprintf(dat, "%s ", rec[i + 1]);
        promjena[i] = 1;
    }
    else if (strcmp(rec[i], "obrni") == 0)
    {
        for (int j = strlen(rec[i + 1])-1; j >= 0; j--)
        {
            fprintf(dat, "%c", rec[i + 1][j]);
        }
        fprintf(dat, " ");
        promjena[i] = 1;
    }
    else if (strcmp(rec[i], "kraj") == 0)
    {
        fclose(dat);
        return 0;
    }
    else if(promjena[i-1] == 0 || i == 0)
        fprintf(dat, "%s ", rec[i]);
}

fclose(dat);
return 0;
}
