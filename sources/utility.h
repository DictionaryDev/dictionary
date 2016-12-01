int searchWord(char* filename, char* word);

char** getUniqWordFromTxt(FILE* text,int* sizeOfTable);
char** getAllWordFromTxt(FILE* text, int* sizeOfTableWord,int* sizeOfEachWords);
char** splitSentence(char* sentence,int sizeOfSentence,int* sizeOfAllWord, char splitter);

int getSizeOfThisFile(FILE* file);
int* getSizeOfEachWordOfTxtFile(FILE* text, int* size);

FILE* openFileRead(char*filename);
