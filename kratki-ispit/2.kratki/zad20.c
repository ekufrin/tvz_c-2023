/*
TEKST ZADATKA:
Precizno napišite (uključujući sve znakove) što će sve ispisati program naziva "prog", ako komandna linija glasi:
C:>prog a3a4a5 5kmd pero

Kod programa prog je:
int main(int argc, char *argv[]) {
char pom[40];
char *ptr;
printf("%d;", argc);
strcpy(pom, argv[1]+3);
printf("%s;", pom);
ptr=strstr(argv[3], "er");
printf("%s", ptr);
return 0;
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>



int main(int argc, char* argv[]) {

	char pom[40];
	char* ptr;
	printf("%d;", argc);	// 4;
	strcpy(pom, argv[1] + 3);	// U niz pom kopiramo 1.element pomaknut za 3 slova u desno, a3a4a5 +3 = 4a5
	printf("%s;", pom);	// 4a5;
	ptr = strstr(argv[3], "er");	// Pointer ptr postavljamo na 3.element od slova "er", pero = ero
	printf("%s", ptr);	// ero

	// REZULTAT: 4;4a5;ero

	return 0;

}
