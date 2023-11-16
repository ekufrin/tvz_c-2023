/*
Prijatelj pohađa kolegij programiranje u C, i na zadatku na vježbi mu dolazi sljedeći zadatak:
Potrebno je učitati dva niza, A i B koji su jednake duljine (zadano unosom varijable N). Nakon toga, potrebno je usporediti
svaki element niza A sa elementom na istom indeksu niza B. Ako je element niza A manji od onog iz B, zapišite 0, u
suprotnom zapišite 1. Tako dobiveni binarni broj je potrebno pretvoriti u dekadski. Duljina nizova A i B neće biti veća od 50.
Pomognite prijatelju da uspješno riješi zadatak 
*/

//TEST CASE
/*Primjer ulaza:
3
3 9 9
8 0 -45
Primjer izlaza:
3
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
