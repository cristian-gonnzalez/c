/** Pointers (creating pointers and dereferencing)
 *
 *      A pointer simple stores an address to a particular type.
 */
#include <stdio.h>


int main()
{
    int x = 42;

    // Prints out the 'address'
    // That's what %p - format specifier gives us 
    printf("Address of x is %p\n", &x);    // Address of x= 0x7ffe7a711e74
    
    // Creating a pointer
    int* px = &x;

    printf("px is                        : %p\n", px);                     // px is          : 0x7ffe7a711e74
    // Accessing the value, to the thing we point to
    printf("*px, the thing we point to is: %d\n", *(px) );       // *px, the thing we point to is: 42
    //                                            ~
    //                                            ^
    //                                        Dereferencing
    printf("size of an address           : %d bytes\n", sizeof(px) );  // size of an address           : 8 bytes
    printf("size of int                  : %d bytes\n", sizeof(int) ); // size of int                  : 4 bytes

    return 0;
}
 