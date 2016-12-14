#include <stdio.h>

/**
 * Function which aim to search a word into a dictionary representated by its @param filename
 * @param filename The filename which represent the dictionary
 * @param word The word to search
 * @return 0 if the word doesn't exist, 1 if the word exist
 */
int searchWord(char* filename, char* word);

/*
	Function that return all the unique words from a text with their respectives length
	"text" behing the focused text
	"sizeOfTable" the number of words returned
	"sizeOfEachWords" the length of each words
*/
char** getUniqWordFromTxt(FILE* text,int* sizeOfTable, int* sizeOfEachWords);

/*
  Function that return all the unique words from a text with their respectives length
  "text" behing the focused text
	"sizeOfTable" the number of words returned
	"sizeOfEachWords" the length of each words
*/
char** getAllWordFromTxt(FILE* text, int* sizeOfTableWord, int* sizeOfEachWords);

/*
  Function that return the total size of the file
  "file" behing the file focused
*/
int getSizeOfThisFile(FILE* file);

/*
  Function that return the size each word in a text
  "text" behing the text focused
  "size" behing the number of word
*/
int* getSizeOfEachWordOfTxtFile(FILE* text, int* size);
