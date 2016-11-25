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
    printf("%s", wordUse);
 /*   char totalList[][] = char[500][100];
    totalList = downloadListWords();*/

}

void showSimilarWords()// afficher les resultats
{

}

void testSeuilSimilarWords()// trie les mots selon leur seuil de similarité
{

}
/*
char[][] downloadListWords()// charge la liste des mots dans un ou plusieurs dictionnaire(s)
{
    char totalList[][] = new char[500][100];
    totalList = imitationListWords();
    return totalList;
}

char[][] imitationListWords()
{
    char totalList[][] = new char[500][100];
    totalList[0] = "trac";
    totalList[1] = "troc";
    totalList[2] = "tric";
    totalList[3] = "tryc";
    totalList[4] = "tsuc";
    totalList[5] = "tduc";
    totalList[6] = "tdac";
    return totalList;
}
*/
