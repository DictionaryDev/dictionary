/*
**Filename: gestbib.c
**
**Made by : Fairfort Yohan ,Baugue Florian
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
  int defaultSize = 9000;

  dico->title = title;
  dico->length = 0;
  dico->lengthOfEachWord = malloc(sizeof(int) * defaultSize);
  dico->words = malloc(sizeof(char*) * defaultSize);

 	FILE* file = fopen(dico->title, "w");
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
Dictionary* newDictionaryWithEverything(char* title, int length, char** words, int* wordsLength){
	Dictionary* dico = malloc(sizeof(Dictionary));

  dico->title = title;
  dico->length = length;
  dico->lengthOfEachWord = wordsLength;
  dico->words = words;

  FILE* file = fopen(dico->title, "w");
  fputs("/***** Dictionary *****/\n", file);
  fclose(file);

	return dico;
}

Dictionary* useDictionary(char* title){
	Dictionary* dico = malloc(sizeof(Dictionary));
  int defaultSize = 10000;
  dico->title = title;
  dico->length = 0;
  dico->lengthOfEachWord = malloc(sizeof(int) * defaultSize);
  dico->words = malloc(sizeof(char*) * defaultSize);
  FILE* file = fopen(title, "r");

  if(file != NULL && isADictionary(title)) {
    dico->words = getAllWordFromTxt(file, &dico->length, dico->lengthOfEachWord);
  }
  else {
    printf("this dictionary doesn't exist");
  }
  fclose(file);
	return dico;
}

Dictionary* createDictionary(char* filePath) {
    if( isADictionary(filePath) == true ) {
      return useDictionary(filePath);
    }
    else if(strcmp(filePath, "") == 0 || filePath == NULL)
    {
    	return newDictionary();
    }
    else
    {
      return newDictionaryWithTitle(filePath);
    }
}

bool isADictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if(file != NULL)
    {
      char* check = malloc(255 * sizeof(char));
      fgets(check, 255, file);
      printf("%s", check);
      if (strcmp(check, DICTIONARY_HEADER) == 0) {
          fclose(file);
          return true;
      } else {
          fclose(file);
          return false;
      }
    }
    else
      return false;

}

void stopUseDictionnary(Dictionary* dictionary){
      free(dictionary->words);
      free(dictionary->lengthOfEachWord);
      free(dictionary);
}

void destroyDictionary(Dictionary* dictionary){
  FILE* file = fopen(dictionary->title, "w+");
	if(file != NULL && isADictionary(dictionary->title)) {
        remove(dictionary->title);
        stopUseDictionnary(dictionary);
  }
}

void writeDictionary(Dictionary* dico,char** wordsToInput,int sizeOfWordsToInput) {
   	int i;
   	FILE* file = fopen(dico->title, "a");

   	for(i = 0; i < sizeOfWordsToInput; i++)
   	{
   		dico->words[dico->length + i] = wordsToInput[i];
   		dico->lengthOfEachWord[dico->length + i] = strlen(wordsToInput[i]);
	    fprintf(file, "%s\n", wordsToInput[i]);
   	}

   	dico->length = dico->length + sizeOfWordsToInput;

    fclose(file);
}

Dictionary* createDictionaryFromTxt(FILE* file, char* filePath) {

    char** listOfUniqueWord;
    int sizeOflistOfUniqueWord;
    int* allSizeOfUniqWords;
    //printf("initialise la liste des mots uniques");
    listOfUniqueWord = getAllWordFromTxt(file, &sizeOflistOfUniqueWord, allSizeOfUniqWords);
    //TODO Fonction qui fait la liste des mots uniques. NOTE: retourner la taille de la liste
    /*printf("SIZE: %d\n", sizeOflistOfUniqueWord);
    for (int i = 0; i < sizeOflistOfUniqueWord; ++i) {
        printf("----> %s\n", listOfUniqueWord[i]);
    }*/

    Dictionary* dictionary = newDictionaryWithEverything(filePath, sizeOflistOfUniqueWord, listOfUniqueWord, allSizeOfUniqWords);
    fclose(file);
    return dictionary;
}

void printDictionary(Dictionary dictionary) {
  int idx;
  printf("Number of words: %d\n", dictionary.length);
  for (idx = 0; idx < dictionary.length; ++idx) {
      printf("%d : %s\n", idx + 1, dictionary.words[idx]);
  }
}
