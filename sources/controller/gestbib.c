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



Dictionary newDictionary() {
    Dictionary dico = {0, {0}, ""};
    return dico;
}

bool createDictionary(char *filename) {
    if( access( filename, F_OK ) != -1 ) {
        // file exists
        char confirm = '0';
        do {
           confirm =  scanf("File already exist. Erase it? (y/n)");
        } while (confirm != 'y' && confirm != 'n');
        if (confirm == 'y') {
            FILE * file = fopen(filename, "w");
            fputs("/***** Dictionary *****/\n", file);
            fclose(file);
            return true;
        } else {
            return false;
        }
    } else {
        FILE * file = fopen(filename, "w");
        fputs("/***** Dictionary *****/\n", file);
        fclose(file);
        return true;
    }
}

void writeDictionary(char * path, Dictionary content) {
    bool isCreated = createDictionary(path);
    if(!isCreated) {
        return;
    }
    for (int idx = 0; idx < content.length; ++idx) {
        insertWordIntoDictionnary(path, content.fileContent[idx]);
    }
}

Dictionary createDictionaryFromTxt(char* fileTxtName) {
	FILE* file = fopen(fileTxtName, "r");
    if(file == NULL) {
        fclose(file);
        printf("Text file not found or unreachable!");
        return newDictionary();
	}
    Dictionary dictionary = newDictionary();
    char ** listOfUniqueWord;
    int sizeOflistOfUniqueWord;
     
    listOfUniqueWord = getUniqWordFromTxt(file, &sizeOflistOfUniqueWord); //TODO Fonction qui fait la liste des mots uniques. NOTE: retourner la taille de la liste
    dictionary.length = sizeOflistOfUniqueWord; /* Taille de la liste */
    dictionary.lengthPerLine = malloc(dictionary.length * sizeof(int));
    dictionary.fileContent = malloc(dictionary.length * sizeof(char *));
    for (int idx = 0; idx < dictionary.length; idx ++) {
        dictionary.lengthPerLine[idx] = strlen(listOfUniqueWord[idx]);
        dictionary.fileContent[idx] = malloc(dictionary.lengthPerLine[idx] * sizeof(char));
    }
    fclose(file);
    return dictionary;
}

bool isADictionary(char * filename) {
    //Tester si la chaine de caractere ligne 1 est presente
    FILE * file = fopen(filename, "r");
    char ** check = malloc(255 * sizeof(char));
    fgets(check, 255, file);
    if (strcmp(check, DICTIONARY_HEADER) == 0) {
        fclose(file);
        return true;
    } else {
        fclose(file);
        return false;
    }
}

void destroyDictionary(char* filename) {
	FILE * file = fopen(filename, "w+");
	if(file != NULL || isADictionary(filename)) {// pourquoi c'est un || ? ce serait pas un &&?
        remove(filename);
	}
	fclose(file);
}

void insertWordIntoDictionnary(char* filename, char* word) {
	FILE* file = fopen(filename, "a");
	if(file != NULL || isADictionary(filename)) {
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
			fscanf("%s\n", thisWordFromDictionnary);
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
	int sizeOfAllWordFromText;
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
	int bufferOfWord = 64;//tailleMaximalDeChaqueMot
	char** allWord = malloc(sizeof(char*) * bufferOfWord);
	int counterAllWords = 0;
	int counterBuffer = 0;

	int sizeOfFile = getSizeOfThisFile(text);
	char bufferOfText[sizeOfFile];
	fgets(bufferOfText, sizeOfFile, text);

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
        printf("%d(%d): %s\n", idx + 1, dictionary.lengthPerLine[idx], dictionary.fileContent[idx]);
    }
}

