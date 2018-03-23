#include <stdio.h>
int main()
{
    int space_cnt = 0, new_line_cnt = 0, other_cnt = 0;
    char ch;
    while ((ch = getchar()) != '#') {
        if (ch == ' ') space_cnt++;
        else if (ch == '\n') new_line_cnt++;
        else other_cnt++;
    }
    printf("You've typed %d spaces, %d new lines and %d other characters.\n",
           space_cnt, new_line_cnt, other_cnt);
    return 0;
}