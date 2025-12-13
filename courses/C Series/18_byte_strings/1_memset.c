/** Byte strings
 *
 *      bstring stands for 'byte string'. Often times when programming in C or other systems 
 *  programming languages, we need to think in terms of bytes which are usually arrays of 'char'
 *  -- thus byte strings. 
 *
 *  > man bstring
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

typedef struct node
{
    int data;

    struct node* next;

} node_t;


int main()
{ 
    // data: 4 (int) + 4 (padding) 
    // next: 8 bytes (pointer)
    printf("sizeof node_t: %lu\n", sizeof(node_t) ); // sizeof node_t: 16
    
    // we can initializes our struct as follow
    //node_t mynode = { 
    //                  .data = 0, 
    //                  .next = NULL 
    //                };

    node_t mynode;

    // Garbage
    printf( "mynode.data: %d\n", mynode.data ); // mynode.data: 2031137273
    printf( "mynode.next: %p\n", mynode.next ); // mynode.next: 0x64

    // In general, it is considered more safe to zero initialize memory.
    // You dont know what is left in memory -- thus use memset or calloc to zero initialize memory
    memset( &mynode, 0, sizeof(node_t) );
    printf( "mynode.data: %d\n", mynode.data ); // mynode.data: 0
    printf( "mynode.next: %p\n", mynode.next ); // mynode.next: (nil)

    // creates an array on the stack with 27 characters (27 bytes)
    char data[27];

    // The c language does not initialize memory for you.
    // Why? There is a cost to default initializing (i.e. zero'ing out memory)
    // C let's you make the decision wheher you want to pay the cost.
    printf("%s\n", data); // �uP;�   -> Garbage

    memset(data, 65, 26);
    printf("%s\n", data); // AAAAAAAAAAAAAAAAAAAAAAAAAA

    // Initializes the array with 65 ('A') + offset
    for(int i=0; i<26; i++)
        data[i] = 65 + i;
    data[26] = 0; // '\0'

    printf("%s\n", data); // ABCDEFGHIJKLMNOPQRSTUVWXYZ

    memset(data+4, 65, 13);
    //     ~~~~~~
    //     Starts from the 5th position and set the next 13 characters with 'A'
    printf("%s\n", data); // ABCDAAAAAAAAAAAAARSTUVWXYZ

    
    return 0; 
}
 