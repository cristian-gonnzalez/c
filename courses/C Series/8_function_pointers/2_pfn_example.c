/** Example of function pointers:
 *
 *      While the program is running, anywhere we have 'pfn' we can reassing that pointer, thus
 *  chanfing the behaviour of our program. This is very comon in event-driven programming. 
 *      Function pointers can also be passed as arguments into functions as well.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int a, int b)
{
    return a+b;
}

int multiply(int a, int b)
{
    return a*b;
}

int main()
{   
    srand( time(NULL) );

    // We have a function pointer
    int (* pfn)(int, int) = NULL;
    
    // Generate a random number
    int random_num = rand() % 2 + 1;

    // Do something, based off of the input
    if( random_num == 1)
    {
        pfn = add;
        printf("2 + 7 = %d\n", pfn(2, 7) );  // 2 + 7 = 9
    }
    else {
        pfn = multiply;
        printf("2 * 7 = %d\n", pfn(2, 7) );  // 2 * 7 = 14
    }

    return 0; 
}
 