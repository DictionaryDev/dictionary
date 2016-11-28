#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

/**
 * Function which aim to search a word into a dictionary representated by its @param filename
 * @param filename The filename which represent the dictionary
 * @param word The word to search
 * @return 0 if the word doesn't exist, 1 if the word exist
 */
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
  char* word = malloc(sizeof(char) * 10000 * 20);
  int i;
  for(i = 0; i < 10000; i++)
    allWord[i] = &word[i * 20];

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
