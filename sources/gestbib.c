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

Dictionary* newDictionary() {
    Dictionary* dico = malloc(sizeof(Dictionary));//{0, {0}, {""}};
    int defaultSize = 10000;
    dico->title = "default dictionnary";
    dico->length = 0;
    dico->lengthOfEachWord = malloc(sizeof(int) * defaultSize);
    dico->words = malloc(sizeof(char*) * defaultSize);

    FILE * file = fopen(dico->title, "w");
    fputs("/***** Dictionary *****/\n", file);
    fclose(file);

    return dico;
}
Dictionary* newDictionaryWithTitle(char* title) {
    Dictionary* dico = malloc(sizeof(Dictionary));
    int defaultSize = 10000;
    dico->title = title;
    dico->length = 0;
    dico->lengthOfEachWord = malloc(sizeof(int) * defaultSize);
    dico->words = malloc(sizeof(char*) * defaultSize);

 	FILE * file = fopen(dico->title, "w");
    fputs("/***** Dictionary *****/\n", file);
    fclose(file);

    return dico;
}
Dictionary* newDictionaryWithTitleAndMax(char* title, int maxWords){
	Dictionary* dico = malloc(sizeof(Dictionary));

  dico->title = title;
  dico->length = 0;
  dico->lengthOfEachWord = malloc(sizeof(int) * maxWords);
  dico->words = malloc(sizeof(char*) * maxWords);

  FILE* file = fopen(dico->title, "w");
  fputs("/***** Dictionary *****/\n", file);
  fclose(file);

	return dico;
}

Dictionary* useDictionary(char* title)    //synchroniser les éléments de la structure
{
	Dictionary* dico = malloc(sizeof(Dictionary));
  int defaultSize = 10000;
  dico->title = title;
  dico->length = 0;
  dico->lengthOfEachWord = malloc(sizeof(int) * defaultSize);
  dico->words = malloc(sizeof(char*) * defaultSize);
  //read the dictionnary to get his properties

	return dico;
}

Dictionary* createDictionary(char *filePath) {
    if( isADictionary(filePath) == true ) {
      return useDictionary(filePath);
    }
    else if(filePath == "" || filePath == NULL)//add more condition about the emptiness of string
    {
    	return newDictionary();
    }
    else
    {
      return newDictionaryWithTitle(filePath);
    }
}

bool isADictionary(char * filename) {
    //Tester si la chaine de caractere ligne 1 est presente
    FILE * file = fopen(filename, "r");
    char ** check = malloc(255 * sizeof(char));
    fgets(*check, 255, file);
    if (strcmp(*check, DICTIONARY_HEADER) == 0) {
        fclose(file);
        return true;
    } else {
        fclose(file);
        return false;
    }
}

void stopUseDictionnary(Dictionary* dictionary) {
      free(dictionary->words);
      free(dictionary->lengthOfEachWord);
      free(dictionary);
}
void destroyDictionary(Dictionary* dictionary){
  FILE * file = fopen(dictionary->title, "w+");
	if(file != NULL && isADictionary(dictionary->title)) {
        remove(dictionary->title);
        stopUseDictionnary(dictionary);
  }
}

void writeDictionary(Dictionary* dico,char** wordsToInput,int sizeOfWords) {
   	int i;
   	FILE* file = fopen(dico->title, "a");

   	for(i = 0; i < sizeOfWords; i++)
   	{
   		dico->words[dico->length + i] = wordsToInput[i];
   		dico->lengthOfEachWord[dico->length + i] = strlen(wordsToInput[i]);
		fprintf(file, "%s\n", wordsToInput[i]);

   	}
   	dico->length = dico->length + sizeOfWords;

    fclose(file);
}

void createDictionaryFromTxt(char* filePath, FILE* file) {

    Dictionary* dictionary = newDictionaryWithTitle(filePath);

    char ** listOfUniqueWord;
    int sizeOflistOfUniqueWord;
    printf("initialise la liste des mots uniques");
    listOfUniqueWord = getUniqWordFromTxt(file, &sizeOflistOfUniqueWord);
    //TODO Fonction qui fait la liste des mots uniques. NOTE: retourner la taille de la liste
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



void printDictionary(Dictionary dictionary) {
  int idx;
  printf("Number of words: %d\n", dictionary.length);
  for (idx = 0; idx < dictionary.length; ++idx) {
      printf("%d(%d): %s\n", idx + 1, dictionary.lengthOfEachWord[idx], dictionary.words[idx]);
  }
}
