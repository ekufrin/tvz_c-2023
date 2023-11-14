//A grupa imas za upisat slovo C i onda neki broj X
//Program mora ispisat slovo u engelskoj abecedi koje je X mjesta iza slova C
//Ako je upisano malo slovo onda mora ispis biti veliko slovo, i obrnuti slucaj


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {

	int X;
	char slovo;
	char rezultat;

	scanf("%c %d", &slovo, &X);
	rezultat = slovo + X;

	if (rezultat >= 'A' && rezultat <= 'Z') {
		printf("%c", tolower(rezultat));

		// ili rezultat+32; ---> pogledati u službeni šalabahter razliku izmeðu velikog A i malog a;
	}
	else if (rezultat >= 'a' && rezultat <= 'z') {
		printf("%c", toupper(rezultat));
		// ili rezultat-32;
	}

	return 0;
}