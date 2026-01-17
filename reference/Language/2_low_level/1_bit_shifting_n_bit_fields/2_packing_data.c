/** Packing data into an integer
 *
 */

#include <stdio.h>

int main()
{   
    // A pixel (typically) has 4 components: red, green, blue and alpha (opacity).
    // Most commin pixel formats use 1 byte (8 bits) to store a value of 0-255 which represents the
    // intensity of the component
    //
    // Hex number representation
    //            R G B A
    int Pixel = 0xFFAACC11;

    // With unsigned char we effectively are able to store 1 byte so the others bytes are truncated or
    // lost
    unsigned char r = (Pixel >> 24);
    unsigned char g = (Pixel >> 16);
    unsigned char b = (Pixel >> 8);
    unsigned char a = (Pixel >> 0);

    printf("r is: %d\n", r); // r is: 255
    printf("g is: %d\n", g); // g is: 170
    printf("b is: %d\n", b); // b is: 204
    printf("a is: %d\n", a); // a is: 17

   
    return 0; 
}
 