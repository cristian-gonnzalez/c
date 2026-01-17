/** Fixed width types and bool in C
 *      
 *      Embedded system migth have int's that are 2 bytes. Most desktop today are likely 4 bytes.
 *
 *      A fixed-width type provides us a guareentee of the number of bits that a data-type will have (or have ar a minimun
 *  in some of the cases).
 */

#include <stdio.h>
#include <stdint.h> // Fixed width integer types
#include <stdbool.h> // gives is a bool
//          ^
//  boool from stdbool.h is a macro defined in a standard library. I recommend using the library versus your own for
//  consitency


// NOTE: Some of the unit_fast32_t types for example may actually be '8 btyes' (64 bits) of data IF in fact, a register
// works best with 64 bits, or data transfer in the cpu works best. Consider this domain specific for knowledge.

int main()
{ 
    printf("sizeof int     = %lu\n", sizeof(int));     // sizeof int     = 4
    printf("sizeof int8_t  = %lu\n", sizeof(int8_t));   // sizeof int8_t  = 1
    printf("sizeof int16_t = %lu\n", sizeof(int16_t)); // sizeof int16_t = 2
    printf("sizeof int32_t = %lu\n", sizeof(int32_t)); // sizeof int32_t = 4


    printf("sizeof bool = %lu\n", sizeof(bool)); // sizeof bool = 1

    if(true)
        printf("condition is true\n"); // condition is true

    return 0;
}

