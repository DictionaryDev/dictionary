/*
**Filename: main1.c
**
**Made by : Fairfort Yohan
**
**Description : main de test de gestbib.c
**
*/

#include <stdio.h>
#include <stdlib.h>
#include "gestbib.h"
#include "utility.h"
#include "gui.h"

int main(int argCount, char* argList[]) {

  /*char* theDictionnary = "aDictionnary";
  int textSize = 3;
  char* text[] = {"oyoy", "tototto", "tata"};
	FILE* file = fopen("test", "r");

  int sizeOfFile = getSizeOfThisFile(file);
  printf("taille du fichier text :%d\n",sizeOfFile);

  int* wordsLength;
  int sizeOfWordsLength;
  char** allWordOfThex = getAllWordFromTxt(file, &sizeOfWordsLength, wordsLength);
  printf("size : %d\n", sizeOfWordsLength);

  printf("Création du dictionnaire\n");
  Dictionary* myDict = createDictionaryFromTxt(file, theDictionnary);

  showDicoScreen(myDict);
  //writeDictionary(myDict, text, textSize);
  printDictionary(*myDict);
	printf("%s",myDict->title);
  destroyDictionary(myDict);
	fclose(file);*/

  showHomeScreen();
	return 0;
};
