/*PRVI ZADATAK KOLOKVIJ
Zadatak: Upises 2 broja(X i N), ispisuje N djelitelja broja X koji su ujedno i kvadrat nekog broja
Uvjet: Brojevi moraju biti odvojeni zarezom, ako je samo jedan broj onda ne smije biti zarez.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    int n, x;
    int br = 0;
    scanf("%d %d", &n, &x);
    br = n-1;
    for (int i = 1; i <= x; i++) {

        if (x % i == 0 && ((int)sqrt(i) == sqrt(i))) {
            if (br != 0) {
                printf("%d, ", i);
            } 
            if (br == 0) {
                printf("%d ", i);
                break;
            }
            br--;
        }
    }
    return 0;
}
