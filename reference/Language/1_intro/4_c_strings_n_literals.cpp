/** C strings and string literals
 *
 */
#include <stdio.h>
#include <string.h>


int main()
{
    // There is a difference between 
    //
    // char* a    This is a literal string you cannot change 
    //
    // char a[]   This is an array we can change the values
    //

    // Declaring a string literal
    char* s = (char*)"hello"; // "hello\0"

    //s[0] = 'b'; // Program terminated with signal: SIGSEGV

    puts(s);  // hello

    char a[] = "hello";

    puts(a);  // hello

    a[0]= 'b';
    printf("a[0]= %c\n", a[0]); // a[0]= b

    printf("length of string s is: %ld\n", strlen(s) );  // length of string s is: 5
    //                             ~~~     ~~~~~~~~~
    //                              ^         ^
    //                           long int    size_t (aka long unsigned int)
    printf("length of string a is: %ld\n", strlen(a) ); // length of string s is: 5

    return 0;
}
 