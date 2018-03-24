#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Function declarations
int output_menu_and_get_choice();
void output_strings(int count, char strings[][128]);
int compare_two_strings(const void *a, const void *b);
void output_strings_in_ascii_order(int count, char strings[][128]);
struct my_string_s {
    int length;
    char string[128];
};
int compare_two_string_lengths(const void *a, const void *b);
void output_strings_in_length_order(int count, char strings[][128]);
struct my_string_s2 {
    int first_word_length;
    char first_word[128];
    char string[128];
};
int compare_two_string_first_word_length(const void *a, const void *b);
void output_strings_according_to_first_word_length(int count, char strings[][128]);

// Main entrance
int main()
{
    char line[128], tmp[128];
    char strings[10][128];
    int count;
    // get source strings
    printf("Please input at most 10 strings, a empty line (including spaces and tabs) will be regarded as terminating input:\n");
    for (count = 0; count < 10; count++) {
        gets(line);
        if (sscanf(line, "%s", tmp) != 1) break; else strcpy(strings[count], line);
    }
    while (true) {
        // get user's choice, invalid choices will be rejected and user will be asked to type again
        int choice = output_menu_and_get_choice();
        // if choose option 5, exit
        if (choice == 5) break;
        // otherwise, do something according to the choice
        switch (choice)
        {
        case 1: output_strings(count, strings);
            break;
        case 2: output_strings_in_ascii_order(count, strings);
            break;
        case 3: output_strings_in_length_order(count, strings);
            break;
        case 4: output_strings_according_to_first_word_length(count, strings);
            break;
        default:    // this branch will not be executed
            break;
        }
    }
    printf("Finished!\n");
    return 0;
}

// Function definitions

// Get option
int output_menu_and_get_choice()
{
    printf("Choose from following list:\n");
    printf("1) Output source strings.\n");
    printf("2) Output stings in ASCII order.\n");
    printf("3) Output strings in length order.\n");
    printf("4) Output strings according to the first word's length.\n");
    printf("5) Quit.\n");
    int choice;
    char remain[128];
    printf("Please enter your choice (1-5): ");
    if (scanf("%d", &choice) == 1) {
        if (1 <= choice && choice <= 5) return choice;
    }
    gets(remain);
    return 0;
}

// Option 1
void output_strings(int count, char strings[][128])
{
    printf("\nThe source strings are as following:\n");
    for (int i = 0; i < count; i++)
        printf("%s\n", strings[i]);
    printf("\n");
}

// Option 2
int compare_two_strings(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}
void output_strings_in_ascii_order(int count, char strings[][128])
{
    char duplicates[10][128];
    for (int i = 0; i < count; i++)
        strcpy(duplicates[i], strings[i]);
    qsort(duplicates, count, sizeof *duplicates, compare_two_strings);
    printf("\nThe strings in ASCII order are as following:\n");
    for (int i = 0; i < count; i++)
        printf("%s\n", duplicates[i]);
    printf("\n");
}

// Option 3
int compare_two_string_lengths(const void *a, const void *b)
{
    struct my_string_s *pa = (struct my_string_s *)a, *pb = (struct my_string_s *)b;
    return pa->length - pb->length;
}
void output_strings_in_length_order(int count, char strings[][128])
{
    struct my_string_s duplicates[10];
    for (int i = 0; i < count; i++) {
        duplicates[i].length = strlen(strings[i]);
        strcpy(duplicates[i].string, strings[i]);
    }
    qsort(duplicates, count, sizeof *duplicates, compare_two_string_lengths);
    printf("\nThe strings in length order are as following:\n");
    for (int i = 0; i < count; i++)
        printf("%s\n", duplicates[i].string);
    printf("\n");
}

// Option 4
int compare_two_string_first_word_length(const void *a, const void *b)
{
    struct my_string_s2 *pa = (struct my_string_s2 *)a, *pb = (struct my_string_s2 *)b;
    return pa->first_word_length - pb->first_word_length;
}
void output_strings_according_to_first_word_length(int count, char strings[][128])
{
    struct my_string_s2 duplicates[10];
    for (int i = 0; i < count; i++) {
        strcpy(duplicates[i].string, strings[i]);
        sscanf(duplicates[i].string, "%s", duplicates[i].first_word);
        duplicates[i].first_word_length = strlen(duplicates[i].first_word);
    }
    qsort(duplicates, count, sizeof *duplicates, compare_two_string_first_word_length);
    printf("\nThe strings sorted according to the first word's length are as following:\n");
    for (int i = 0; i < count; i++)
        printf("%s\n", duplicates[i].string);
    printf("\n");
}