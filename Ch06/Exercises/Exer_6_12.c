#include <stdio.h>
int main()
{
    int times;
    while (scanf("%d", &times) == 1) {
        if (times <= 0) break;
        double value_first = 0.0, value_second = 0.0;
        for (int i = 1; i <= times; i++) {
            value_first += 1.0 / i;
            value_second += (i % 2 == 1 ? 1.0 / i : -1.0 / i);
        }
        printf("The value of the first sequence is %.6f\n", value_first);
        printf("The value of the second sequence is %.6f\n", value_second);
    }
    return 0;
}