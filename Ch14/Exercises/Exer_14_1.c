#include <stdio.h>
#include <string.h>

const int year = 2018;

struct month_s
{
    char str[10];
    char str_abbr[4];
    int days;
    int number;
};

struct month_s months[12] = {
    { "January",    "Jan", 31,  1 },
    { "February",   "Feb", 28,  2 },
    { "March",      "Mar", 31,  3 },
    { "April",      "Apr", 30,  4 },
    { "May",        "May", 31,  5 },
    { "June",       "Jun", 30,  6 },
    { "July",       "Jul", 31,  7 },
    { "August",     "Aug", 31,  8 },
    { "September",  "Sep", 30,  9 },
    { "October",    "Oct", 31, 10 },
    { "November",   "Nov", 30, 11 },
    { "December",   "Dec", 31, 12 }
};

int main()
{
    char month[10];
    printf("Please input the month: ");
    scanf("%s", month);
    int count = 0;
    for (int i = 0; i < 12; i++) {
        count += months[i].days;
        if (strcmp(months[i].str, month) == 0) break;
    }
    printf("Days: %d\n", count);
    return 0;
}