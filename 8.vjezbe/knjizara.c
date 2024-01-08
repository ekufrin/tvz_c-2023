/*U datoteci naziva "knjizara.dat" nalaze se informacije o knjigama zapisane u obliku struktura:

naziv knjige - string od 30+1 znak,
pisac - string od 30+1 znak,
broj stranica - cijeli broj
cijena - realni broj (float)
kolicina - cijeli broj.

Potrebno je napisati program koji će od korisnika traziti unos imena (ili dijela imena) pisca i unutar funkcije pretraga u novu formatiranu datoteku naziva "moj_pisac.txt" upisati samo one knjige koje odgovaraju pretrazi i to u sljedećem formatu:

Ime_knjige#cijena#broj_stranica

U slučaju da se upiše nepostojeći pisac, potrebno je ispisati poruku "Nije pronadjen zapis.". 

POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/baaa749ba8dc51129a196d96905d707bbc55c158/tekstovi%20i%20test%20caseovi/knjizara.dat
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char naziv[30 + 1];
char pisac[30 + 1];
int broj_str;
float cijena;
int kolicina;
}knjiga;

void pretraga(FILE* dat2, knjiga* knjige, char* unos, int vel);

int main()
{
FILE* dat = NULL;
FILE* dat2 = NULL;
char unos[30 + 1];
knjiga knjige[1000];
int velicina;

scanf("%[^\n]", unos);

dat = fopen("knjizara.dat", "rb");
dat2 = fopen("moj_pisac.txt", "w");

fseek(dat, 0, SEEK_END);
velicina = ftell(dat);
velicina = velicina / sizeof(knjiga);
fseek(dat, 0, SEEK_SET);

fread(knjige, sizeof(knjiga), velicina, dat);

pretraga(dat2, knjige, unos, velicina);

fclose(dat);
fclose(dat2);

return 0;
}

void pretraga(FILE* dat2, knjiga* knjige, char* unos, int vel)
{
int br = 0;
for (int i = 0; i < vel; i++)
{
if (strncmp(unos, knjige[i].pisac, strlen(unos)) == 0)
{
fprintf(dat2, "%s#%.2f#%d\n", knjige[i].naziv, knjige[i].cijena, knjige[i].broj_str);
//printf("%s#%.2f#%d\n", knjige[i].naziv, knjige[i].cijena, knjige[i].broj_str);
br = 1;
}
}

if (!br)
    fprintf(dat2, "Nije pronadjen zapis.");

return;
}
