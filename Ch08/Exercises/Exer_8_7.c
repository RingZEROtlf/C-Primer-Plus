#include <stdio.h>
#include <ctype.h>
#define BASE_TIME       40.0
#define FACTOR          1.5
#define RATE1           0.15
#define BASE1           300.0
#define RATE2           0.20
#define BASE2           150.0
#define RATE3           0.25
void output_menu(double base_salaries[]);
int main()
{
    double base_salaries[4] = { 8.75, 9.33, 10.00, 11.20 };
    do {
        output_menu(base_salaries);
        double base_salary;
        char choice;
        while (isspace(choice = getchar()));
        if (choice == 'q') break;
        else if ('a' <= choice && choice <= 'd') base_salary = base_salaries[choice - 'a'];
        else {
            printf("Invalid choice!\n");
            continue;
        }
        double hour;
        printf("Please enter the working hour in a week: ");
        scanf("%lf", &hour);
        if (hour > BASE_TIME) hour = BASE_TIME + (hour - BASE_TIME) * FACTOR;
        double salary = hour * base_salary;
        if (salary > BASE1 + BASE2) {
            salary -= BASE1 * RATE1 + BASE2 * RATE2 + (salary - BASE1 - BASE2) * RATE3;
        }
        else if (salary > BASE1) {
            salary -= BASE1 * RATE1 + (salary - BASE1) * RATE2;
        }
        else salary *= (1.0 - RATE1);
        printf("The salary of a week should be $%.2f.\n", salary);
    } while (1);
    return 0;
}
void output_menu(double base_salaries[])
{
    printf("*******************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a)$%0.2f/hr                         b)$%0.2f/hr\n", base_salaries[0], base_salaries[1]);
    printf("c)$%0.2f/hr                         d)$%0.2f/hr\n", base_salaries[2], base_salaries[3]);
    printf("q)quit\n");
    printf("*******************************************************************\n");
}