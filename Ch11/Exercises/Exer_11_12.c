#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main()
{
    char character;
    int counter_word = 0, counter_upper_case = 0, counter_lower_case = 0, counter_punctuation = 0, counter_digit = 0;
    bool is_parsing_word = false;
    while (scanf("%c", character) == 1) {
        if (isupper(character)) counter_upper_case++;
        if (islower(character)) counter_lower_case++;
        if (ispunct(character)) counter_punctuation++;
        if (isdigit(character)) counter_digit++;
        if (!isblank(character) && !iscntrl(character) && !ispunct(character)) {
            if (!is_parsing_word) {
                is_parsing_word = true;
                counter_word++;
            }
        }
        else is_parsing_word = false;
    }
    printf("The input contains %d words, %d upper-case letters, %d lower-case letters, %d punctuations and %d digits.\n",
           counter_word, counter_upper_case, counter_lower_case, counter_punctuation, counter_digit);
    return 0;
}