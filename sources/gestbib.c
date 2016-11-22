/*
**Filename: gestbib.c
**
**Made by : Fairfort Yohan
**
**Description : Partie 1 du dictionnary
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "gestbib.h"
#include <unistd.h>
#include <stdbool.h>


//Dictionnaire de 10 000 mots par défaut
Dictionary* newDictionary() {
    Dictionary* dico = malloc(sizeof(Dictionary));//{0, {0}, {""}};
    
    dico->title = "default dictionnary";
    dico->length = 0;
    dico->lengthOfEachWord = malloc(sizeof(int) * 10000);
    dico->words = malloc(sizeof(char*) * 10000);

    FILE * file = fopen(dico->title, "w");
    fputs("/***** Dictionary *****/\n", file);
    fclose(file);

    return dico;
}

Dictionary* newDictionaryWithTitle(char* title) {
    Dictionary* dico = malloc(sizeof(Dictionary));//{0, {0}, {""}};
    
    dico->title = title;
    dico->length = 0;
    dico->lengthOfEachWord = malloc(sizeof(int) * 10000);
    dico->words = malloc(sizeof(char*) * 10000);

 	FILE * file = fopen(dico->title, "w");
    fputs("/***** Dictionary *****/\n", file);
    fclose(file);

    return dico;
}

Dictionary* newDictionaryWithTitleAndMax(char* title, int maxWords)
{
	Dictionary* dico = malloc(sizeof(Dictionary));//{0, {0}, {""}};
    
    dico->title = title;
    dico->length = 0;
    dico->lengthOfEachWord = malloc(sizeof(int) * maxWords);
    dico->words = malloc(sizeof(char*) * maxWords);

    FILE* file = fopen(dico->title, "w");
    fputs("/***** Dictionary *****/\n", file);
    fclose(file);

	return dico;			
}

Dictionary* createDictionary(char *filePath) {
        char confirm = '0';
        do {
        if (confirm == 'y') {
        } else {
        }
    } else {
        fclose(file);
    }
}

void writeDictionary(char * path, Dictionary content) {
    for (int idx = 0; idx < content.length; ++idx) {
    }
}

	FILE* file = fopen(fileTxtName, "r");
    if(file == NULL) {
        fclose(file);
        printf("Text file not found or unreachable!");
        return ;
	}

    char ** listOfUniqueWord;
    int sizeOflistOfUniqueWord;
    printf("initialise la liste des mots uniques");
    /*printf("SIZE: %d\n", sizeOflistOfUniqueWord);
    for (int i = 0; i < sizeOflistOfUniqueWord; ++i) {
        printf("----> %s\n", listOfUniqueWord[i]);
    }
    
    dictionary.length = sizeOflistOfUniqueWord; Taille de la liste 
    dictionary.lengthPerLine = malloc(dictionary.length * sizeof(int));
    dictionary.fileContent = malloc(dictionary.length * sizeof(char *));
    for (int idx = 0; idx < dictionary.length; idx ++) {
        dictionary.lengthPerLine[idx] = strlen(listOfUniqueWord[idx]);
        dictionary.fileContent[idx] = malloc(dictionary.lengthPerLine[idx] * sizeof(char));
    }*/
    fclose(file);
    printf("passe dans cette fonction");
}

		fprintf(file, "%s\n", word);
	}
	fclose(file);
}

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
	int sizeOfAllWordFromText = 0;
	int* ptrSizeOfAllWordFromText = &sizeOfAllWordFromText;

	char** allWordsFromText = getAllWordFromTxt(text,ptrSizeOfAllWordFromText);
	char** uniqWords = malloc(sizeof(char*) * sizeOfAllWordFromText);
	uniqWords[0] = allWordsFromText[0];
	int sizeUniqWords = 1;
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

	*sizeOfTable = sizeUniqWords;
	return uniqWords;
}

char** getAllWordFromTxt(FILE* text, int* sizeOfAllWord){
	int bufferOfWord = 64;
	char** allWord = malloc(sizeof(char*) * bufferOfWord);
	int counterAllWords = 0;
	int counterBuffer = 0;

	int sizeOfFile = getSizeOfThisFile(text);
	char bufferOfText[sizeOfFile];
	fgets(bufferOfText, sizeOfFile, text);

	printf("%s",bufferOfText);
	char space = ' ';
	int counterText;
	int counterThisWord;
	for(counterText = 0; counterText < sizeOfFile; counterText++)
	{
		char* thisWord[bufferOfWord];
		if(bufferOfText[counterText] == space)
		{
			thisWord[counterThisWord] = '\0';
			counterThisWord = 0;
			allWord[counterAllWords] = thisWord;
			counterAllWords++;
		}
		else
		{
			thisWord[counterThisWord] = bufferOfText[counterText];
			counterThisWord++;
		}
	}

	*sizeOfAllWord = counterAllWords;
	return allWord;

}

int getSizeOfThisFile(FILE* file){
	int resultat;
	fseek(file, 0, SEEK_END);	
	resultat = ftell(file) + 1;
	rewind(file);

	return resultat;
}

void printDictionary(Dictionary dictionary) {
    printf("Number of words: %d\n", dictionary.length);
    for (int idx = 0; idx < dictionary.length; ++idx) {
        printf("%d(%d): %s\n", idx + 1, dictionary.lengthOfEachWord[idx], dictionary.words[idx]);
    }
}

