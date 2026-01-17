/** sizeof - Size of stack variable > heap variable
 *
 *      Stack allocated array (fixed-size) the compiler can tell us the number of bytes.
 *      For Heap allocated data, sizeof is really just returning us the size of the pointer type 
 *  sizeof(int*) = 8, which is also stack allocated (thus not the number of bytes from malloc)
 */

#include <stdio.h>
#include <stdlib.h> // malloc/free

int main()
{ 
    // Creates an array in the stack.
    int data[] = {1,2,3,4,5,6};

    printf("sizeof(int)  : %lu\n", sizeof(int) ); // sizeof(int): 4

    // this works 'sizeof(data)' if 'data' is stack allocated.
    printf("sizeof(data) : %lu\n", sizeof(data) ); // sizeof(data): 24

    size_t num_elems = sizeof(data) / sizeof(int);  
    printf("number of elements of data: %ld\n", num_elems ); // num_elems: 6


    // Creates an array in the heap.
    int* hdata = (int*)malloc(sizeof(int)*6);

    printf("sizeof(hdata): %lu\n", sizeof(hdata) ); // sizeof(hdata): 8
    //                                                                ^
    //                                                        size of the pointer type

    num_elems = sizeof(hdata) / sizeof(int);
    //          ~~~~~~~~~~~~~ ^ ~~~~~~~~~~
    //division 'sizeof (int *) / sizeof (int)' does not compute the number of array elements 
    // [-Wsizeof-pointer-div]

    printf("number of elements of hdata: %ld\n", num_elems ); // number of elements of hdata: 2
    //                                                                                        ^
    //                                                                                   Incorrect


    free(hdata);

    return 0; 
}
 