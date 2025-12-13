/** structs & union (anonymous stricts and union with C11)
 *  
 *  NOTE: May need to use -std=c11 for this example. The anonymous 'struct' (i.e. without name) might
 * make some compilers complain.
 *
 */

#include <stdio.h>

typedef union v2
{
    // Underlying data
    float elements[2];          // 8 bytes

    // Anonymous structure
    struct                      // 8 bytes
    { 
        float width;
        float height;
    }; // No tag for the inner structure
    
    // Anonymous structure
    struct                      // 8 bytes
    {
        float x;
        float y;
    }; // No tag for the inner structure
} vec2_t;

int main()
{ 
    printf("sizeof float : %d bytes\n", sizeof(float) );  // sizeof float : 4 bytes
    printf("sizeof vec2_t: %d bytes\n", sizeof(vec2_t) ); // sizeof vec2_t: 8 bytes

    vec2_t point = { .x = 5.0f, .y = 3.0f };
    vec2_t rectangle = { .width = 100.0f, .height = 50.0f };
    vec2_t vec = { .elements= {4.0f, 3.05f } };

    printf("point     = { width = %f, height= %f }\n\n", 
            point.width, point.height ); // point     = { width = 5.000000, height= 3.000000 }
    printf("rectangle = { x = %f, y= %f }\n\n", 
            rectangle.width, rectangle.height );  // rectangle = { x = 100.000000, y= 50.000000 }
    printf("vec = { elements = [%f, %f] }\n\n", 
            vec.width, vec.height );  // vec = { elements = [4.000000, 3.050000] }

    return 0; 
}
 