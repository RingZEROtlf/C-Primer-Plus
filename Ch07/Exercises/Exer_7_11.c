#include <stdio.h>
#include <ctype.h>
int main()
{
    char type;
    double artichoke = 0.0, beet = 0.0, carrot = 0.0;
    do {
        while (isspace(type = getchar())) continue;
        double weight;
        switch (type) {
        case 'a':
            printf("Please enter the weight of artichoke: ");
            scanf("%lf", &weight);
            artichoke += weight;
            break;
        case 'b':
            printf("Please enter the weight of beet: ");
            scanf("%lf", &weight);
            beet += weight;
            break;
        case 'c':
            printf("Please enter the weight of carrot: ");
            scanf("%lf", &weight);
            carrot += weight;
            break;
        case 'q':
            break;
        default:
            printf("Invalid type!\n");
        }
    } while (type != 'q');
    double price = artichoke * 2.05 + beet * 1.15 + carrot * 1.09;
    double discount = price > 100.0 ? price * 0.05 : 0.0;
    double total_weight = artichoke + beet + carrot;
    double misc;
    if (total_weight <= 5.0) misc = 6.5;
    else if (total_weight <= 20.0) misc = 14.0;
    else misc = 14.0 + (total_weight - 20.0) * 0.5;
    printf("artichoke, %.2f pounds, $%.2f.\n", artichoke, artichoke * 2.05);
    printf("beet, %.2f pounds, $%.2f.\n", beet, beet * 1.15);
    printf("carrot, %.2f pounds, $%.2f.\n", carrot, carrot * 1.09);
    printf("total price is $%.2f.\n", price);
    printf("discount is $%.2f.\n", discount);
    printf("misc price is $%.2f.\n", misc);
    printf("the final price is $%.2f.\n", price - discount + misc);
    return 0;
}