/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/accf6c944c590b45bc54ad1c82a8797e1b96bdc5/tekstovi%20i%20test%20caseovi/%5B5%5DBrojevna%20spojka%201.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int funkcija(long long int x, long long int y) {

    if (x == 0) {
        return y;  
    }
    
    long long int temp = y;
    long long int m = 1;

    while (temp > 0) {
        m *= 10;
        temp /= 10;
    }

    if (y == 0) {
        return x * 10;  
    }

    if (x < 0) {
        return x * m - y;
    }
    else {
        return x * m + y;
    }
}

int main() {
    long long int a, b, c, d;

    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    while (!(a >= -1000000 && a <= 1000000 && c >= -1000000 && c <= 1000000 && b >= 0 && b <= 1000000 && d >= 0 && d <= 1000000)) {
        printf("Neispravan unos!\n");
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    }

    long long int br1 = funkcija(a, b);
    long long int br2 = funkcija(c, d);

    if (-1000000000 <= br1 && br1 <= 1000000000 && -1000000000 <= br2 && br2 <= 1000000000) {
        printf("\n%lld+%lld=%lld", br1, br2, br1+br2);
        printf("\n%lld-%lld=%lld", br1, br2, br1-br2);
        printf("\n%lld*%lld=%lld", br1, br2, br1 * br2);
    }
}
