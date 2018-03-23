#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int guess = 1;
    printf("Pick an integer from 1 to 100. I will try to guess it.\n");
    printf("Respond with a y if my guess is right and with\n");
    printf("an n if it is smaller than the number you pick,\n");
    printf("and with an N if it is larger than the number you pick.")
    int left = 1, right = 100;
    bool success = false;
    while (left <= right) {
        int guess = (left + right) / 2;
        printf("Well, is your number %d?\n", guess);
        char response = getchar();
        if (response == 'y') {
            success = true;
            break;
        }
        else if (response == 'n') left = guess + 1;
        else if (response == 'N') right = guess - 1;
    }
    if (success) printf("I knew I could do it!\n"); else printf("It's impossible!\n");
    return 0;
}