/** Simulating OOP in C:
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct array
{
    // Pointer to 'self'
    // In other languages, called 'this'
    // This is not neccesary but give us an idea of oop
    struct array* self;

    // Actual member variables
    int* data;
    size_t size;


    // 'Member functions' or 'methods' that we implement from scratch.
    // Could embed these in another strcut to change behaviour of a different functions-
    void (* set_cb)( struct array*, size_t, int);
    int (* get_cb)( struct array*, size_t);

} array_t;

// In C, we have to pass-by-value (or pass-by-pointer) to modufy our struct
int array_get(array_t* self, size_t index)
{
    return self->data[index];
}

// In C, we have to pass-by-value (or pass-by-pointer) to modufy our struct
void array_set(array_t* self, size_t index, int value)
{
    if( self == NULL)
        return;
    if( index >= 0 && index < self->size )
        self->data[index] = value; 
}

// Array constructor
// Using a 'factory method' 
array_t* make_array(size_t capacity)
{
    array_t* array = (array_t*)malloc( sizeof(array_t) );

    // store the pointer back to the memory that holds our actual object
    array->self = array;
    array->data =  (int*)malloc( sizeof(int)*capacity );
    array->size = capacity;

    // Set up the function pointers
    array->set_cb = array_set;
    array->get_cb = array_get;
}

void array_destroy(array_t* self)
{
    free(self->data);
    free(self);
}


int main()
{   
    array_t* test = make_array(10);

    // Set all of the values
    for(size_t i=0; i< test->size; i++)
        test->set_cb( test->self, i, i);

    // Get all of the values
    printf("[");
    for(size_t i=0; i< test->size; i++)
        printf( "%d, ", test->get_cb( test->self, i) );
    printf("]\n");  // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ]
    
    array_destroy( test );

    return 0; 
}
 