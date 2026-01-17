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

// The destination needs to have enought room to copy the source
char* cstr_cat( char* dst, const char* src)
{
    size_t len = cstr_len(dst) + cstr_len(src) + 1;
    
    char* s = dst + cstr_len(dst);
    while(*src != 0)
    {
        *s = *src;
        s++;
        src++;
    }

    return dst;
}


int main()
{
    char name[13] = "hello\0";
    char name2[] = " world!\0";

    cstr_cat(name, name2);

    printf("%s", name);

    return 0; 
}
 