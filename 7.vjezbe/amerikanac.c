//Amerikanac ste i radite u NASA - i(National Aeronautics and Space Administration) kao inženjer zadužen za hvatanje i dešifriranje poruka koje dolaze iz svemira.
//Uhvatili ste signal neobičnog oblika, i odlučili ga analizirati kako bi otkrili tajnu poruku.Signal se sastoji od niza znakova.Uočili ste da slični signali najčešće
//imaju u sebi znakove # i !(može biti 2 '#' ili 2 '!' ili '#' i '!') kojima pošiljaoc razdvaja jedan niz znakova na 3 manja niza znakova.Nakon toga, uočili se da se
//često bitna informacija u pravilu krije zapisana u sva 3 manja niza.Kako bi si uštedili vrijeme, odlučili ste napisati program koji na početku rastavlja inicijalni
//signal na 3 manja signala(razdvojena sa znakovima # ili !), te nakon toga traži nadulji zajednički podniz unutar 3 niza znakova.
//Za pronalazak najduljeg niza koristiti funkciju s prototipom(unutar funkcije alocirati memoriju za rezultat) :
// char* najduljiPodniz(char* niz1, char* niz2, char* niz3)
//Poruke se sastoje od malih i velikih slova eng.abecede, te znamenki i znakova # ili !.

/*
ulaz:
ttmars#komars!marsar
izlaz:
mars

ulaz:
isdbhfjdfklekrumpirisbgozuesbgbzu#rgekrumpirasz954ho8g!juidfg7808h5840870ghghkrumpirizg78jue56780jgeo8579h9krumpir
izlaz:
krumpir

ulaz:
sedamnaestogodisnjakinja78dfi8dhflg79hfd67gfo8hfnoz7hf7e8hfberuiheihut8ehieh78erhtsedamnaestogodisnjakinjinolkdnfpiudhu8gdfnklihg78dhngklihdf8hgčfsdhdfsgljihdsf8ghosedamnaestidhfug87zidhufg87dhidf78ghdf87ghd8fhgdfilsfh#odfjigiohsgihuouszrghtglsjdhbfguisrbudhsfbgdzusbgouszsedamnaestogodisnjakinja#sedamnaestogodisnjakinjsedamnaestsedamsedamnaestogodisnjakinjinosedamnaestogodisnjakinjinsedamnaestogodisnjakinja
izlaz:
sedamnaestogodisnjakinja

ulaz:
abcabcabcabcdefdefdefdefjkl#abcjklabcabcabcabcabcabcghighighighi#defdefdefghijklghighi
izlaz:
jkl

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* najduljiPodniz(char* niz1, char* niz2, char* niz3);

int main()
{
char** poruke = NULL;
poruke = (char**)calloc(3, sizeof(char*));
for (int i = 0; i < 3; i++)
{
poruke[i] = (char*)calloc(1000, sizeof(char));
}

scanf("%[^#]#%[^!#]%*[!#]%[^\n]", poruke[0], poruke[1], poruke[2]);

char* rez = najduljiPodniz(poruke[0], poruke[1], poruke[2]);

printf("%s\n", rez);

return 0;
}

char* najduljiPodniz(char* niz1, char* niz2, char* niz3)
{
int max = 0;
char* rez = NULL;

rez = (char*)calloc(100, sizeof(char));
rez[0] = '\0';

for (int i = 0; i < strlen(niz1); i++) {
	for (int j = 0; j < strlen(niz2); j++) {
		for (int k = 0; k < strlen(niz3); k++) {
			int l = 0;
			while (niz1[i + l] == niz2[j + l] && niz2[j + l] == niz3[k + l] && niz1[i + l] != '\0') {
				l++;
				if (l > max) {
					max = l;
					strncpy(rez, &niz1[i], l);
					rez[l] = '\0';
				}
			}
		}
	}
}

return rez;
}
