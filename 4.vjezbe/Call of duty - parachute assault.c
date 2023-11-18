#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int move(int** heights, int north_pos, int south_pos, int col) {

    // Startne i ciljne pozicije oba vojnika
    int north_start = heights[north_pos][col], south_start = heights[south_pos][col],
        north_end = heights[north_pos+1][col], south_end = heights[south_pos-1][col];

    /*
     * Ako je udaljenost vojnika jednaka ili manja od jedinice, izracunaj pobjednika i vrati
     * 1 - sjever pobijedio
     * 2 - jug pobijedio
     * 0 - nerijeseno
     */
    if ((south_pos - north_pos) <= 1) {
        if (north_start > south_start) return 1;
        else if (north_start < south_start) return 2;
        else return 0;
    }

    // Vremena potrebna da vojnici prijedu na iduce polje (default je 1 jer je toliko potrebno za polja iste visine)
    float time_north = 1, time_south = 1;

    if (north_start > north_end) {
        time_north = 0.5 * (north_start - north_end);
    }
    else if (north_start < north_end) {
        time_north = 1.5 * (north_end - north_start);
    }

    if (south_start > south_end) {
        time_south = 0.5 * (south_start - south_end);
    }
    else if (south_start < south_end) {
        time_south = 1.5 * (south_end - south_start);
    }

    // Vojniku kojemu treba krace cemo promjeniti poziciju, 
    // a drugom vojniku cemo promjeniti visinu za onoliko koliko stigne prije nego se sjeverni vojnik premjesti
    if (time_north < time_south) {
        north_pos++;

        if (south_start > south_end) {
            heights[south_pos][col] = south_start - floor(time_north / 0.5);
        }
        else {
            heights[south_pos][col] = south_start + floor(time_north / 1.5);
        }
    }
    else if (time_north > time_south) {
        south_pos--;

        if (north_start > north_end) {
            heights[north_pos][col] = north_start - floor(time_south / 0.5);
        }
        else {
            heights[north_pos][col] = north_start + floor(time_south / 1.5);
        }
    }
    else {
        north_pos++;
        south_pos--;
    }

    // Opet zovi funkciju sa promjenjenim vrijednostima sve dok neko ne pobijedi ili bude nerijeseno
    return move(heights, north_pos, south_pos, col);
}

int main()
{
    int rows, cols;
    int i, j;
    int north_pos, south_pos, winner;
    int scores[3] = { 0, 0, 0 };

    scanf("%d %d", &rows, &cols);

    // Alociraj memoriju za 2d niz
    int** heights = (int**)malloc(sizeof(int*) * rows);

    for (i = 0; i < rows; i++) {
        // Alociraj memoriju za niz
        heights[i] = (int*)malloc(sizeof(int) * cols);

        for (j = 0; j < cols; j++) 
            scanf("%d", &heights[i][j]);
    }
        
    // Prvo prodi sve stupce jer vojnici idu od sjevera prema jugu i obrnuto
    for (j = 0; j < cols; j++) {
        north_pos = 0; // Postavi poziciju vojnika sa sjevera na nulu (dolazi odozgo)
        south_pos = rows-1; // Postavi poziciju vojnika sa juga na broj redova - 1 (dolazi odozdo)

        winner = move(heights, north_pos, south_pos, j);

        switch (winner) {
        case 1:
            scores[0]++;
            break;
        case 2:
            scores[2]++;
            break;
        default:
            scores[1]++;
            break;
        }
    }

    if (scores[0] > scores[2]) {
        printf("S: %d-%d-%d", scores[0], scores[1], scores[2]);
    }
    else if (scores[0] < scores[2]) {
        printf("J: %d-%d-%d", scores[2], scores[1], scores[0]);
    }
    else {
        printf("Nerijeseno!\n");
        printf("S: %d-%d-%d\n", scores[0], scores[1], scores[2]);
        printf("J: %d-%d-%d", scores[2], scores[1], scores[0]);
    }

    return 0;
}
