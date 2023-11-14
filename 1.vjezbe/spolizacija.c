//Spolizacija je proces u birokraciji kojim se na temelju JMBG broja graðana odreðuje kojeg je spola graðanin.Za Zagreb vrijedi sljedeæe pravilo kod JMBG brojeva : prvih 7 znamenki nastaje iz datuma roðenja, nakon toga 330 ako se radi o muškarcu, 335 ako se radi o ženi.Algoritam za zadnje 3 znamenke je u našem sluèaju nebitan, i recimo da su zadnje 3 znamenke proizvoljne.
//
//Primjer jednog JMBG - a muškarca roðenog na datum 04.07.2010. :
//	0407010330007 (test case 1)
//	Primjer jednog JMBG - a žene roðene na datum 12.03.1996. :
//	1203996335909 (test case 2)
//
//	Dodatno, spolizaciju obavlja tek referent poèetnik, te zbog ne snalaženja u poslu unosi JMBG znamenku po znamenku u svaki redak.Vaša je zadaæa napisati program u kojem æe on unijeti znamenku po znamenku i po unosu svih 13 znamenki, program ispisuje „Muška osoba“ ukoliko se radi o muškarcu ili „Ženska osoba“ ukoliko se radi o ženi.


//Test case #1
//Primjer ulaza :
//0
//4
//0
//7
//0
//1
//0
//3
//3
//0
//0
//0
//7
//
//Primjer izlaza :
//Musko!
//Test case #2
//Primjer ulaza :
//1
//2
//0
//3
//9
//9
//6
//3
//3
//5
//9
//0
//9
//
//Primjer izlaza :
//Zensko!
//Test case #3
//Primjer ulaza :
//1
//2
//0
//3
//9
//9
//6
//3
//3
//4
//9
//0
//9
//
//Primjer izlaza :
//Greska!



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int JMBAG = 0;
	int spol = 0;

	for (int i = 0; i < 13; i++) {
		scanf("%d", &JMBAG);
		if (i == 9) {
			spol = JMBAG;
		}
	}

	if (spol == 0) {
		printf("Musko!");
	}
	else if (spol == 5) {
		printf("Zensko!");
	}
	else {
		printf("Greska!");
	}

	return 0;
}