//Ivan i njegovi prijatelji odlučili su napraviti novogodišnji afterparty i na taj način potrošiti ostatke cuge koju nisu popili za vrijeme dočeka.Napravili su
//WhatsApp grupu „Ima se može se“ u koju svatko mora poslati poruku o tome koja vrsta cuge mu je ostala i koliko komada.Poruke se šalju u formatu Broj - Artikl
//i u svakoj poruci može biti minimalno 1 i maksimalno tri artikla odvojenih zarezom : negazirani sok, gazirani sok i voda.Poruka završava unosom znaka za novi red.
//VAŽNO : Svaka poruka sprema se kao zasebni string!
//Pomognite Ivanu napraviti listu cuge koja se nije potrošila, a koju ekipa može iskoristiti za afterparty, tako što ćete obraditi poruke poslane u grupu
//„Ima se može se“.Broj poruka nije unaprijed poznat te se poruke obrađuju sve dok Ivan ne unese poruku sadržaja „OK“.
//Program se OBAVEZNO mora sastojati od tri funkcije :
//1. Funkcija prototipa char* ucitajPoruku();
//Poziva se iz funkcije main
//Služi za čitanje i pohranu jedne poruke na način da se za istu rezervira točno onoliko prostora koliko je potrebno(dinamički!) s time da treba voditi računa o tome
//da nije unaprijed poznato koliko će biti dugačka koja poruka
//Funkcija vraća string koji sadrži jednu pročitanu poruku i tako vraćeni string potrebno je pohraniti u polje stringova definirano u funkciji main
//2. Funkcija prototipa void prebroji(char** lista, int i);
//Poziva se iz funkcije main
//Prima dva argumenta : polje stringova(stringove poruka) i broj koliko poruka treba obraditi
//Funkcija prolazi kroz listu svih poruka, broji koliko ima kojeg artikla i na kraju ispisuje stanje artikala u formatu :
//Sok -> 5
//Voda -> 4
//Pivo -> 6

/*

ulaz:
1-sok
2-voda
3-pivo
OK
izlaz:
Sok -> 1
Voda -> 2
Pivo -> 3

ulaz:
3-sok,2-voda,3-pivo
OK
izlaz:
Sok -> 3
Voda -> 2
Pivo -> 3

ulaz:
122-pivo
OK
izlaz:
Sok -> 0
Voda -> 0
Pivo -> 122

ulaz:
12-voda
13-sok,4-pivo,12-voda
15-pivo
30-sok,16-pivo
3-pivo,14-sok,3-voda
OK
izlaz:
Sok -> 57
Voda -> 27
Pivo -> 38

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ucitajPoruku();
void prebroji(char** lista, int brojPoruka);

int main()
{
char** lista = NULL;
lista = (char**)calloc(10, sizeof(char*));
for (int i = 0; i < 10; i++)
{
lista[i] = (char*)calloc(50, sizeof(char));
}

int brojac = 0;
while (brojac < 10)
{
	char* por = ucitajPoruku();
	lista[brojac] = por;
	if (strcmp(lista[brojac], "OK") == 0)
		break;

	brojac++;
}

prebroji(lista, brojac);

return 0;
}

char* ucitajPoruku()
{
char* poruka;
poruka = (char*)calloc(50, sizeof(char));
scanf("%[^\n]", poruka);
getchar();
return poruka;
}

void prebroji(char** lista, int brojPoruka)
{
int sok = 0, voda = 0, pivo = 0;

for (int i = 0; i < brojPoruka; i++) {
	char* tmp = strtok(lista[i], ",");
	while (tmp != NULL) {
		char artikl[20];
		int kolicina;

		sscanf(tmp, "%d-%19[^,],", &kolicina, artikl);

		if (strcmp(artikl, "sok") == 0) {
			sok += kolicina;
		}
		else if (strcmp(artikl, "voda") == 0) {
			voda += kolicina;
		}
		else if (strcmp(artikl, "pivo") == 0) {
			pivo += kolicina;
		}
		tmp = strtok(NULL, ",");
	}
}

printf("Sok -> %d\n", sok);
printf("Voda -> %d\n", voda);
printf("Pivo -> %d\n", pivo);

return 0;
}
