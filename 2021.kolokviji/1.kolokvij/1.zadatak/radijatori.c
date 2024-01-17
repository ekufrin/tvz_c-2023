/*
Potrebno je ucitati broj N, koji oznacava broj radijatora u stanu. Nakon toga slijedi N decimalnih brojeva koji oznacavaju temperaturu pojedinog radijatora. Potrebno je ispisati temperaturnu razliku izmedu radijatora najblize bojleru i radijatora koji je najdalje.
Radijator najblize bojleru je onaj s najvecom temperaturom, a onaj koji je najdalje ima najmanju temperaturu.

Test case-ovi
Ulaz:
5
34.1 35.2 30.2 37.7 41.1
Izlaz:
Ralika je: 10.8 C

Ulaz:
1
31.1
Izlaz:
Ralika je: 0.0 C

Ulaz:
4
32.2 32.2 32.2 32.2
Izlaz:
Ralika je: 0.00
*/

#include <stdio.h>

int main() {
   
    int brojRadijatora;
    
    scanf("%d", &brojRadijatora);
    
    double temperatura[100];
    
    for (int i = 0; i < brojRadijatora; i++) {
        scanf("%lf", &temperatura[i]);
    }

    double najblizi = temperatura[0], najdalji = temperatura[0];
    
    for (int i = 0; i < brojRadijatora; i++) {
        if (temperatura[i] > najblizi) {
            najblizi = temperatura[i];
        } else if (temperatura[i] < najdalji) {
            najdalji = temperatura[i];
        }
    }
    
    printf("Razlika je: %.1lf C", najblizi - najdalji);
    
    return 0;
}
