#include <stdio.h>
#include <math.h>

const double pi = acos(-1.0);

void transform(double source[], double target[], int size, double (*func)(double));

double multiply_by_2(double number);
double add_by_1(double number);

int main()
{
    double source[360];
    for (int i = 0; i < 360; i++)
        source[i] = pi / 180.0 * i;
    double target[4][360];
    transform(source, target[0], 360, sin);
    transform(source, target[1], 360, cos);
    transform(source, target[2], 360, multiply_by_2);
    transform(source, target[3], 360, add_by_1);
    return 0;
}

void transform(double source[], double target[], int size, double (*func)(double))
{
    for (int i = 0; i < size; i++)
        target[i] = func(source[i]);
}

double multiply_by_2(double number)
{
    return number * 2.0;
}

double add_by_1(double number)
{
    return number + 1.0;
}
