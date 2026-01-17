/** Pointer arithmetic
 *      When we are adding something that is a pointer, we are offsetting the size of that type
 */

#include <stdio.h>

int main()
{ 
    // Note: C is smart enough to figure out the size of our array.
    //       So we can use: int data[]  = {1,2,3,4,5,6} or
    //                      int data[6] = {1,2,3,4,5,6}
    int data[] = {1,2,3,4,5,6};

    printf("sizeof(int): %lu\n", sizeof(int) ); // sizeof(int): 4

    printf("[");
    for(size_t i=0; i<6; i++)
        printf("%d, ", data[i]);
    printf("]\n"); // [1, 2, 3, 4, 5, 6, ]

    //      ~  'i' is the offset that we are dereferencing
    // data[i]
    //     ^ ^ the brackets '[]' are dereferencing for us
    //
    // What it is actually doing is: *(data + i)
    // 

    printf("[");
    for(size_t i=0; i<6; i++)
        printf("%d, ", *(data+i));
    printf("]\n"); // [1, 2, 3, 4, 5, 6, ]


    printf("[");
    for(size_t i=0; i<6; i++)
        printf("%p, ", (data+i));
    printf("]\n"); // [0x7ffeac440e20, 0x7ffeac440e24, 0x7ffeac440e28, 0x7ffeac440e2c, 0x7ffeac440e30, 0x7ffeac440e34, ]
                   //              ~~              ~~              ~~              ~~              ~~              ~~   
                   // Notice that the addresses are moving by 4


    // Lets see with short
    short data2[] = {1,2,3,4,5,6};

    printf("sizeof(short): %lu\n", sizeof(short) ); // sizeof(short): 2

    printf("[");
    for(size_t i=0; i<6; i++)
        printf("%p, ", (data2+i));
    printf("]\n"); // [0x7ffd96f104b4, 0x7ffd96f104b6, 0x7ffd96f104b8, 0x7ffd96f104ba, 0x7ffd96f104bc, 0x7ffd96f104be, ]
                   //              ~~              ~~              ~~              ~~              ~~              ~~   
                   // Notice that the addresses are moving by 2

    return 0; 
}
 