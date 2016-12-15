/*
**Filename: gestrech.h
**
**Made by : Baugue Florian, Fairfort Yohan
**
**Description : Partie 2 du dictionnary
**
*/

// programme controle
void searchSimilarWords(char* wordUse, int seuil);

// afficher les resultats
void showSimilarWords(char** affinedList, int count);

// trie les mots selon leur seuil de similarité
char** testSeuilSimilarWords(char** affinedList,char** totalList, char* wordUse, int *count, int seuil);

// charge la liste des mots dans un ou plusieurs dictionnaire(s) 
char** downloadListWords(char** totalList);

// Liste de test
char** imitationListWords(char** totalList);

// compte les différences
int countDiff(char* wordExam, char* wordUse);





