/*
Potrebno je učitati sva broja, N i M, te matricu NxM, gdje je 1 <= N, M <= 10. Svaki element matrice je dvoznamenkasti
broj.
Susjed nekog broja u matrici je broj koji se nalazi koso od njega - gore-lijevo, dolje-lijevo, gore-desno ili dolje-desno.
Potrebno je ispisati sve brojeve matrice koji imaju zajedničku znamenku s barem jednim susjedom.
Napomena: kod provjere navedenog svojstva, broj ispisati ako zadovoljava gornji uvjet, inače ispisati "**" na njegovo
mjesto.

Test case
Prvi broj u matrici je 11. Njegov jedini susjed je 26 i pošto nema niti jednu zajedničku znamenku, on ne zadovoljava traženog svojstvo. Pogledajmo broj 26 - njegovi susjedi su 11, 33, 42 i 91. Sa susjedom "42" on dijeli znamenku 2, te on zadovoljava traženo svojstvo

Primjer ulaza:
3 3
11 22 33
44 26 66
42 73 91
Primjer izlaza:

** 26 **
42 ** **

Test case
Nema susjeda - nema zajedničkih znamenki.

Primjer ulaza:
1 1
17
Primjer izlaza:
**

Test case
Primjer ulaza:
4 10
91 26 34 25 59 39 66 47 73 13
85 49 51 35 54 84 77 30 71 22
82 63 23 97 94 11 64 89 36 17
74 29 72 76 41 42 18 95 81 27
Primjer izlaza:
91 ** 34 25 59 ** ** 47 73 13
** 49 51 35 54 84 77 30 71 **
82 ** 23 97 94 11 64 89 36 17
** 29 72 ** 41 42 18 ** 81 **
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int n, m, temp_susjed;
    int i, j;

    int mat[10][10];
    char final_mat[10][10] = { {0} };

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {

            if (j != 0) {
                if (i != 0) {
                    temp_susjed = mat[i - 1][j - 1];

                    while (temp_susjed > 0) {
                        if (temp_susjed % 10 == mat[i][j] / 10 || temp_susjed % 10 == mat[i][j] % 10) {
                            final_mat[i][j] = 1;
                        }

                        temp_susjed /= 10;
                    }
                }

                if (i != n - 1) {
                    temp_susjed = mat[i + 1][j - 1];

                    while (temp_susjed > 0) {
                        if (temp_susjed % 10 == mat[i][j] / 10 || temp_susjed % 10 == mat[i][j] % 10) {
                            final_mat[i][j] = 1;

                        }

                        temp_susjed /= 10;
                    }
                }
                
            }

            if (j != m - 1) {
                if (i != 0) {
                    temp_susjed = mat[i - 1][j + 1];

                    while (temp_susjed > 0) {
                        if (temp_susjed % 10 == mat[i][j] / 10 || temp_susjed % 10 == mat[i][j] % 10) {
                            final_mat[i][j] = 1;

                        }

                        temp_susjed /= 10;
                    }
                }

                if (i != n - 1) {
                    temp_susjed = mat[i + 1][j + 1];

                    while (temp_susjed > 0) {
                        if (temp_susjed % 10 == mat[i][j] / 10 || temp_susjed % 10 == mat[i][j] % 10) {
                            final_mat[i][j] = 1;
                        }

                        temp_susjed /= 10;
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (final_mat[i][j]) {
                printf("%d ", mat[i][j]);
            }
            else {
                printf("** ");
            }
        }

        printf("\n");
    }

    return 0;
}
