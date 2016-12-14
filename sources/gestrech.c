/*
**Filename: gestrech.c
**
**Made by : Baugue Florian
**
**Description : Partie 2 du dictionnary
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <stdbool.h>
#include "gestrech.h"

void searchSimilarWords(char* wordUse, int seuil)// programme controle
{
    int count = 0;
    char** totalList = malloc(sizeof(char*) * 500);
    char** affinedList = malloc(sizeof(char*) * 500);
    totalList = downloadListWords(totalList);
    affinedList = testSeuilSimilarWords(affinedList, totalList, wordUse, &count, seuil);
    free(totalList);
    showSimilarWords(affinedList, count);
    free(affinedList);
}

void showSimilarWords(char** affinedList, int count)// afficher les resultats
{
    int i = 0;
    for (i = 0 ; i < count ; i++)
    {
        printf("%s\n", affinedList[i]);
    }
}

char** testSeuilSimilarWords(char** affinedList,char** totalList, char* wordUse, int *count, int seuil)// trie les mots selon leur seuil de similarité (par defaut 1 erreur tolérée)
{
    int i = 0;
    for (i = 0 ; i < 10 ; i++)
    {
        if (countDiff(totalList[i], wordUse) < seuil+1)
        {
            affinedList[*count] = totalList[i];
            *count = *count + 1;
        }
    }
    return affinedList;
}

int countDiff(char* wordExam, char* wordUse)// compte le nombre de differences entre les mots (a affiner)
{
    int diff = 0;
    int i = 0;
    for (i = 0 ; i < sizeof(wordUse) ; i++)
    {
        if (wordExam[i] != wordUse[i])
            diff++;
    }
    return diff;
}

char** downloadListWords(char** totalList)// charge la liste des mots dans un ou plusieurs dictionnaire(s)
{
    totalList = imitationListWords(totalList);
    return totalList;
}

char** imitationListWords(char** totalList)// en attendant le fonctionnement de la partie 1...
{
    totalList[0] = "trac";
    totalList[1] = "troc";
    totalList[2] = "tric";
    totalList[3] = "tryc";
    totalList[4] = "tsuc";
    totalList[5] = "tduc";
    totalList[6] = "tdac";
    totalList[7] = "tru";
    totalList[8] = "ruc";
    totalList[9] = "chose";
    return totalList;
}

