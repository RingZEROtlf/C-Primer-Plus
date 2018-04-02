#include <stdio.h>
#include <math.h>

#define FACTOR_OF_DEGREE_TO_RADIUS  (acos(-1.0) / 180.0)

typedef struct polar_v {
    double magnitude;
    double angle;
} Polar_V;

typedef struct rect_v {
    double x;
    double y;
} Rect_V;

Rect_V polar2rect(Polar_V polar);

int main()
{
    puts("Please enter the magnitude and angle of an axis:");
    Polar_V polar;
    scanf("%lf%lf", &polar.magnitude, &polar.angle);
    Rect_V rect = polar2rect(polar);
    printf("The rectangular coordinate of this axis is (%lf, %f).\n", rect.x, rect.y);
    return 0;
}

Rect_V polar2rect(Polar_V polar)
{
    double r = polar.magnitude, a = polar.angle;
    Rect_V rect = { r * cos(a * FACTOR_OF_DEGREE_TO_RADIUS), r * sin(a * FACTOR_OF_DEGREE_TO_RADIUS) };
    return rect;
}