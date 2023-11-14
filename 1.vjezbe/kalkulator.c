//  Isprogramirajte jednostavni kalkulator!
//
//  Vaš kalkulator treba podržavati funkcije :
//
//  Zbrajanje
//  Oduzimanje
//  Množenje
//  Dijeljenje
//  Kvadriranje
//
//
//  Kalkulator treba raditi samo s cijelim brojevima.
//
//  Pogledajte test caseove za primjere rada kalkulatora.

//Test case #1
//Primjer ulaza :
//3 + 65
//Primjer izlaza :
//68
//Test case #2
//Primjer ulaza :
//13 - 50
//Primjer izlaza :
//-37
//Test case #3
//Primjer ulaza :
//5 * 10
//Primjer izlaza :
//50
//Test case #4
//Primjer ulaza :
//10 / 2
//Primjer izlaza :
//5
//Test case #5
//Ukoliko se broj želi kvadrirati kao input se unosi broj i veliko slovo 'K'.
//Primjer ulaza :
//12K
//Primjer izlaza :
//144


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    int br1, br2;
    char operator;
	scanf("%d%c", &br1, &operator);
	if (operator != 'K') {
			scanf("%d", &br2);
	}

	switch (operator)
	{
	case '+':
		printf("%d", br1 + br2);
		break;
	case '-':
		printf("%d", br1 - br2);
		break;
	case '*':
		printf("%d", br1 * br2);
		break;
	case '/':
		printf("%d", br1 / br2);
		break;
	case 'K':
		printf("%.f", pow(br1,2));
		break;
	default:
		break;
	}
	return 0;
}

