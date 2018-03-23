#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
float get_number();
int main()
{
    while (true) {
        printf("Enter the operation of your choice:\n");
        printf("a. add              s. subtract\n");
        printf("m. multiply         d. divide\n");
        printf("q. quit\n");
        char operation;
        while (isspace(operation = getchar()));
        if (operation == 'q') break;
        else if (operation == 'a' || operation == 's' || operation == 'm' || operation == 'd') {
            float a, b;
            printf("Enter first number: ");
            a = get_number();
            printf("Enter second number: ");
            b = get_number();
            switch (operation)
            {
            case 'a':
                printf("%.2f + %.2f = %.2f\n", a, b, a + b);
                break;
            case 's':
                printf("%.2f - %.2f = %.2f\n", a, b, a - b);
                break;
            case 'm':
                printf("%.2f * %.2f = %.2f\n", a, b, a * b);
                break;
            case 'd':
                while (b == 0.0) {
                    printf("Enter a number other than 0: ");
                    b = get_number();
                }
                printf("%.2f + %.2f / %.2f\n", a, b, a / b);
                break;
            default:
                break;
            }
        }
        else {
            printf("Invalid operation!\n");
            continue;
        }
    }
    printf("Bye.\n");
    return 0;
}
float get_number(void)
{
    float number;
    char ch;
    while (scanf("%f", &number) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);    // deal with wrong number
        printf(" is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    return number;
}