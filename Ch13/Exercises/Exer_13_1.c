#include <stdio.h>
#include <stdlib.h>
int main()
{
    int ch;
    FILE *fp;
    unsigned long count = 0;
    printf("Please enter the filename: ");
    char filename[1024];
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters\n", filename, count);
    return 0;
}