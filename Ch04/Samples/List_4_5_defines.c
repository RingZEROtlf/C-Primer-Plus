// defines.c -- use manifest constants defined in limits.h and float.h header files
#include <stdio.h>
#include <limits.h>      // limitation of integers
#include <float.h>      // limitation of float
int main(void)
{
    printf("Some numbers limits for this system:\n");
    printf("Biggest int: %d\n", INT_MAX);
    printf("Smallest long long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this system.\n", CHAR_BIT);
    printf("Smallest normal float: %e\n", FLT_MIN);
    printf("Largest normal float: %e\n", FLT_MAX);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);
    printf("Smallest normal double: %e\n", DBL_MIN);
    printf("Largest normal double: %e\n", DBL_MAX);
    printf("double precision = %d digits\n", DBL_DIG);
    printf("double epsilon = %e\n", DBL_EPSILON);
    return 0;
}

