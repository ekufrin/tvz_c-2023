/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/8d3c262600771b3ece03aa85410383466c1fbc17/tekstovi%20i%20test%20caseovi/%5B7%5DTolerantni%20palindrom.pdf
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tolPalindrom(char* s, int t) {
	int br = 0;
	for (int i = 0; i < strlen(s)-1; i++) {
		if (s[i] != s[strlen(s)-i-1]) {
			br++;
		}
	}

	if (br > t) {
		return 1;
	}
	else {
		return 0;
	}
}


int main()
{
	char string[100+1];
	int t = 0;
	scanf("%[^ ] %d", &string, &t);
	if (tolPalindrom(string, t) == 0) {
		printf("%s je tolerantni palindrom.", string);
	}
	else {
		printf("%s nije tolerantni palindrom.", string);
	}
	return 0;
}
