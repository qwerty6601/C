#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **duplicateArgs(int wordsCount, char **words) {
    char **copiedWords = (char **)malloc((wordsCount + 1) * sizeof(char *));
    int i = 0;
    while(*(words + i)!= 0) {
        int wordLength = strlen(words[i]); // after one word++, := (&originalWord[1])[0] , so 2nd element of array
        copiedWords[i] = (char *)malloc((wordLength + 1) * sizeof(char));

        for(int j = 0; j <= strlen(copiedWords[i]); j++) {
            copiedWords[i][j] = toupper(words[i][j]);
        }
        i++;
    }
    copiedWords[i] = NULL;
    return copiedWords;
}

void freeDuplicatedArgs(char **addressToBeFreed)
{
    int i = 0;
    while(addressToBeFreed[i] != 0) {
        free(addressToBeFreed[i]);
        i++;
    }
    free(addressToBeFreed);
}


int main(int argc, char **argv)
{
    if (argc <= 1)
        return 1;

    char **copy = duplicateArgs(argc, argv);
    char **p = copy;

    argv++;
    p++;

    while (*argv) {
        printf("%s %s\n", *argv++, *p++);
    }
    freeDuplicatedArgs(copy);
    return 0;
}

