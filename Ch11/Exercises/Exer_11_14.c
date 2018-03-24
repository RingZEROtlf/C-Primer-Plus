#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
    double a, b;
    sscanf(argv[1], "%lf", &a);
    sscanf(argv[2], "%lf", &b);
    printf("%.4lf\n", pow(a, b));
    return 0;
}