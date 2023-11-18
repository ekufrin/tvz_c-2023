#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int main()
{
    char field[3][21];

    int scores[3][2];

    int i, j, best_score = 0, best_time = 0, best_row = 1;

    for (i = 0; i < 3; i++) {
        scanf("%20s", field[i]);
    }

    for (i = 0; i < 3; i++) {
        scores[i][0] = 0;
        scores[i][1] = 0;

        for (j = 0; j < 20; j++) {

            // scores[i][0] -> vrijeme
            // scores[i][1] -> broj ubranih kukuruza
            switch (field[i][j]) {
                case 'I':
                    scores[i][0] += 5;
                    scores[i][1]++;
                    break;
                case '.':
                    scores[i][0]++;
                    break;
                case ',':
                    scores[i][0] += 2;
                    break;
                default:
                    break;
            }
        }

        // Dobij maksimalni broj kukuruza koji se moze ubrati
        if (scores[i][1] > best_score) {
            best_score = scores[i][1];
            best_time = scores[i][0];
            best_row = i + 1;
        }
    }

    for (i = 0; i < 3; i++) {
        if (scores[i][1] >= (best_score - 3) && scores[i][0] <= best_time) {

            // Ako je broj ubranih kukuruza i vrijeme isto ko u prvom redu, ne mijenjaj red
            if (scores[i][1] == best_score && scores[i][0] == best_time && best_row == 1) continue;

            best_time = scores[i][0];
            best_row = i + 1;
        }
    }

    printf("Pozicioniraj se u %d. red!", best_row);

    return 0;
}
