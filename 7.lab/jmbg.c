/*
TEKST ZADATKA:
JMBG je broj od 13 znamenaka, od kojih prvih 7
predstavlja datum rođenja.
Potrebno je napisati C program koji od korisnika
traži unos JMBG-a u obliku stringa i iz njega
izračunava datum rođenja osobe.
Izračun je potrebno napraviti u funkciji
prototipa char *datum (char *jmbg) koja kao
argument prima JMBG, a vraća datum rođenja u
formatu dd.mm.gggg.
U slučaju da je datum rođenja nemoguć, potrebno je
vratiti string "Greska", ispisati ga i ponoviti unos.

TEST CASEOVI:

Test case #1
Primjer ulaza:
1212974335051
Primjer izlaza:
12.12.1974.

Test case #2
Primjer ulaza:
3510985356732
0510985356732
Primjer izlaza:
Greska
05.10.1985.

Test case #3
Primjer ulaza:
5822998335242
0816998335242
0812998335242
Primjer izlaza:
Greska
Greska
08.12.1998.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* datum(char* jmbg) {
	char* dan = (char*)calloc(3,sizeof(char));
	char* mjesec= (char*)calloc(3, sizeof(char));
	char* godina= (char*)calloc(4, sizeof(char));
	int d = 0, m = 0, g = 0;

	strncpy(dan, jmbg, 2);
	strncpy(mjesec, jmbg + 2, 2);
	strncpy(godina, jmbg + 4, 3);


	d = atoi(dan);
	m = atoi(mjesec);
	g = atoi(godina);

	if (d > 31 || m > 12) {
		return "1";
	}

	char* rez=(char*)calloc(strlen(dan)+strlen(mjesec)+strlen(godina),sizeof(char));
	strcat(rez, dan);
	strcat(rez, ".");
	strcat(rez, mjesec);
	strcat(rez, ".");
	strcat(rez, "1");
	strcat(rez, godina);
	strcat(rez, ".");

	
	return rez;
}

int main()
{
	
	char jmbg[13+1];
	char* rezultat;
	do {
		scanf("%s%*c", &jmbg);
		rezultat = datum(jmbg);
		if (strcmp(rezultat, "1") == 0) {
			printf("Greska\n");
		}
	} while (strcmp(rezultat, "1") == 0);
	
	printf("%s", rezultat);

	return 0;
}
