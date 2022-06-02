#include "arraySort.h"


void swap(int *xp, int *yp){
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

void sort_integer_array(int *begin, int *end, int ascending){

    int *sortArr = begin;
    int n = end - begin;

        // Find the minimum element in unsorted array
    if (ascending) {
        for (int i = 0; i < n; i++) {
            int min_idx = i; // min_idx temporarily i, may later be replaced w/ true min j
            for (int j = i + 1; j < n; j++) {
                if (sortArr[j] < sortArr[min_idx])
                    min_idx = j;
            }

            // Swap the found minimum element with the first element
            swap(&sortArr[min_idx],&sortArr[i]); // why not working?
        }
    } else {
        for (int i = 0; i < n; i++) {
            int min_idx = i; // min_idx temporarily i, may later be replaced w/ true min j
            for (int j = i + 1; j < n; j++) {
                if (sortArr[j] > sortArr[min_idx])
                    min_idx = j;
            }
            // Swap the found minimum element with the first element
            swap(&sortArr[min_idx], &sortArr[i]);
        }
    }

}
