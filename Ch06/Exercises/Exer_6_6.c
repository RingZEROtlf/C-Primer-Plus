#include <stdio.h>
int main()
{
    int a, b;
    printf("Please input the lower bound and upper bound of the list: ");
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        printf("%5d%5d%5d\n", i, i * i, i * i * i);
    }
    return 0;
}