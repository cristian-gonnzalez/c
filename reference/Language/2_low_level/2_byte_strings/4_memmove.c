/** memmove (wmemmove)
 *
 *      Similar to memcpy 
 *
 *      Handle case where memory overlaps (Im copyng into myself)
 *      
 *      Some folks recommend to alway use memmove over memcpy as it may be slightly safer. The reality is
 *  you have to think about what operation you are doing and if yu want to pay for that safety.
 *
 */

#include <stdio.h>
#include <string.h>


// byte strings (string.h):
// 
//  memmove (wmemmove) - 

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
 
    // we can use this like memcpy
    memmove(dst, data, 27);
    printf("dst: %s\n", dst); // dst: ABCDEFGHIJKLMNOPQRSTUVWXYZ
    
    // this could be a way you can rotate data
    memmove(data, data+12, 12);
    printf("data: %s\n", data); // data: MNOPQRSTUVWXMNOPQRSTUVWXYZ
    //                                   ^^^^^^^^^^^^
    
    return 0; 
}
 