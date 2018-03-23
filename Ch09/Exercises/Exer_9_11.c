#include <stdio.h>
typedef long long int64_t;
int64_t Fibonacci(int n);
int main()
{
    printf("%lld\n", Fibonacci(10));
    return 0;
}
int64_t Fibonacci(int n)
{
    int64_t a = 0, b = 1;
    while (--n > 0) {
        int64_t tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}