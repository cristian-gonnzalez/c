/** C Compiler Optimization Fundamentals (and brief performance experiment)
 *
 *  Optimization levels:
 *
 *      The optimization flags make things go faster...
 *
 *      -O1   : Take a little more time to compile. Perfomr some level of optimization on the code that will 
 *              usually speed it up
 *      -O2   : The 'release build' often uses '-O2'. It's important to test your application on both 'realease'
 *           and 'debug' (-g) builds. Note: When we use -O2, we often lose some of the debugging information in
 *           our application.
 *      -O3
 *      -Ofast: This might break your program. 
 *      -Og   : Debugging
 *      -Os   : Optimize for size. Optimizing not just the executable pr execution speed but the size of the 
 *           executable that we produce
 *
 *  Loop unrolling:
 *      In the code below, the body of the loop can be replaced once and the number of iteration can be reduce from 100
 *  to 50;
 *
 *  for(i=0; i<100; i++)               ->           for(i=0; i<100; i+=2)
 *      g();                                        {
 *                                                     g();
 *                                                     g();
 *                                                  }  
 *
 *      Loop unrolling also assists the 'brancj predictor' -- meaning the computer can fetch the exact instructions ahead 
 *  of time. There are ewer 'jumps' in our code quessing what instruction will next execute.
 *
 *  strength reduction:
 *      Bit shifting (e.g. x<<2) to multiply by 2 is another common operation. This idea of 'term rewriting' or 
 *  'instruction selection' to optimize our code is what is meant by 'strength reduction'.
 *
 *     x++; -> It is doing x = x + 1. That means we have to look up the value of 'x', increment it and then store 
 *             that value back into 'x'
 *
 *     ++x; ->  It finds and increments the value of 'x' first and then returns the incremented value. It directly 
 *              modifies x in place. It is a cheaper instruction than x++;
 *
 *  Use: > time ./prog   -> to know the time the program takes and compared with the one with optimization
 */

#include <stdio.h>

int my_add(int a, int b)
{
    return a+b;
}

int main()
{ 
    int var=0;

    var++;

    int r = my_add(2,5);  // function inline
    printf("my_add(2+5) = %d\n", r);


    for(int i=0; i<4; ++x /*instead of i++ */)
    {      
        int r = my_add(2,5);
        printf("my_add(2+5) = %d\n", r);
    }
    return 0; 
}
 