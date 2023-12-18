//Nevenka Bekavac(40) iz Splita već nekoliko godina zaredom prijavljuje se u emisiju „Ljubav je na selu“ kako bi pronašla ljubav svog života.Međutim, do sada ju još uvijek
//nije pronašla.Ona zna što želi i kako bi trebao izgledati savršeni odabranik njenog srca, ali takav se još nije pojavio ni u emisiji ni u njenom životu.Kako bi joj pomogli,
//voditeljica showa Marijana Batinić i posrednik za ljubav Gangster pomažu Nevenki da pronađe svog princa na bijelom konju te joj šalju SMS poruke(jer Nevenka ne koristi
//podatkovne usluge svog mobilnog operatera) u kojima se nalaze informacije o potencijalnim ženicima.Od dobivenog skupa SMS poruka Nevenka se svaki put mora odlučiti
//za kandidate za spoj i njihova imena i prezimena poslati porukom nazad Marijani i Gangsteru.
//Od svih kandidata Nevenka će se pristati naći s onim koji posjeduje neku od sljedećih karakteristika :
//Mlađi je od nje ili maksimalno 5 godina stariji
//Crn
//Visok
//Bogat
//U svaku SMS poruku stane maksimalno 160 znakova, te su poruke često jako sažete, a u njima se može nalaziti opis i više kandidata.Ime i prezime kandidata uvijek se nalazi
//napisano na početku svake SMS poruke.Ukoliko u jednoj poruci ima više kandidata isti su odvojeni znakom '#'.Nevenka nikada ne zna koliko će dobiti SMS poruka(svaka SMS
//poruka prima se kao zasebni string).Prije nego dobije SMS - ove s potencijalnim ženicima, Nevenka dobiva kontrolni SMS(također string!) u kojem piše broj poruka koje će dobiti.
//Napišite funkciju prototipa char* trazi(char* sms) koja će na temelju primljenih SMS poruka pronaći kandidate koji se sviđaju Nevenki te umjesto nje složiti SMS poruku(funkcija
//kreira znakovni niz s imenima i prezimenima kandidata iz SMS poruke) koja se šalje Marijani i Gangsteru.
/*
ulaz:
2
Goran Zigo(38).Lucani.Uzgaja ovce i vino.Zivi s majkom, ocem i bratom.Crn.
Matija Prebic(40).Bogat.
izlaz:
Goran Zigo
Matija Prebic

ulaz:
3
Stanko Rajcic (52). Nevest. Voli pjevati ojkalicu. Bio u braku. Ne želi vegetarijanku.
Alojz Kanceljak (31). Glogovac. Njegova obitelj prodaje mlijeko jednoj poznatoj maloj mljekari. Clan je DVD-a i igra nogomet. Sportas.
Drazen Bozic (41). Grude. Crn i visok. Strojarski tehnicar. Zivi s majkom. Uzgaja duhan, smilje i lozu. Navijac Hajduka.
izlaz:
Alojz Kanceljak
Drazen Bozic

ulaz:
3
Ranko Pavlovic Rumeni (39). Kokinci. Bavi se uzgojem svinja te radi i kao licilac. Dvoje djece. Na youtube kanalu postavlja skeceve.
Danko Bezmalinovic (57). Brac. Zidar.#Josip Juric (25). Sportas. Vinar. Zivi sa sestrom.#Ivica Stapic (52). Habjanovci. Autoelektricar.
Stipe Filipovic (40). Aleksinci. Ima brk. Uzgaja ovce. Ne podnosi nepravdu i laz.
izlaz:
Ranko Pavlovic Rumeni
Josip Juric
Stipe Filipovic
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trazi(char* sms);

int main()
{
int broj_poruka;
scanf("%d\n", &broj_poruka);

char** poruke = (char**)calloc(broj_poruka, sizeof(char*));

for (int i = 0; i < broj_poruka; i++)
{
    poruke[i] = (char*)calloc(500, sizeof(char));
    scanf("%[^\n]", poruke[i]);
    getchar();
    poruke[i][strlen(poruke[i]) - 1] = '\0';
}
char** nove_poruke = (char**)calloc(broj_poruka, sizeof(char*));
for (int i = 0; i < broj_poruka; i++)
{
    nove_poruke[i] = (char*)calloc(100, sizeof(char));
}

int j = 0;

for (int i = 0; i < broj_poruka; i++) 
{
    char* tmp = strtok(poruke[i], "#");

    while (tmp != NULL) 
    {
        char* nova_poruka = trazi(tmp);
        if (nova_poruka != NULL)
        {
            nove_poruke[j] = nova_poruka;
            j++;
        }
        tmp = strtok(NULL, "#");
    }
}

for (int i = 0; i < j; i++)
{
    printf("%s\n", nove_poruke[i]);
}

return 0;
}

char* trazi(char* sms)
{
int godina;
char ime[100];

sscanf(sms, "%[^(](%d)", ime, &godina);

if ((godina <= 45 && godina >= 1) || strstr(sms, "Crn") != NULL || strstr(sms, "Visok") != NULL || strstr(sms, "Bogat") != NULL) {
    char* rezultat = (char*)calloc((strlen(ime) + 1), sizeof(char));
    strcpy(rezultat, ime);
    return rezultat;
}

return NULL;
}
