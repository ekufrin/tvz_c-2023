/*Igrate jednu jako jako zanimljivu igru, a radi se o tome da na brdovitom Balkanu želite što više izravnati brda i planine kako bi prostor bio što ujednačeniji jer je to garancija ekonomskog uspjeha.
Svaka lokacija na mapi ima određenu visinu, a poravnavanje se radi na način da se visina prilagođava s obzirom na susjedne lokacije uzimajući prosjek svih susjednih lokacija i trenutne lokacije, te to postaje nova visina.
Nastavlja se iterativno s procesom dok god najveća razlika izmežu bilo koje dvije točke ne bude manja od 1.

Primjerice, ako je zadana mapa od 3 retka i 3 stupca (neće biti više od 20 redaka ili stupaca), gdje je u sredini brdo visine 2, poravnavanje se vrši samo u jednom koraku:
0 0 0
0 2 0
0 0 0

Nakon poravnavanja dobiva se sljedeća konfiguracija terena:
0.50 0.33 0.50
0.33 0.22 0.33
0.50 0.33 0.50

Primjerice, gornji lijevi ugao [0,0] se računa kao (0+0+0+2)/4 = 0.5 (zbroj visina na trenutnoj i lokacijama koje su susjedne - [0,0]+[0,1]+[1,0]+[1,1])
Središnja lokacija se računa na isti način, ali ima 8 susjeda - [0,0], [0,1], [0,2], [1,0], [1,2], [2,0], [2,1], [2,2] => (0+0+0+0+0+0+0+0+2)/9 = 0.22.

Savjet za rješavanje
Pošto koraka potencijalno ima više, potrebno je koristiti glavnu i pomoćnu matricu, računati nove visine i spremati ih u pomoćnu matricu, te na kraju svakog koraka prepisati vrijednosti iz pomoćne u glavnu matricu.
Koristiti tip podatka za decimalni broj dvostruke preciznosti, pri čemu se učitava s %lf, a ispisuje sa %f.


FALI OSTATAK TEST CASEOVA.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main() {
double mapa[MAX][MAX];
int red, stu;
scanf("%d %d", &red, &stu);

for (int i = 0; i < red; i++) {
	for (int j = 0; j < stu; j++) {
		scanf(" %lf", &mapa[i][j]);
	}
}

double konacno[MAX][MAX], tmp[MAX][MAX], maxRazlika = 0;
double suma = 0, br = 0., avg;
int koraci = 0;

for (int i = 0; i < red; i++) {
	for (int j = 0; j < stu; j++) {
		for (int m = 0; m < red; m++) {
			for (int n = 0; n < stu; n++) {
				if (m != i || n != j) {
					float razlika = mapa[i][j] - mapa[m][n];
					if (razlika < 0) {
						razlika *= -1;
					}
					if (razlika > maxRazlika) {
						maxRazlika = razlika;
					}
				}
			}
		}
	}
}

while (maxRazlika >= 1) {
	koraci++;
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < stu; j++) {
			for (int m = (i == 0 ? i : i - 1); m <= i + 1 && m < red; m++) {
				for (int n = (j == 0 ? j : j - 1); n <= j + 1 && n < stu; n++) {
					suma += mapa[m][n];
					br++;
				}
			}
			avg = suma / br;
			suma = 0;
			br = 0.;
			tmp[i][j] = avg;
		}
	}
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < stu; j++) {
			mapa[i][j] = tmp[i][j];
		}
	}
	maxRazlika = 0;
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < stu; j++) {
			for (int m = 0; m < red; m++) {
				for (int n = 0; n < stu; n++) {
					if (m != i || n != j) {
						double razlika = mapa[i][j] - mapa[m][n];
						if (razlika < 0) {
							razlika *= -1;
						}
						if (razlika > maxRazlika) {
							maxRazlika = razlika;
						}
					}
				}
			}
		}
	}
}

printf("Potrebno je %d koraka. Konacna matrica:\n", koraci);
for (int i = 0; i < red; i++) {
	for (int j = 0; j < stu; j++) {
		if (j == stu - 1) {
			printf("%.2f\n", mapa[i][j]);
		}
		else {
			printf("%.2f ", mapa[i][j]);
		}
	}
}
return 0;
}
