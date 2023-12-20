/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/bc63f9d0090015aae720604800c3c143a4af70a5/tekstovi%20i%20test%20caseovi/%5B7%5DTajne%20poruke%201.PDF
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* kodiranje(char* znakovi, char* poruka) {
	char* rezultat = (char*)calloc(strlen(poruka)+1,sizeof(char));
	for (int i = 0;i<strlen(poruka); i++) {
		if (isalpha(poruka[i])) {
			for (char j = 'a'; j <= 'z'; j++) {
				if (poruka[i] == j) {
					rezultat[i] = znakovi[j-'a'];
				}
			}
		}
		else if (isspace(poruka[i])) {
			rezultat[i] = '|';
		}
		else if (isdigit(poruka[i])) {
			rezultat[i] = poruka[i];
		}
	}

	return rezultat;
}


int main() {

	char znakovi[26 + 1];
	char poruka[80 + 1];
	int brojac = 0;
	char* kodirana;

	scanf("%[^\n]%*c", &znakovi);
	do {
		scanf("%[^\n]%*c", &poruka);
		kodirana = kodiranje(znakovi, poruka);
		printf("%s\n", kodirana);
		brojac++;
	} while (strstr(poruka, "idem spat") == NULL);

	printf("Broj poruka: %d", brojac);

	return 0;
}
