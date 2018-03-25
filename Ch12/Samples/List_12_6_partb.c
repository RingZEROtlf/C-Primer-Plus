// partb.c -- the rest part of program
// compiled together with List_12_5_parta.c
#include <stdio.h>
extern int count;           // reference declaration, external linkage
static int total = 0;       // static definition, internal linkage
void accumulate(int k);     // function prototype
void accumulate(int k)      // k has block-scope, no linkage
{
    static int subtotal = 0;    // static, no linkage
    if (k <= 0)
    {
        printf("loop cycle: %d\n", count);
        printf("subtotal: %d; total: %d\n", subtotal, total);
        subtotal = 0;
    }
    else
    {
        subtotal += k;
        total += k;
    }
}