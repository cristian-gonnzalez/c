/** calloc
 *
 *      For this lesson, make sure you understand stack vs heap:
 *
 *      - stack: automatically allocated memory, available in a block scope.
 *      - heap: memory that you manage explicity (using malloc/free)
 *
 *      calloc, the memory that we ask for is set to zero by default. This is a nice litle guarantee for
 *  us that the operating system is either going to look a place in memory where it might have a bunch
 *  of zeros allocated for us or otherwise just zero out all the memory perhaps using memset
 *
 *      
 *         void *calloc(size_t nelem, size_t elsize);
 *
 *
 *  calloc  - Allocates memory and zero fills the bytes.
 *  realloc - Attemtps to change the size of the allocation, copying as much the old data that will fit
 *           in the new allocation.
 *      reallocf - Same as realloc, but will 'free' passed pointer if we do not have enouth memory for
 *                 allocation.
 *  alloca - Allocate memory on the stack (memory reclaimed when scope leaves)
 *         - Often need to be carefil with this as stack size is limited (see 'limit')
 *         - Otherwose, a good optimization to avoid heap allocations when memory is truly meant to be
 *           on the stack and for a fast allocation.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // calloc

int main()
{ 
    // Observe that for 'calloc' the interface is different then the interface for malloc. I personally
    // like to always keep documentation up or frequently check so I minimize mistakes
    //
    // Allocates 7 char's, and zero-initializes the value
    //
    // NOTE: now we might pay a tiny cost actually zero initialize that's why most the time you will see 
    // folks just use malloc and then set the values
    //
    char* eight_bytes = (char*)calloc(8, sizeof(char));
                     // ~~~~~~        ^  ~~~~~~~~~~~~ -> size of element
                     // cast to    number of element 
                     // char*
    
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

    free(eight_bytes);

    return 0; 
}
 