// addaword.c -- using fprintf(), fscanf() and rewind()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX     41
int main(void)
{
    FILE *fp;
    char words[MAX];
    int count = 0;
    if ((fp = fopen("wordy", "r")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    while (scanf("%d: %s", &count, words) == 2)
        continue;
    fclose(fp);
    if ((fp = fopen("wordy", "a+")) == NULL)
    {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter words to add to the file : press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
        fprintf(fp, "%d: %s\n", count + 1, words);
        count++;
    }
    puts("File contents:");
    rewind(fp);     // return to the beginning of the file
    while (fscanf(fp, "%d: %s", &count, words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");
    return 0;
}