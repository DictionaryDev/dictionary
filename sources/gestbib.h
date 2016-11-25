#include <stdbool.h>
#include <stdio.h>

#define DICTIONARY_HEADER "/***** Dictionary *****/"

struct Dictionary {

	char* title;
    int length;
    int* lengthOfEachWord;
    char** words;
};
typedef struct Dictionary Dictionary;
/*
	Constructor of the Dictionnary
*/
Dictionary* newDictionary();
Dictionary* newDictionaryWithTitle(char* title);
Dictionary* newDictionaryWithTitleAndMax(char* title, int maxWords);

/**
 * Function which aime to create a file dictionary.
 * return a dictionnary with the path as title
 * @param filename The file which will be created
 */
Dictionary* createDictionary(char *filePath);

/*
	Check if a file is a dictionnary
*/
bool isADictionary(char * filename);

void writeDictionary(Dictionary* dico,char** wordsToInput,int sizeOfWords);

/**
 * Function which aim to create a dictionary from a text file
 * @param fileTxtName The text file which will be used to create a dictionary
 */
void createDictionaryFromTxt(char* filePath, char* fileTxtName);
/**
 * Function wich aim to destroy the dictionary representated by its @param filename
 * @param filename The filename which represent the dictionary
 */
void destroyDictionary(Dictionary* dico);
Dictionary* useDictionary(char* title);
void stopUseDictionnary(Dictionary* dictionary);

/**
 * Function which aim to search a word into a dictionary representated by its @param filename
 * @param filename The filename which represent the dictionary
 * @param word The word to search
 * @return 0 if the word doesn't exist, 1 if the word exist
 */
int searchWord(char* filename, char* word);


void printDictionary(Dictionary);

char** getUniqWordFromTxt(FILE* text,int* sizeOfTable);
char** getAllWordFromTxt(FILE* text, int* sizeOfAllWord);
int getSizeOfThisFile(FILE* file);
