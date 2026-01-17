/** Stack Memory:
 *
 *  It is a reserved place of memory for our function to execute and store data. 
 *  So it´s some sort of working memory for us where we can freely allocate variables 
 *  and then these variable will be reclaimed for us.
 *  
 *  The stack is where our 'temporary' (e.g. local variables) memory is stored. 
 *  The stack also stores information like where a function was called from (so we know where to
 *  return) and other things like function arguments
 *
 */
#include <stdio.h>


void bar()
{
    int d;
}

/*
 *        When calling                                    stack is freed
 *           foo()                                       when I leave foo()
 *        ___________                                       ___________
 *       |           |                                     |           |
 *       |   stack   |                                     |   stack   |
 *       |           |                                     |           | 
 *       |   bar()   | -> this is the return address       |           |       
 *       |   d       |                                     |           |       
 *       |   foo()   | -> this is the return address       |           |       
 *       |   arg     | -> function parameters              |           |
 *    ^  |   c=10    |                                     |           |       
 *    |  |   b=7     |                                     |           |       
 *    |  |   a=4     |                                     |           |       
 *       |___________|                                     |___________|
 *       |           |                                     |           |
 *       |   heap    |                                     |   heap    |
 *       |___________|                                     |___________|
 *       |           |                                     |           |
 *       |   data    |                                     |   data    |
 *       |___________|                                     |___________|
 *       |           |                                     |           |
 *       |   .text   | -> source code                      |   .text   |
 *       |___________|                                     |___________|
 *
 *   Local variables, return address and function arguments are push into the stack when calling 
 *   the function and then are pops out (cleared) when finish the function. 
 *
 *   If we go over the stack (this means, we go outs of the stack and enter to anoter region of 
 *   memory), we get a stack overflow (we call recursively and create infinite local variables)  
 *
 *   C is a pass-by-value language. Arguments are 'copied' when paased into functions. The copies 
 *   of our arguments are stored on the stack. This is why we cannot modify out arguments unless
 *   we pass an argument by pointer.  
 */
void foo(int arg)
{   // Block scope: Memory for local varibales is automatically created or reclaimed within the 
    // block in which was initialized everytime we call foo.
    // This means, every time we call foo(), the local varibale 'x' will be created

    int x = 4;     // local variable (only availble in foo )
    int b = 7;
    int c = 10;

    bar();

}  // when we hit this '}' curly brace, 'x' will be reclaimed or removed from memory


int main()
{
    for(int i=0; i < 100000; i++)
        foo(i);

    int x = 4;  // local variable (only available in the main function)
    return 0;
}
 