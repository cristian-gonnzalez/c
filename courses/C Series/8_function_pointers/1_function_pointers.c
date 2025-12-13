/** Function pointers:
 *      The ability to store a function address of a specific function signature.
 *
 *      - Encapsulate (or hold) the behaviour of a function in a pointer.
 *
 *          int (* pfn)(int, int) = &add;
 *          ~~   ^ ~~~~ ~~~~~~~~~    
 *          ^    |  ^      ^                  
 *          |    |  |     Arguments
 *          |    |  |
 *          |    | name of the 
 *          |    | function pointer
 *          |    |
 *          |    |
 *          |  Because we are 
 *          |  initializying a pointer
 *          |
 *      return type 
 *   of the function 
 *   we are storing
 *
 *  Note: 'pfn' is a common prefix for function pointer data types that I have personally seen
 *  in large codebases. It is just a 'style' convention, but not a requirement.
 *   
 *  Note: objdump
 *      objdump is a neat tool that allows you to inspect binary files. It can be very useful when 
 *  debugging, or just trying to understand what is going on during the compilation process.
 *
 *      > objump -t prog
 *               ~~
 *                ^
 *           represents the symbol table    
 *
 *  Note: Output the assemby
 *
 *      > gcc -S main.c -> This will create this file called main.s
 *
 *      The assembly is a textual representation of binary.
 */
#include <stdio.h>

// add and multly has the same signature int func(int a, int b). This is important for this 
// example.

// Note: assembly
//     Looking the assembly, we notice some sort of add function (add:). This gives the idea that 
// this add function must live somewhere and that means add must have an address
//
// Note: objdump
//      Observe that 'add' has an 'F' in its row, indicating it is a function. You can then see 
// the actual address stored in the binary object file (i.e. the execvutable binary prog)
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
    // Functions have addreses too.
    printf("&add = %p\n", add );   // &add = 0x401126

    // Create a function pointer
    int (* pfn)(int, int) = &add;
    //int (* pfn)(int, int) = add; // Depending in your compiler, you can usually just directly
    //                                assing 'add' without puttin the & (address of)
    
    // Acces the add function thorugh our function pointer pfn
    printf("2 + 7 = %d\n", pfn(2, 7) );  // 2 + 7 = 9

    //printf("2 + 7 = %d\n", *pfn(2, 7) );  // error: invalid type argument of unary '*' (have 'int')
    //                       ^~~~~~~~~~
    //           No need to 'dereference' our function pointer, remember we are just returning
    //         an 'int' in this example.

    // Chnage to point to multiply
    pfn = multiply;
    printf("2 * 7 = %d\n", pfn(2, 7) );  // 2 * 7 = 14

    return 0; 
}
 