#include <stdio.h>
#include <string.h>

unsigned int b2i(char *str);
void i2b_and_output(unsigned int number);

int main(int argc, char *argv[])
{
    unsigned int a = b2i(argv[1]), b = b2i(argv[2]);
    printf("~a is ");
    i2b_and_output(~a);
    printf("~b is ");
    i2b_and_output(~b);
    printf("a & b is ");
    i2b_and_output(a & b);
    printf("a | b is ");
    i2b_and_output(a | b);
    printf("a ^ b is ");
    i2b_and_output(a ^ b);
    return 0;
}

unsigned int b2i(char *str)
{
    int length = strlen(str);
    unsigned int ret = 0;
    for (int i = 0; i < length; i++)
        ret = ret * 2 + str[i] - '0';
    return ret;
}

void i2b_and_output(unsigned int number)
{
    if (number == 0) {
        puts("0");
        return;
    }
    char output[32];
    int count = 0;
    while (number > 0) {
        output[count] = (char) (number % 2 + '0');
        count++;
        number /= 2;
    }
    for (int i = count - 1; i >= 0; i--)
        putchar(output[i]);
    putchar('\n');
}