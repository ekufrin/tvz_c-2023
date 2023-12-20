/*
TEKST ZADATKA:
Pretvori telefonski broj u standardizirani. (Pogledaj test caseove)

TEST CASEOVI:
Test case #1
Ulaz:
01/2323211
Izlaz:
+38512323211

Test case #2
Ulaz:
098/123-456
Izlaz:
+38598123456

Test case #3
Ulaz:
+385-21-987-6543
Izlaz:
+385219876543

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char* telefonski(char* stari)
{
	char* telefonski=NULL;
	telefonski = (char*)calloc(20, sizeof(char));
	strcpy(telefonski, "+385");

	int i = 0;
	int t = 4;
	while (stari[i]!=NULL)
	{
		if ((stari[i] == '+') && (stari[i + 1] == '3') && (stari[i + 2] == '8') && (stari[i + 3] == '5'))
		{
			i += 4;
		}
		if (isdigit(stari[i]))
		{
			telefonski[t] = stari[i];
			t++;
		}
		if ((stari[i] == '0') && (t == 5))
		{
			t--;
		}
		i++;
	}

	return telefonski;
}

int main()
{
	char tel[20+1];
	scanf("%s", tel);

	char* stari = tel;

	printf("%s", telefonski(stari));
}
