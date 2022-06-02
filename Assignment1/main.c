/*#include <stdio.h>
#include "gcd.h"
#include "prime.h"

float avg(int x, int y){
    printf("%d\n", (x+y)/2); // why x+y where x = 6, y = 8 -> 2?
    return (x+y)/2;
}
int main(){
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    avg(x,y);
    printf("GCD(%d, %d) = %dn\n", x, y, gcd(x, y));
    int greatestCD = gcd(x,y);
    printf("%s\n", "Are the 2 numbers relatively prime?");
    if (greatestCD == 1){
        printf("%s\n", "Yes!");
    } else {
        printf("%s\n", "No :(");
    }

} */

#include <stdio.h>
#include "gcd.h"
#include "prime.h"

int main(){
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);
    printf("%f\n", ((x+y))/ 2.0); // print out avg ?? why no \n after print avg?
    printf("%d\n", gcd(x,y));
    printf ("%s\n", "Are the 2 numbers relatively prime?");
    if (gcd(x,y) == 1){
        printf("%s\n", "Yes, they're relatively prime!");
    } else {
        printf("%s\n", "No, they're not.");
    }
    isPrime(x);
    isPrime(y);
}

