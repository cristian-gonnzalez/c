/** 
 *  gcc invokes the entire build process, which involves preprocessing, compiling, assesmbling and 
 *  liking our code.
 *
 *  ldd:
 *      ldd is a tool that will show what libraries are needed by a dynamic linker. Generally, I use it
 *  as a debuggin tool to see what share object (.so) files are missing when building software.
 *
 *      > ldd ./prog
 */

#include <stdio.h>
#include "cmath.h"
#include "cmult.h"


int main()
{
    printf("add(4, 7) = %d\n", add(4, 7));   
    printf("mult(4, 7) = %d\n", mult(4, 7));   
    return 0; 
}
 