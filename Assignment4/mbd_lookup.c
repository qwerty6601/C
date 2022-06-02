#include "mdb.h"
#include "mylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// loads given file and puts data in linked list
int fillMdb(FILE *fp, struct List *llist) {
    struct MdbRec myRec; // has size of 40 specified in mdb.h
    struct Node *prevNode = NULL;
    int line = 0;
    initList(llist);

    // puts record into linked list memory
    // read from file fp nitems and store to myRec: (1) data, each sizeof(myRed) size
    while (fread(&myRec, sizeof(myRec), 1, fp) == 1) {
        struct MdbRec *data = malloc(sizeof(myRec)); // allocates space for myRec in heap
        if (data == NULL) {
            perror("malloc returned NULL");
            exit(1);
        }
        memcpy(data, &myRec, sizeof(myRec)); // copy from myRec to data (not strcpy cuz string isnt being copied)
        struct Node *newNode = addAfter(llist, prevNode, data); // add newNode w/ data after prev newNode into llist
        if (newNode == NULL) {
            perror("adding error"); // !!change error message
            exit(1);
        }
        prevNode = newNode;
        line++;
    }

    if (ferror(fp)) {
        perror("error reading file");
        exit(1);
    }

    return line;
}

// frees all allocated memory
void freedb(struct List *list) {
    struct Node *current = list->head;
    while(current != NULL) {
        current = current->next;
        free(popFront(list));
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) { // # of input args + 1 (?? for executable file rite?)
        fprintf(stderr, "%s\n", "usage: mdb_lookup.c <file_name>"); // ?? what <file_name> for?
        exit(1);
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "rb"); // b/rb not necc if I'm not using windows rite? but wut if grader is?

    if (fp == NULL) {
        perror(filename);
        exit(1);
    }

    // initialize and load list
    struct List dbList;
    initList(&dbList);
    fillMdb(fp, &dbList);  // fill contents from file fp into dbList

    // prints everything in list if user presses enter
    printf("%s", "lookup: ");
    fflush(stdout);
    char buff[1000];
    int maxChar = 5; // max (??first right?) 5 chars considered

    // searches for lookup keyword
    while(fgets(buff, sizeof(buff), stdin) != NULL) { // fgets enough since only reading String input from user
        char toFind[maxChar + 1]; // +1 bc after the max 5 chars, '\0\ must be added to convert to String
        if (strlen(buff) > maxChar) { // if input more than 5
            strncpy(toFind, buff, maxChar); // copy user input (buff) into toFind array
            toFind[maxChar] = '\0';
        } else { // ensures last char is not a newline character ?? by making last char \0 rite?
            strncpy(toFind, buff, strlen(buff));
            toFind[strlen(buff) - 1] = '\0';
        }

        // prints matching lookups from list
        struct Node *curr = dbList.head;
        int recNum = 1;
        while(curr != NULL) {
            struct MdbRec *recordData = (struct MdbRec *)curr->data;
            // strstr: Returns a pointer to the first occurrence of toFind in recordData->name/msg
            // ?? allowed to use for lab?
            if (strstr(recordData->name, toFind) != NULL || strstr(recordData->msg, toFind) != NULL) {
                // ?? dont need the 4 for formatting / aligning the output to 4 digits rite?
                printf("%4d: {%s} said {%s}\n", recNum, recordData->name, recordData->msg);
            }
            curr = curr->next;
            recNum++;
        }

        // asks for another toFind
        printf("\ntoFind: ");
        fflush(stdout);
    }

    while (fgets(buff, sizeof(buff), stdin) != NULL) { // read sizeof(buff) bytes from stdin into buff
        char toFind[maxChar + 1]; // +1 bc after the max 5 chars n '\0' must be added to convert to String
        if (strlen(buff) > maxChar) { // if input more than 5
            strncpy(toFind, buff, maxChar); // copy user input (buff) into toFind array
            toFind[maxChar] = '\0'; // makes toFind char array into String
        } else {
            strncpy(toFind, buff, strlen(buff));
            toFind[strlen(buff) - 1] = '\0';
        }
        struct Node *curr = dbList.head;
        int recNum = 1;
        while(curr != NULL) {
            struct MdbRec *recordData = (struct MdbRec *)curr->data;
            if (strcmp(recordData->name, toFind) || strcmp(recordData->msg, toFind)){
                printf("[%d] %s said %s\n", recNum, recordData->name, recordData->msg);
            }
            curr = curr->next;
            recNum++;
        }
        printf("to Find: ");

    }


    if (ferror(stdin)) {
        perror("stdin error");
        exit(1);
    }

    //deallocates memory
    freedb(&dbList);
    fclose(fp);
    return 0;
}
