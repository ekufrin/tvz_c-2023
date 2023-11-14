//Napišite program koji æe na temelju boje oèiju roditelja odrediti koju boju oèiju može imati njihovo dijete.
//Boja oèiju djeteta odreðuje se prema sljedeæim pravilima :
//Program kao ulazni parametar prima 2 znaka koji predstavljaju boju oèi roditelja, gdje :
//
//	smeðe oèi mogu biti unesene znakom S ili s
//
//	zelene oèi mogu biti unesene znakom Z ili z
//
//	plave oèi mogu biti unesene znakom P ili p


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {

	char oko1, oko2;
	int rezultat;
	scanf("%c %c", &oko1, &oko2);
	oko1 = tolower(oko1);
	oko2 = tolower(oko2); // Pošto je potrebno napraviti unos i za veliko i malo slovo, ova komanda æe nebitno unesemo li veliko ili malo slovo, transformirati ga u malo

	rezultat = oko1 + oko2;

	// zbrojimo 2 slova te pomoæu ASCII tablice dobijemo rezultat koji koristimo u switch caseu
	// npr s(115 broj u ASCII tablici) + s(115) = 230 , stavimo case 230: i isprintamo rezultat koji treba, i tako i za ostale kombinacije
	// takoðer možemo i direktno u case staviti 's'+'s', te æe program sam automatski to zbrojiti i usporediti sa rezultatom

	switch (rezultat)
	{
	case 's'+'s':
		printf("75%%");
		break;
	case 'z'+'s':
		printf("50%%");
		break;
	case 'p' + 's':
		printf("50%%");
		break;
	case 'z' + 'z':
		printf("<1%%");
		break;
	case 'z' + 'p':
		printf("0%%");
		break;
	case 'p' + 'p':
		printf("0%%");
		break;
	default:
		printf("Krivi unos!");
		break;
	}
	

	return 0;
}