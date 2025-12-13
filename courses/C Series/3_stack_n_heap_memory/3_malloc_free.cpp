/** Malloc/Free: Allocating memory on the heap in a separate function
 *
 */
#include <stdio.h>
#include <stdlib.h>  // contains malloc/free


int* allocate_on_heap(int size)
{
    int* array = (int*) malloc( sizeof(int)*50000 );
    //   ~~~~~
    //     ^
    //   This is just a local variable. It happens to point to the start of a block of memory
    // that has beem allocated on the heap.
    //
    //   When I return from this function this local variable goes away but the actual memory 
    // we allocate will live on forever 

    printf("heap memory address          : %p\n", array );  // heap memory address          : 0x7bad08a86010
    printf("stack memory of local (array): %p\n", &array ); // stack memory of local (array): 0x7ffdb9a09518


    return array;
}

int main()
{
    int size = 10;
    int* heap_data = allocate_on_heap(size);
    //   ~~~~~~~~~
    //     ^
    //   This is just a local variable. It happens to point to the start of a block of memory
    // that has beem allocated on the heap.
    //
    // Note: Local variables created in the stack memory starts with 0x7ffdXXXX that are relatively  
    // close in location but heaps memory is 0x7ba wildly different thats because there is some sort
    // of distance on the stack memory versus the heap memory

    printf("heap memory address              : %p\n", heap_data );  // heap memory address              : 0x7bad08a86010
    printf("stack memory of local (heap_data): %p\n", &heap_data ); // stack memory of local (heap_data): 0x7ffc2f94b330

    for(size_t i=0; i<size; i++)
        heap_data[i] = i + 15;
    
    printf("heap_data = [");
    for(size_t i=0; i<size; i++)
        printf("%d, ", heap_data[i]);   
    printf("]\n");
    // heap_data = [15, 16, 17, 18, 19, 20, 21, 22, 23, 24, ]

    free(heap_data);

    // Note: why are pointers important?
    //    Because we can point to chuncks of memory allocated in the heap.
    //    We can point to things in the stack but that's kind of dangerours since local variable are only 
    //    temporary. If we hacve a pointer that points to specific stack block and this block gets cleared
    //    away, then we dont know whats in a block

    return 0;
}
 