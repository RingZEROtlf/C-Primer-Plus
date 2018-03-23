#include <stdio.h>

#define CONVERSION_FACTOR_FROM_MILE_TO_KM       1.609
#define CONVERSION_FACTOR_FROM_GALLON_TO_LITRE  3.785

int main()
{
    float distance_in_miles, gas_cost_in_gallons;
    printf("Please enter the distance in miles: ");
    scanf("%f", &distance_in_miles);
    printf("Please enter the gas cost in gallons: ");
    scanf("%f", &gas_cost_in_gallons);
    printf("Every 1.0 gallon gas can provide your car to travel %.1f miles.\n", 
            distance_in_miles / gas_cost_in_gallons);
    float distance_in_km = distance_in_miles * CONVERSION_FACTOR_FROM_MILE_TO_KM; 
    float gas_cost_in_litre = gas_cost_in_gallons * CONVERSION_FACTOR_FROM_GALLON_TO_LITRE;
    printf("Your distance in km is %.1f.\n", distance_in_km);
    printf("Your gas cost in litre is %.1f.\n", gas_cost_in_litre);
    printf("Your gas cost rate is %.1f litre/100km.\n", gas_cost_in_litre * 100.0 / distance_in_km);
    return 0;
}

