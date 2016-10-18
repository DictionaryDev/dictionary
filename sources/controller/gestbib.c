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

void createDictionnary(char* filename, char** listOfWords, int sizeOfListOfWords) {
	FILE* f = fopen(filename, "w");//on doit choisir une extension pour le dictionnaire

	int i;
	for(i = 0; i < sizeOfListOfWords; i++) {
		fprintf(f, "%s\n",listOfWords[i] );
	}
	fclose(f);
}

void useExistingDictionnary(char* filename) {
	FILE* f = fopen(filename, "r");

	if(f != NULL) {
		//je ne comprend pas exactement ce qu'il veux dire par le fait d'utiliser.
	}
	fclose(f);
}

void createDictionnaryFromTxt(char* fileTxtName) {
	FILE* f = fopen(fileTxtName, "r");

	if(f != NULL) {
		char** allUniqWordFromTxt; //récupérer tous les mots unique du dictionnaire
		int sizeOfallUniqWordFromTxt;
		char* newDictionnaryTitle = "";// setter un nom par rapport au dictionnaire?
		createDictionnary(newDictionnaryTitle, allUniqWordFromTxt, sizeOfallUniqWordFromTxt);
	}
	fclose(f);
}

void destroyDictionnary(char* filename) {
	FILE * f = fopen(filename, "w+");
	if(f != NULL) {
		fputs(f, "");//delete le tout normalement;
	}
	fclose(f);
}

void insertWordIntoDictionnary(char* filename, char* word) {
	FILE* f = fopen(filename, "a");
	if(f != NULL) {
		fprintf(f, "%s\n", word);
	}
	fclose(f);
}

int searchWord(char* filename, char* word) {
	FILE* f = fopen(filename, "r");
	int isItInDictionnary = 0;

	if(f != NULL) {
		fseek(f, 0, SEEK_END);
		int sizeFile = ftell(f);
		rewind(f);
		do {
			char* thisWordFromDictionnary;
			fscanf("%s\n", thisWordFromDictionnary);
			if(strcmp(thisWordFromDictionnary, word) == 0) {
				isItInDictionnary = 1;
				break;
			}
		} while(ftell(f) < sizeFile);

	}

	if(isItInDictionnary == 1) {
		printf("%s est bien dans le dictionnaire",word);
	} else {
		printf("%s n'est pas dans le dictionnaire\n", word);
	}

	fclose(f);
	return isItInDictionnary;
}