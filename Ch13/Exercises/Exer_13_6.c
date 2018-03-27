// reducto.c -- compress a file to one third of its original size
#include <stdio.h>
#include <stdlib.h>     // provide function prototype of exit()
#include <string.h>     // provide function prototype of strcpy() and strcat()
#define LEN     40
int main()
{
    FILE *in, *out;     // declaration of two FILE pointers
    int ch;
    char name[LEN];     // storing filename of output
    int count = 0;
    // set input
    char filename[LEN];
    printf("Please enter filename: ");
    scanf("%s", filename);
    if ((in = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", filename);
        exit(EXIT_FAILURE);
    }
    // set output
    strncpy(name, filename, LEN - 5);    // copy filename
    name[LEN - 5] = '\0';
    strcat(name, "red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);       // print the first character of every three characters
    // finish part
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");
    return 0;
}