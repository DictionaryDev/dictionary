/**
 * Function which aime to create a dictionary.
 * @param filename The file which will be created
 * @param listOfWords The list of words which the dictionary representated by its @param filename will contain.
 * @param sizeOfListOfWords The size of the given @param listOfWords
 */
void createDictionnary(char* filename, char** listOfWords, int sizeOfListOfWords);
/**
 * Fuction which aim to use a dictionary representated by its @param filename
 * @param filename The file name of the dictionary.
 */
void useExistingDictionnary(char* filename);
/**
 * Function which aim to create a dictionary from a text file
 * @param fileTxtName The text file which will be used to create a dictionary
 */
void createDictionnaryFromTxt(char* fileTxtName);
/**
 * Function wich aim to destroy the dictionary representated by its @param filename
 * @param filename The filename which represent the dictionary
 */
void destroyDictionnary(char* filename);
/**
 * Function which aim to insert a word into an existing dictionary representated by its @param filename
 * @param filename The filename which represent the dictionary
 * @param word The word to insert
 */
void insertWordIntoDictionnary(char* filename, char* word);
/**
 * Function which aim to search a word into a dictionary representated by its @param filename
 * @param filename The filename which represent the dictionary
 * @param word The word to search
 * @return 0 if the word doesn't exist, 1 if the word exist
 */
int searchWord(char* filename, char* word);