/** void* pointers (void* to function pointer)
 *
 *      Recall, a pointer simple stores an address to a particular type.
 *
 *      void* is a 'generic pointer' that can hold any data type.
 *      
 *
 *  void* - Generic pointer
 *  ~~~~~
 *      ^
 *      |- Point to anything
 *              |-> any object/type
 *              |-> even functions 
 */

#include <stdio.h>

void print()
{
    printf("Called the 'print' function\n");
}

int return42()
{
    return 42;
}

int add(int a, int b)
{
    return a+b;
}

int main()
{   
    // void* to a int*
    int x = 500;
    void* generic_pointer = &x;

    printf("x is %d\n", *(int*)generic_pointer); // x is 500
    //                    ~~~~
    // void* pointers cannot be dereferenced, we need to cast them to the correct type first.

    // void* to a void function
    generic_pointer = print; // generic_pointer = &print

    // By rule, with void* we need to cast to the correct type. That makes dangerous!!!
    // generic_pointer(); // error: called object 'generic_pointer' is not a function or function pointer
    ( (void (*)())generic_pointer )(); // Called the 'print' function
    // ~~~~~~~~~~
    // Casting to the signature of print function

    generic_pointer = return42;
    int result = ( (int (*)())generic_pointer )();

    printf("result is %d\n", result); // result is 42

    generic_pointer = add;
    result = ( (int (*)(int, int))generic_pointer )(2, 5);

    printf("result is %d\n", result); // result is 7

    return 0; 
}
 