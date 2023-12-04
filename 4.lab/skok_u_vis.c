/* kao treba unijeti u "tablicu" u prva dva stupca inicijale imena i prezimena, u 3 stupac kolko je visoko skocila, u 4 koji je to bio skok po redu
i onda kao moras provjerit tocnost podatka
i onda moras nac pobjednicu, koja je najvise skocila, ak ih ima vise onda trazis koja je od njih to u manje pokusaja, ako je i takvih vise onda njih sve ispises

FALI TEKST ZADATKA I TEST CASEOVI!

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
char inicijali[5][2], noviinicijali[5][2];
int brojevi[5][2], novibrojevi[5][2], b = 0;
for (int i = 0; i < 5; i++)
{
for (int j = 0; j < 2; j++)
{
scanf(" %c", &inicijali[i][j]);
}
for (int j = 0; j < 2; j++)
{
scanf("%d", &brojevi[i][j]);
if (j == 0)
{
if ((brojevi[i][0] != 200) && (brojevi[i][0] != 205) && (brojevi[i][0] != 208))
{
printf("Neispravni podatci\n");
i--;
break;
}
}
else
{
if (brojevi[i][1] > 3)
{
printf("Neispravni podatci\n");
i--;
break;
}
}
}
}

int max = brojevi[0][0], najmanjiredni = brojevi[0][1], a;
for (int i = 1; i < 5; i++)
{
	if (brojevi[i][0] > max)
	{
		max = brojevi[i][0];
		//pamcenje reda
		a = i;
	}
	if (najmanjiredni > brojevi[i][1])
	{
		najmanjiredni = brojevi[i][1];
	}
}
int brojanjeistih = 0;
for (int i = 0; i < 5; i++)
{
	int j = 0;
	if (max == brojevi[i][j])
	{
		novibrojevi[brojanjeistih][0] = brojevi[i][j];
		novibrojevi[brojanjeistih][1] = brojevi[i][1];
		noviinicijali[brojanjeistih][0] = inicijali[i][j];
		noviinicijali[brojanjeistih][1] = inicijali[i][1];

		brojanjeistih++;
	}
}
printf("Pobjednica je:\n");
for (int i = 0; i <= brojanjeistih; i++)
{
	if (novibrojevi[i][1] == najmanjiredni)
	{
		printf("%c%c %d %d\n", noviinicijali[i][0], noviinicijali[i][1], novibrojevi[i][0], novibrojevi[i][1]);
	}
}




return 0;
}
