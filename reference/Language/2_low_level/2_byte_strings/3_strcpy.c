/** strcpy
 *
 *  char*   strcpy(char* dest, const char* src);
 *
 *  The different with memcpy is that strcpy will just copy until it finds a null terminator.
 */

#include <stdio.h>
#include <string.h>


// byte strings (string.h):
// 
//  memset             - Set a blcok of memory.
//  memcpy (wmemcpy)   - copy a block of memory
//  strcpy             - Similar to memcpy, however special case where it copies until we reach 
//                       a '\0' character
//  memmove (wmemmove) - Similar to memcpy 
//                     - Handle case where memory overlaps


int main()
{ 
    // creates an array on the stack with 27 characters (27 bytes)
    char data[27];
    char dst[27];
    
    // Initializes the array with 65 ('A') + offset
    for(int i=0; i<26; i++)
        data[i] = 65 + i;
    data[26] = 0; // '\0'

    printf("data: %s\n", data); // data: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    printf("dst : %s\n", dst);  // dst : @   -> Garbage 

    strcpy(dst, data);

    printf("data: %s\n", data); // data: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    printf("dst : %s\n", dst);  // dst : ABCDEFGHIJKLMNOPQRSTUVWXYZ   

    return 0; 
}
 