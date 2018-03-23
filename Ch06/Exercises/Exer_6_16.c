#include <stdio.h>
int main()
{
    int year = 0;
    double Daphne = 100.0, Deirdre = 100.0;
    do {
        year++;
        Daphne += 10.0;
        Deirdre *= 1.05;
    } while (Daphne >= Deirdre);
    printf("At year %d, Daphne has %.4f dollars, while Deirdre has %.4f dollars.\n", 
           year, Daphne, Deirdre);
    return 0;
}