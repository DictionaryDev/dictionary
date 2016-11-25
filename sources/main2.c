/*
**Filename: main2.c
**
**Made by : Baugue Florian
**
**Description : Partie 2 du dictionnary
**
*/

#include <stdio.h>
#include <stdlib.h>
#include "gestrech.c"

int main()
{
    char wordUse[256];
    printf("indiquez le mot a examiner...\n");
    scanf("%s", &wordUse);
    searchSimilarWords(wordUse);
    return 0;
}
