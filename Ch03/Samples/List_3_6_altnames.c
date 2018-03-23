/* altnames.c -- portable integer types */
#include <stdio.h>
#include <inttypes.h>   /* support portable types */

int main(void)
{
    int32_t me32;       // me32 is a 32-bit signed integer variable
    me32 = 45933945;
    printf("First, assume int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead, use a \"macro\" from inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32);
    return 0;
}