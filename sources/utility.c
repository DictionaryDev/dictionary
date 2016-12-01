#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/**
 * Function which aim to search a word into a dictionary representated by its @param filename
 * @param filename The filename which represent the dictionary
 * @param word The word to search
 * @return 0 if the word doesn't exist, 1 if the word exist
 */
int searchWord(char* filename, char* word) {
	FILE* file = fopen(filename, "r");
	int isItInDictionnary = 0;

	if(file != NULL) {
		fseek(file, 0, SEEK_END);
		int sizeFile = ftell(file);
		rewind(file);
		do {
			char* thisWordFromDictionnary;
			fscanf(file,"%s\n", thisWordFromDictionnary);
			if(strcmp(thisWordFromDictionnary, word) == 0) {
				isItInDictionnary = 1;
				break;
			}
		} while(ftell(file) < sizeFile);

	}

	if(isItInDictionnary == 1) {
		printf("%s est bien dans le dictionnaire",word);
	} else {
		printf("%s n'est pas dans le dictionnaire\n", word);
	}

	fclose(file);
	return isItInDictionnary;
}

char** getUniqWordFromTxt(FILE* text,int* sizeOfTable){
	int sizeOfAllWordFromText = 10000;

	//char** allWordsFromText = getAllWordFromTxt(text, &sizeOfAllWordFromText);
	char** uniqWords = malloc(sizeof(char*) * sizeOfAllWordFromText);
	//uniqWords[0] = allWordsFromText[0];
	/*int sizeUniqWords = 1;
	int i,j;

	for(i = 1; i < sizeOfAllWordFromText; i++){
		int flag = 0;
		for(j = 0; j < sizeUniqWords; j++){
			if(strcmp(allWordsFromText[i],uniqWords[j]) == 0)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			uniqWords[sizeUniqWords - 1] = allWordsFromText[i];
			sizeUniqWords++;
		}
	}

	*sizeOfTable = sizeUniqWords;*/
	return uniqWords;
}


//imparfait, il faut faire un splitter basé sur une regex(partie4)
char** getAllWordFromTxt(FILE* text, int* sizeOfTableWord, int* sizeOfEachWords){

  int sizeOfText = getSizeOfThisFile(text);

	int sizeOfSizes;//a retourner plus haut
 	int* sizes = getSizeOfEachWordOfTxtFile(text, &sizeOfSizes);
	sizeOfEachWords = sizes;
	*sizeOfTableWord = sizeOfSizes;

	int i;
	char** allWord = malloc(sizeof(char*) * (sizeOfSizes));
	for (i = 0; ftell(text) < sizeOfText - 1;	i++)
	{
		allWord[i] = malloc(sizeof(char) * sizes[i]);
		fscanf(text,"%s ",allWord[i]);
	}
	rewind(text);

	return allWord;
}

int getSizeOfThisFile(FILE* file){
	int resultat;
	fseek(file, 0, SEEK_END);
	resultat = ftell(file) + 1;
	rewind(file);

	return resultat;
}

int* getSizeOfEachWordOfTxtFile(FILE* text, int* size)
{
	int i;
	char buffer[60];
	int sizeOfText = getSizeOfThisFile(text);
	for (i = 0; ftell(text) < sizeOfText - 1;	i++)
	{
		fscanf(text,"%s ",buffer);
	}
	*size = i;
	rewind(text);

	int taille;
	int precTell = 0;
	int* lenghtOfEachWord = malloc(sizeof(int) * (*size));
	for (i = 0; ftell(text) < sizeOfText - 1;	i++)
	{
		fscanf(text, "%s ", buffer);
		taille = ftell(text) - precTell;
		precTell = ftell(text);
		lenghtOfEachWord[i] = taille;
		//printf("%d %d|%s ",ftell(text) ,lenghtOfEachWord[i] , buffer);
	}
	rewind(text);

	return lenghtOfEachWord;
}
