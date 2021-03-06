#include <stdio.h>
void to_base_n(unsigned long n, unsigned int base);
int main(void)
{
    unsigned long number;
    unsigned int base;
    printf("Enter an integer and the base (q to quit):\n");
    while (scanf("%lu %u", &number, &base) == 2)
    {
        printf("It's equivalent to ");
        to_base_n(number, base);
        putchar('\n');
        printf("Enter an integer and the base (q to quit):\n");
    }
    printf("Done.\n");
    return 0;
}
void to_base_n(unsigned long n, unsigned int base)
{
    int r;
    r = n % base;
    if (n >= base)
        to_base_n(n / base, base);
    putchar(r < 10 ? '0' + r : 'a' + r - 10);
    return;
}