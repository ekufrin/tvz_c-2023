/*
Potrebno je na početku učitati broj n, koji označava broj redaka i broj stupaca matrice (matrica je uvijek kvadratna -
jednaki broj redaka i stupaca). Broj n mora biti u intervalu [3, 21] i mora biti djeljiv s 3. Ako neko od tih pravila nije
ispoštovano, zahtjevati ponovni unos uz ispis poruke (pogledati test primjere).
Nakon što se učita matricu, potrebno je matricu podijeliti na 9 jednakih dijelova, i izračunati sumu svih brojeva u
pojedinom dijelu matrice, te na kraju ispisati novu matricu 3x3 koja sadrži sume svih pojedinih dijelova matrice. Primjerice,
ako je dana matrica:
1 1 2 2 3 3
1 1 2 2 3 3
4 4 5 5 6 6
4 4 5 5 6 6
7 7 8 8 9 9
7 7 8 8 9 9
Nova matrica bi bila:
4 8 12
16 20 24
28 32 36

#1 test case
Ulaz:
1 1 2 2 3 3
1 1 2 2 3 3
4 4 5 5 6 6
4 4 5 5 6 6
7 7 8 8 9 9
7 7 8 8 9 9
Izlaz:
4 8 12
16 20 24
28 32 36

#2 test case
Ulaz:
22
8
3
1 9000 3
4 78 8932
3267 382 2132
Izlaz:
Ponoviti unos!
Ponoviti unos!
1 9000 3
4 78 8932
3267 382 2132

#3 test case
Ulaz:
18
625 502 421 149 810 342 961 2 869 93 483 368 680 433 161 319 703 734
950 100 847 235 220 655 780 609 695 550 232 829 426 129 21 579 566 319
893 285 143 274 672 317 626 767 950 208 364 129 157 363 645 157 821 938
597 752 330 686 757 984 410 527 609 745 592 627 220 850 928 438 277 487
724 722 424 368 734 400 520 849 38 536 612 75 959 846 576 859 405 214
150 993 2 344 588 300 682 663 295 429 42 911 144 177 840 909 502 794
727 724 989 128 594 165 149 68 412 390 750 158 573 302 426 40 344 464
147 242 210 726 632 727 181 224 610 176 414 502 643 815 675 762 905 679
577 881 640 730 221 715 486 435 442 88 138 501 659 638 311 83 297 113
534 866 943 307 314 452 268 684 328 719 744 274 486 349 243 644 235 172
778 532 0 305 124 500 925 272 756 331 951 168 799 144 161 645 49 493
513 805 731 591 732 704 455 893 492 745 583 672 712 954 827 266 517 983
162 722 196 930 867 878 484 207 612 930 673 384 35 992 701 332 402 688
655 723 912 891 993 381 326 202 542 852 768 445 340 983 677 729 982 497
272 24 637 977 296 839 623 315 628 420 456 727 83 463 129 176 411 483
375 64 705 501 894 322 352 772 85 184 453 985 779 982 443 153 682 318
986 32 26 422 374 801 666 55 612 659 347 143 528 990 797 202 685 87
327 340 685 592 912 66 314 515 475 609 899 56 435 207 251 925 523 833

Izlaz:
18295 18677 18576
19506 16384 17408
19779 17775 18923
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX 100

int main() {
    
    int n;
    scanf("%d", &n);
    while (n < 3 || n > 21 || n % 3 != 0) {
        printf("Pogresni unos!\n");
        scanf("%d", &n);
    }

    int matrica[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }
    int x = n * n;
    x = x / 9;
    x = sqrt(x);

    int polje[3][3] = { 0 };

    int a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < x && j < x) {
                polje[0][0] = polje[0][0] + matrica[i][j];
            }
            else if (i < x && j < 2 * x) {
                polje[0][1]= polje[0][1] + matrica[i][j];
            }
            else if (i < x && j < 3 * x) {
                polje[0][2] = polje[0][2] + matrica[i][j];
            }

            else if (i < 2 * x && j < x) {
                polje[1][0] = polje[1][0] + matrica[i][j];
            }
            else if (i < 2 * x && j < 2 * x) {
                polje[1][1] = polje[1][1] + matrica[i][j];
            }
            else if (i < 2 * x && j < 3 * x) {
                polje[1][2] = polje[1][2] + matrica[i][j];
            }

            else if (i < 3 * x && j < x) {
                polje[2][0] = polje[2][0] + matrica[i][j];
            }
            else if (i < 3 * x && j < 2 * x) {
                polje[2][1] = polje[2][1] + matrica[i][j];
            }
            else if (i < 3 * x && j < 3 * x) {
                polje[2][2] = polje[2][2] + matrica[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d", polje[i][j]);
        }
        printf("\n");
    }

    return 0;
}
