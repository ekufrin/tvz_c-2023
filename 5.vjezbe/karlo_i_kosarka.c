/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/29787c78a508b8a98d438b1e60e528bdb6972db5/tekstovi%20i%20test%20caseovi/%5B5%5Dkarlo_i_kosarka.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prostiBrojevi(int a, int b) {
    int prostiBrojevi = 0;

    for (int i = a; i <= b; i++) {
        int brojac = 0;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                brojac++;
                if (brojac > 1) {
                    break;
                }
            }
        }
        if (brojac == 0) {
            prostiBrojevi++;
        }
    }
    return prostiBrojevi;
}

int djeljiviBrojevi(int a, int b) {
    int djeljiviBrojevi = 0;
    for (int i = a; i <= b; i++) {
        if (i % 7 == 0 || i % 9 == 0) {
            djeljiviBrojevi++;
        }
    }
    return djeljiviBrojevi;
}

int main() {
    int n;
    scanf("%d", &n);

    int SMSbrojevi[150] = { 0 };
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        SMSbrojevi[i] = prostiBrojevi(a, b) + djeljiviBrojevi(a, b);
    }

    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) {
            if (SMSbrojevi[j] < SMSbrojevi[i]) {
                int temp = SMSbrojevi[i];
                SMSbrojevi[i] = SMSbrojevi[j];
                SMSbrojevi[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", SMSbrojevi[i]);
        }
        else {
            printf(", %d", SMSbrojevi[i]);
        }
    }

    return 0;
}
