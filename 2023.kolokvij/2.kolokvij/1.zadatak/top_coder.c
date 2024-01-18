/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/95082aa206ad92b0c46eaa8f8dd77d95547ad3e2/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B2%5DTop%20coder.PDF
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void encode(char* s) {
    int brojac = 1;
    int kodiranoIndex = 0;

    for (int i = 1; i <= strlen(s); i++) {
        if (s[i] == s[i - 1]) {
            brojac++;
        }
        else {
            s[kodiranoIndex++] = brojac+'0';
            s[kodiranoIndex++] = s[i - 1];
            brojac = 1;
        }
    }
    s[kodiranoIndex] = '\0';
}

int main() {
    char str[100];

    scanf("%s", str);

    encode(str);

    printf("%s", str);

    return 0;
}
