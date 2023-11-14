/*
Davor i Ivica su u Dubaiu i gledaju nebodere. Pošto je to novi grad, sve zgrade su posložene vrlo pravilno - te su se Davor i Ivica optimalno pozicionirali kako bi mogli izgrati jednu interesantnu igru koju im je predložio Vlado. Naime, stanu se na način da se između njih pravocrtno nalazi N nebodera, a svaki ima visinu V. Skicirajmo to na ovaj način:
D1 511714661
Davor stoji s lijeve strane i ispred njega su redom neboderi visine 1, 5, 11, 7,14, 6 i 6 katova. Ivica naprotiv stoji s druge strane, i neboderi iz njegove perspektive su visoki 6, 6, 14, 7, 11, 5, 1. Vlado, koji se nalazi negdje dalje od njih treba pogoditi koliko nebodera vidi Davor a koliko Ivica. Višlji neboder će zakloniti one iza sebe, tako da Davor vidi 4 nebodera: one visine 1, 5, 11 i 14. Ivica vidi samo 2 nebodera - prvi visine 6, i onaj idući viši od 14 katova.
Vrijede ograničenja:
1 <= N <= 100
1 <= V <= 100

Test case #1
Primjer iz teksta zadatka - Davor je s lijeve strane, Ivica s desne. Postoji 7 nebodera - to je prvi broj koji se unosi.
Primjer ulaza:
7
1 5 11 7 14 6 6
Primjer izlaza:
Davor 4 Ivica 2
Test case #2
Potrebno je ispisati ime onoga koji vidi više nebodera prvo. Slična pozicija kao maloprije, ali Ivica ovaj puta vidi 7 nebodera.
Primjer ulaza:
12
1 5 11 7 14 6 6 5 4 3 2 1
Primjer izlaza:
Ivica 7 Davor 4
Test case #3
Ulaz:
98
71 46 49 24 23 29 40 67 33 59 54 27 41 33 53 30 5 7 45 49 1 3 59 12 1 31 20 4 6 37 19 51 17 8 52 6 66 41 42 18 31 3 62 38 18 36 56 2 3 3 51 29 3 17 26 53 55 7 5 63 46 35 23 4 37 25 48 4 56 23 40 10 30 62 5 60 55 19 50 38 26 28 25 2 42 21 32 13 57 15 65 39 3 39 45 10 33 71
Primjer izlaza:
Davor 1
Ivica 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int main()
{
    int n, davor[MAX] = {}, ivica[MAX] = {};

    // Unos broja zgrada
    scanf("%d", &n);

    // Unos visine zgrada iz Davorove i Ivicine perspektive. 
    // Ivica je s druge strane niza pa visinu prve zgrade iz Davorove perspektive unosimo kao zadnju zgradu iz Ivicine perspektive
    int k = n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &davor[i]);
        ivica[k - 1] = davor[i];
        k--;
    }

    int najvisaDavor = 0, najvisaIvica = 0, vidljiveIvica = n, vidljiveDavor = n;

    // Provjera vidljivosti zgrada iz oba smjera
    for (int i = 0; i < n; i++) {
        if (davor[i] > najvisaDavor) { // Ako je zgrada 'i' najvisa zgrada do sad stavljamo ju kao najvisaDavor
            najvisaDavor = davor[i];
        }
        else {
            vidljiveDavor--;           // Sve zgrade manje od najvisaDavor se nece vidjeti
        }
        if (ivica[i] > najvisaIvica) { 
            najvisaIvica = ivica[i];
        }
        else {
            vidljiveIvica--;
        }
    }

    // Ispis rezultata
    if (vidljiveDavor >= vidljiveIvica) {
        printf("Davor %d\n", vidljiveDavor);
        printf("Ivica %d\n", vidljiveIvica);
    }
    else {
        printf("Ivica %d\n", vidljiveIvica);
        printf("Davor %d\n", vidljiveDavor);
    }

    return 0;
}
