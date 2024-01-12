/*
Potrebno je izmjeniti originalni zadatak na način da se učitava samo interval za cijenu, a ispisuju brodovi poredano po cijeni silazno, a nakon toga po hali uzlazno. Ispisati samo 6 najskupljih.

Opis datoteka

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


POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/fb11da54723cdabf1c5c68764217e363cc98b47b/tekstovi%20i%20test%20caseovi/%5B8%5DSajam-skupi.zip
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char naz_model[100];
    char kategorija[50];
    float duljina;
    int br_lezaja;
    int br_soba;
    int cijena;
}model;

typedef struct {
    char hala[6];
    int id;
    char ime[100];
    char fleet_op[20];
    int booth[3];
}sajam;


int main()
{
    FILE* file = fopen("modeli.dat", "rb");
    FILE* file1 = fopen("sajam.txt", "r");
    FILE* file2 = fopen("rezultat.out", "w");
    model mod[150], rez[100], tmp;
    sajam saj[110], temp;
    int i = 0, j = 0, velicina, mincijena, maxcijena;

    scanf("%d-%d", &mincijena, &maxcijena);

    fseek(file, 0, SEEK_END);
    velicina = ftell(file) / sizeof(model);
    fseek(file, 0, SEEK_SET);

    fread(mod, sizeof(model), velicina, file);

    while (fscanf(file1, "%[^ ] %d %[^#]#%[^#]#%[^\n]\n", temp.hala, &temp.id, temp.ime, temp.fleet_op, temp.booth) != EOF) {
        for (int i = 0; i < velicina; i++) {
            if (temp.id == mod[i].id) {
                if (mod[i].cijena >= mincijena && mod[i].cijena <= maxcijena) {
                    rez[j] = mod[i];
                    saj[j] = temp;
                    j++;
                }
            }
        }
    }

    for (i = 0; i <= j; i++) {
        for (int z = i + 1; z <= j; z++) {
            if (rez[z].cijena > rez[i].cijena) {
                tmp = rez[i];
                rez[i] = rez[z];
                rez[z] = tmp;

                temp = saj[i];
                saj[i] = saj[z];
                saj[z] = temp;
            }
        }
    }

    for (i = 0; i <= j; i++) {
        for (int z = i + 1; z <= j; z++) {
            if (rez[z].cijena == rez[i].cijena) {
                if (strcmp(saj[z].hala, saj[i].hala) < 0) {
                    tmp = rez[i];
                    rez[i] = rez[z];
                    rez[z] = tmp;

                    temp = saj[i];
                    saj[i] = saj[z];
                    saj[z] = temp;
                }
            }
        }
    }

    for (int z = 0; z < 6; z++) {
        printf("%s(%s) %s %s %.02f %d EUR\n", saj[z].hala, saj[z].booth, rez[z].naz_model, saj[z].ime, rez[z].duljina, rez[z].cijena);
        fprintf(file2, "%s(%s) %s %s %.02f %d EUR\n", saj[z].hala, saj[z].booth, rez[z].naz_model, saj[z].ime, rez[z].duljina, rez[z].cijena);
    }
    
    fclose(file);
    fclose(file1);
    fclose(file2);

    return 0;
}

