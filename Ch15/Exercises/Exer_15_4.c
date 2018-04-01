#include <stdio.h>

int check_bit_number(int value, int mask_pos);

int main()
{
    printf("%d\n", check_bit_number(3, 0));
    printf("%d\n", check_bit_number(3, 1));
    printf("%d\n", check_bit_number(3, 2));
    return 0;
}

int check_bit_number(int value, int mask_pos)
{
    int bit_mask = 0x1;
    while (mask_pos-- > 0)
        bit_mask <<= 1;
    return (value & bit_mask ? 1 : 0);
}