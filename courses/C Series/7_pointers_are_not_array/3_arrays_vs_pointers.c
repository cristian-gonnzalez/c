/** Are arrays and pointers the same?

 *
 */
#include <stdio.h>

int main()
{
    // Are arrays and pointers the same?
    // No: but we can trat an array 'like' a pointer
    int array[4];
    int* parray1 = array;

    // Can I treat an array like a pointer
    int* parray2;
    //int array2[4] = parray2;
    //                ~~~~~~~
    //                   ^
    //            error: invalid initializer

    return 0; 
}
 