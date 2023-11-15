/*
TEKST ZADATKA: Unose se dva broja, 1.broj je koliko ima pjesama, 2.broj je koliko je pjesama kratkih. 
Potrebno je prvo ispisati N kratkih pjesama, te zatim ostale pjesme.
Pogledati test caseove.
TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/ba35335fef55cd5183e31070463de5a4d141f3c4/tekstovi%20i%20test%20caseovi/%5B3%5D%20Playlist.png
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, K, pjesme[100], min, s, zamjena = 0;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d:%d", &min, &s);
		pjesme[i] = min * 60 + s;
	}

	do
	{
		zamjena = 0;
		for (int i = 0; i < N - 1; i++)
		{
			if (pjesme[i + 1] < pjesme[i])
			{
				int t = pjesme[i];
				pjesme[i] = pjesme[i + 1];
				pjesme[i + 1] = t;
				zamjena = 1;
			}
		}
	} while (zamjena);
	printf("\n");
	for (int i = K - 1; i >= 0; i--)
	{
		printf("%d:%02d\n", pjesme[i] / 60, pjesme[i] % 60);
	}
	printf("\n");
	for (int i = N - 1; i >= K; i--)
	{
		printf("%d:%02d\n", pjesme[i] / 60, pjesme[i] % 60);
	}



}
