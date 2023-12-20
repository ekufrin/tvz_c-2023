/*
TEKST ZADATKA:
U glavnoj funkciji potrebno je s tipkovnice
pročitati dva znakovna niza i spremiti ih u
odgovarajuća dva jednodimenzionalna polja.
Broj unesenih znakova po nizu ne smije biti
manji od 5. Ukoliko se unese manje od 5
znakova zatražiti ponovni unos niza. Pozvati
svoju verziju funkcije strlen i ispisati duljinu
svakog niza u glavnoj funkciji, ali tako da se u
duljinu ubrajaju jedino mala slova.
Funkcija mora imati isti prototip kao i ugrađena
funkcija (samo ju je potrebno nazvati drugačije):
size—t strlen(const char *s);
Zabranjeno je korištenje funkcija iz standardne
biblioteke string.h

TEST CASEOVI:
Test case #1
Primjer ulaza:
Stipe Filipovic (40). Aleksinci. Ima
brk. Uzgaja ovce. Ne podnosi
nepravdu i laz.
FJFKIROEWKEWJKEWKEW DKDKEKEKE KFKFKW
Primjer izlaza:
54 i 0
Test case #2
Prvi niz ima samo 2 mala slova, ali je
ukupna duljina sa interpunkcijama i vel
ikim slovima veća ili jednaka 5.
Primjer ulaza:
Bok!!!!!
Bok kako si?
Primjer izlaza:
2 i 8
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int strlen1(char* s)
{
int br = 0;
int tmp = 0;

while (s[tmp] != '\0')
{  
    if (islower(s[tmp]))
    {
        br++;
    }
    tmp++;
}
return br;
}

int main()
{
char** poruke = NULL;
poruke = (char**)calloc(2, sizeof(char*));

int br1 = 0;
int br2 = 0;

for (int i = 0; i < 2; i++)
{
    poruke[i] = (char*)calloc(1000, sizeof(char));
}

scanf("%[^\n]%*c", poruke[0]);
scanf("%[^\n]%*c", poruke[1]);

br1 = strlen1(poruke[0]);
br2 = strlen1(poruke[1]);

printf("%d i %d", br1, br2);

return 0;
}
