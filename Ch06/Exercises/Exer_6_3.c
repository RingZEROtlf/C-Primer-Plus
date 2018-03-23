#include <stdio.h>
int main()
{
    for (int i = 1; i <= 6; i++) {
        for (char j = 'F'; j >= 'F' - i + 1; j--) {
            printf("%c", j);
        }
        printf("\n");
    }
    return 0;
}