/** C string
 *
 *      C-strings are actually just arrays (array of characters).    
 *
 *      ['h','e','l','l','o','\0'] 
 *        0   1   2   3   4   5
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~
 *              length = 6
 */
#include <stdio.h>
#include <stdlib.h>  // contains malloc/free

size_t cstr_len(const char* s)
{
    const char* start = s;
    while(*s != 0)
        s++;
    return s-start;
}

int main()
{
    char s[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("s: %s\n", s); // s: hello

    // The local variable name allocates 5 characters on the stack and it points to the start of
    // the string
    //
    // Note: A character array (i.e. char name[5]) and a pointer to a char (i.e. char*) are 
    // 'diferent' to the compiler. But both allow us to acces a series of characters
    char name[5];
    
    name[0] = 'N';
    name[1] = 'i';
    name[2] = 'k';
    name[3] = 'e';
    name[4] = '\0';
    printf("name       : %s\n", name); // name: Nike
    printf("name length: %ld\n", cstr_len(name) ); // name: Nike
   

    char* brand =(char*) malloc(sizeof(char)*5);
    brand[0] = 'T';
    brand[1] = 'o';
    brand[2] = 'p';
    brand[3] = 'p';
    brand[4] = '\0';
    printf("brand       : %s\n", brand); // brand       : Topp
    printf("brand length: %ld\n", cstr_len(brand) ); // brand length: 4

    free(brand);
   

    return 0;
}
 