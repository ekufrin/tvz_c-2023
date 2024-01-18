/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/eed8701fe9482f04924781d070228821127f9573/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DASCII%20maker.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void pronadiASCII(char* recenica);

int main() {
	
	char recenica[100];

	scanf("%[^.]%*c", recenica);
	pronadiASCII(recenica);

	return 0;
}
void pronadiASCII(char* recenica) {
	int tempZbroj = 0;
	int maxZbroj = 0;
	char rijec[20];
	char* token = strtok(recenica," \n");
	
	while (token != NULL) {
		for (int i = 0; i < strlen(token); i++) {
			tempZbroj += (int)token[i];
		}
		if (tempZbroj > maxZbroj) {
			maxZbroj = tempZbroj;
			strcpy(rijec, token);
		}
		tempZbroj = 0;
		token = strtok(NULL, " \n");
	}

	printf("%s: %d", rijec, maxZbroj);
}
