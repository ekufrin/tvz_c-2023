/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/4976a7166fb32f3d763656441f22e99a5606cfc3/tekstovi%20i%20test%20caseovi/%5B2021.kol%5D%5B2%5DRazdjelnik.zip
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void razdijeli(char* ulaz, char razdjelnik, char* prvi, char* drugi);

int main()
{
    
    int n = 0;
    char razdjelnik;
    scanf("%d", &n);

    char* niz = (char*)malloc(n+1 * sizeof(char));
    char* prvi = (char*)malloc(n+1 * sizeof(char));
    char* drugi = (char*)malloc(n+1 * sizeof(char));

    scanf(" %[^\n]", niz);
    scanf(" %c", &razdjelnik);
    razdijeli(niz, razdjelnik, prvi, drugi);

    printf("%s %zd\n", prvi, strlen(prvi));
    printf("%s %zd\n", drugi, strlen(drugi));

    free(niz);
    free(prvi);
    free(drugi);
   
    return 0;
}
void razdijeli(char* ulaz, char razdjelnik, char* prvi, char* drugi) {
    char* temp;
    temp = strtok(ulaz, &razdjelnik);
    strcpy(prvi, temp);
    temp = strtok(NULL, "");
    strcpy(drugi, temp);

}
