#include <stdio.h>
int main()
{
    double sequence1[8], sequence2[8];
    printf("Please enter the 8 numbers of the first sequence: ");
    for (int i = 0; i < 8; i++) {
        scanf("%lf", &sequence1[i]);
    }
    sequence2[0] = sequence1[0];
    for (int i = 1; i < 8; i++) {
        sequence2[i] = sequence2[i - 1] + sequence1[i];
    }
    for (int i = 0; i < 8; i++) {
        printf("%7.2f ", sequence1[i]);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%7.2f ", sequence2[i]);
    }
    printf("\n");
    return 0;
}