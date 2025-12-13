/** Heap Memory:
 *
 *  - Large storage
 *  - Variables and data structures that are going to be long-lived (this means that is going
 *    to live until we say to free this memory)
 *  - We allocate and free this memory 
 *
 *  When you think 'heap memory' you can associate that with malloc/free (malloc and free are 
 *  used in conjuntion).
 *
 *  This region might expand or decrease based on of how many allocations that we do
 */
#include <stdio.h>
#include <stdlib.h>  // contains malloc/free


int main()
{
 
    // Note:
    //    Remenber that heap is big so that means we can store losts of data.
    // On the stack region, if we sotre 50000 of sth, that might be actually 
    // too big for our stack and then we can get stack overflow.

    // Note2:
    //      void* malloc(size_t size);     void means no return type but 
    //      ~~~~~                          void* actually means any data type since we are
    //        ^                            returning a pointer
    //  This means any data type

    // this will allocate somewhere in the heap region a block of 50000*sizeof(int) and
    // we get a pointer to the start of that block
    int* array = (int*) malloc( sizeof(int)*50000 );
    //           ~~~~~~
    //             ^
    //        I will cast explicity to the type I need since malloc return any data type

    // malloc and free are used in conjuntion
    free(array);

    //
    //         malloc                                             free
    //        ___________                                       ___________
    //       |           |                                     |           |
    //       |   stack   |                                     |   stack   |
    //       |___________|                                     |___________|
    //       |  ______   |                                     |           |
    //       | |______|<-|---|______|                          |           |
    //       |  50000    |      ^                              |           |
    //       |           |    int* array                       |           |
    //       |   heap    |                                     |   heap    |
    //       |___________|                                     |___________|
    //       |           |                                     |           |
    //       |   data    |                                     |   data    |
    //       |___________|                                     |___________|
    //       |           |                                     |           |
    //       |   .text   | -> source code                      |   .text   |
    //       |___________|                                     |___________|
 
    return 0;
}
 