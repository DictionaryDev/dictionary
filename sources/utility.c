#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utility.h"
#include "gestbib.h"

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

char** getUniqWordFromTxt(FILE* text, int* sizeOfTable, int* sizeOfEachWords){

	int* wordsLength;
	int sizeOfWordsLength;
	printf("GotText");

	char** allWordsFromText = getAllWordFromTxt(text, &sizeOfWordsLength, wordsLength);

	int* uniqWordsLength = malloc(sizeof(int) * sizeOfWordsLength);
	char** uniqWords = malloc(sizeof(char*) * sizeOfWordsLength);

	uniqWords[0] = allWordsFromText[0];
	int sizeUniqWords = 1;
	int i,j;
	printf("Commencement Uniq");

	for(i = 1; i < sizeOfWordsLength; i++){
		bool flag = false;
		for(j = 0; j < sizeUniqWords; j++){
			if(strcmp(allWordsFromText[i], uniqWords[j]) == 0)
			{
				flag = true;
				printf("%s ", allWordsFromText[i]);
				break;
			}
		}

		if(flag == false)
		{
			uniqWords[sizeUniqWords - 1] = malloc(sizeof(char) * wordsLength[i]);
			uniqWordsLength[sizeUniqWords - 1] = wordsLength[i];
			uniqWords[sizeUniqWords - 1] = allWordsFromText[i];
			sizeUniqWords++;
		}
	}

	sizeOfEachWords = uniqWordsLength;
	*sizeOfTable = sizeUniqWords;
	return uniqWords;
}

char** getAllWordFromTxt(FILE* text, int* sizeOfTableWord, int* sizeOfEachWords){

  int sizeOfText = getSizeOfThisFile(text);

	int sizeOfSizes;
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

int* getSizeOfEachWordOfTxtFile(FILE* text, int* size){
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
		//printf("%ld %d|%s ",ftell(text) ,lenghtOfEachWord[i] , buffer);
	}
	rewind(text);

	return lenghtOfEachWord;
}
