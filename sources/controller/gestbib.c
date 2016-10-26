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

bool createDictionary(char* filename) {
    if( access( filename, F_OK ) != -1 ) {
        // file exists
        char confirm = '0';
        do {
           confirm =  scanf("File already exist. Erase it? (y/n)");
        } while (confirm != 'y' && confirm != 'n');
        if (confirm == 'y') {
            FILE * file = fopen(filename, "w");
            fputs("/***** Dictionary *****/", file);
            fclose(file);
            return true;
        } else {
            return false;
        }
    } else {
        FILE * file = fopen(filename, "w");
        fputs("/***** Dictionary *****/", file);
        fclose(file);
        return true;
    }
}

void createDictionnaryFromTxt(char* fileTxtName) {
	FILE* f = fopen(fileTxtName, "r");

	if(f != NULL) {
		char** allUniqWordFromTxt; //récupérer tous les mots unique du dictionnaire
		int sizeOfallUniqWordFromTxt;
		char* newDictionnaryTitle = "";// setter un nom par rapport au dictionnaire?
		createDictionary(newDictionnaryTitle);
	}
	fclose(f);
}

bool isADictionary(char * filename) {
    //Tester si la chaine de caractere ligne 1 est presente
    FILE * file = fopen(filename, "r");
    fclose(file);
    return true;
}

void destroyDictionary(char* filename) {
	FILE * file = fopen(filename, "w+");
	if(file != NULL || isADictionary(filename)) {
        remove(filename);
	}
	fclose(file);
}

void insertWordIntoDictionnary(char* filename, char* word) {
	FILE* f = fopen(filename, "a");
	if(f != NULL || isADictionary(filename)) {
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