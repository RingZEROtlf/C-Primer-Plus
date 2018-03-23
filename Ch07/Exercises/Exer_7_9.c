#include <stdio.h>
#include <stdbool.h>
bool is_prime(int number);
int main()
{
    int limit;
    scanf("%d", &limit);
    for (int number = 2; number <= limit; number++)
        if (is_prime(number)) printf("%d ", number);
    printf("\n");
}
bool is_prime(int number)
{
    for (int divisor = 2; divisor * divisor <= number; divisor++)
        if (number % divisor == 0) return false;
    return true;
}