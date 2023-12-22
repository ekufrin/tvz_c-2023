/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/551772d7e5e7992c9f6c8155e4f3f300567681ea/tekstovi%20i%20test%20caseovi/%5B7%5DVis%CC%8Cestruki%20slogovi%202.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zamijena(char* ulaz, char* slog) {
	int brojac = 0;
	//petlja strncpy, usporedi slog i strncpy
	for (int i = 0; i < strlen(ulaz); i++) {
		char* provjera = (char*)calloc(strlen(slog) + 1, sizeof(char));
		strncpy(provjera, ulaz + i, strlen(slog));
		provjera[strlen(slog)] = '\0';
		if (strcmp(provjera, slog) == 0) {
			brojac++;
			i += strlen(slog) - 1;
		}
	}

	return brojac;
}
int main() {
	char ulaz[50], slog[10];
	scanf("%s", ulaz);
	scanf("%s", slog);

	int broj = zamijena(ulaz, slog);
	printf("Broj zamjena: %d", broj);

	return 0;
}
