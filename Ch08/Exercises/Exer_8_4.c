#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
int main()
{
    int ch;
    FILE *fp;
    char fname[50];
    printf("Enter the name of the file: ");
    scanf("%s", fname);
    if ((fp = fopen(fname, "r") == NULL) {
        printf("Failed to open file. Bye\n");
        exit(1);
    }
    int words_count = 0, letters_count = 0;
    bool is_word = false, possible_word = true;
    while ((ch = getc(fp)) != EOF) {
        if (isupper(ch) || islower(ch)) {
            if (is_word) {
                letters_count++;
            }
            else if (possible_word) {
                is_word = true;
                words_count++;
                letters_count++;
            }
        }
        else if (ispunct(ch) || isspace(ch)) {
            is_word = false;
            possible_word = true;
        }
        else {
            is_word = false;
            possible_word = false;
        }
    }
    fclose(fp);
    printf("This file contains %d words, and %d letters.\n", words_count, letters_count);
    printf("The average letters in a word is %.2f.\n", (double)letters_count / words_count);
    return 0;
}