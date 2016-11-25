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

int main(int argCount, char* argList[]) {
  //parseCMDLine(argCount, argList);
  char* theDictionnary = "aDictionnary";
  int textSize = 3;
  char* text[] = {"oyoy", "tototto", "tata"};
	FILE* file = fopen("test", "r");

  int sizeOfFile = getSizeOfThisFile(file);
  printf("taille du fichier text :%d\n",sizeOfFile);

  int wordsLength[10] = {0};
  char** allWordOfThex = getAllWordFromTxt(file, wordsLength);
  Dictionary* myDict = createDictionary(theDictionnary);
  writeDictionary(myDict, text, textSize);
  printDictionary(*myDict);
	printf("%s",myDict->title);
  destroyDictionary(myDict);
	fclose(file);
	return 0;
};
