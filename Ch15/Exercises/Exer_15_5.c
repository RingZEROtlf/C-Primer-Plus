#include <stdio.h>

typedef unsigned int uint32_t;

uint32_t rotate_l(uint32_t value, int length);

int main()
{
    printf("%u\n", rotate_l(123, 10));
    printf("%u\n", rotate_l(2147483647, 10));
    return 0;
}

uint32_t rotate_l(uint32_t value, int length)
{
    for (int i = 0; i < length; i++) {
        uint32_t a = (value & 0x80000000 ? 0x1 : 0x0), b = value << 1;
        value = a | b;
    }
    return value;
}