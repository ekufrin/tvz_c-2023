/*
TEKST ZADATKA:
Napišite C program koji će standardizirati uneseni datum. Od korisnika se traži unos dva stringa - datuma i predloška po kojem se datum čita
(pogledati test case za detalje).
Potrebno je napisati funkciju prototipa char *datumi (char *dat, char *pred) koja je će za uneseni datum dat i predložak pred vratiti standarizirani
zapis datuma, pri čemu je standardizirani zapis u obliku dd.mm.gggg.

TEST CASEOVI:
Test case #1
Primjer ulaza:
1/2/2014
m/d/gggg
Primjer izlaza:
02.01.2014.

Test case #2
Primjer ulaza:
2015-30-08
gggg-dd-mm
Primjer izlaza:
30.08.2015

Test case #3
Primjer ulaza:
4.7/13
d.m/g
Primjer izlaza:
04.07.2013
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* datumi(char* dat, char* pred);
int main()
{
	char unesenidatum[20] = {0};
	char predlozak[20] = {0};
	scanf("%s %s", unesenidatum, predlozak);

	char* rjesenje;
	rjesenje = datumi(unesenidatum, predlozak);
	printf("%s", rjesenje);
	return 0;
}
char* datumi(char* dat, char* pred) {
	int duljina = strlen(dat);
	char dan[5] = { 0 };
	char mjesec[5] = { 0 };
	char godina[10] = { 0 };
	char konacni[12] = { 0 };
	int brdan = 0, brmj = 0, brgod = 0;

	for (int i = 0; i < duljina; i++) {
		if (pred[i] == 'd') {
			dan[brdan] = dat[i];
			brdan++;
		}
		else if (pred[i] == 'm') {
			mjesec[brmj] = dat[i];
			brmj++;
		}
		else if (pred[i] == 'g') {
			godina[brgod] = dat[i];
			brgod++;
		}
	}
	if (strlen(dan) == 1) {
		dan[1] = dan[0];
		dan[0] = '0';
	}
	if (strlen(mjesec) == 1) {
		mjesec[1] = mjesec[0];
		mjesec[0] = '0';
	}
	if (strlen(godina) == 2) {
		godina[2] = godina[0];
		godina[3] = godina[1];
		godina[0] = '2';
		godina[1] = '0';

	}
	strcat(konacni, dan);
	strcat(konacni, ".");
	strcat(konacni, mjesec);
	strcat(konacni, ".");
	strcat(konacni, godina);
	strcat(konacni, ".");

	return konacni;
}
