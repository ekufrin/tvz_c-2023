/*
TEKST ZADATKA I TEST CASEOVI NEDOSTAJU :/
DATOTEKE POTREBNE ZA ZADATAK: https://github.com/emanuelkufrin/tvz_c-2023/blob/cf1eb866557fb9bad667daebfa169f7d57df5da5/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DSateliti.zip
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX (10+1)

typedef struct{
    char imePlanete[MAX];
    float minDistance;
    float maxDistance;
    float masa;
    float trajanje;
    float period;
    int temperatura;
    int brojSatelita;
} planete;

char* prvi_satelit(char planet[MAX]){
    FILE* satelitiTxt = fopen("sateliti.txt", "r");

    char *ime_planeta = (char*) malloc(sizeof(char) * MAX);
    char *ime_satelita = (char*) malloc(sizeof(char) * MAX);

    while(fscanf(satelitiTxt, "%[^#]#%s\n", ime_planeta, ime_satelita) == 2){
        if(strcmp(ime_planeta,planet) == 0){
            fclose(satelitiTxt);
            return ime_satelita;
        }
    }

    return "-";
}

int main(){
    int i, br = 0;
    float m;

    scanf("%f", &m);

    FILE* planetiDat = fopen("planeti.dat", "rb");
    fseek(planetiDat,0,SEEK_END);
    br = ftell(planetiDat) / sizeof(planete);
    rewind(planetiDat);

    FILE* output = fopen("mala_masa.txt", "w");
    planete planet[br];
    for(i = 0; i < br; i++){
        fread(&planet[i], sizeof(planete), 1, planetiDat);
        if(m > planet[i].masa)
            fprintf(output, "%s#%.3f#%d#%s\n", planet[i].imePlanete, planet[i].masa, planet[i].brojSatelita, prvi_satelit(planet[i].imePlanete));
    }
    fclose(output);
    fclose(planetiDat);
}
