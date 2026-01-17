/** realloc
 *
 *      Attemtps to change the size of the allocation, copying as much the old data that will fit
 *  in the new allocation.
 *      reallocf - Same as realloc, but will 'free' passed pointer if we do not have enouth memory for
 *  allocation.
 *
 *          void *realloc(void *ptr, size_t size);
 *
 *      When I realloc, the new allocation could be smaller or larger. 
 *      
 *  Scenario 1:
 *
 *      calloc                          realloc( eight_bytes, 4)
 *   [0 ,0 ,0 ,0 ,0 ,0 ,0, 0]         ->   [0 ,0 ,0 ,0]    
 *    ^                                     ^
 *    |                                     |
 *  |___| ---------------------------------- 
 *  eight_bytes
 *
 *      The example of realloc will give me or reallocate our original memory and just take 
 *  the 4 firts bytes and now the pointer points to the start of this smaller block of memory
 *
 *
 *  Scenario 2:
 *
 *      If the new size is larger than the old size, the added memory will not be initialized.
 *
 *      calloc                          realloc( eight_bytes, 17)
 *   [0 ,0 ,0 ,0 ,0 ,0 ,0, 0]         ->   [0 ,0 ,0 ,0, 0 ,0 ,0 ,0,  ,  ,  , ,  ,  ,  , ]    
 *    ^                                     ~~~~~~~~~~~~~~~~~~~~~~ ^^^^^^^^^^^^^^^^^^^^^
 *    |                                     ^    old content            garbage
 *    |                                     |
 *  |___| ---------------------------------- 
 *  eight_bytes
 *
 *      That's going to copy all the old content and then we dont kwnow wht's in the next memory
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // calloc/realloc

int main()
{ 
    // Allocates 7 char's, and zero-initializes the value
    char* eight_bytes = (char*)calloc(8, sizeof(char));
    
    size_t i= 0;
    printf( "[" );
    while( i<8 )
    {
        printf("%d, ", eight_bytes[i] );
        i++;
    }
    printf( "]\n\n" ); // [0, 0, 0, 0, 0, 0, 0, 0, ]

    memset(eight_bytes, 65, 8); 

    i= 0;
    printf( "[" );
    while( i<8 )
    {
        printf("%d, ", eight_bytes[i] );
        i++;
    }
    printf( "]\n\n" );  // [65, 65, 65, 65, 65, 65, 65, 65, ]


    eight_bytes = (char*)realloc(eight_bytes, 16*sizeof(char));
    i= 0;
    printf( "[" );
    while( i<16 )
    {
        printf("%d, ", eight_bytes[i] );
        i++;
    }
    printf( "]\n\n" );  // [65, 65, 65, 65, 65, 65, 65, 65, 0, 0, 0, 0, 0, 0, 0, 0, ]
    //                                                      ~~~~~~~~~~~~~~~~~~~~~~
    //  It will not always be the case that yuor memory is filled with zeroes. Again, use calloc 
    // or memset to explicity set your memory to zero.
    // In this example we got 'lucky' that the memory we acquired was 0. 


    free(eight_bytes);

    return 0; 
}
 