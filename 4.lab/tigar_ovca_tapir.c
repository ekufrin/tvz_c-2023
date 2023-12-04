/*
FALI TEKST ZADATKA I TEST CASEOVI!
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX 20

int main() {
int R, S, St, Ov, Ta;
char polje[20][20], poljeOv[20], poljeSt[20], poljeTa[20];
int vrijemeS = 0, vrijemeO = 0, vrijemeT = 0;
char unos[3][2];

scanf("%d %d", &R, &S);

for (int i = 0; i < R; i++) {
	for (int j = 0; j < S; j++) {
		scanf(" %c", &polje[i][j]);
	}
}
scanf("%d %d %d", &St, &Ov, &Ta);

for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 2; j++) {
		scanf(" %c", &unos[i][j]);
	}
}
// dobivanje pozicija
for (int i = 0; i < R; i++) {
	if (unos[i][0] == 'S') {
		St = unos[i][1] - '0';
	}
	if (unos[i][0] == 'O') {
		Ov = unos[i][1] - '0';
	}
	if (unos[i][0] == 'T') {
		Ta = unos[i][1] - '0';
	}
}

//unos gore

for (int i = 0; i < S; i++) {
	if (polje[St - 1][S - i - 1] == 'T') {
		vrijemeS += 15;
	}
	if (polje[St - 1][S - i - 1] == 'S') {
		vrijemeS += 35;
	}
	if (polje[St - 1][S - i - 1] == 'L') {
		vrijemeS += 75;
	}
}
for (int i = 0; i < S; i++) {
	if (polje[Ov - 1][S - i - 1] == 'T') {
		vrijemeO += 40;
	}
	if (polje[Ov - 1][S - i - 1] == 'S') {
		vrijemeO += 80;
	}
	if (polje[Ov - 1][S - i - 1] == 'L') {
		vrijemeO += 10;
	}
}
for (int i = 0; i < S; i++) {
	if (polje[Ta - 1][S - i - 1] == 'T') {
		vrijemeT += 110;
	}
	if (polje[Ta - 1][S - i - 1] == 'S') {
		vrijemeT += 5;
	}
	if (polje[Ta - 1][S - i - 1] == 'L') {
		vrijemeT += 30;
	}
}

if (vrijemeS < vrijemeO && vrijemeS < vrijemeT) {
	printf("Pobjednik je sibirski tigar - %ds do cilja.", vrijemeS);
}
if (vrijemeO < vrijemeS && vrijemeO < vrijemeT) {
	printf("Pobjednik je ovca - %ds do cilja.", vrijemeO);
}
if (vrijemeT < vrijemeO && vrijemeT < vrijemeS) {
	printf("Pobjednik je tapir - %ds do cilja.", vrijemeT);
}
if (vrijemeS == vrijemeO && vrijemeS < vrijemeT) {
	printf("Nema pobjednika.");
}
if (vrijemeS == vrijemeT && vrijemeS < vrijemeO) {
	printf("Nema pobjednika.");
}
if (vrijemeT == vrijemeO && vrijemeT < vrijemeS) {
	printf("Nema pobjednika.");
}



return 0;
}
