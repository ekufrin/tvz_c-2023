/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/1571681268b79315225a2150e491f4b7b5f1671d/tekstovi%20i%20test%20caseovi/%5B3%5D%20Niz%20compare.pdf
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
    long long int n;
    long long int nizA[50];
    long long int nizB[50];
    long long int nizC[50];
    long long int dek = 0;
    
    scanf("%lld", &n);

    for (long int i = 0; i < n; i++)
    {
        scanf("%lld", &nizA[i]);
    }
    for (long int i = 0; i < n; i++)
    {
        scanf("%lld", &nizB[i]);
    }

    for (long int i = 0; i < n; i++)
    {
        if (nizA[i] < nizB[i])
        {
            nizC[i] = 0;
        }
        else {
            nizC[i] = 1;
        }
    }

    for (long int i = 0; i < n; i++)
    {
        if (nizC[i] == 1)
        {
            dek +=  nizC[i] * pow(2, n - 1 - i);
        }
    }
    printf("%lld", dek);
  
}
