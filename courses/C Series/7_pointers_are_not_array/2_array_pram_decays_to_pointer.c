/** Array parameter decays to a pointer
 *
 */
#include <stdio.h>

void print_array(int param[])
//               ~~~~~~~~~~~
//                   ^
//           array function parameter 'param' 
//         will be decaying to 'int *' even if
//         Im passing it with the array size
//         i.e int param[7]
{
    printf("[");
    for(int i=0; i<7; i++)
        printf("%d, ", param[i]);
    printf("]\n");

    // int param[] is 'decaying' to a pointer (type 'int* param'). In a way, this is very efficent,
    // because otherwise we would have to 'pass-by-value' and 'copy' the entire array.
    // Decaying a pointer, is very efficent but we do lose the 'size' information we may have had.
    printf("param: %ld\n", sizeof(param)); // param: 8
    
}

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

    print_array(array); // [0, 1, 2, 3, 4, 5, 6, ]
    
    // Printing the size of our array
    //
    //  sizeof(array) = 4 bytes * 7 elems = 28 bytes 
    //                  ~~~~~~~
    //                    ^
    //                 sizeof(int)    
    printf("array: %ld\n", sizeof(array)); // array: 28
    
    return 0; 
}
 