#include <stdbool.h>
#include "utility.h"
#define DICTIONARY_HEADER "/***** Dictionary *****/"

struct Dictionary {
	char* title;
	int length;
	int* lengthOfEachWord;
	char** words;
};
typedef struct Dictionary Dictionary;
/*
	Default Constructor of the Dictionnary
	- a title "default Dictionary"
	-a default capacity of 9000
*/
Dictionary* newDictionary();

/*
	Constructor of the Dictionnary giving :
	- his title
	- a default capacity of 9000
*/
Dictionary* newDictionaryWithTitle(char* title);

/*
	Constructor of the Dictionnary giving :
	- his title
	- his maximun capacity
*/
Dictionary* newDictionaryWithTitleAndMax(char* title, int maxWords);

/*
	Constructor of the Dictionary giving his :
	- title
	- his real length
	- his words
	- the length of each words
*/
Dictionary* newDictionaryWithEverything(char* title, int length, char** words, int* wordsLength);

/*
	use existing dictionary based on his title
*/
Dictionary* useDictionary(char* title);

/**
 * Function creating or using a dictionary a file dictionary based of if he exist or not
 * return a dictionnary
 * @param filename The file which will be created
 */
Dictionary* createDictionary(char *filePath);

/*
	Check if a file is a dictionnary
*/
bool isADictionary(char * filename);

/*
	write a table of characters into a dictionary
*/
void writeDictionary(Dictionary* dico,char** wordsToInput,int sizeOfWords);

/*
  Function which aim to create a dictionary from a text file
 	"file" the original text file
  "dico" the name of the dictionnary
 */
Dictionary* createDictionaryFromTxt(FILE* file, char* dico);

/*
	The dictionnary is stopped being used in the program
*/
void stopUseDictionnary(Dictionary* dictionary);

/**
 * both the inmemory dictionary and file dictionnary are destroyed
 * @param filename The filename which represent the dictionary
 */
void destroyDictionary(Dictionary* dico);

/*
	print all the word of dictionary
*/
void printDictionary(Dictionary);
