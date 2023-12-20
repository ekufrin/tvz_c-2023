/*
TEKST ZADATKA:
Napišite funkciju naziva stringUfloat koja pretvara
string unesen preko tipkovnice u float tip podatka.
Prototip funkcije je: float stringUfloat (char *s)
NAPOMENA: Za rješavanje zadatka zabranjeno je
koristiti ugrađene funkcije iz string.h i stdlib.h.


TEST CASEOVI:
Test case #1
Ulaz:
12
Izlaz:
12.0

Test case #2
Ulaz:
-123.456
Izlaz:
-123.456

Test case #3
Ulaz:
-123.456e2
Izlaz:
-12345.6

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

float stringUfloat(char* s)
{
	float broj = 0;
	int i = 0;
	int umnozak = 1;
	int brZn = 0;
	

	//Brojanje znamenki
	while (s[i] != '\0')
	{
		brZn++;
		i++;
	}
	i = brZn - 1;

	//Provjeravanje posbenih znakova
	int mjDecimale = 0;
	int mje = 0;
	for (int i = 0; i < brZn; i++)
	{
		if (s[i] == '.')
		{
			mjDecimale = i;
		}
		if (s[i] == 'e')
		{
			mje = i;
		}
	}
	//Cijeli = 0, Decimalni = 2, Znanstveni = 3
	int tipBr = 0;
	for (int x = 0; x < brZn; x++)
	{
		if (s[x] == '.')
		{
			tipBr = 2;
		}
		if (s[x] == 'e')
		{
			tipBr = 3;
		}
	}

	//Pretvorba broja
	switch (tipBr)
	{
	case 0:
		for (int i = brZn - 1; i >= 0; i--)
		{
			if (s[0] == '-')
			{
				if (s[i] != '-')
				{
					broj -= (float)(s[i] - '0') * umnozak;
					umnozak *= 10;
				}
			}
			else {
				broj += (float)(s[i] - '0') * umnozak;
				umnozak *= 10;
			}
		}
		break;

	case 2:
		//Racunanje cijelog dijela
		for (int i = mjDecimale - 1; i >= 0; i--)
		{
			if (s[0] == '-')
			{
				if(s[i] != '-')
				{
					broj -= (float)(s[i] - '0') * umnozak;
					umnozak *= 10;
				}
			}
			else {
				broj += (float)(s[i] - '0') * umnozak;
				umnozak *= 10;
			}
		}
		int djelitelj = 10;
		//Racunanje dec dijela
		for (int i = mjDecimale + 1; i < brZn; i++)
		{
			
			if (s[0] == '-')
			{
				broj -= (float)(s[i] - '0') / djelitelj;
				djelitelj *= 10;
			}
			else {
				broj += (float)(s[i] - '0') / djelitelj;
				djelitelj *= 10;
			}
		}
		break;

	case 3:
		//Racunanje cijelog dijela
		for (int i = mjDecimale - 1; i >= 0; i--)
		{
			if (s[0] == '-')
			{
				if (s[i] != '-')
				{
					broj -= (float)(s[i] - '0') * umnozak;
					umnozak *= 10;
				}
			}
			else {
				broj += (float)(s[i] - '0') * umnozak;
				umnozak *= 10;
			}
		}
		djelitelj = 10;
		//Racunanje dec dijela
		for (int i = mjDecimale + 1; i < mje; i++)
		{

			if (s[0] == '-')
			{
				broj -= (float)(s[i] - '0') / djelitelj;
				djelitelj *= 10;
			}
			else {
				broj += (float)(s[i] - '0') / djelitelj;
				djelitelj *= 10;
			}
		}

		//Mnozenje znanstvenim umnoskom
		for (int i = 0; i < s[mje + 1] - '0'; i++)
		{
			broj *= 10;
		}
		break;
	}
	return broj;
}

int main()
{
	char broj[20];
	scanf("%s", broj);
	float konBr = stringUfloat(broj);
	if ((int)konBr == konBr)
	{
		printf("%g.0", konBr);
	}
	else {
		printf("%g", konBr);
	}
	return 0;
}
