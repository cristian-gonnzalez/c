/** Custom array_t data type
 *
 *      The goal here is to build a new array_t data type that will store size along with a heap 
 *  allocated array.
 */
#include <stdio.h>
#include <stdlib.h> // malloc/free

typedef struct array
{
    // This is the array
    int* data;

    // The max capacity
    size_t max_elems;

    // The number of elems
    size_t num_elems;

} array_t;


// This is like a 'constructor'
array_t* array_init(size_t size)
{
    // Allocating array_t in the heap
    array_t* array = (array_t*) malloc( sizeof(array_t) );

    array->num_elems = 0;
    array->max_elems = size;
    array->data = (int*) malloc( sizeof(int)*size );

    return array;
}

// This is like a 'destructor'
void array_delete(array_t* array)
{
    free(array->data);
    array->data = NULL;
    array->max_elems = 0;
    array->num_elems = 0;

    free(array);
}

int array_add(array_t* array, int value)
{
    if( array->num_elems + 1 > array->max_elems) 
        return -1;

    array->data[ array->num_elems ] = value;
    array->num_elems++;

    return 0;
}

void array_print(const array_t* array)
{
    printf("[");
    for(int i=0; i<array->num_elems; i++)
        printf("%d, ", array->data[i]);
    printf("]\n");
}


int main()
{
    array_t* data = array_init( 8 );

    for(size_t i=0; i<8; i++)
        array_add(data, i);
    
    array_print( data ); // [0, 1, 2, 3, 4, 5, 6, 7, ]

    array_delete(data);
    return 0; 
}
 