/** Assert (and being carefull wiht data types)
 *
 */
#include <stdio.h>
#include <assert.h>

void countdown( int n )
{
    assert( n>=0 && "n was not greater than 0");

    // base case
    if( n<=0)
    {
        printf("%d\n", n);
        return;
    }
    
    printf("%d ", n);
    return countdown(n-1);
}


int main()
{
    countdown(10);
    countdown(-10);
    
    return 0;
}
