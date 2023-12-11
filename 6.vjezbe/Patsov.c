/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/d6d4b320f937d361bcc58a953e7234a789aec401/tekstovi%20i%20test%20caseovi/%5B6%5DPatsov.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void getPosOffset(int dir, int x, int y, int* x_offset, int* y_offset) {
    *x_offset = 0;
    *y_offset = 0;

    switch (dir)
    {
    case 0:
        *y_offset = -1;
        break;
    case 1:
        *x_offset = 1;
        break;
    case 2:
        *y_offset = 1;
        break;
    case 3:
        *x_offset = -1;
        break;
    default:
        break;
    }
}

int distanceToFood(char mat[50][50], int n, int m, int x, int y, int dir) {
    int x_offset = 0, y_offset = 0, steps = 0;

    getPosOffset(dir, x, y, &x_offset, &y_offset);

    if (x + x_offset < 0 || x + x_offset >= m || y + y_offset < 0 || y + y_offset >= n) return 1000;

    do {
        x += x_offset;
        y += y_offset;
        steps++;

        if (mat[y][x] == 'h') return steps;

    } while (x >= 0 && x < m && y >= 0 && y < n && mat[y][x] != 'x' && mat[y][x] != '-' && mat[y][x] != '|' && mat[y][x] != '+');

    return 100;
}

int move(char mat[50][50], int n, int m, int* x, int* y, int* dir) {

    // dir: 0 - gori, 1 - desno, 2 - doli, 3 - livo
    int x_offset = 0, y_offset = 0;
    int canMoveFwd = 1;

    getPosOffset(*dir, *x, *y, &x_offset, &y_offset);

    // Provjeri dali iduci pomak ide van granica mape
    if (*x + x_offset < 0 || *x + x_offset > m - 1 || *y + y_offset < 0 || *y + y_offset > n - 1) canMoveFwd = 0;

    // Provjeri dali iduci pomak ide u zid
    if (mat[*y + y_offset][*x + x_offset] == 'x') canMoveFwd = 0;

    // Provjeri dali iduci pomak ide u vec prijedeno polje
    if (mat[*y + y_offset][*x + x_offset] == '-' || mat[*y + y_offset][*x + x_offset] == '|' || mat[*y + y_offset][*x + x_offset] == '+') {
        mat[*y][*x] = '*';
        return 0;
    }

    if (canMoveFwd) {
        mat[*y][*x] = *dir % 2 == 0 ? '|' : '-';

        *x = *x + x_offset;
        *y = *y + y_offset;

        return 1;
    }

    int left_dir = *dir == 0 ? 3 : *dir - 1;
    int right_dir = *dir == 3 ? 0 : *dir + 1;

    int left_distance = distanceToFood(mat, n, m, *x, *y, left_dir);
    int right_distance = distanceToFood(mat, n, m, *x, *y, right_dir);

    mat[*y][*x] = '+';

    if (left_distance < right_distance) {
        getPosOffset(left_dir, *x, *y, &x_offset, &y_offset);
        *dir = left_dir;
    }
    else {
        getPosOffset(right_dir, *x, *y, &x_offset, &y_offset);
        *dir = right_dir;
    }

    // Provjeri dali iduci pomak ide u vec prijedeno polje
    if (mat[*y + y_offset][*x + x_offset] == '-' || mat[*y + y_offset][*x + x_offset] == '|' || mat[*y + y_offset][*x + x_offset] == '+') {
        mat[*y][*x] = '*';
        return 0;
    }

    *x = *x + x_offset;
    *y = *y + y_offset;

    return 1;
}

int main()
{
    int m, n, x = 0, y = 0, dir = 1, canMove = 1;
    int i, j;

    char mat[50][50];

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf(" %c", &mat[i][j]);
        }
    }

    while (move(mat, n, m, &x, &y, &dir));

    printf("\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%c", mat[i][j]);
        }

        printf("\n");
    }

    return 0;
}
