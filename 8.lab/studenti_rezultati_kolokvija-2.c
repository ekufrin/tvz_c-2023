/*
TEKST ZADATKA, TEST CASEOVI I POTREBNE DATOTEKE: https://github.com/emanuelkufrin/tvz_c-2023/blob/85e4904e82a12e225f2fb8dd9ca0bbb057a263f9/tekstovi%20i%20test%20caseovi/%5B8%5DStudenti%20-%20rezultati%20kolokvija%202.zip
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct studenti
{
    char ime[30 + 1];
    char prezime[30 + 1];
    int ocjena;
};

void pali_sortirano(struct studenti *stud, int velicina);
void odlicni(struct studenti* stud, int velicina);

void prolaznost(struct studenti* stud, int velicina);

int main()
{
    FILE* file = fopen("studenti.dat", "rb");
    FILE* file1 = fopen("rezultati.txt", "w");

    struct studenti stu[50];
    int x = 0, y = 0, n;

    fseek(file, 0, SEEK_END);
    int velicina = ftell(file) / sizeof(struct studenti);
    fseek(file, 0, SEEK_SET);

    fread(stu, sizeof(struct studenti), velicina, file);

    scanf("%d", &n);

    if (n == 1)
        pali_sortirano(stu, velicina);
    else if (n == 2)
        odlicni(stu, velicina);

    fclose(file);

    return 0;
}

void pali_sortirano(struct studenti* stud, int velicina) {
    FILE* file1 = fopen("rezultati.txt", "w");
    struct studenti stud1[10], temp;
    int j = 0;
    for (int i = 0; i < velicina; i++) {
        if (stud[i].ocjena == 1) {
            stud1[j] = stud[i];
            j++;
        }
    }

    for (int i = 0; i < j; i++) {
        for (int z = i + 1; z < j; z++) {
            if (strcmp(stud1[i].ime, stud1[z].ime) > 0) {
                temp = stud1[i];
                stud1[i] = stud1[z];
                stud1[z] = temp;
            }
        }
    }


    for (int i = 0; i < j; i++) {
        fprintf(file1, "%s %s\n", stud1[i].ime, stud1[i].prezime);
    }

    int x = 0, y = 0;
    for (int i = 0; i < velicina; i++) {
        if (stud[i].ocjena == 1) {
            y++;
        }
        else if (stud[i].ocjena > 1) {
            x++;
        }
    }

    fprintf(file1, "\nKolokvij je proslo %d studenata, a palo %d.", x, y);
    fclose(file1);
}

void odlicni(struct studenti* stud, int velicina) {
    FILE* file1 = fopen("rezultati.txt", "w");

    for (int i = 0; i < velicina; i++) {
        if (stud[i].ocjena == 5) {
            fprintf(file1, "%s %s\n", stud[i].prezime, stud[i].ime);
        }
    }
    int x = 0, y = 0;
    for (int i = 0; i < velicina; i++) {
        if (stud[i].ocjena == 1) {
            y++;
        }
        else if (stud[i].ocjena > 1) {
            x++;
        }
    }
    fprintf(file1, "\nKolokvij je proslo %d studenata, a palo %d.", x, y);
    fclose(file1);

}
