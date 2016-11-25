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
#include "cmdLineParser.h"

int main(int argCount, char* argList[]) {
  //parseCMDLine(argCount, argList);
  char* theDictionnary = "aDictionnary";
  int textSize = 3;
  char* text[] = {"oyoy", "toto", "tata"};
	FILE* file = fopen("test", "r");
	Dictionary* myDict = createDictionary(theDictionnary);
  writeDictionary(myDict, text, textSize);
	printf("%s",myDict->title);
  destroyDictionary(myDict);
	fclose(file);
	return 0;
};
