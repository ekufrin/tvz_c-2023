/*Napravite C kod koji provjerava je li sudoku matrica ispravna.

Sudoku pravila su sljedeća:
matrica sadrži 9 redaka i 9 stupaca
u svakom retku trebaju biti brojevi od 1 do 9 (ne smije se ponavljati niti jedan)
u svakom stupcu trebaju biti brojevi od 1 do 9 (ne smije se ponavljati niti jedan)
ukoliko matricu podijelimo na 9 jednakih 3x3 dijelova, u svakom tom 3x3 dijelu moraju biti brojevi od 1 do 9 (ne smije se ponavljati niti jedan broj)
moguće je na internetu pretražiti pravila popunjavanja sudoku matrica

Test case #1
Ova sudoku matrica je ispravna. 
Primjer ulaza:
172549683
645873219
389261745
496327851
813456972
257198436
964715328
731682594
528934167
Primjer izlaza:
Ispravno!

Test case #2
Ova matrica je slična gornjoj, osim što nema ispravnu vrijednost u 7. retku - broj 2 se ponavlja više puta. Samim time, greska je i u 6. stupcu, te u 8. 3x3 kvadratu (kvadrati se broje odozgo na dolje i s lijeva na desno). Uvijek će biti samo jedna greška.
Primjer ulaza:
172549683
645873219
389261745
496327851
813456972
257198436
964712328
731682594
528934167
Primjer izlaza:
Neispravno!
Greska u: 7. redak, 6. stupac, 8. kvadrat.

Test case #3
Primjer ulaza:
572549683
645873219
389261745
496327851
813456972
257198436
964715328
731682594
528934167
Primjer izlaza:
Neispravno!
Greska u: 1. redak, 1. stupac, 1. kvadrat.

Test case #4
Primjer ulaza:
126437958
895621473
374985126
457193862
983246517
612578394
269314785
548769231
731852649
Primjer izlaza:
Ispravno!

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
int main() {

    int sudoku[9][9];
    char znak;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %c", &znak);
            sudoku[i][j] = znak - 48;
        }
    }

    int brojRed = -1;
    int ponavljanjeRed = 0;
    int kojiStupac = 0;

    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            ponavljanjeRed = 0;
            for (int k = 0; k < 9; k++) {
                if (sudoku[j][k] == i) {
                    ponavljanjeRed++;
                    if (ponavljanjeRed > 1) {
                        brojRed = j + 1;
                        kojiStupac = k + 1;
                        break;
                    }
                }
            }
        }
    }

    int brojStupac = -1;
    int ponavljanjeStupac = 0;
    int kojiRed = 0;

    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (ponavljanjeStupac > 1) {
                break;
            }
            ponavljanjeStupac = 0;
            for (int k = 0; k < 9; k++) {
                if (sudoku[k][j] == i) {
                    ponavljanjeStupac++;
                    if (ponavljanjeStupac > 1) {
                        kojiRed = k + 1;
                        brojStupac = j + 1;
                        break;
                    }
                }
            }
        }
    }

    int broj = 0;
    int kojiKvadrat = 0;
    int kvadrat = 0;

    int x = 0, y = 3;
    int z = 0, t = 3;

    while (kvadrat < 9) {
        if (kvadrat == 3 || kvadrat == 6) {
            z = 0, t = 3;
        }

        if (kvadrat > 2 && kvadrat < 6) {
            x = 3, y = 6;
        }
        else if (kvadrat > 5 && kvadrat < 9) {
            x = 6, y = 9;
        }

        for (int i = 1; i < 10; i++) {
            if (broj > 1) {
                kojiKvadrat = kvadrat + 1;
                break;
            }
            broj = 0;
            for (int j = x; j < y; j++) {
                for (int k = z; k < t; k++) {
                    if (sudoku[j][k] == i) {
                        broj++;
                    }
                }
            }
        }

        if (broj > 1) {
            kojiKvadrat = kvadrat + 1;
            break;
        }

        
        z = z + 3;
        t = t + 3;
        kvadrat++;
    }

    if (ponavljanjeRed <= 1 && ponavljanjeStupac <= 1) {
        printf("Ispravno!");
    }
    else {
        printf("Neispravno!\n");
        printf("Greska u: %d. redak, %d. stupac, %d. kvadrat.", brojRed, brojStupac, kojiKvadrat);
    }

    return 0;
}
