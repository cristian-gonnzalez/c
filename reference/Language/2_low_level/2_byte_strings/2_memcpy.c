/** memcpy
 *
 */

#include <stdio.h>
#include <string.h>

// byte strings (string.h):
// 
//  memcpy (wmemcpy)   - copy a block of memory
// 
//                          void *memcpy(size_t n, const void* dest, const void *src, size_t n);
//
//                       The memcpy() function copies n bytes from memory area src to
//                       memory area dest.  The memory areas must not overlap (it's importatn that 
//                       Im not copyng into myself).   ~~~~~~~~~~~~~~~~~~~~~~
//                      


void memcpy_create_a_copy()
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

    memcpy(dst, data, 27);

    printf("data: %s\n", data); // data: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    printf("dst : %s\n", dst);  // dst : ABCDEFGHIJKLMNOPQRSTUVWXYZ   
}

void memcpy_copy_to_smaller_region_of_memory()
{
    // creates an array on the stack with 27 characters (27 bytes)
    char data[27];
    char dst[13];
    
    // Initializes the array with 65 ('A') + offset
    for(int i=0; i<26; i++)
        data[i] = 65 + i;
    data[26] = 0; // '\0'

    printf("data: %s\n", data); // data: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    printf("dst : %s\n", dst);  // dst : @   -> Garbage 

    memcpy(dst, data, 13);

    printf("data: %s\n", data); // data: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    printf("dst : %s\n", dst);  // dst : ABCDEFGHIJKLMABCDEFGHIJKLMNOPQRSTUVWXYZ
    //                                   ^^^^^^^^^^^^^~
    //                                                ^
    //  This happends since we dont set a termination character (Printf writes up to a 
    // terminating null byte('\0') ). So what it could be happening is that we allocates dst
    // in the stack without a termination character, the next piece of memory is allocated
    // data. Then it is going to print dst and data
    // 
    // Memory: ABCDEFGHIJKLM ABCDEFGHIJKLMNOPQRSTUVWXYZ\0
    //         ~~~~~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    //            dst                   data
    //

    dst[12] = 0;  // '\0'
    printf("dst : %s\n", dst);  // dst : ABCDEFGHIJKL
}


int main()
{ 
    memcpy_create_a_copy();
    memcpy_copy_to_smaller_region_of_memory();  
    return 0; 
}
 