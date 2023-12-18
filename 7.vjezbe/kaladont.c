/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/59d5ab9b335f0a63a1d2b06a04430da595868959/tekstovi%20i%20test%20caseovi/%5B7%5DKaladont.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
void allCaps(char* string) {
for (int i = 0; i < strlen(string); i++) {
string[i] = toupper(string[i]);
}
}
char* skupSlova(char* string) {
char* skupslova = (char*)malloc(3sizeof(char));
strncpy(skupslova, string + strlen(string)-2, 2);
skupslova[2] = '\0';
skupslova[0] = toupper(skupslova[0]);
skupslova[1] = toupper(skupslova[1]);
return skupslova;
}
int main() {
char ime[MAX];
int br_igraca = 0;
char igraci[10][MAX];
while (br_igraca < 2 || strcmp(ime, "KRAJ") != 0) {
scanf("%s", ime);
if (strcmp(ime, "KRAJ") != 0) {
br_igraca++;
strcpy(igraci[br_igraca], ime);
}
else if ((strcmp(ime, "KRAJ") == 0) && br_igraca < 2){
printf("U igri moraju sudjelovati minimalno 2 igraca. Unesite jos igraca.\n");
}
}
printf("Igru igraju:\n");
for (int i = 1; i <= br_igraca; i++) {
printf("%d#%s\n", i, igraci[i]);
}
printf("\n");
char skup = skupSlova(igraci[br_igraca]);
printf("1. zadani skup slova je %s.\n", skup);
char unos[100];
int trenutni = br_igraca;
int counter = 2;
int pobjednik = 0;
do {
scanf(" %[^\n]", unos);
if (strstr(unos, "Ne znam") != NULL) {
trenutni--;
}
else {
skup = skupSlova(unos);
printf("%d. zadani skup slova je %s.\n", counter++, skup);
pobjednik = atoi(unos);
}
} while (trenutni != 1);
printf("\n");
allCaps(igraci[pobjednik]);
printf("Pobjednik je: %s", igraci[pobjednik]);
return 0;
}
