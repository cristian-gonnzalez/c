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

typedef unsigned int uint;

typedef int* intptr;

/* // One way

// This would ne in the .c file
struct Student
{
    int id;
    char grade;
};

// This would live in it's own header file
typedef struct Student student_t;

*/
/*
// Another way
typedef struct Student
{
    int id;
    char grade;
}student_t;
*/

// Anonimous way
typedef struct
{
    int id;
    char grade;
}student_t;

// typedf for function pointers
typedef float (*pfn)(float, float);


float add(float a, float b)
{
    return a+b;
}


int main()
{ 
    uint uvalue = 56;
    intptr ptr = NULL;

    printf("uvalue: %d\n", uvalue);  // uvalue: 56 
    printf("intptr: %p\n", ptr);     // intptr: (nil)

    
    // 'struct Student' in the C language is the full name of the type
    /*struct Student stud = { */
    student_t stud = { 
                       .id = 5, 
                       .grade = 'A' 
                    };
    printf("stud: { id = %d, grade = %c }\n", stud.id, stud.grade );     // stud: { id = 5, grade = A }

    // function pointer to some operation
    pfn operation = add;
    printf("operation() = %f\n", operation(2.5f,3.5f) ); // operation() = 6.000000


    return 0;
}

