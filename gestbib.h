void createDictionnary(char* filename, char** listOfWords, int sizeOfListOfWords);
void useExistingDictionnary(char* filename);
void createDictionnaryFromTxt(char* fileTxtName);
void destroyDictionnary(char* filename);
void insertWordIntoDictionnary(char* filename, char* word);
int searchWord(char* filename, char* word);