//Roðak ste od gradonaèelnika, i postavljate stupiæe uz pristojnu maržu.Zakonom je propisano u gradu gdje je gradonaèelnik da je minimalna udaljenost(S) izmeðu 2 stupiæa toèno 25cm.Naravno, uz zadanu duljinu D u metrima, i radijus stupiæa(R, u cm) koji su vam dostupni, potrebno je izraèunati koliko je najviše stupiæa moguæe natrpati na zadanu duljinu.
//Želite znati, za unesene podatke R i D, koliko je potrebno naruèiti stupiæa.
//Test case #1
//Radijus je 10cm, duljina je 1.1m.Mozemo savrseno natrpati 3 stupiæa.
//Primjer ulaza :
//10 1.1
//Primjer izlaza:
//3
//
//Test case #2
//Primjer ulaza :
//1 17
//Primjer izlaza :
//63
//
//Test case #3
//Primjer ulaza :
//7 180
//Primjer izlaza :
//462
//
//Test case #4
//Primjer ulaza :
//10 1.2
//Primjer izlaza :
//3
//
//Test case #5
//Primjer ulaza :
//22 180
//Primjer izlaza :
//261

#define _CRT_SECURE_NO_WARNINGS
#define udaljenost 25
#include <stdio.h>
#include <math.h>

int main() {
	float radijus,duljina, stupici;
	int provjera;

	scanf("%f %f", &radijus, &duljina);
	stupici = (duljina * 100) / (radijus*2 + udaljenost);
	provjera = (int)stupici;
	if (provjera == 2) {
		stupici += 1;
	}

	printf("%.f", stupici);



	return 0;
}