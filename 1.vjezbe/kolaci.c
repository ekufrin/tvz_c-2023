//Perici je mama dala džeparac za šlolu, a on ga je odluèio potrošiti na kolaèe u slastièarni.
//Slastièarna nudi kolaèe razlièitih oblika, velièina i cijena.
//Perica treba program u koji unosi iznos džeparca, broj stranica, duljinu stranice, visinu kolaèa(sve u cm) i cijenu jednog komada(u kn).
//Program ispisuje koliko kolaèa može kupiti i kolika je isplativost(koliko kuna plati za jedan cm ^ 3 kolaèa).
//
//Broj stranica kolaèa ne smije biti manji od 3. Duljina stranice moraju biti 0 ili veæi.Ukoliko je unos krivi, ispisati "Krivi unos! Molim probajte opet." i èekati na novi unos.
//
//Napomene:
//ukljuèiti #include <math.h>
//formula za volumen jednog kolaèa : V = h * n * (a ^ 2) * (cos(3.14 / n) / sin(3.14 / n)) / 4
//isplativost = cijena jednog kolaèa / volumen jednog kolaèa

//Test case #1
//Moguæe je kupiti samo cijeli broj kolaèa!
//Primjer ulaza :
//1003 3 5 2 10
//Primjer izlaza :
//Perica moze kupiti : 100 kolaca, a platit ce 0.46kn / cm ^ 3.
//Test case #2
//Primjer ulaza :
//67 2 6 2 1 3
//Primjer izlaza :
//Krivi unos!Molim probajte opet.
//Perica moze kupiti : 22 kolaca, a platit ce 0.29kn / cm ^ 3.
//Test case #3
//Primjer ulaza :
//5 3 4 1 7
//Primjer izlaza :
//Perica moze kupiti : 0 kolaca, a platit ce 1.01kn / cm ^ 3.
//Test case #4
//Primjer ulaza :
//300 5 1 1 30
//Primjer izlaza :
//Perica moze kupiti : 10 kolaca, a platit ce 17.43kn / cm ^ 3.
//Test case #5
//Cijena može biti decimalni broj!
//Primjer ulaza :
//16 3 2 4 2.3
//Primjer izlaza :
//Perica moze kupiti : 6 kolaca, a platit ce 0.33kn / cm ^ 3.




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int dzeparac, n, a, h,kolicina;
	float cijena,isplatljivost,V;

	scanf("%d %d %d %d %f", &dzeparac, &n, &a, &h, &cijena);
	if (n < 3 || a < 0) {
		printf("Krivi unos! Molim probajte opet.");
		scanf("%d %d %d %d %f", &dzeparac, &n, &a, &h, &cijena);
	}
	else{
	V = (h * n * (a ^ 2) * (cos(3.14 / n)) / (sin(3.14 / n)) / 4);
	
	kolicina = dzeparac / cijena;
	isplatljivost = cijena / V;

	printf("Perica moze kupiti: %d kolaca, a platit ce %fkn/cm^3.", kolicina, isplatljivost);

	}
	return 0;
}