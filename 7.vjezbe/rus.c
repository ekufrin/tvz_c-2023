//Rus ste i radite u Roscosmos-u (Федеральное космическое агентство России Federal'noye kosmicheskoye agentstvo Rossii). Vaš glavni zadatak je da generirate signale i
//šaljete ih amerikancima kako bi oni mislili da zapravo hvataju vanzemaljske signale i kako bi vi bili u prednosti navodeći ih na krivi put. Uočili ste da amerikanci puno
//pažnje poklanjaju signalima koji predstavljaju niz znakova, za koji vrijede sljedeća pravila:
//Niz u sebi sadrži 2 znaka: # ili !(može biti 2 '#' ili 2 '!' ili '#' i '!'), pomoću kojih je jedan niz rastavljen na 3 manja niza.
//Unutar svakog od manjih nizova je skrivena poruka na način da se ista poruka pojavljuje u sva 3 niza, i ima svojstvo da je najduži podniz u sva 3 niza.
//Odlučili ste napisati program koji će „zamaskirati“ neku poruku gore opisanim algoritmom.Dodatno program zahtjeva unos 6 brojeva koji određuju način skrivanja poruke, po
//2 broja za skrivanje unutar svakog niza.Prvi broj označava koliko slučajnih znakova je potrebno izgenerirati u prvom nizu lijevo od poruke, drugi broj označava koliko
//slučajnih znakova je potrebno izgenerirati u prvom nizu desno od poruke.Treći broj i četvrti broj govore to isto za drugi niz, a peti i šesti broj za treći niz.
//Za generiranje svakog od 3 podniza koristiti ISTU funkciju sa sljedećim protitipom(spojiti generirane nizove u main funkciji, alocirati memoriju dinamički) :
// char* generirajNiz(char* poruka, int brSlovaPrije, int brSlovaPoslije)
// Za ispravno generiranje slučajnih brojeva potrebno je pozvati srand(1000) na početku programa, i zatim pozivati funkciju rand() za generiranje slučajnog znaka.Generirani
// znakovi trebaju biti samo znamenke, velika te mala slova engleske abecede, prema sljedećim naputcima :
//ukoliko rand() vrati broj manji od 10 - tada je znamenka
//ukoliko vrati broj između 10 i 35 - veliko slovo
//broj između 36 i 61 - malo slovo
//ne odbacivati niti jedan rand() poziv, nego koristiti% operator kako bi dobili odgovarajuće vrijednosti
//što se tiče # i !, potrebno ih je staviti u poretku !, pa zatim # (nije rand() funkcija).

/*
ulaz:
kozmonaut
3 2 0 1 1 1
izlaz:
Ib3kozmonautQL!kozmonauth#ikozmonautY

ulaz:
krumpir
7 11 96 43 13 198
izlaz:
Ib3QLhikrumpirYOsPdgdwOMP!gMFnW3Mq5tGRpqHtUiYwjLxYBZfVfJOeofybrOIBLpoGRguxbQC11U5XnagxkzLflH6FUjzA697j9LoR1g7hsfsnaFibybokkrumpirCn0muKC5VaWX8qXNzYCMrHG2xVvbS1FYJk7OmC3dAtT#tOQX1eY0QKubrkrumpirIq6i0K6ZJ89F70eHEDaa80c3lelMuMd9U8BoGJ62Qupe8gNNsAb0rE2tYHKITdUexkjlbSufuwbzqJaXHqQboQOLjKfseQCwgTw4fScqy9Vh3CUlem6NY9eX76uqq7AOb6BLNf9OxIlKGLhLhxlUr8FvSPLzFqgEfHwBOkrPbfBSnTBPdJEbIpSnZTMklQyUtEMq9w

ulaz:
blitva
1002 1 0 0 0 0
izlaz:
Ib3QLhiYOsPdgdwOMPgMFnW3Mq5tGRpqHtUiYwjLxYBZfVfJOeofybrOIBLpoGRguxbQC11U5XnagxkzLflH6FUjzA697j9LoR1g7hsfsnaFibybokCn0muKC5VaWX8qXNzYCMrHG2xVvbS1FYJk7OmC3dAtTtOQX1eY0QKubrIq6i0K6ZJ89F70eHEDaa80c3lelMuMd9U8BoGJ62Qupe8gNNsAb0rE2tYHKITdUexkjlbSufuwbzqJaXHqQboQOLjKfseQCwgTw4fScqy9Vh3CUlem6NY9eX76uqq7AOb6BLNf9OxIlKGLhLhxlUr8FvSPLzFqgEfHwBOkrPbfBSnTBPdJEbIpSnZTMklQyUtEMq9wwqixlIESMvjFUT9tvDFzV39q43kZBcNnYx7KdaMT0BE4bTafkeJcU0Jq0dnKruYyfMeR1gqHHnOdJVOhrpcR8h2p6k23uAtQDSApOT2QjDZcU5Em8s10PLnQ8jWE4vuDyV13i129qCVnAmxrmBupwjNxFJqHdJMBcb73DKlqQL2HyGGaRVeMyjHSSVX4bWpMGeKnDbPgk61hDj3M6udVNnqAj6jS5pYxIN4BA2rysDn6LYyDhKLejv51rL2EL4eO7rmVASqlOlG0vZWyXRd5hiNdYBa7lDQHUyN5zHnl8glOBHtYIq2aYMIsuRzpPjzzzyNe0vTSSCiAxE4h2ORto7BHvowVvDhUgNhRFRpxUNXjl2oGGpt9YIh4TkbjfsBbU4rZrzA9qcgOFudpohM1UohkrZf53OqBhGregiUZze3vC8lDRqM4WhswBvpbj7Lw0Vjl9SaxF19503JtnxxKAx712logQx5BVdzsr1Uotdw2kdX4Pc8H4IdVNONmUMnTfMiVWs4lZgvR9sYcBdzsYOrCUSjjUQu3sfS21VNAIhbtVNfBTh6W23Y49NhOZl9tsSnMs2mbVXUuqIU3xJ349BAlQR0023VdprrHDatNywAXGvREjLxmXiSfrFblitvaW!blitva#blitva

ulaz:
moskva
0 0 0 0 0 0
izlaz:
moskva!moskva#moskva

*/

char* generirajNiz(char* poruka, int brSlovaPrije, int brSlovaPoslije);

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char rijec[100];
int d1, d2, d3, d4, d5, d6;
srand(1000);

scanf("%s", rijec);
scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);

char* rijec1 = (char*)calloc(strlen(rijec) + d1 + d2 + 1, sizeof(char));
char* rijec2 = (char*)calloc(strlen(rijec) + d3 + d4 + 1, sizeof(char));
char* rijec3 = (char*)calloc(strlen(rijec) + d5 + d6 + 1, sizeof(char));

rijec1 = generirajNiz(rijec, d1, d2);
rijec2 = generirajNiz(rijec, d3, d4);
rijec3 = generirajNiz(rijec, d5, d6);

char* poruka = (char*)calloc(strlen(rijec) * 3 + d1 + d2 + d3 + d4 + d5 + d6 + 2 + 1, sizeof(char));

int brojac = 0;
for (int i = 0; i < strlen(rijec1); i++)
{
    poruka[brojac] = rijec1[i];
    brojac++;
}
poruka[brojac] = '!';
brojac++;
for (int i = 0; i < strlen(rijec2); i++)
{
    poruka[brojac] = rijec2[i];
    brojac++;
}
poruka[brojac] = '#';
brojac++;
for (int i = 0; i < strlen(rijec3); i++)
{
    poruka[brojac] = rijec3[i];
    brojac++;
}
poruka[brojac] = '\0';
brojac++;

printf("%s", poruka);

return 0;
}

char* generirajNiz(char* poruka, int brSlovaPrije, int brSlovaPoslije)
{
char* novapor = (char*)calloc(strlen(poruka) + brSlovaPrije + brSlovaPoslije + 1, sizeof(char));
int br = 0;
char tmp;

for (int i = 0; i < brSlovaPrije; i++)
{
    tmp = rand() % 62;
    if (tmp < 10)
    {
        tmp = tmp + '0';
        novapor[br] = tmp;
        br++;
    }
    else if (tmp >= 10 && tmp <= 35)
    {
        tmp = tmp-10 + 'A';
        novapor[br] = tmp;
        br++;
    }
    else if (tmp >= 36 && tmp <= 61)
    {
        tmp = tmp-36 + 'a';
        novapor[br] = tmp;
        br++;
    }
}
for (int i = 0; i < strlen(poruka); i++)
{
    novapor[br] = poruka[i];
    br++;
}

for (int i = 0; i < brSlovaPoslije; i++)
{
    tmp = rand() % 62;
    if (tmp < 10)
    {
        tmp = tmp + '0';
        novapor[br] = tmp;
        br++;
    }
    else if (tmp >= 10 && tmp <= 35)
    {
        tmp = tmp - 10 + 'A';
        novapor[br] = tmp;
        br++;
    }
    else if (tmp >= 36 && tmp <= 61)
    {
        tmp = tmp - 36 + 'a';
        novapor[br] = tmp;
        br++;
    }
}
novapor[br] = '\0';

return novapor;
}
