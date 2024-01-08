/*U datoteci naziva "knjiznica.dat" nalaze se informacije o svim knjigama koje knjižnica posjeduje zapisane u obliku struktura:
kataloški broj - string od 6+1 znak
naziv knjige - string od 30+1 znak,
pisac - string od 30+1 znak
vrsta - string od 20+1 znak
broj stranica - cijeli broj
kolicina - cijeli broj.

U tekstualnoj datoteci "posudbe.txt" nalaze se podaci o pojedinim posudbama, zapisanima u formatu:
ime_i_prezime_clana#ime knjige#datum_povrata
Pretpostavite da se datoteka ažurira kod svake prosudbe ili povrata, tj. podaci prikazuju trenutnu situaciju.
Potrebno je napisati program koji će od korisnika tražiti unos naziva knjige i unutar funkcije trazilica pronaći koliko je još preostalo neposuđenih knjiga zadanog naziva.
U slučaju da nije ostala niti jedna knjiga, potrebno je ispisati datum kada će najranije postati dostupna.
U slučaju da se upiše nepostojeći naslov, potrebno je ispisati poruku "Nije pronadjen zapis.". 

POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/0f7e1882cec893d01b9c89f6217201e4517e11b6/tekstovi%20i%20test%20caseovi/%5B8%5DKnjiznica.zip
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char kat_broj[6 + 1];
char naziv[30 + 1];
char pisac[30 + 1];
char vrsta[20 + 1];
int broj_stranica;
int kolicina;
}knjiga;

typedef struct {
char ime_prezime[60 + 1];
char ime_knjige[30 + 1];
char datum[12];
}posudba;

int main()
{
FILE* dat1 = NULL;
FILE* dat2 = NULL;
knjiga popis[100];
posudba pos[10];
int br = 0, velicina, broj_knjiga = 0, index = 0;
char unos[30 + 1];

scanf("%[^\n]", unos);

dat1 = fopen("knjiznica.dat", "rb");
dat2 = fopen("posudbe.txt", "r");

fseek(dat1, 0, SEEK_END);
velicina = ftell(dat1) / sizeof(knjiga);
fseek(dat1, 0, SEEK_SET);

fread(popis, sizeof(knjiga), velicina, dat1);

while (fscanf(dat2, "%[^#]#%[^#]#%[^\n]\n", pos[br].ime_prezime, pos[br].ime_knjige, pos[br].datum) == 3)
    br++;

for (int i = 0; i < velicina; i++)
{
    if (strcmp(popis[i].naziv, unos) == 0)
        broj_knjiga = popis[i].kolicina;
}

for (int i = 0; i < br; i++)
{
    if (strcmp(pos[i].ime_knjige, unos) == 0)
    {
        broj_knjiga--;
        index = i;
    }  
}

if (broj_knjiga == 0 && index == 0)
       printf("Nije pronadjen zapis.");
else if (broj_knjiga == 0)
    printf("0\nKnjiga ce biti dostupna: %10s", pos[index].datum);
else
    printf("%d", broj_knjiga);

fclose(dat1);
fclose(dat2);

return 0;
}
