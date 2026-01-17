/** Typedef (An alias for new type)
 *      
 *      Creates an alias for a type.
 *
 *      typedef > #define
 *         ^          ^ text sustitution
 *         |           |
 *         |        is used for a textual replacement durin preprocessing. Remeber, anything that begins with '#' is processed
 *         |      by the preprocessor. (e.g. #include, #if, #else, #ifndef, #define, etc.)
 *         |
 *     A typedef is ot creating a new data type. It creates an 'alias' for an existing type that you can refer to by 
 *   another name.
 *
 *   typedef <existing_name> <alias_name>;
 */

#include <stdio.h>

#define PI 3.1415

typedef unsigned int uint;

// A vere WRONG way to use define.
// NOTE: 
//   This is probably a code smell in any language. In C++ "#define private public" can also be quite dangerous 
// and break encapsulation
#define char int
/* Lets print the preprocessor

> gcc main.c -E

#include <stdio.h>

typdef unsined int uint;;

int main()
{
  float value = 3.1415000000000002;
  uint uvalue = 56;
  int a = 'a';
  printf("value: %f\n", value);
  printf("uvalue: %d\n", uvalue);
  printf("a: %c\n", a);
  return 0;
}
*/

int main()
{ 
    float value = PI;
    uint uvalue = 56;
    char a = 'a';

    printf("value: %f\n", value);    // value: 3.141500 
    printf("uvalue: %d\n", uvalue);  // uvalue: 56 
    printf("a: %c\n", a);  // a: a

    return 0;
}

