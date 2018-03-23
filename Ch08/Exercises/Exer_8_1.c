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
    int count = 0;
    while ((ch = getc(fp)) != EOF) {
        count++;
    }
    fclose(fp);
    printf("This file contains %d characters.\n", count);
    return 0;
}