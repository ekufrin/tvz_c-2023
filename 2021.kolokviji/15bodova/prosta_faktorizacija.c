/*
Za uneseni broj X ispisati njegove proste faktroe.
Ukoliko je broj X prost, ispisati "X je prost broj. Inace ispisati njegoce faktore u obliku X=f1f2f3..*fn
Prijedlog za rijesavanje: kada se pronade prvi prosti faktor, zapisati ga u poseban niz a orginalni broj podijeliti s tim faktorom i nastaviti proces do se ne dode do 1, te na kraju ispisati niz.

Test case-ovi:
Ulaz:
15
Izlaz:
15 = 3 * 5

Ulaz:
100
Izlaz:
100 = 2 * 2 * 5 * 5

Učaz:
17
Izlaz:
17 je prost broj"
*/

#include <stdio.h>

int main() {
    
    int broj;
    
    scanf("%d", &broj);
    
    int faktor[100];
    int temp = broj, j = 0;
    while (temp > 1) {
        for (int i = 2; i <= temp; i++) {
            if (temp % i == 0) {
                faktor[j] = i;
                j++;
                temp /= i;
                break;
            }
        }
    }
    
    if (j != 1) {
        printf("%d = ", broj);
        for (int i = 0; i < j; i++) {
            if (i == 0) {
                printf("%d", faktor[i]);
            } else {
                printf(" * %d", faktor[i]);
            }
        }
    } else {
        printf("%d je prosti broj", broj);
    }

    return 0;
}
