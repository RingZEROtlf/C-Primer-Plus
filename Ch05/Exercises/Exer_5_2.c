#include <stdio.h>
int main()
{
    int a;
    printf("Please enter an integer: ");
    scanf("%d", &a);
    for(int i = a; i <= a + 10; i++)
        printf("%d\n", i);
    return 0;
}