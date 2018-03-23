/* addemup.c -- several normal expressions */
#include <stdio.h>
int main(void)          // calculate the sum of the first 20 integers
{
    int count, sum;     // declaration
    count = 0;          // expression
    sum = 0;            // expression
    while(count++ < 20) // iteration expression
        sum = sum + count;
    printf("sum = %d\n", sum);  // expression;
    return 0;           // jump expression
}