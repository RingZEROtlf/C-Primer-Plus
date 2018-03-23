// wordcnt.c -- count number of characters, words, lines
#include <stdio.h>
#include <ctype.h>      // provide isspace() function prototype
#include <stdbool.h>    // provide definition of bool, true, false
#define STOP '|'
int main(void)
{
    char c;             // read character
    char prev;          // the previous character read
    long n_chars = 0L;  // number of characters
    int n_lines = 0;    // number of lines
    int n_words = 0;    // number of words
    int p_lines = 0;    // number of incomplete lines
    bool inword = false;    // if word contains c, inword equals true
    printf("Enter text to be analyzed (| to terminate):\n");
    prev = '\n';        // used to recognize complete line
    while ((c = getchar()) != STOP)
    {
        n_chars++;       // count characters
        if (c == '\n')
            n_lines++;  // count lines
        if (!isspace(c) && !inword)
        {
            inword = true;  // a new word starts
            n_words++;      // count words
        }
        if (isspace(c) && inword)
            inword = false; // hit the end of a word
        prev = c;       // store the value of the character
    }
    if (prev != '\n')
        p_lines = 1;
    printf("characters = %ld, words = %d, lines = %d, ",
           n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);
    return 0;
}