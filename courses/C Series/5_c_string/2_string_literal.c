/** String literal
 *
 *      Strings that exists in memory.
 *   
 *      Also know as a 'string constant' is created by enclosing a seuqence of characters with " "'s.
 *      NOTE: The null byte ("\0") at the end, is automatically included.
 *
 */
#include <stdio.h>
#include <stdlib.h>  // contains malloc/free

size_t cstr_len(const char* s)
{
    const char* start = s;
    const char* end = s;
    while(*end != 0)
        end++;
    
    return (end-start);
}

int main()
{
    // String literal
    char* name = "hello wordl!";
    printf("name       : %s\n", name);             // name       : hello wordl!
    printf("name length: %ld\n", cstr_len(name) ); // name length: 12

    // String literals cannot be modified (they acctually const)
    // What we actually do when we create a string literal is label it as const
    //
    //  const char* name = "hello word!";
    //
    // Note: 
    //      The reason that string literals are not modifiable, is beacause the C compiler will
    // generate assemby code (and eventually a binary from the assembly), which stores the 
    // 'string lieral' in read-only region of the executable binary.
    //name[0] = 'H'; // SIGSEGV

    return 0; 
}
 