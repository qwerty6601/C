#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arraySort.h"

int main() {
	int numInts;
	scanf("%d", &numInts);

	int a[3];
    srandom(time(NULL));
    int i; // why need to declare integer separately here?
    for (i = 0; i < 3; i++){
        int toInput = random() % 100;
        printf("Random value = %d\n", toInput);
        a[i] = toInput;
    }
    printf("XXXXX");
    // allocate space for asc array
	int *aUp = malloc(numInts * sizeof(int));
    // check return value of malloc()
    if (aUp == NULL){
        perror("malloc returned NULL");
        exit(1);
    }
    // copy original array's contents into asc array
	for(int i = 0; i < numInts; i++)
        aUp[i] = a[i];
	// sort array
    sort_integer_array(aUp, a + numInts, 1); // do the changes from here get saved?

    printf("Sarah 1112");
    // allocate space for desc array
	int *aDesc = malloc(numInts * sizeof(int));
    // check return value of malloc()
    if (aDesc == NULL){
        perror("malloc returned NULL");
        exit(1);
    }
    for(int i = 0; i < numInts; i++)
        aDesc[i] = a[i];
	sort_integer_array(aDesc, aDesc + numInts, 0); // Descending sort
	// ;
	printf("original:  ");
    for (int i = 0; i < numInts; i++)
        printf(" %d", a[i]);
    printf("\n");
    printf("descending:  ");
    for (int i = 0; i < numInts; i++)
        printf(" %d", aDesc[i]);
    free(aDesc);
    printf("\n");
    printf("ascending:  ");
    for (int i = 0; i < numInts; i++)
        printf(" %d", aUp[i]);
    free(aUp);
    printf("\n");
}
