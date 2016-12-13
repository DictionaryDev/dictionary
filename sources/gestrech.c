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
    char** totalList;
    char** affinedList;
    totalList = downloadListWords();
    affinedList = testSeuilSimilarWords(totalList, wordUse);
}

void showSimilarWords(char** affinedList)// afficher les resultats
{

}

char** testSeuilSimilarWords(char** totalList, char* wordUse)// trie les mots selon leur seuil de similarité
{
    char** affinedList;
    int i = 0;
    int count = 0;
    for (i = 0 ; i < 10 ; i++)
    {
        if (countDiff(totalList[i], wordUse) < 2)
        {
            affinedList[count] = totalList[i];
        }
    }
    return affinedList;

}

int countDiff(char* wordExam, char* wordUse)
{
    int diff = 0;
    if (sizeof wordUse !=sizeof wordExam)
        diff = 10;
    return diff;
}

char** downloadListWords()// charge la liste des mots dans un ou plusieurs dictionnaire(s)
{
    char** totalList;
    printf("Ici ca marche");
    //totalList = imitationListWords();// Error Unknown
    printf("Ici ca merde...");
    return totalList;
}

char** imitationListWords()
{
    char** totalList;
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

