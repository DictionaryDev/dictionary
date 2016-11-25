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


//Dictionnaire de 10 000 mots par défaut
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
    Dictionary* dico = malloc(sizeof(Dictionary));//{0, {0}, {""}};
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

Dictionary* newDictionaryWithTitleAndMax(char* title, int maxWords)
{
	Dictionary* dico = malloc(sizeof(Dictionary));//{0, {0}, {""}};

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

	return dico;
}
Dictionary* createDictionary(char *filePath) {
    if( isADictionary(filePath) == true ) {
        // si c'est un dictionnaire le lire.
        char confirm = '0';
        do {
           confirm = scanf("dictionary already exist. Erase it? (y/n)");
        }
        while (confirm != 'y' && confirm != 'n');
        if (confirm == 'y') {

            return newDictionaryWithTitle(filePath);
        } else {
            return NULL;//renvoyer a l'invite précédent
        }
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
void destroyDictionary(Dictionary* dictionary)
{
  FILE * file = fopen(dictionary->title, "w+");
	if(file != NULL && isADictionary(dictionary->title)) {
        remove(dictionary->title);
        stopUseDictionnary(dictionary);
  }
}
void stopUseDictionnary(Dictionary* dictionary) {
      free(dictionary->words);
      free(dictionary->lengthOfEachWord);
      free(dictionary);
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

int searchWord(char* filename, char* word) {
	FILE* file = fopen(filename, "r");
	int isItInDictionnary = 0;

	if(file != NULL) {
		fseek(file, 0, SEEK_END);
		int sizeFile = ftell(file);
		rewind(file);
		do {
			char* thisWordFromDictionnary;
			fscanf(file,"%s\n", thisWordFromDictionnary);
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
	int sizeOfAllWordFromText = 10000;

	char** allWordsFromText = getAllWordFromTxt(text, &sizeOfAllWordFromText);
	char** uniqWords = malloc(sizeof(char*) * sizeOfAllWordFromText);
	uniqWords[0] = allWordsFromText[0];
	/*int sizeUniqWords = 1;
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

	*sizeOfTable = sizeUniqWords;*/
	return uniqWords;
}

char** getAllWordFromTxt(FILE* text, int* sizeOfAllWord){

  int sizeOfText = getSizeOfThisFile(text);
	char bufferOfText[sizeOfText];
	fgets(bufferOfText, sizeOfText, text);

	//printf("%s",bufferOfText);
	char space = ' ';

  char** allWord = splitSentence(bufferOfText, sizeOfText, sizeOfAllWord, space);

	return allWord;
}

char** splitSentence(char* sentence,int sizeOfSentence,int* sizeOfAllWord, char splitter)
{
  int counterOfWords = 0;

  char** allWord = malloc(sizeof(char*) * 10000);
  int i;
  for(i = 0; i < 10000; i++)
    allWord[i] = malloc(sizeof(char) * 64);

  int counterSentence;
	int counterThisWord = 0;
	for(counterSentence = 0; counterSentence < sizeOfSentence; counterSentence++)
	{
		if(sentence[counterSentence] == splitter)
		{
			allWord[counterOfWords][counterThisWord] = '\0';
			counterThisWord = 0;

			counterOfWords++;
      printf("word %d = %c\n", counterOfWords, allWord[counterOfWords][counterThisWord]);
		}
		else
		{
			allWord[counterOfWords][counterThisWord] = sentence[counterSentence];
			counterThisWord++;
		}
	}
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
  int idx;
  printf("Number of words: %d\n", dictionary.length);
  for (idx = 0; idx < dictionary.length; ++idx) {
      printf("%d(%d): %s\n", idx + 1, dictionary.lengthOfEachWord[idx], dictionary.words[idx]);
  }
}
