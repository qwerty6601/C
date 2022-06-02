#include <stdio.h>
#include <math.h>
/*int main()
{
    int x = -1;

    printf("printf-ing -1 as %%d: %d\n", x);
    printf("printf-ing -1 as %%u: %u\n", x);
    printf("printf-ing -1 as %%x: %x\n", x);

    return 0;
} */

int main(){
    int a;

    scanf("%d", &a);
    printf("signed dec:   %d\n", a);
    printf("unsigned dec: %u\n", a);
    printf("hex:          %x\n", a);
    printf("binary:       ");

    // for getting binary version
    int start = 31; // 32 - 1 (since starts at index 0) = 31 // ?? output should always be in 32-bit format right?

    for (int i = start; i >= 0; i--) {
        printf("%d", 1 & (a >> i));
        if (i % 4 == 0)
            printf(" ");
    }
    // Can't do this way where sth other than the 0th bit is printed, bc zB if 0001, 0010, 0100,
    // it wont print 1 1 1 but rather 1 2 4; also can't start w/ rightmost bit and go left
    // (can't make i from 0 to start) bc then bits would be printed in reverse (leftmost bit must
    // be printed first

   /* for (i = 0; i < 32; i++) {
        printf("%d", a & (1 << i));
        if (i % 4 == 0)
            printf(" ");
    } */

   // 0 0 0 0 0 0 0 1
   // a: 1 1 0 1 1 0 0 0
   // a >> 31
    printf("\n");
    return 0;
}