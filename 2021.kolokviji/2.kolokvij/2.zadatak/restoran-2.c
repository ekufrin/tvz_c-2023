/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/8e19afd4eb3a7d0d4b8be73344b3d7f0c1316bdb/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DRestoran%202.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char ime[30 + 1];
    char rok_trajanja[30 + 1];
    char vrsta[30 + 1];
    int kolicina;
    float cijena;
}namirnice;


void provjera(FILE* izlaz, namirnice popis[], int vel, char namirnica[]);

int main()
{
    FILE* ulaz = fopen("ostava.dat", "rb");
    FILE* izlaz = fopen("lista.txt", "w");

    namirnice popis[100];

    char namirnica[50];

    fseek(ulaz, 0, SEEK_END);
    int vel = ftell(ulaz) / sizeof(namirnice);
    fseek(ulaz, 0, SEEK_SET);


    fread(popis, sizeof(namirnice), vel, ulaz);

    while (1) {
        scanf("%[^\n]%*c", &namirnica);
        if (strcmp(namirnica, "0") == 0) {
            break;
        }
        
        provjera(izlaz, popis, vel, namirnica);
        
    }

    if (ftell(izlaz)==0) {
        fprintf(izlaz, "Ne treba kupiti nista.");
    }

    fclose(ulaz);
    fclose(izlaz);
   
    return 0;
}
void provjera(FILE* izlaz, namirnice popis[], int vel, char namirnica[]) {
    for (int i = 0; i < vel; i++) {
        if (strcmp(namirnica, popis[i].vrsta) == 0) {
            
            char dan[3];
            char mjesec[3];
            char godina[5];

            
            strncpy(dan, popis[i].rok_trajanja, 2);
            dan[2] = '\0';
            strncpy(mjesec, popis[i].rok_trajanja+3, 2);
            mjesec[2] = '\0';
            strncpy(godina, popis[i].rok_trajanja+6, 4);
            godina[4] = '\0';

            if (strcmp(godina, "2014") < 0) {
                fprintf(izlaz, "%s#%s#%d\n", popis[i].ime, popis[i].rok_trajanja, popis[i].kolicina);
            }
            else if (strcmp(mjesec, "01") < 0) {
                fprintf(izlaz, "%s#%s#%d\n", popis[i].ime, popis[i].rok_trajanja, popis[i].kolicina);
            }
            else if (strcmp(dan, "30") <= 0 && strcmp(mjesec, "01") <= 0 && strcmp(godina, "2014") <= 0) {
                fprintf(izlaz, "%s#%s#%d\n", popis[i].ime, popis[i].rok_trajanja, popis[i].kolicina);
            }

           

        }
    }
       
}
