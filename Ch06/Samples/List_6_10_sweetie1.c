// sweetie1.c -- a counting loop
#include <stdio.h>
int main(void)
{
    const int NUMBER = 22;
    int count = 1;                      // initialization
    while(count <= NUMBER)              // test
    {
        printf("Be my Valentine!\n");   // behavior
        count++;                        // update counter
    }
    return 0;
}