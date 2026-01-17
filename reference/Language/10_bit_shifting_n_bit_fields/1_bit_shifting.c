/** Bit shifting
 *
 *  NOTE: this is important because we can multiply/double quickly and divide quickly as well.
 *  This is a very efficient operation fr us to perform on our machine. Its much cheaper than 
 *  actually going though and doing a multiplication or divide 
 */

#include <stdio.h>

int main()
{   
    // The left shift (<<) operation multiplies by 2 for every bit shifted
    int x = 1;
    printf("x is: %d\n", x); // x is: 1
    x = x << 1;
    printf("x is: %d\n", x); // x is: 2
    x = x << 1;
    printf("x is: %d\n", x); // x is: 4
    x = x << 1;
    printf("x is: %d\n", x); // x is: 8
    x = x << 1;
    printf("x is: %d\n", x); // x is: 16

    // The rigth shift (>>) operation divides by 2 for every bit shifted
    x = 64;
    printf("x is: %d\n", x); // x is: 64
    x = x >> 1;
    printf("x is: %d\n", x); // x is: 32
    x = x >> 1;
    printf("x is: %d\n", x); // x is: 15
    x = x >> 1;
    printf("x is: %d\n", x); // x is: 8
    x = x >> 1;
    printf("x is: %d\n", x); // x is: 4
   
    return 0; 
}
 