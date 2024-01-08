/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/a0b1bc47ef9ef3969a48af4501f261bc78625987/tekstovi%20i%20test%20caseovi/%5B8%5DSigurne_i_nesigurne_lozinke.zip
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char user[40][40] = { 0 };
char pass[40][40] = { 0 };
char commonpasses[160][40] = { 0 };
char password[40] = { 0 };
int i = 0;
int j = 0;
int sigbrojac = 0;

FILE* lozinke = fopen("common_passwords.txt", "r");

while (fscanf(lozinke, "%s", password) == 1)
{
	strcpy(commonpasses[j], password);
	j++;
}

while (scanf("%[^:]:%s\n", user[i], pass[i])==2)
{
	i++;
}

FILE* rezultat = fopen("RezultatiAnalize.txt", "w");

for (int n = 0; n < i; n++)
{
	fprintf(rezultat, "%s\n", pass[n]);
}

fprintf(rezultat, "\n");
fprintf(rezultat, "Popis sigurnih lozinki:\n");

for (int k = 0; k < i; k++)
{
	sigbrojac = 0;
	for (int m = 0; m < j; m++)
	{
		if (strcmp(pass[k], commonpasses[m]) == 0)
		{
			sigbrojac++;
		}
		if (strncmp(user[k], pass[k], 5) == 0)
		{
			sigbrojac++;
		}
	}
	if (sigbrojac == 0)
	{
		fprintf(rezultat, "%s\n", pass[k]);
	}
}

fclose(lozinke);

return 0;
}
