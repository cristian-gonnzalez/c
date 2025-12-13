/** Bit fields
 *
 * In C we can actually specify how many bits we actually want this information to take up here 
 */

#include <stdio.h>

// Using bit fields 
typedef struct StagesCompleted
{
    char level1Completed:1;
    //                  ~^
    //                   How many bits we take from char  
    char level2Completed:1;
    char level3Completed:1;
    char level4Completed:1;
    char level5Completed:1;
    char level6Completed:1;
    char level7Completed:1;
    char level8Completed:1;

} StagesCompleted_t;


// Althought we only need 3 bits, the C compiler is still going to pad this data structure with 5 bits
// to complete 1 byte (minimun amount of information we can address)
typedef struct
{
    char level1Completed:1;
    char level2Completed:1;
    char level3Completed:1;
} UncompletedByte_t;

int main()
{   
    printf("Size of StagesCompleted_t: %ld byte\n", 
           sizeof(StagesCompleted_t) ); // Size of StagesCompleted_t: 1 byte

    printf("Size of UncompletedByte_t: %ld byte\n", 
           sizeof(UncompletedByte_t) ); // Size of UncompletedByte_t: 1 byte
 
    return 0; 
}
 