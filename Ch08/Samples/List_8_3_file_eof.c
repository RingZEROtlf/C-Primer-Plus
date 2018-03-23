// file_eof.c -- open a file and display it
#include <stdio.h>
#include <stdlib.h>     // to use exit()
int main()
{
    int ch;
    FILE *fp;
    char fname[50];             // used to store the name of file
    printf("Enter the name of the file: ");
    scanf("%s", fname);
    fp = fopen(fname, "r");     // open the file to be read
    if (fp == NULL)             // if failed
    {
        printf("Failed to open file. Bye\n");
        exit(1);                // exit the program
    }
    // getc(fp) read a character from the file opened
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);                 // close the file
    return 0;
}