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
	FILE* file = fopen("test", "r");
	Dictionary* myDict = newDictionaryWithTitle(theDictionnary);
	printf("%s",myDict->title);
	fclose(file);
	return 0;
};