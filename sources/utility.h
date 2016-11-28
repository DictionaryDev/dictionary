int searchWord(char* filename, char* word);

char** getUniqWordFromTxt(FILE* text,int* sizeOfTable);
char** getAllWordFromTxt(FILE* text, int* sizeOfAllWord);
char** splitSentence(char* sentence,int sizeOfSentence,int* sizeOfAllWord, char splitter);

int getSizeOfThisFile(FILE* file);
FILE* openFileRead(char*filename);
