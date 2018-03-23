#include <stdio.h>
int main()
{
    int number;
    int sum_odd = 0, cnt_odd = 0, sum_even = 0, cnt_even = 0;
    while (scanf("%d", &number) == 1) {
        if (number == 0) break;
        if (number % 2 == 1) {
            sum_odd += number;
            cnt_odd++;
        }
        else {
            sum_even += number;
            cnt_even++;
        }
    }
    printf("You've inputed %d odd numbers, the average is %.2f.\n", cnt_odd, (double)sum_odd / cnt_odd);
    printf("You've inputed %d even numbers, the average is %.2f.\n", cnt_even, (double)sum_even / cnt_even);
    return 0;
}