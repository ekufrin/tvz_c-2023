/*
Napisi program u C koji sa tipkovnice ucitava dva peteroznamenkasta broja A i B takvi da B vece od A za najmanje 100.
Pocevsi od A do B (ukljuceno) pretraziti sve brojeve takve da su prva i druga znamenka relicite izmedu sebe i razlicite od nule, a da je broj polindrom (jednako se pise s lijeve i s densne strane). Primjer takvog broja 21012.
Ispisati prvi i zadnji takav broj, zatim ukupan broj takvih brojeva na takvom intervalu.
Ako je na zadanom intervalu samo jedan broj - ispisati samo njega, a ako nema takvih brojeva ispisati "Nema takvog broja"

Test case-ovi:
Ulaz
10000 11000
Izlaz
Nema takvog broja

Ulaz
11922 12022
Izlaz
12021

Ulaz
21001 34000
Izlaz
21012 32923 100
*/

#include <stdio.h>

int unesiBroj() {
    int broj, brojac;

    do {
        brojac = 0;
        scanf("%d", &broj);
        int temp = broj;
        
        while (temp > 0) {
            temp /= 10;
            brojac++;
        }
        
    } while (brojac < 5);
    
    return broj;
}

int main() {

    int a, b;
    
    do {
        a = unesiBroj();
        b = unesiBroj();
    } while ((a + 100) > b);
    
    int znamenka[5], polindrom[1000];
    int brojac2 = 0;
    for (int i = a; i <= b; i++) {
        int temp2 = i;
        for (int j = 0; j < 5; j++) {
            znamenka[j] = temp2 % 10;
            temp2 /= 10;
        }
        if (znamenka[4] != 0 && znamenka[3] != 0 &&
            znamenka[4] != znamenka[3]) {
            if (znamenka[4] == znamenka[0] && 
                znamenka[3] == znamenka[1]) {
                polindrom[brojac2] = i;
                brojac2++;
            }
        }
    }
    
    printf("\n");
    
    if (brojac2 > 1) {
        printf("%d %d %d", polindrom[0], polindrom[brojac2 - 1], brojac2);
    } else if (brojac2 == 1) {
        printf("%d", polindrom[0]);
    } else {
        printf("Nema takvog broja");
    }

    return 0;
}
