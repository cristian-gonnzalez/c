/** Passing 'size' information with arrays in functions
 *
 */
#include <stdio.h>

void print_array(int param[], size_t size)
//                ~~~~~~~~~~  ~~~~~~~~~~~~
//                    ^            ^
//                    |    We need to pass size information
//                decay to int*
{
    printf("[");
    for(int i=0; i<size; i++)
        printf("%d, ", param[i]);
    printf("]\n");

    
}


int main()
{
    int array[7];
    
    // Setting up our array
    for(int i=0; i<7; i++)
        array[i] = i;

    size_t array_size = (sizeof(array) / sizeof( (array)[0]) );
    //                   ~~~~~~~~~~~~~   ~~~~~~~~~~~~~~~~~~~
    //                       28        /        4             = 7
    print_array( array, array_size );  // [0, 1, 2, 3, 4, 5, 6, ]

    return 0; 
}
 