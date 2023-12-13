/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/1863744b9e1e3578ab659cf149aea73aeb361a0d/tekstovi%20i%20test%20caseovi/%5B6%5DKolonizacija%20s%20konkurencijom.jpg
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void brojanjeM(char** polje, int m, int n, int t)
{
	int br = 0;
	int h = 0;
	int max = 0;
	int niz[100] = { 0 };
	int y = 0;
	int x = 0;
	int spremi = 0;
	for (int i = 0; i <= m-t; i++)
	{
		for (int j = 0; j <= n - t; j++)
		{
			for (int f = 0; f < t; f++)
			{
				for (int g = 0; g < t; g++)
				{
					if (polje[i + f][j + g] == 'M')
					{
						br++;
					}
				}
			}
		
		if (br > max)
		{
			max = br;
			x = i + 1;
			y = j + 1;
		}
		br = 0;
		h = 0;
		}
	}

	printf("Optimalno je staviti gornji lijevi kut tora na lokaciju [%d,%d] sto donosi ukupno %d muflona.",x ,y,max);
	printf("\n");
}

int main()
{
	int m, n, t;

	scanf("%d %d %d", &m, &n, &t);

	char** polje = (char*)malloc(m * sizeof(char));
	for (int i = 0; i < m; i++)
	{
		polje[i] = (char*)malloc(n * sizeof(char));
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf(" %c", &polje[i][j]);
		}
	}
	printf("\n");
	brojanjeM(polje, m, n, t);


	for (int i = 0; i < m; i++)
	{
		free(polje[i]);
	}
	free(polje);
}
