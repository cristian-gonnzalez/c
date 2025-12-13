/** Pointer substraction to show you allocation boundary
 *
 *
 *        ___________  
 *       |           | 
 *       |   stack   | 
 *       |           | 
 *       |           | 
 *       | data2 0   | 
 *       |           | 
 *       |           | 
 *       |      10   | 
 *       |       9   | 
 *       |       8   | 
 *       |       7   | 
 *       |       6   |        
 *       |       5   |        
 *       |       4   |        
 *       |       3   | 
 *    ^  |       2   |        
 *    |  |       1   |        
 *    |  | data  0   |        
 *       |___________| 
 *       |           | 
 *       |   heap    | 
 *       |___________| 
 *       |           | 
 *       |   data    | 
 *       |___________| 
 *       |           | 
 *       |   .text   | 
 *       |___________| 
 */

#include <stdio.h>
#include <stdlib.h> // malloc/free

int main()
{ 
    int data[]  = {1,2,3,4,5,6};
    int data2[] = {1,2,3,4,5,6,7,8,9,10};

    printf("sizeof(data) : %lu\n", sizeof(data) );  // sizeof(data) : 24
    printf("sizeof(data2): %lu\n", sizeof(data2) ); // sizeof(data2): 40

    int diff = data2 - data;
    printf("diff: %d\n", diff ); // diff: -12
    int diff2 = ( (int*)data2 - (int*)data );
    printf("diff2: %d\n", diff2 ); // diff: -12
    //                                        ^
    // The different between start of data2 address and the start of data address
    // is 12 bytes 

    return 0; 
}
 