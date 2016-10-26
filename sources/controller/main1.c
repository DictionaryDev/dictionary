/*
**Filename: main1.c
**
**Made by : Fairfort Yohan
**
**Description : main de test de gestbib.c
**
*/

#include <stdio.h>
#include <stdlib.h>
#include "gestbib.h"
#include "cmdLineParser.h"

int main(int argCount, char* argList[]) {
    parseCMDLine(argCount, argList);
	return 0;
};

