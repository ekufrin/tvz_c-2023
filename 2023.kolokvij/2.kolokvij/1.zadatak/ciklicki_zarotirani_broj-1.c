/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/be56eafc645985f0c01f07cce19e0f41bf8b02d2/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B2%5DCiklicki%20zarotirani%20broj%201.jpg
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int provjera(int n, int k, int b);

int main()
{
    int n, k, b;

    scanf("%d %d %d", &n, &k, &b);

    int m = provjera(n, k, b);

    printf("%d\n", m);

    return 0;
}

int provjera(int n, int k, int b)
{
    int brojac = 0, m = 0;
    int broj[30];

    while (n > 0)
    {
        broj[brojac++] = n % b;
        n /= b;
    }

    for (int i = 0; i < brojac; i++)
    {
        printf("%d", broj[brojac-i-1]);
    }
    printf("\n");

    int novi[30];
    for (int i = 0; i < brojac; i++)
    {
        novi[(i + k) % brojac] = broj[brojac-i-1];
    }

    for (int i = 0; i < brojac; i++)
    {
        printf("%d", novi[i]);
    }
    printf("\n");

    for (int i = 0; i < brojac; i++)
    {
        m = m*b + novi[i];
    }

    return m;
}
