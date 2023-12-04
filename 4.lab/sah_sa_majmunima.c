/*Tek ste naučili igrati šah (i to zamalo), pa je prvi protivnik s kojim ćete se okušati susjedov majmun. Pošto majmun ipak
nije baš vješt u šahu, odlučili ste malo pojednostaviti pravila:
vi koristite K pijuna
majmun koristi samo jednog topa (topovi u šahu se kreću vodoravno i okomito)
šahovska ploča ima isti broj redaka i stupaca (ali ne nužno 8)
Dali ste svom protivniku da rasporedi figure po vlastitom nahođenju (!?), te vas sada interesira koliko je vaših pijuna u
opasnosti od protivnikovog topa.
Kao rezultat, potrebno je ispisati šahovsku tablu na način da:
vaši pijun koji nisu u opasnosti budu ispisani velikim slovom P
vaši pijuni koji su pod napadom topa budu ispisani velikim slovom X
protivnikov top velikim slovom T
prazno polje na tabli treba ispisati kao točku '.'
pod napadom može biti samo prvi pijun koji se nalazi u retku ili stupcu do topa. Primjerice: TPP -> TXP - drugi
pijun nije pod napadom jer top ne može preskočiti prvog pijuna.
Ulazni podaci su zadani na sljedeći način:
Prvi redak sadrži broj N koji označava broj redaka i broj stupaca na tabli. N će uvijek biti manji od 10
Drugi redak sadrže koordinate majmunovog topa u obliku Tr Ts, gdje je Tr redak u kojem je top a Ts stupac u
kojem je top.
Slijedi broj K, koji označava broj vaših pijuna
Na kraju je potrbeno učitati K redaka, u obliku Pr Ps, gdje je Pr redak a Ps stupac pojedinog pijuna

FALE TEST CASEOVI!
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
int N = 0;
int Tr = 0;
int Ts = 0;
int K = 0;
int Pr = 0;
int Ps = 0;

char niz[25][25] = { 0 };

scanf("%d", &N);

for (int i = 0; i < N; i++)
{
	for (int j = 0; j < N; j++)
	{
		niz[i][j] = '.';
	}
}

scanf("%d", &Tr);
scanf("%d", &Ts);

niz[Tr - 1][Ts - 1] = 'T';

scanf("%d", &K);

for (int i = 0; i < K; i++)
{
	scanf("%d", &Pr);
	scanf("%d", &Ps);

	niz[Pr - 1][Ps - 1] = 'P';
	for (int j = 0; j < K; j++)
	{
		if (niz[Pr - 1 - j][Ps - 1] == 'T')
		{
			niz[Pr - 1][Ps - 1] = 'X';
		}
	}
	for (int j = 0; j < K; j++)
	{
		if (niz[Pr - 1 + j][Ps - 1] == 'T')
		{
			niz[Pr - 1][Ps - 1] = 'X';
		}
	}
	for (int j = 0; j < K; j++)
	{
		if (niz[Pr - 1][Ps - 1 - j] == 'T')
		{
			niz[Pr - 1][Ps - 1] = 'X';
		}
	}
	for (int j = 0; j < K; j++)
	{
		if (niz[Pr - 1][Ps - 1 + j] == 'T')
		{
			niz[Pr - 1][Ps - 1] = 'X';
		}
	}
}

for (int i = 0; i < N; i++)
{
	for (int j = 0; j < N; j++)
	{
		printf("%c", niz[i][j]);
	}
	printf("\n");
}

return 0;
}
