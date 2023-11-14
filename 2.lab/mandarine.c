/*
Sezona je branja mandarina i zelite pomoæi oko stanja u skladistu.
Prvo je potrebno unijeti broj dana koliko je trajala jedna berba(N), dok se ne upise broj izmeðu 1 i 20 (ukljucujuci).
Svaki dan tokom berbe se dio mandarina i pojede i podijeli prijateljima pa nikad ne zavrsi na skladistu.No, da bi vlasnik vocnjaka imao pravilnu statistiku,
zeli imati podatke i o kolicini ubranih i podijeljenih / pojedenih mandarina(u kg).Ti brojevi se unose za svaki dan berbe, po dva broja za svaki dan.
Program mora ispisivati koliko je ukupno ubrano mandarina kroz sve dane te koji dan je razlika izmeðu ubranih i podijeljenih mandarina bila najveca.
Napomena: za rjesavanje zadatka ne smiju se koristiti polja

TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/00e6ff5e9b203cb4369ef9c874a7e5d59f5b43a0/tekstovi%20i%20test%20caseovi/%5B2%5D%20mandarine_test-case.jpeg

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	int N = 0, ubrano = 0, podijeljeno = 0, kojiDan = 0, ukupnoUbrano = 0, najvecaRazlika = 0, brojacPogresnihUnosa = -1;

	
	do {
		scanf("%d", &N);
		brojacPogresnihUnosa++;
	} while (N < 1 || N>20);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &ubrano, &podijeljeno);
		ukupnoUbrano += ubrano;
		if (ubrano - podijeljeno > najvecaRazlika) {
			najvecaRazlika = ubrano - podijeljeno;
			kojiDan = i+1;
		}
	}

	for (int i = 0; i < brojacPogresnihUnosa; i++) {
		printf("Neispravan unos!\n");
	}

	printf("Ukupno ubrano: %d kg.\n", ukupnoUbrano);
	printf("Najveca razlika je bila %d.dan.\n", kojiDan);

	return 0;
}
