#include <stdio.h>
void output(int a, int b);
int main()
{
    int a, b;
    printf("Enter lower and upper integer limits: ");
    while (scanf("%d%d", &a, &b) == 2) {
        if (a >= b) break;
        output(a, b);
        printf("Enter next set of limits: ");
    }
    printf("Done\n");
    return 0;
}
void output(int a, int b)
{
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += i * i;
    }
    printf("The sums of the squares from %d to %d is %d\n", a * a, b * b, sum);
}