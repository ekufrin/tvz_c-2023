/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/361d4f853013dc609fd9efb80cfee20d19c8dd72/tekstovi%20i%20test%20caseovi/%5B8%5DRed%20letenja%202.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char sifra[6 + 1];
	float cijena;
}cijene;

typedef struct {
	char pol[30 + 1];
	char odr[30 + 1];
	char sifraa[6 + 1];
}letovi;

int main()
{
	FILE* dat1 = fopen("cijene.dat", "rb");
	FILE* dat2 = fopen("letovi.txt", "r");
	cijene popis[1000];
	letovi niz[1000];
	float ulaz;
	int br = 0;

	scanf("%f", &ulaz);

	fseek(dat1, 0, SEEK_END);
	int vel = ftell(dat1) / sizeof(cijene);
	fseek(dat1, 0, SEEK_SET);
	fread(popis, sizeof(cijene), vel, dat1);

	while (fscanf(dat2, "%[^#]#%[^#]#%[^\n]\n", niz[br].pol, niz[br].odr, niz[br].sifraa) == 3)
	{
		br++;
	}

	for (int i = 0; i < vel; i++)
	{
		if (popis[i].cijena <= ulaz)
		{
			for (int j = 0; j < br; j++)
			{
				if (strcmp(popis[i].sifra, niz[j].sifraa) == 0)
				{
					printf("%s - %s\n", niz[j].pol, niz[j].odr);
				}
			}
		}
	}
	fclose(dat1);
	fclose(dat2);

	return 0;
}
