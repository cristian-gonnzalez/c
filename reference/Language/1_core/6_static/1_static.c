/** Static
 *
 *  Static variables:
 * 
 *    'static' means the duration of the variable is 'forever' (static-storage duration).
 *  The memory for that variable is reserved within the actual binary (.bss or .data).
 *  The scope of that variable is where the variable is declared. 
 * 
 *    It also applies to global variables.
 *
 *  Static function:
 * 
 *     'static' means sth different in functions. it gives internal linkage meaning that it is 
 *  only used in the file where is defined 
 * 
 *     Making static a global variable, it also gives internal linkage.
 * 
 *  Static storage:
 *
 *      > objdump -t ./prog       -> This allows me to see where the 'static storage' actually is
 * 
 *      The static varibales are stored in the .bss section that's how they can persist forever
 */

#include <stdio.h>

// If you must have a global variable, making them 'static' limits the usage to the current file
// -- internal linkage (i.e. main.c in this case). This is more safe way to have a global state 
// in you program
static int global = 100;

int function()
{
    static int i = 0;
    //           ~~~
    // 'static' variables are initialized exactly one time.
    //
    // The first time it is called, it'll be set to zero but any subsequence times that we call this
    // function i's value is perserved
    //
    // NOTE: the scope of this static variable is still within this function, we cannnot use it anywhere
    // outside of the scope  

    printf( "%d, ", i++ );

    return 0;
}

static void s_fun(void) 
//~~~~
//  When applied to a function, 'static' does NOT mean static storage duration.
//  it means it can only be used within this source file -- internal linkage. 
// 
// Note:
//   Therefore, when we want to restrict access to functions, we make them static. 
//
//   Another reason for making functions static can be the reuse of the same function 
// name in other files.
{ 
  printf("\nI am a static function \n"); 
}

int main()
{   
    for(int i=0; i<10; i++)
        function();  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 

    s_fun(); // I am a static function 

    return 0; 
}
 