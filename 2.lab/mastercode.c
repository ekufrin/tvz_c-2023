/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/00e6ff5e9b203cb4369ef9c874a7e5d59f5b43a0/tekstovi%20i%20test%20caseovi/%5B2%5D%20Mastercode%202.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char prvi, zadnji;
	char recenica[100];
	int cnt = 0;
	scanf("%c-%c", &prvi, &zadnji);
	while (prvi != '.')
	{
		if (prvi == '_')
		{
			recenica[cnt] = ' ';
			cnt++;
		}
		else if((int)prvi < (int)zadnji)
		{
			for (int i = (int)prvi; i <= (int)zadnji; i++)
			{
				recenica[cnt] = (char)i;
				cnt++;
			}
		}
		else if ((int)prvi > (int)zadnji)
		{
			for (int i = (int)prvi; i >= (int)zadnji; i--)
			{
				recenica[cnt] = (char)i;
				cnt++;
			}
		}
		else if ((int)prvi == (int)zadnji)
		{
			recenica[cnt] = prvi;
			cnt++;
		}
		scanf(" %c-%c", &prvi, &zadnji);
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%c", recenica[i]);
	}

	return 0;
}