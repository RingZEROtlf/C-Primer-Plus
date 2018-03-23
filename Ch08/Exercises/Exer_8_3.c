#include <stdio.h>
#include <stdlib.h>
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
    int upper_count = 0, lower_count = 0;
    while ((ch = getc(fp)) != EOF) {
        if ('a' <= ch && ch <= 'z') lower_count++;
        else if ('A' <= ch && ch <= 'Z') upper_count++;
    }
    fclose(fp);
    printf("This file contains %d upper-case letters, and %d lower-case letters.\n", 
           upper_count, lower_count);
    return 0;
}