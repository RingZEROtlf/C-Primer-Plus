#include <stdio.h>
#include <string.h>

int b2i(char *str);

int main()
{
    char *pbin = "01001001";
    printf("%d\n", b2i(pbin));
    return 0;
}

int b2i(char *str)
{
    int length = strlen(str);
    int ret = 0;
    for (int i = 0; i < length; i++)
        ret = ret * 2 + str[i] - '0';
    return ret;
}