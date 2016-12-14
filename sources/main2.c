/*
**Filename: main2.c
**
**Made by : Baugue Florian, Fairfort Yohan
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
    int seuil = 1;// seuil vaut 1 par default
    printf("indiquez le mot a examiner...\n");
    scanf("%s", &wordUse);
    printf("indiquez le nombre de differences tolerees...\n");
    scanf("%d", seuil);
    searchSimilarWords(wordUse, seuil);
    return 0;
}
