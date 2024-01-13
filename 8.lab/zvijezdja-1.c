/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/a6c264a8b56029dd64c5116833864014d359279d/tekstovi%20i%20test%20caseovi/%5B8%5DZvijezdja%201.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char ime[15 + 1];
	char kratica[3 + 1];
	int broj_najsjajnijih;
	float povrsina_neba;
}zvijezdjaStruct;

typedef struct {
	char kratica[3 + 1];
	char ime[15 + 1];
}zvijezdeStruct;

void trazi_zvijezdu(zvijezdjaStruct rezultat[], zvijezdeStruct popis_najsjajnijih[],int rez,int br);

int main()
{
	FILE* zvijezde = fopen("zvijezde.txt","r");
	FILE* zvijezdja = fopen("zvijezdja.dat", "rb");

	zvijezdjaStruct popis_zvijezdja[100];
	zvijezdjaStruct rezultat[100];
	zvijezdeStruct popis_najsjajnijih[100];

	fseek(zvijezdja, 0, SEEK_END);
	int vel = ftell(zvijezdja) / sizeof(zvijezdjaStruct);
	fseek(zvijezdja, 0, SEEK_SET);

	fread(popis_zvijezdja, sizeof(zvijezdjaStruct), vel, zvijezdja);

	int br = 0;
	int rez = 0;
	while (fscanf(zvijezde, "%[^#]#%[^\n]%*c", popis_najsjajnijih[br].kratica, popis_najsjajnijih[br].ime) != EOF) {
		br++;
	}

	int donja, gornja;
	scanf("%d", &donja);
	scanf("%d", &gornja);

	for (int i = 0; i < vel; i++) {
		if (popis_zvijezdja[i].broj_najsjajnijih > donja && popis_zvijezdja[i].broj_najsjajnijih < gornja) {
			rezultat[rez++] = popis_zvijezdja[i];
		}
	}

	trazi_zvijezdu(rezultat, popis_najsjajnijih, rez, br);

	

	fclose(zvijezde);
	fclose(zvijezdja);
	return 0;
}

void trazi_zvijezdu(zvijezdjaStruct rezultat[], zvijezdeStruct popis_najsjajnijih[],int rez,int br) {
	if (rez == 0) {
		printf("Prazan interval.");
	}
	else {
		for (int i = 0; i < rez; i++) {
			for (int j = 0; j < br; j++) {
				if (strcmp(rezultat[i].kratica, popis_najsjajnijih[j].kratica) == 0) {
					printf("%s - %s\n", popis_najsjajnijih[j].ime, rezultat[i].ime);
				}
			}

		}
	}
}
