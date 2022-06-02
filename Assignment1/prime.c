#include <stdio.h>
#include "prime.h"


int isPrime(int n){
    if (n <= 1){
        printf("%d is not a prime number\n", n);
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            printf("%d is not a prime number\n", n);
            return 0;
        }
    }

    printf("%d is a prime number\n", n);
    return 0;
}