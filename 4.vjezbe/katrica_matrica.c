/*
Tvoja kolegica Katarina pala je prvi kolokvij iz Matematike 1 jer ne razumije izvođenje osnovnih operacija s matricama. Pomozi joj tako što ćeš napraviti program koji zbraja, oduzima, transponira i množi dvije matrice.

Napomena: Prilikom ispisa koristite %4d. Maksimalna dimenzija matrica je 10x10, a minimalna 2x2.

TEST CASEOVI:

Test case #1
Dimenzija prve matrice je 2x2, druge također 2x2. Nakon toga unosi se matrica 1 te matrica 2.
Primjer ulaza:
2x2
2x2

2 4
1 3

4 3
2 1

Primjer izlaza:
Suma matrica:
 6 7
 3 4
Razlika matrica:
-2 1
-1 2
Transponirana prva matrica:
 2 1
 4 3
Transponirana druga matrica:
 4 2
 3 1
Umnozak matrica:
16 10
10 6
Test case #2
Primjer ulaza:
3x2
5x4
2x4

12 12
-7 0
2 1

1 2 3 4
-5 0 0 2
Primjer izlaza:
Matrice nisu ulancane!
Matrice nisu istih dimenzija, ne mogu se zbrojiti!
Matrice nisu istih dimenzija, ne mogu se oduzimati!
Transponirana prva matrica:
12 -7 2
12 0 1
Transponirana druga matrica:
 1 -5
 2 0
 3 0
 4 2
Umnozak matrica:
-48 24 36 72
-7 -14 -21 -28
-3 4 6 10
Test case #3
Primjer ulaza:
4x4
5x2
4x4

2 3 4 -1
0 9 4 3
-4 5 2 11
8 -3 23 10

-2 3 0 0
4 3 0 0
-3 4 -2 1
4 5 6 7
Primjer izlaza:
Matrice nisu ulancane!
Suma matrica:
 0 6 4 -1
 4 12 4 3
-7 9 0 12
12 2 29 17
Razlika matrica:
 4 0 4 -1
-4 6 4 3
-1 1 4 10
 4 -8 17 3
Transponirana prva matrica:
 2 0 -4 8
 3 9 5 -3
 4 4 2 23
-1 3 11 10
Transponirana druga matrica:
-2 4 -3 4
 3 3 4 5
 0 0 -2 6
 0 0 1 7
Umnozak matrica:
-8 26 -14 -3
36 58 10 25
66 66 62 79
-57 157 14 93
Test case #4
Primjer ulaza:
11x11
2x3
1x1
4x3
3x4

2 -4 0
-7 6 1

4 5 6 7
-3 0 0 0
1 1 -3 2
Primjer izlaza:
Unesena je nedozvoljena dimenzija prve matrice!
Unesena je nedozvoljena dimenzija druge matrice!
Matrice nisu ulancane!
Matrice nisu istih dimenzija, ne mogu se zbrojiti!
Matrice nisu istih dimenzija, ne mogu se oduzimati!
Transponirana prva matrica:
 2 -7
-4 6
 0 1
Transponirana druga matrica:
 4 -3 1
 5 0 1
 6 0 -3
 7 0 2
Umnozak matrica:
20 10 12 14
-45 -34 -45 -47
Test case #5
Primjer ulaza:
4x4
23x23
4x4

2 3 -3 2
0 0 1 3
-7 6 5 4
0 9 2 12

12 1 1 5
-3 6 11 1
0 2 -3 11
3 4 2 -5
Primjer izlaza:
Unesena je nedozvoljena dimenzija druge matrice!
Suma matrica:
14 4 -2 7
-3 6 12 4
-7 8 2 15
 3 13 4 7
Razlika matrica:
-10 2 -4 -3
 3 -6 -10 2
-7 4 8 -7
-3 5 0 17
Transponirana prva matrica:
 2 0 -7 0
 3 0 6 9
-3 1 5 2
 2 3 4 12
Transponirana druga matrica:
12 -3 0 3
 1 6 2 4
 1 11 -3 2
 5 1 11 -5
Umnozak matrica:
21 22 48 -30
 9 14 3 -4
-90 55 52 6
 9 106 117 -29

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define MAX 10

int main()
{
    int matrica1[MAX][MAX] = { 0 };
    int matrica2[MAX][MAX] = { 0 };

    int stupciM1, redoviM1;
    int stupciM2, redoviM2;

    do {
        scanf("%dx%d", &redoviM1, &stupciM1);
        if (stupciM1 > 10 || stupciM1 < 2 || redoviM1>10 || redoviM1 < 2) {
            printf("Unesena je nedozvoljena dimenzija prve matrice!\n");
        }
    } while (stupciM1 > 10 || stupciM1 < 2 || redoviM1>10 || redoviM1 < 2);

    do {
        scanf("%dx%d", &redoviM2, &stupciM2);
        if (stupciM2 > 10 || stupciM2 < 2 || redoviM2>10 || redoviM2 < 2) {
            printf("Unesena je nedozvoljena dimenzija druge matrice!\n");
        }
        else if (redoviM1 != stupciM2 && redoviM2 != stupciM1) {
            printf("Matrice nisu ulancane!\n");
        }
    } while (stupciM2 > 10 || stupciM2 < 2 || redoviM2>10 || redoviM2 < 2 || redoviM2 != stupciM1);

    for (int i = 0; i < redoviM1; i++) {
        for (int j = 0; j < stupciM1; j++) {
            scanf("%d", &matrica1[i][j]);
        }
    }
    for (int i = 0; i < redoviM2; i++) {
        for (int j = 0; j < stupciM2; j++) {
            scanf("%d", &matrica2[i][j]);
        }
    }

    int suma[MAX][MAX] = { 0 };

    if (stupciM1 != stupciM2 && redoviM1 != redoviM2) {
        printf("Matrice nisu istih dimenzija, ne mogu se zbrojiti!\n");
    }
    else {
        printf("Suma matrica:\n");
        for (int i = 0; i < redoviM1; i++) {
            for (int j = 0; j < stupciM1; j++) {
                suma[i][j] = matrica1[i][j] + matrica2[i][j];
                if (j == 0) {
                    printf("%d", suma[i][j]);
                }
                else {
                    printf(" %d", suma[i][j]);
                }

                
            }
            printf("\n");
        }
    }

    int razlika[MAX][MAX] = { 0 };

    if (stupciM1 != stupciM2 && redoviM1 != redoviM2) {
        printf("Matrice nisu istih dimenzija, ne mogu se oduzimati!\n");
    }
    else {
        printf("Razlika matrica:\n");
        for (int i = 0; i < redoviM1; i++) {
            for (int j = 0; j < stupciM1; j++) {
                razlika[i][j] = matrica1[i][j] - matrica2[i][j];
                if (j == 0) {
                    printf("%d", razlika[i][j]);
                }
                else {
                    printf(" %d", razlika[i][j]);
                }
            }
            printf("\n");
        }
    }

    int transM1[MAX][MAX] = {0};

    printf("Transponirana prva matrica:\n");

    for (int i = 0; i < stupciM1; i++) {
        for (int j = 0; j < redoviM1; j++) {
            transM1[i][j] = matrica1[j][i];
            if (j == 0) {
                printf("%d", transM1[i][j]);
            }
            else {
                printf(" %d", transM1[i][j]);
            }
        }
        printf("\n");
    }

    int transM2[MAX][MAX] = { 0 };

    printf("Transponirana druga matrica:\n");

    for (int i = 0; i < stupciM2; i++) {
        for (int j = 0; j < redoviM2; j++) {
            transM2[i][j] = matrica2[j][i];
            if (j == 0) {
                printf("%d", transM2[i][j]);
            }
            else {
                printf(" %d", transM2[i][j]);
            }
        }
        printf("\n");
    }

    int umnozak[MAX][MAX] = { 0 };
    int temp = 0;

    printf("Umnozak matrica:\n");

    for (int i = 0; i < redoviM1; i++) {
        for (int j = 0; j < stupciM2; j++) {
            temp = 0;
            for (int k = 0; k < redoviM2; k++) {
                temp = temp + matrica1[i][k] * matrica2[k][j];

            }
            umnozak[i][j] = temp;
            if (j == 0) {
                printf("%d", umnozak[i][j]);
            }
            else {
                printf(" %d", umnozak[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
