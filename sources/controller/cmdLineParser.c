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
    for (int i = 0; i < argCount; ++i) {
        if(strcmp(argList[i], "-h") == 0 || strcmp(argList[i], "--help") == 0) {
            printHelp();
        } else if (strcmp(argList[i], "create") == 0) {
            createDictionary(argList[i+1]);
        }
        //Continuer la serie de if et faire le mode interactif aussi
    }
}

void printHelp() {
    const char maskCommand[] = "%30s%50s";
    const char maskOption[] = "%20s%60s";
    printf("Usages of the dictionary tools\n\n");
    printf("dictionary -i| [COMMAND] ... [OPTION] ...\n\n");
    printf("COMMAND:\n");
    printf(maskCommand, "create [path]", "Create a dictionary from a file\n");
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