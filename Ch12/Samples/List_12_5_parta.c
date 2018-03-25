// parta.c -- different storage classes
// compiled together with List_12_6_partb.c
#include <stdio.h>
void report_count();
void accumulate(int k);
int count = 0;          // file scope, exteranl linkage
int main(void)
{
    int value;          // auto variable
    register int i;     // register varaible
    printf("Enter a positive integer (0 to quit): ");
    while (scanf("%d", &value) == 1 && value > 0)
    {
        ++count;        // using file-scope variable
        for (i = value; i >= 0; i--)
            accumulate(i);
        printf("Enter a positive integer (0 to quit): ");
    }
    report_count();
    return 0;
}
void report_count()
{
    printf("Loop executed %d times\n", count);
}