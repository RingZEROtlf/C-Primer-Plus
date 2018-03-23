/* and_f.c -- values of truth and false in C */
#include <stdio.h>
int main(void)
{
    int true_val, false_val;
    true_val = (10 > 2);        // value of true relation
    false_val = (10 == 2);      // value of false relation
    printf("true = %d; false %d \n", true_val, false_val);
    return 0;
}