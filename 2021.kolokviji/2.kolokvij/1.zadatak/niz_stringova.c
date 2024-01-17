/*
Napišite C program koji od korisnika traži unos rečenica dok se ne učita znak "?".
Nakon toga, u program treba u funkciji sort_po_a sortirati sve unesene rečenice prema broju slova a (neovisno o tome jesu li
velika ili mala) u svakoj od njh, od najvećeg broja prema najmanjem. U slučaju da ima jednak broj slova a, potrebno ih je ostaviti
u redoslijedu kojem su upisane.
Sortirane rečenice potrebno je ispisati u glavnom programu.

Test case #1
Primjer ulaza:
Sutra je utorak.
Je li danas ponedjeljak?

Primjer izlaza:
Je li danas ponedjeljak?
Sutra je utorak.

Test case #2
Primjer ulaza:
Sutra je utorak.
Jucer je bila nedjelja.
Danas je ponedjeljak.
Koliko dana ima tjedan?

Primjer izlaza:
Koliko dana ima tjedan?
Danas je ponedjeljak.
Sutra je utorak.
Jucer je bila nedjelja.

test case #3:
primjer ulaza:
Sutra je utorak.
Aaaaa...pomozite!
Jucer je bila nedjelja.
Abrakadabra!
Danas je ponedjeljak.
Koliko dana ima tjedan?

primjer izlaza:
Aaaaa...pomozite!
Abrakadabra!
Koliko dana ima tjedan?
Danas je ponedjeljak.
Sutra je utorak.
Jucer je bila nedjelja.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void sort_po_a(char** recenice, int br);

int main()
{
char** recenice = NULL;
int br = 0;

recenice = (char**)calloc(10, sizeof(char*));
for (int i = 0; i < 10; i++)
	recenice[i] = (char*)calloc(200, sizeof(char));

while (1)
{
	scanf("%[^\n]%*c", recenice[br]);

	if (recenice[br][strlen(recenice[br]) - 1] == '?')
		break;

	br++;
}
br++;

sort_po_a(recenice, br);

for (int i = 0; i < br; i++)
	printf("%s\n", recenice[i]);

return 0;
}

void sort_po_a(char** recenice, int br)
{
char* tmp;
int brojaci[10] = { 0 };

for (int i = 0; i < br; i++)
{
	for (int j = 0; j < strlen(recenice[i]); j++)
	{
		if (recenice[i][j] == 'a' || recenice[i][j] == 'A')
			brojaci[i]++;
	}
}

for (int i = 0; i < br; i++)
{
	for (int i = 0; i < br-1; i++)
	{
		if (brojaci[i] < brojaci[i + 1])
		{
			int tmp1 = brojaci[i];
			brojaci[i] = brojaci[i + 1];
			brojaci[i + 1] = tmp1;

			tmp = recenice[i];
			recenice[i] = recenice[i + 1];
			recenice[i + 1] = tmp;
		}
	}
}

return;
}
