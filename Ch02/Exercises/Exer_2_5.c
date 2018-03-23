#include <stdio.h>

int br();
int ic();

int main()
{
    br();
    printf("\t");
    ic();
    printf("\n");
    ic();
    printf("\n");
    br();
    printf("\n");

    return 0;
}

int br()
{
    printf("Brazil, Russia.");

    return 0;
}

int ic()
{
    printf("India, China.");

    return 0;
}