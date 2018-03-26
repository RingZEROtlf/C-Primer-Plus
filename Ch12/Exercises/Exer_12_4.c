#include <stdio.h>
int revoke_counter();
int main()
{
    for (int i = 0; i < 10; i++)
        printf("This function has been revoked %d time(s).\n", revoke_counter());
    return 0;
}
int revoke_counter()
{
    static int counter = 0;
    counter++;
    return counter;
}