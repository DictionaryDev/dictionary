/*
**Filename: gestrech.c
**
**Made by : Fairfort Yohan, Baugue Florian
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
/*
int calculateSeuilBetween(char* this, char* that);
char** advanceSearch(char* word,char** listOfCommonWord,int sizeOfListOfCommonWord,int* sizeOfSimilarWord,int myMaxSeuil);
void showSearchOf(char* word);

void showSearchOf(char* word)
{
	int sizeOfSimilarList;
	int theMaxSeuilThatIWant = 3;
	char** listOfWord;
	int sizeOfListOfWord;
	char** listOfSimilar(word, listOfWord, sizeOfListOfWord, &sizeOfSimilarList, theMaxSeuilThatIWant);

	int i;
	for(i = 0; i < sizeOfSimilarList; i++)
	{
		//afficher;
		printf(listOfSimilar[i]);
	}
}

char** advanceSearch(char* word,char** listOfCommonWord,int sizeOfListOfCommonWord,int* sizeOfSimilarWord,int myMaxSeuil)
{
	int i;
	*sizeOfSimilarWord = 0;
	char** listOfSimilarWord = malloc(sizeof(char*) * sizeOfListOfCommonWord);

	for(i = 0; i < sizeOfListOfCommonWord; i++)
	{
		int seuil = calculateSeuilBetween(listOfCommonWord[i], word)
		int isItSimilar = myMaxSeuil > seuil;
		printf(isItSimilar);
		if(isItSimilar == 0)//a vérifier si c'est 0 ou 1;
		{
			listOfSimilarWord[*sizeOfSimilarWord] = listOfCommonWord[i];
			*sizeOfSimilarWord++;
		}
	}

	return listOfSimilarWord;
}

int calculateSeuilBetween(char* this, char* that)
{
	int i;
	int seuil;
	int isItTHeEndOfThisOrThat = this[i] != '\0' || that[i] != '\0';
	for(i = 0; isItTHeEndOfThisOrThat; i++)
	{
		if(this[i] == that[i])
			seuil++;
	}
	return seuil;
}
*/

void searchSimilarWords(char* wordUse)// programme controle
{
    int count = 0;
    char** totalList = malloc(sizeof(char*) * 500);
    char** affinedList = malloc(sizeof(char*) * 500);
    totalList = downloadListWords(totalList);
    affinedList = testSeuilSimilarWords(affinedList, totalList, wordUse, &count);
    showSimilarWords(affinedList, count);
}

void showSimilarWords(char** affinedList, int count)// afficher les resultats
{
    int i = 0;
    for (i = 0 ; i < count ; i++)
    {
        printf("%s\n", affinedList[i]);
    }
}

char** testSeuilSimilarWords(char** affinedList,char** totalList, char* wordUse, int *count)// trie les mots selon leur seuil de similarité
{
    int i = 0;
    for (i = 0 ; i < 10 ; i++)
    {
        if (countDiff(totalList[i], wordUse) < 2)
        {
            affinedList[*count] = totalList[i];
            *count = *count + 1;
        }
    }
    return affinedList;

}

int countDiff(char* wordExam, char* wordUse)
{
    int diff = 0;
    int i = 0;
    for (i = 0 ; i < 4 ; i++)
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

char** imitationListWords(char** totalList)
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

