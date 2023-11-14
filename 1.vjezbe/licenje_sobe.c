//Napišite C program koji raèuna cijenu za lièenje prostorije visine V metara, širine S metara i duljine D metara, ako se jedan metar kvadratni naplaæuje 10, 40 kn.
//Potrebno je uzeti u obzir da se u prostoriji ne lièe podovi i vrata visine 0, 75 * V(75 % visine prostorije) i širine A i dva prozora dimenzija 0, 1 * Vx0, 1 * S(10 % visine i širine prostorije).
//
//V, S, D i A su pozitivni realni brojevi koje unosi korisnik.
//U sluèaju pogrešnih unosa dimenzija, ispisati odgovarajuæe poruke("Dimenzija mora biti pozitivna!" ili "Vrata moraju stati u prostoriju!").
//
//Nakon ispravnih unosa potrebno je ispisati konaènu cijenu lièenja u obliku :
//Konacna cijena je : __ kuna i ___lipa.

//Test case #1
//Visina je 2.2m, sirina je 3m, duzina je 4 m, a sirina vrata je 0.9m
//Primjer ulaza :
//2.2 3 4 0.9
//Primjer izlaza :
//Konacna cijena je : 428 kuna i 30 lipa.
//Test case #2
//Dimenzije sobe moraju biti pozitivni brojevi.
//Primjer ulaza :
//3.1 - 4 2.45 0.9
//Primjer izlaza :
//Dimenzija mora biti pozitivna!
//Test case #3
//Vrata moraju biti manja od sirine barem jednog od zidova.
//Primjer ulaza :
//4 2.3 2.81 3
//Primjer izlaza :
//Vrata moraju stati u prostoriju!



#define _CRT_SECURE_NO_WARNINGS
#define kvadrat 10.4
#include <stdio.h>
#include <math.h>

int main() {
	float V, S, D, SA;
	float cijena;

	scanf("%f %f %f %f", &V, &S, &D, &SA);

	if (V < 0 || S < 0 || D < 0 ) {
		printf("Dimenzija mora biti pozitivna!");
	}
	else if (SA > S) {
		printf("Vrata moraju stati u prostoriju!");
	}
	else {
		cijena = (((S * D) + 2 * (V * S) + 2 * (D * V)) - ((0.75 * V * SA) + 2 * (0.1 * V * 0.1 * S))) * kvadrat;
		int cijena2 = cijena;
		printf("Konacna cijena je: %.f kuna i %.f lipa.", cijena, (cijena-cijena2)*100);
	}


	return 0;
}