/*
Perica je programer kojem je zadaća održavati postojeće i raditi na novim sustavima za Sabor. Posao je dobio tek prošle godine, pa se nije još najbolje snašao.
Fakultet je završio davnih dana, a od tada nije napisao liniju koda, pa nije više u najboljoj formi. Zapravo, nije ni za vrijeme fakulteta bio u najboljoj formi,
budući da je nakon prve godine shvatio da programiranje baš i nije za njega. Ali kada je vidio oglas za posao - nije se mogao ne prijaviti.
“Odlično radno vrijeme, odlične pare i jeftina saborska menza”, često se hvalio svojim prijateljima dok su zajedno pili treću dnevnu kavu.
Neki rituali moraju postojati. Često bi nadodao i “a još nisam imao ni jedan projekt”. No, svemu što je lijepo brzo dođe kraj.
Perica je dobio važnu ulogu na novom projektu eSabornica, kojem je cilj modernizirati sabornicu i učiniti ju potpuno transparentnom.
Jedan od glavnih aspekata projekta je instalacija SmartSofa. SmartSofa je proizvod Norveškog startupa SmartIoT. U suštini, SmartSofa je pametna sjedalica
koja u sebi ima razne napredne funkcije - od senzora otkucaja srca, do motora za masažu. Jedna od glavnih značajki je i 'senzor sjedenja', tako da svaka stolica
šalje signal glavnom serveru sjedi li netko na toj poziciji ili ne (0 ili 1). Svaki zastupnik uvijek sjedi na istoj sjedalici. Budući da je nedavno izglasana odluka
da svaki saborski zastupnik mora biti na barem jednoj sjednici dnevno,

Peričin zadatak je isprogramirati program koji vodi statistiku dolaska na sjednice, te ispisuje zastupnike koje valja ukoriti za nedolazak, odnosno one kojih taj
dan nema ni na jednom zasjedanju.

Sabornica se sastoji od MxN sjedala, a dnevno se održava S sjednica. Glavni server podatke o stolicama nakon svake sjednice dostavlja u jednoj liniji, gdje se
podatak o svakoj stolici odvaja zarezom. Primjerice, za punu sabornicu dimenzija 2x3, podatak bi izgledao ovako: 1, 1, 1, 1, 1, 1. U projekt su uloženo mnogo novaca,
a Pericu bi neispunjenje ovog zadatka moglo stajati posla iz snova. Svojim programerskim znanjem morate mu pomoći!

Umnožak M i N neće biti veći od 250. S neće biti veći od 20. Na kraju je potrebno ispisati pozicije zastupnika koje treba opomenuti za nedolazak (od 1, 1 do m, n)
i grafički prikaz sabornice, gdje '0' označava dolazak na jednu od sjednica, a '-' nedolazak.

TEST CASEOVI:
2 2
3
1, 0, 0, 0
1, 0, 0, 0
1, 0, 0, 0

IZLAZ:
0 -

Ukoriti (1, 2).
Ukoriti (2, 1).
Ukoriti (2, 2).

TEST CASEOVI:
5 3
10
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

IZLAZ:
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0

TEST CASEOVI:
5 5
1
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0

IZLAZ:
0 - - - -

0 - - - -
Ukoriti (1, 2).
Ukoriti (1, 3).
Ukoriti (1, 4).
Ukoriti (1, 5).
Ukoriti (2, 1).
Ukoriti (2, 2).
Ukoriti (2, 3).
Ukoriti (2, 4).
Ukoriti (2, 5).
Ukoriti (3, 1).
Ukoriti (3, 2).
Ukoriti (3, 3).
Ukoriti (3, 4).
Ukoriti (3, 5).
Ukoriti (4, 1).
Ukoriti (4, 2).
Ukoriti (4, 3).
Ukoriti (4, 4).
Ukoriti (4, 5).
Ukoriti (5, 2).
Ukoriti (5, 3).
Ukoriti (5, 4).
Ukoriti (5, 5).

TEST CASEOVI:
2 2
5
1, 1, 0, 0
1, 1, 1, 0
0, 0, 0, 0
0, 0, 0, 0
1, 1, 1, 1

IZLAZ:
0 0
0 0

TEST CASEOVI:
2 4
8
1, 0, 0, 0, 0, 0, 0, 0
0, 1, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0
1, 1, 1, 0, 0, 0, 0, 0
0, 0, 0, 0, 1, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 1
0, 0, 0, 0, 0, 0, 1, 1

IZLAZ:
0 0 0 -
0 - 0 0
Ukoriti (1, 4).
Ukoriti (2, 2).

TEST CASEOVI:
8 7
3
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0
1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1
1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1

IZLAZ:
0 - 0 - 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 - - - -

0 0
0 0 0 - - - -
0 0 0 0
0 0 0 0 0 0 0
Ukoriti (1, 2).
Ukoriti (1, 4).
Ukoriti (4, 4).
Ukoriti (4, 5).
Ukoriti (4, 6).
Ukoriti (4, 7).
Ukoriti (5, 1).
Ukoriti (5, 2).
Ukoriti (5, 3).
Ukoriti (5, 4).
Ukoriti (5, 5).
Ukoriti (6, 4).
Ukoriti (6, 5).
Ukoriti (6, 6).
Ukoriti (6, 7).
Ukoriti (7, 1).
Ukoriti (7, 2).
Ukoriti (7, 3).
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
int matrica[250][250], n, r, s;
char bd[250][250];
scanf("%d %d", &r, &s);
scanf("%d", &n);
for (int i = 0; i < r; i++)
{
for (int j = 0; j < s; j++)
{
bd[i][j] = '-';
}
}
while (n > 0) {
for (int i = 0; i < r; i++)
{
for (int j = 0; j < s; j++)
{
scanf("%d,",&matrica[i][j]);
}
}
for (int i = 0; i < r; i++)
{
for (int j = 0; j < s; j++)
{
if (matrica[i][j] == 1)
{
bd[i][j] = '0';
}
}
}
n--;
}
for (int i = 0; i < r; i++)
{
for (int j = 0; j < s; j++)
{
printf("%c ", bd[i][j]);
}
printf("\n");
}
for (int i = 0; i < r; i++)
{
for (int j = 0; j < s; j++)
{
if (bd[i][j] != '0')
{
printf("Ukoriti (%d, %d). \n", i + 1, j + 1);
}
}
}
return 0;
}
