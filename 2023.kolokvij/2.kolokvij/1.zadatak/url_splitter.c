/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/450e57c00d0b7872c7f12ff5f0dad63cd2cd2230/tekstovi%20i%20test%20caseovi/%5B2023.kol%5D%5B2%5DURL%20splitter.PDF
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void exploreURL(const char* url, char* protokol, char* host, char* port, char* relPath, char* queryString);

int main()
{
    const char url[1000] = { '\0' };
    char protokol[1000] = { '-' }, host[1000] = { '-' }, port[1000] = { '-' }, relPath[1000] = { '-' }, queryString[1000] = { '-' };

    scanf("%s", url);

    exploreURL(url, protokol, host, port, relPath, queryString);

    printf("Protokol: %s\nHost: %s\nPort: %s\nRelative path: %s\nQuery string: %s", protokol, host, port, relPath, queryString);

    return 0;
}

void exploreURL(const char* url, char* protokol, char* host, char* port, char* relPath, char* queryString) {
    char fullHost[1000] = { '-' };

    sscanf(url, "%[^://]://%[^/]%[^?]?%s", protokol, fullHost, relPath, queryString);
    sscanf(fullHost, "%[^:]:%s", host, port);
}
