#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int atoi(const char *str);
int main()
{
    char strings[4][128] = {
        " -123junk",
        "0",
        "junk",
        "2147483648"
    };
    for (int i = 0; i < 4; i++)
        printf("%d\n", atoi(strings[i]));
    return 0;
}
int atoi(const char *str)
{
    bool parsing_began = false, plus_minus_operator_parsed = false;
    int factor = 1, ret = 0;
    while (*str != '\0') {
        if (!parsing_began && isblank(*str)) {
            // do nothing;
        }
        else {
            parsing_began = true;
            if (*str == '+' || *str == '-') {
                if (!plus_minus_operator_parsed) {
                    plus_minus_operator_parsed = true;
                    factor = (*str == '+' ? 1 : -1);
                }
                else break;
            }
            else if (isdigit(*str)) {
                plus_minus_operator_parsed = true;
                ret = ret * 10 + (*str - '0');
            }
            else break;
        }
        str++;
    }
    return ret;
}