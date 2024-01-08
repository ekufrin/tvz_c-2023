/*
U datoteci naziva "nogomet.txt" nalaze se rezultati utakmica 18 nogometnih klubova australske lige (nazivi klubova su točni, a rezultati su nasumično odabrani!).
Jedan zapis u datoteci je zapisan prema sljedećem:
naziv 1. kluba#naziv 2. kluba#broj golova 1.kluba:broj golova 2.kluba
kao na primjeru:
North Melbourne Kangaroos (Melbourne)#Adelaide Crows (Adelaide)#6:3
Nazivi klubova mogu se sastojati od više riječi.

Učitavanjem ulazne datoteke sastavite izlaznu datoteku s nazivom "prvi.txt" koja sadrži zapis kluba koji ima najviše bodova, u obliku strukture:
naziv kluba (do 40 znakova),
broj odigranih utakmica, cijeli broj,
broj pobjeda, cijeli broj,
broj neriješenih ishoda, cijeli broj,
broj poraza, cijeli broj,
ukupni broj bodova, cijeli broj.
Bodove računate prema uobičajenom kriteriju: za pobjedu 3, za neriješeno 1, za poraz 0.

Datoteka za ulaz: nogomet.txt
Izlazna datoteka: prvi.txt

POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/62c20f7bf20e58b7e007c59aba7e7c8250cbd18d/tekstovi%20i%20test%20caseovi/nogomet.txt
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tim
{
char naziv[40] = { 0 };
int brojutakmica;
int pobjede;
int nerjeseni;
int porazi;
int ukupnibodovi;
};

int main()
{
FILE* klubovi = fopen("nogometi.txt", "r");

char nazivtima[40] = { 0 };
char nazivdrugogtima[40] = { 0 };
int rez1 = 0;
int rez2 = 0;
int flag1 = 0;
int flag2 = 0;
int brojactimova = 0;
int timindex = 0;
int najbodovi = 0;

tim timovi[18] = { 0 };

while (fscanf(klubovi, "%[^#]#%[^#]#%d:%d\n", nazivtima, nazivdrugogtima, &rez1, &rez2) == 4)
{
	flag1 = 0;
	flag2 = 0;

	for (int i = 0; i < 18; i++)
	{
		if (strcmp(timovi[i].naziv, nazivtima) == 0)
		{
			flag1++;
			timovi[i].brojutakmica++;
			if (rez1 > rez2)
			{
				timovi[i].pobjede++;
				timovi[i].ukupnibodovi += 3;
			}
			else if (rez1 == rez2)
			{
				timovi[i].nerjeseni++;
				timovi[i].ukupnibodovi += 1;
			}
			else
			{
				timovi[i].porazi++;
			}
		}

		if (strcmp(timovi[i].naziv, nazivdrugogtima) == 0)
		{
			flag2++;
			timovi[i].brojutakmica++;
			if (rez1 < rez2)
			{
				timovi[i].pobjede++;
				timovi[i].ukupnibodovi += 3;
			}
			else if (rez1 == rez2)
			{
				timovi[i].nerjeseni++;
				timovi[i].ukupnibodovi += 1;
			}
			else
			{
				timovi[i].porazi++;
			}
		}
	}

	if (flag1 == 0)
	{
		strcpy(timovi[brojactimova].naziv, nazivtima);
		timovi[brojactimova].brojutakmica++;
		if (rez1 > rez2)
		{
			timovi[brojactimova].pobjede++;
			timovi[brojactimova].ukupnibodovi += 3;
		}
		else if (rez1 == rez2)
		{
			timovi[brojactimova].nerjeseni++;
			timovi[brojactimova].ukupnibodovi += 1;
		}
		else
		{
			timovi[brojactimova].porazi++;
		}
		brojactimova++;
	}

	if (flag2 == 0)
	{
		strcpy(timovi[brojactimova].naziv, nazivdrugogtima);
		timovi[brojactimova].brojutakmica++;
		if (rez1 < rez2)
		{
			timovi[brojactimova].pobjede++;
			timovi[brojactimova].ukupnibodovi += 3;
		}
		else if (rez1 == rez2)
		{
			timovi[brojactimova].nerjeseni++;
			timovi[brojactimova].ukupnibodovi += 1;
		}
		else
		{
			timovi[brojactimova].porazi++;
		}
		brojactimova++;
	}
}

for (int i = 0; i < 18; i++)
{
	if (timovi[i].ukupnibodovi > najbodovi)
	{
		najbodovi = timovi[i].ukupnibodovi;
		timindex = i;
	}
}

FILE* prvitim = fopen("prvi.txt", "w");

fprintf(prvitim, "%s %d %d %d %d %d", timovi[timindex].naziv, timovi[timindex].brojutakmica, timovi[timindex].pobjede,
	timovi[timindex].nerjeseni, timovi[timindex].porazi, timovi[timindex].ukupnibodovi);

fclose(klubovi);
fclose(prvitim);

return 0;
}
