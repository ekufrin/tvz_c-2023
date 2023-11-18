#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, i, j, k;
    int x, y, sjever, istok, jug, zapad;
    int min_col = 1000, min_row = 1000, max_col = 0, max_row = 0;

    int ocitanja[100][6];
    char podrum[1000][1000];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++)
            scanf("%d", &ocitanja[i][j]);
    }

    for (i = 0; i < n; i++) {
        x = ocitanja[i][0];
        y = ocitanja[i][1];
        sjever = ocitanja[i][2];
        istok = ocitanja[i][3];
        jug = ocitanja[i][4];
        zapad = ocitanja[i][5];

        for (j = y - sjever - 2; j < y + jug + 1; j++) {
            for (k = x - zapad - 2; k < x + istok + 1; k++) {
                if (j == y - sjever - 2 || j == y + jug || k == x - zapad - 2 || k == x + istok) {
                    podrum[j][k] = '#';
                }
                else {
                    podrum[j][k] = '.';
                }

                if (j < min_row) min_row = j;
                if (j > max_row) max_row = j;
                if (k < min_col) min_col = k;
                if (k > max_col) max_col = k;
            }
        }
    }

    for (i = min_row; i <= max_row; i++) {
        for (j = min_col; j <= max_col; j++) {
            printf("%c", podrum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
