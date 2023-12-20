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
#include <stdlib.h>
#include <string.h>

char* datumizacija(char* dat, char* pred)
{
int duljina = strlen(dat);
int brojmj = 0;
int brojdan = 0;
int brojgod = 0;
int flag = 0;
char mjeseci[5] = { 0 };
char dani[5] = { 0 };
char godine[6] = { 0 };
char* gotovi = (char*)calloc(20, sizeof(char));

for (int i = 0; i < duljina; i++)
{
	if (pred[i] == 'm')
	{
		mjeseci[brojmj] = dat[i];
		brojmj++;
	}
	else if (pred[i] == 'd')
	{
		dani[brojdan] = dat[i];
		brojdan++;
	}
	else if (pred[i] == 'g')
	{
		godine[brojgod] = dat[i];
		brojgod++;
		flag = i;
	}
}

if (brojgod == 1)
{
	godine[1] = dat[flag+1];
}

if (strlen(dani) == 1)
{
	dani[1] = dani[0];
	dani[0] = '0';
	dani[2] = '.';
}
else if (strlen(dani) == 2)
{
	dani[2] = '.';
}

if (strlen(mjeseci) == 1)
{
	mjeseci[1] = mjeseci[0];
	mjeseci[0] = '0';
	mjeseci[2] = '.';
}
else if (strlen(mjeseci) == 2)
{
	mjeseci[2] = '.';
}

if (strlen(godine) == 2)
{
	godine[2] = godine[0];
	godine[3] = godine[1];
	godine[0] = '2';
	godine[1] = '0';
	godine[4] = '.';
}

strcat(gotovi, dani);
strcat(gotovi, mjeseci);
strcat(gotovi, godine);

return gotovi;
}

int main()
{
char datum[20] = { 0 };
char predlozak[20] = { 0 };
char* rjesenje = 0;

scanf("%s", datum);
scanf("%s", predlozak);

rjesenje = datumizacija(datum, predlozak);

printf("%s", rjesenje);

free(rjesenje);

return 0;
}
