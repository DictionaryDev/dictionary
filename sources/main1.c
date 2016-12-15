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
  showHomeScreen();
	return 0;
};

void testCreateSimple()
{
  char* theDictionnary = "aDictionnary";
  int textSize = 3;
  char* text[] = {"oyoy", "tototto", "tata"};
}

void testLifeCycleFromFile()
{
  FILE* file = fopen("test", "r");
  char* theDictionnary = "aDictionnary";

  int sizeOfFile = getSizeOfThisFile(file);
  printf("taille du fichier text :%d\n",sizeOfFile);

  int* wordsLength;
  int sizeOfWordsLength;
  char** allWordOfThex = getAllWordFromTxt(file, &sizeOfWordsLength, wordsLength);

  printf("Création du dictionnaire\n");
  Dictionary* myDict = createDictionaryFromTxt(file, theDictionnary);
  printDictionary(*myDict);
  printf("%s",myDict->title);
  destroyDictionary(myDict);
  fclose(file);

}
