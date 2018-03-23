#include <stdio.h>
int main()
{
    double height;
    printf("Enter a height in centimeters: ");
    scanf("%lf", &height);
    double height_in_inches = height / 2.54;
    int feet = (int)(height_in_inches / 12);
    double inches = height_in_inches - 12.0 * feet;
    printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inches);
    while(1) {
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%lf", &height);
        if(height <= 0.) break;
        height_in_inches = height / 2.54;
        feet = (int)(height_in_inches / 12);
        inches = height_in_inches - 12.0 * feet;
        printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inches);
    }
    printf("bye\n");
    return 0;
}