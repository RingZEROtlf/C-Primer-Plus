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
        if (ch == '\n') printf("\\n");
        else if (ch == '\t') printf("\\t");
        else if (ch < ' ') printf("^%c", ch + 64, (int)ch);
        else printf(" %c", ch);
        printf(" %2d ", (int)ch);
        count = (count + 1) % 10;
        if (count == 0) printf("\n");
    }
    fclose(fp);
    return 0;
}