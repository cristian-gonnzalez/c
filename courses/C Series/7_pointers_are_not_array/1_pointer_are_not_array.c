/** Pointer are not array
 *
 */
#include <stdio.h>

int main()
{
    //  Array: contiguous block of memory
    //
    //  int array[7]: [0, 1, 2, 3, 4, 5, 6, ]
    //                 0  1  2  3  4  5  6
    //
    int array[7];

    // Setting up our array
    for(int i=0; i<7; i++)
        array[i] = i;

    // Looping through our array
    printf("[");
    for(int i=0; i<7; i++)
        printf("%d, ", array[i]);
    printf("]\n"); // [0, 1, 2, 3, 4, 5, 6, ]
    
    // Printing the size of our array
    //
    //  sizeof(array) = 4 bytes * 7 elems = 28 bytes 
    //                  ~~~~~~~
    //                    ^
    //                 sizeof(int)    
    printf("array: %ld\n", sizeof(array)); // array: 28
    
    // Two equivalent ways, to create a pointer that points to the start of an array
    //
    //  int array[7]: [0, 1, 2, 3, 4, 5, 6, ]
    //                 0  1  2  3  4  5  6
    //                 ^
    //                 |
    //              int* parray  (A pointer just holds an address: &array[0])
    int* parray = array; // int* parray = &array[0]
    
    // Looping through our pointer
    printf("[");
    for(int i=0; i<7; i++)
        printf("%d, ", parray[i]);
    printf("]\n"); // [0, 1, 2, 3, 4, 5, 6, ]
    
    // Printing the size of our pointer
    // sizeof - When used on a pointer, returns the size of the pointer data type
    //          The size is typacally '8 bytes' on a 64-bit architecture
    printf("parray: %ld\n", sizeof(parray)); // parray: 8

    return 0; 
}
 