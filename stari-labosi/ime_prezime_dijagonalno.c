/*
TEKST ZADATKA:
Napišite program u C u kojem se u niz Ime učitava
ime, a u niz Prez prezime osobe.
Ime i prezime mogu sadržavati jednu ili više riječi
odvojene razmakom. Nizovi Ime i Prez smiju imati
najviše 36 znakova.
Napišite funkciju koja će od ta dva niza sastaviti niz
Ime_Prez, s razmakom između imena i prezimena i s
točkom na kraju. U glavnu funkciju treba vratiti broj
znakova dobivenog niza i ispisati niz i pripadajući
broj.
Na kraju, iz glavne funkcije pozvati funkciju prototipa
void Ispis(char* Ime, char *Prez);
u kojoj ćete ispisati nizove Prez i Ime dijagonalno,
prema primjeru:

TEST CASEOVI:
Test case #1
ULAZ
Max
Mad

IZLAZ
Unesi ime
Unesi prezime
Max Mad. 8
Mad Max
M   M
 a   a
  d   x

Test case #2
ULAZ
Kresimir IV
Kralj Petar

IZLAZ
Unesi ime
Unesi prezime
Kresimir IV Kralj Petar. 24
Kralj Petar Kresimir IV
K           K
 r           r
  a           e
   l           s
    j           i
                 m
      P           i
       e           r
        t
         a           I
          r           V

Test case #3
ULAZ
Ime1 Ime2
Prezime1 Prez2

IZLAZ
Unesi ime
Unesi prezime
Ime1 Ime2 Prezime1 Prez2. 25
Prezime1 Prez2 Ime1 Ime2
P              I
 r              m
  e              e
   z              1
    i
     m              I
      e              m
       1              e
                       2
         P
          r
           e
            z
             2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void spoji(char* ime_prez, char* ime, char* prezime)
{
    strcat(ime_prez, ime);
    strcat(ime_prez, " ");
    strcat(ime_prez, prezime);
    strcat(ime_prez, ".");
}

void ispis(char* ime, char* prezime)
{

    int duljina;
    int imeInd = 0;
    int prezimeInd = 0;
    if (strlen(ime) > strlen(prezime))
    {
        duljina = strlen(ime);
    }
    else
    {
        duljina = strlen(prezime);
    }
    for (int i = 0; i < duljina; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf(" ");
        }
        if (i < strlen(prezime))
        {
            printf("%c", prezime[i]);
        }
        else
        {
            printf(" ");
        }
        if (i < strlen(ime))
        {
            printf("%15c\n", ime[i]);
        }
        else
        {
            printf(" \n");
        }
    }
}

int main()
{
    char Ime[36 + 1];
    char Prez[36 + 1];
    int duljina = 0;

    printf("Unesi ime\n");
    scanf("%[^\n]%*c", Ime);
    printf("Unesi prezime\n");
    scanf("%[^\n]%*c", Prez);

    char* ime_prez = (char*)calloc(strlen(Ime) + strlen(Prez), sizeof(char));
    spoji(ime_prez, Ime, Prez);
    duljina = strlen(ime_prez);
    printf("%s %d\n", ime_prez, duljina);
    printf("%s %s\n", Prez, Ime);
    ispis(Ime, Prez);

    return 0;
}
