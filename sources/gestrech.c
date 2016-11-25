/*
**Filename: gestrech.c
**
**Made by : Fairfort Yohan
**
**Description : Partie 1 du dictionnary
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <stdbool.h>
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

void searchSimilarWords()// programme controle
{

}

void showSimilarWords()// afficher les resultats
{

}

void testSeuilSimilarWords()// trie les mots selon leur seuil de similarité
{

}

void downloadListWords()// charge la liste des mots dans un ou plusieurs dictionnaire(s)
{

}
