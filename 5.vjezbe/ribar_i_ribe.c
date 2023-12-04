/*
OVAJ KOD SADRŽI GLAVNI ZADATAK + 3 PODZADATKA, KAKO BI TESTIRALI SVAKI DIO POSEBNO, POTREBNO JE SAMO ODKOMENTIRATI DIO KOJI ŽELITE.

GLAVNI ZADATAK: https://github.com/emanuelkufrin/tvz_c-2023/blob/432844864f93edc3dc16857aa654a11b5ed33e0e/tekstovi%20i%20test%20caseovi/%5B5%5DRibar%20i%20ribe.pdf

1.PODZADATAK RIBICE: https://github.com/emanuelkufrin/tvz_c-2023/blob/432844864f93edc3dc16857aa654a11b5ed33e0e/tekstovi%20i%20test%20caseovi/%5B5%5DRibar%20i%20ribe-pametne%20ribice.pdf
2.PODZADATAK KAPITALAC: https://github.com/emanuelkufrin/tvz_c-2023/blob/432844864f93edc3dc16857aa654a11b5ed33e0e/tekstovi%20i%20test%20caseovi/%5B5%5DRibar%20i%20ribe%20-%20kapitalac.pdf
3.PODZADATAK DODATNO: https://github.com/emanuelkufrin/tvz_c-2023/blob/432844864f93edc3dc16857aa654a11b5ed33e0e/tekstovi%20i%20test%20caseovi/%5B5%5DRibar%20i%20ribe%20-%20dodatno.pdf


*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000


int simuliraj(char niz[], int n, int x) {
    int suma = 0;
    int brojac = 0;
    for (int i = x; i < n; i++) {
        if (niz[(i)] != '.') {
            //if (niz[i] == 'T') {
            //    suma += 100;         //<-- Dio koda za dodatak zadatka: Kapitalac
            //    break;
            //}


           /* brojac += 1;
            if (brojac == 3) {
                suma = 0;            //<-- Dio koda za dodatak zadatka: Pametne ribice.
                brojac = 0;
                break;
            }*/
            suma += niz[i] - 'A' + 1;
            i += 2;
        }
    }
    return suma;
}

//void sort(int niz[], int n) {
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (niz[j] > niz[i]) {
//                int temp = niz[i];             //<-- Dio koda za dodatak zadatka: Dodatno
//                niz[i] = niz[j];
//                niz[j] = temp;
//            }
//        }
//    }
//}


int main() {

    char niz[MAX];
    int tezina[MAX];
    int br = 0;
    int maxSuma = 0;
    int maxX = 0;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c", &niz[i]);
    }

    for (int i = 0; i < n; i++) {
        int suma = simuliraj(niz, n, i);
        tezina[br++] = niz[i] - 'A' + 1;
        if (suma > maxSuma) {
            maxSuma = suma;
            maxX = i;
        }
    }

    printf("Optimalno je baciti udicu nakon %ds, sto donosi %dkg ribe.", maxX * 10, maxSuma);

    //int ulovljene[MAX] = { 0 }, brojac = 0;
    //for (int i = maxX; i < n; i++) {
    //    if (niz[i] != '.') {
    //        ulovljene[brojac] = niz[i] - 'A' + 1;
    //        brojac++;
    //        i += 2;
    //    }                                             //<-- Dio koda za dodatak zadatka: Dodatno
    //}

    //sort(ulovljene, n);
    //printf("\nSortirano polje: \n");
    //for (int i = 0; i < brojac; i++) {
    //    printf("%3d", ulovljene[i]);
    //}

    return 0;
}
