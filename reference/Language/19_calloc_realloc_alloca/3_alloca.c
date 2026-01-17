/** alloca
 *
 *      Allocate memory on the stack (memory reclaimed when scope leaves)
 *      Often need to be carefil with this as stack size is limited (see 'limit')
 *      Otherwose, a good optimization to avoid heap allocations when memory is truly meant to be
 *  on the stack and for a fast allocation.
 *
 *
 *  > ulimit -a   -> print out your actual stack size 
 *  ...
 *  stack size              (kbytes, -s) 8192
 *  ~~~~~
 *  ...
 *
 *      alloca is very efficient compared to mallof for instance (stack memory is quite fast). So if 
 *  you need to allocate a variable size block of memory that is relatively small, and does not need 
 *  to live a long duration -- consider alloca.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>  // toupper
#include <stdlib.h> // alloca


void print_upper_case(char* null_terminated_char_array)
{
    // Allocate on the stack for a new mutated string
    // Add +1 for the null terminated character
    char* print_name = (char*)alloca(strlen(null_terminated_char_array)+1);
    strcpy(print_name, null_terminated_char_array);

    // Setthe individual characters to upercase
    size_t i=0;
    while(print_name[i] != 0)
    {
        print_name[i] = toupper( null_terminated_char_array[i] );
        i++;
    }

    // Print all at once the uppercase string with an endline
    printf("%s\n", print_name); 
}  // -> alloca is foing to free memory when we leave scope jus like regular static variables

int main()
{ 
    // we ran out of actual stack space. That's why we use heap memory
    // int memory[8192000000000000]; // Segmentation failt (core dump)

    print_upper_case( "cristian" ); // CRISTIAN
    return 0; 
}
 