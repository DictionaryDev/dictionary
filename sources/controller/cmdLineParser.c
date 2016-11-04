//
// Created by Sephy on 18/10/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "cmdLineParser.h"
#include "gestbib.h"


void parseCMDLine(int argCount, char * argList[]) {
    if (argCount == 1) {
        printHelp();
        return;
    }
    Dictionary dictionary = newDictionary();
    for (int i = 1; i < argCount; ++i) {
        if(strcmp(argList[i], "-h") == 0 || strcmp(argList[i], "--help") == 0) {
            printHelp();
            return;
        } else if (strcmp(argList[i], "-i") == 0 || strcmp(argList[i], "--interactive") == 0) {
            //TODO faire le mode interactif
        } else if (strcmp(argList[i], "create") == 0) {
            createDictionary(argList[i + 1]);
        } else if (strcmp(argList[i], "create-from-txt") == 0) {
            dictionary = createDictionaryFromTxt(argList[i+1]);
        } else if (strcmp(argList[i], "delete") == 0) {
            destroyDictionary(argList[i + 1]);
        } else if (strcmp(argList[i], "insert") == 0) {
            insertWordIntoDictionnary(argList[i + 1], argList[i + 2]);
        } else if (strcmp(argList[i], "search") == 0) {
            searchWord(argList[i + 1], argList[i + 2]);
        }
        //Continuer la serie de if et faire le mode interactif aussi
        if (strcmp(argList[i], "-o") == 0 || strcmp(argList[i], "--output") == 0) {
            if(dictionary.length == 0) {
                printf("Dictionary is empty, creating an empty one at: %s\n", argList[i + 1]);
                createDictionary(argList[i + 1]);
            } else {
                printf("Writing Dictionary to: %s\n", argList[i + 1]);
                writeDictionary(argList[i + 1], dictionary);
            }
        } else {
            printDictionary(dictionary);
        }
    }
}

void printHelp() {
    const char maskCommand[] = "%30s%50s";
    const char maskOption[] = "%20s%60s";
    printf("Usages of the dictionary tools\n\n");
    printf("dictionary -i| [COMMAND] ... [OPTION] ...\n\n");
    printf("COMMAND:\n");
    printf(maskCommand, "create [path]", "Create a dictionary from a file\n");
    printf(maskCommand, "create-from-txt [txt-file]", "Make a dictionary from a text file\n");
    printf(maskCommand, "delete [file]", "Delete the given dictionary\n");
    printf(maskCommand, "insert [file] [word]", "Insert a word into a dictionary\n");
    printf(maskCommand, "search [file] [word]", "Search a word into a dictionary\n");
    /**
     * Not implemented yet
     */
    //printf(maskCommand, "search-near [file] [word] [amount]", "Search a word and all near word into a dictionary\n");
    /**
     * Not implemented yet
     */
    //printf(maskCommand, "search [file] [regexp]", "Search a word into a dictionary\n");
    printf("\n\n");
    printf("OPTIONS:(Option which modify input or output of the software)\n");
    printf("\n");
    printf(maskOption, "--interactive -i", "Ignore all options and enter into interactive mode\n");
    printf(maskOption, "--output -o [path]", "Store output into the given file (default: terminal)\n");
    printf(maskOption, "--help -h", "Print help");
}