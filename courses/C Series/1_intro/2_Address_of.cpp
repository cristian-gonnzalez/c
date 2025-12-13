/** Address of (& operator)
 *
 */
#include <stdio.h>


int main()
{
    int x = 42;

    // Prints out the 'address'
    // That's what %p - format specifier gives us 
    printf("Address of x= %p\n", &x);    // Address of x= 0x7ffc7a31096c
    // If we want the value, in (&x)
    printf("Value of x= %d\n", *(&x) );  // Value of x= 42
    //                         ~
    //                         ^
    //                    Look inside the address

    return 0;
}
