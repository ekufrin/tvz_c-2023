/*
TEKST ZADATKA JE ISTI KAO TAJNE PORUKE 1

TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/ea2d9deeeaad9af43f07682b59c2ba93d8d957f1/tekstovi%20i%20test%20caseovi/%5B7%5DTajne%20poruke%202.jpg

1.TEST CASE:
*-_=]$%,:[#>({)@/'&;?}+.<!
=)=[:|}]_]'*&|?|9
{]|()%?|-)>:|(]|%>}
){=|:=](|[|&@*;

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* kodiranje(char* znakovi, char* poruka) {
	char* rezultat = (char*)calloc(strlen(poruka)+1, sizeof(char));
	for (int i = 0;i<strlen(poruka); i++) {
		if (poruka[i] == '|') {
			rezultat[i] = ' ';
		}
		else if (isdigit(poruka[i])) {
		rezultat[i] = poruka[i];
		}
		else if (isalpha(poruka[i]) == 0) {
			for (int j = 0; j <= 32; j++) {
				if (poruka[i] == znakovi[j]) {
					rezultat[i] = j+'a';
				}
			}
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
	} while (strstr(kodirana, "idem") == NULL && strstr(kodirana,"spat")==NULL);

	printf("Broj poruka: %d", brojac);

	return 0;
}
