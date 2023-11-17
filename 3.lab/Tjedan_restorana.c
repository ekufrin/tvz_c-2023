/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/bf0c8b2b87986d4b73fc66393a0fe85ac6c9d4cd/tekstovi%20i%20test%20caseovi/%5B3%5D%20Tjedan%20restorana.jpeg
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int N = 0;
    int counterPogresaka = -1;
    float A[50] = { 0 };
    float B[50] = { 0 };
    float srHrana = 0, srLokacija = 0;

    do {
        scanf("%d", &N);
        counterPogresaka++;
    } while (N < 3 || N>=10);

    for (int i = 0; i < N; i++) {
        scanf("%f %f", &A[i], &B[i]);
        srHrana += A[i];
        srLokacija += B[i];
    }
    srHrana /= N;
    srLokacija /= N;

    for (int i = 0; i < counterPogresaka; i++) {
        printf("Broj N nije u zadanom intervalu.\n");
    }
    if (counterPogresaka == N) {
        printf("Niti jedan restoran ne zadovoljava kriterije.");
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (A[i] > srHrana && B[i] > srLokacija) {
            printf("Restoran br. %d: Hrana +%.2f, lokacija +%.2f.\n", i + 1, A[i] - srHrana, B[i] - srLokacija);
        }
    }

    

    return 0;
}
