// Jakov je na poslu dobio zadatak provjeravati logove i brojati koliko se puta neka znamenka z u njima pojavljuje. Logovi su organizirani tako da se pamte samo zadnja
//4 retka teksta unesena s tipkovnice.
//Jakovu je dosadilo ručno brojati koliko se puta pojavila tražena zamenka te Vas je zamolio da mu pomognete. Treba mu program koji od korisnika traži unos znamenke
//z i zatim niz redaka teksta.
//Program uvijek pamti samo 4 posljednja retka teksta i unutar posebne funkcije trazi prebrojava koliko se puta tražena znamenka pojavljuje u trenutnim logovima.
//Nakon svakog novog unesenog retka, glavni program ispisuje novi broj pojave znamenke. Program završava unosom stringa END.

/*
ulaz:
2
INFO:root:Started process 1
INFO:root:Started process 2
INFO:root:Started process 3
END
izlaz:
0
1
1

ulaz:
2
INFO:root:Started process 1
INFO:root:Started process 2
INFO:root:Started process 3
WARNING:root:Unauthorized changes in process 3
WARNING:42 alarms active
INFO:sector_1:open gate 12
END
izlaz:
0
1
1
1
2
2

ulaz:
3
INFO:root:Started process 1
WARNING:33 alarms active
INFO:root:Started process 2
ERROR:Unauthorized access
INFO:root:Ended process 2
WARNING:37 alarms active
INFO:root:Started process 3
WARNING:root:Unauthorized changes in process 3
INFO:root:Ended process 3
WARNING:42 alarms active
INFO:sector_1:open gate 12
END
izlaz:
0
2
2
2
2
1
2
3
4
3
2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pojava_znamenke(char* rijec, char z);

int main()
{
char** rijeci = (char**)calloc(20, sizeof(char*));
int brojac = 0, br_znam = 0, pojava[20] = { 0 }, tmp = 0, brojevi[20] = { 0 };
char z;

for (int i = 0; i < 20; i++)
{
	rijeci[i] = (char*)calloc(100, sizeof(char));
}

scanf("%c\n", &z);

while (brojac < 20)
{
	scanf("%100[^\n]", rijeci[brojac]);
	getchar();
	if (strcmp(rijeci[brojac], "END") == 0)
		break;
	tmp += pojava_znamenke(rijeci[brojac], z);
	pojava[brojac] = tmp;
	brojevi[brojac] = pojava_znamenke(rijeci[brojac], z);

	if (brojac >= 4)
	{
		for (int i = 0; i <= brojac-4; i++)
		{
			if (brojevi[i] > 0)
				pojava[brojac] -= brojevi[i];
		}
	}

	printf("%d\n", pojava[brojac]);
	brojac++;
}

return 0;
}

int pojava_znamenke(char* rijec, char z)
{
int brojac = 0;

for (int i = 0; i <= strlen(rijec); i++)
{
	char tmp = rijec[i];
	if (tmp == z)
	{
		brojac++;
	}
}

return brojac;
}
