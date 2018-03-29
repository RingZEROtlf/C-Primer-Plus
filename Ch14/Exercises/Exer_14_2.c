#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

bool is_lunar_year(int year);

int main()
{
    int day, month, year;
    printf("Please enter the day, month and year seperately: ");
    scanf("%d", &day);
    if (scanf("%d", &month) != 1) {
        char temp[10];
        scanf("%s", temp);
        for (int i = 0; i < 12; i++)
            if (strcmp(months[i].str, temp) == 0 || strcmp(months[i].str_abbr, temp) == 0) {
                month = months[i].number;
                break;
            }
    }
    scanf("%d", &year);
    int count = 0;
    for (int i = 0; i < 12; i++) {
        if (month == months[i].number) break;
        count += months[i].days;
        if (months[i].number == 2 && is_lunar_year(year)) count++;
    }
    printf("Days: %d\n", count + day);
    return 0;
}

bool is_lunar_year(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}