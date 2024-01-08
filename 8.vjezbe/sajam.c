/*
Popis modela jahti se nalazi u datoteci modeli.dat. U datoteci sajam.txt se nalazi popis hala gdje se nalaze pojedini modeli. Želite vidjeti koji modeli su dostupni u
kojoj hali za tražene uvjete - recimo min/max cijena, min/max duljina. Vaš zadatak je na temelju informacije koje uvjete model mora zadovoljavati, i koji se modeli
nalaze u kojoj hali, ispisati modele poredano po hali, zatim nazivu.

modeli.dat
U ovoj datoteci se nalaze mogući modeli jahti. Datoteka je binarna, i svaki zapis je strukturiran na sljedeći način:
ID - broj u intervalu [1, 100], tipa int. Također, zapis s ID = 1 se nalazi na prvom mjestu u datoteci, zapis, s rednim brojem X, se nalazi na X-tom mjestu u datoteci.
Naziv modela - znakovno polje od 100 znakova (char[100], ne char[101])
Kategorija - polje od 50 znakova (char[50], ne char[50+1])
Duljina - float
Broj ležajeva - int
Broj soba - int
Cijena - int (cijena najma jahte na tjedan dana)
Napomena: neki zapisi ne moraju postojati. U tom slučaju će ID biti 0.

sajam.txt
U ovoj datoteci se nalazi popis jahti po halama. Svaki redak predstavlja jednu jahtu, i u ovom je formatu:
HALA MODEL IME#FLEET_OP#BOOTH
gdje je:
HALA = šifra hale, ukupno 2-5 znakova, velika slova eng. abecede ili znamenke
MODEL = šifra modela. To je zapravo ID iz datoteke modeli.dat
IME = naziv broda - može sadržavati mala i velika slova engleske abecede, razmake, i druge znakove osim #. Neće biti dulje od 100 znakova
FLEET_OP = naziv fleet operatora (onaj koji prodaje brodove).
BOOTH = šifra štanda gdje se nalazi taj fleet operator
Ulazni podaci se sastoje od 2 retka: minimalna i maksimalna cijena, a u drugom retku minimalna i maksimalna duljina, te treba pronaći sve brodove koji zadovoljavaju kriterije.
Dodatno, ispisati rezultat u datoteku rezultat.out.

Prijedlog za način rješavanja:

definirati dvije strukture: Model i Brod. U strukturi brod staviti i jedan član tipa Model, u koji će se prilikom učitavanja dohvatiti podatak iz datoteke modeli.dat
prilikom učitavanja tekstualne datoteke, odmah kod učitavanja eliminirati brodove koji ne zadovoljavaju kriterije
nakon što su učitani samo brodovi koji zadovoljavaju kriterije, sortirati taj niz te ispisati rezultate

DATOTEKE POTREBNE ZA ZADATAK: https://github.com/emanuelkufrin/tvz_c-2023/blob/93068766522971c2b6aada67c5b3c5935fed0f81/tekstovi%20i%20test%20caseovi/%5B8%5D%20Sajam.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
int id;
char naziv[100];
char kategorija[50];
float duljina;
int broj_lezajeva;
int broj_soba;
int cijena;
}model;

typedef struct {
char hala[6];
int model;
char ime[100];
char fleet_op[100];
char booth[5];
}jahta;

int main()
{
FILE* dat1 = NULL;
FILE* dat2 = NULL;
FILE* dat3 = NULL;
model popis[150];
model rez[100];
jahta niz[110], tmp;
int br = 0, velicina, mincijena, maxcijena;
float mind, maxd;

scanf("%d-%d\n%f-%f", &mincijena, &maxcijena, &mind, &maxd);

dat1 = fopen("modeli.dat", "rb");
dat2 = fopen("sajam.txt", "r");
dat3 = fopen("rezultat.out", "w");

fseek(dat1, 0, SEEK_END);
velicina = ftell(dat1) / sizeof(model);
fseek(dat1, 0, SEEK_SET);

fread(popis, sizeof(model), velicina, dat1);
            
while (fscanf(dat2, "%[^ ] %d %[^#]#%[^#]#%[^\n]\n", tmp.hala, &tmp.model, tmp.ime, tmp.fleet_op, tmp.booth) == 5)
{
    for (int i = 0; i < velicina; i++)
    {
        if (tmp.model == popis[i].id)
        {
            if (popis[i].duljina >= mind && popis[i].duljina <= maxd && popis[i].cijena >= mincijena && popis[i].cijena <= maxcijena)
            {
                niz[br] = tmp;
                br++;
            }
        }
    }
}
 int brojac = 0;
for (int i = 0; i < br; i++)
{
    for (int i = 0; i < br-1; i++)
    {
        if (strlen(niz[i].hala) > strlen(niz[i + 1].hala))
        {
            for (int j = 0; j < strlen(niz[i].hala); j++)
            {
                if (niz[i].hala[j] > niz[i + 1].hala[j])
                {
                    jahta tmp2 = niz[i];
                    niz[i] = niz[i + 1];
                    niz[i + 1] = tmp2;
                    break;
                }
                else if (niz[i].hala[j] == niz[i + 1].hala[j])
                    brojac++;
                else
                    break;
            }
        }
        else
        {
            for (int j = 0; j < strlen(niz[i+1].hala); j++)
            {
                if (niz[i].hala[j] > niz[i + 1].hala[j])
                {
                    jahta tmp2 = niz[i];
                    niz[i] = niz[i + 1];
                    niz[i + 1] = tmp2;
                    break;
                }
                else if (niz[i].hala[j] == niz[i + 1].hala[j])
                    brojac++;
                else
                    break;
            }
        }
        if (strcmp(niz[i].hala, niz[i+1].hala) == 0)
        {
            if (niz[i].ime[0] > niz[i + 1].ime[0])
            {
                jahta tmp2 = niz[i];
                niz[i] = niz[i + 1];
                niz[i + 1] = tmp2;
            }
        }
        brojac = 0;
    }
}

for (int i = 0; i < br; i++)
{
    for (int j = 0; j < velicina; j++)
    {
        if (niz[i].model == popis[j].id)     
            fprintf(dat3, "%s(%s) %s %s %.2f %d EUR\n", niz[i].hala, niz[i].booth, popis[j].naziv, niz[i].ime, popis[j].duljina, popis[j].cijena);
    }
}

fclose(dat1);
fclose(dat2);
fclose(dat3);

return 0;
}
