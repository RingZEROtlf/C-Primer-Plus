// randbin.c -- use binary I/O to access randomly
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE  1000
int main()
{
    double numbers[ARSIZE];
    double value;
    const char *file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;
    // generate a set of values of double type
    for (i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i + 1);
    // try to open file
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
    // write arrays into file using binary format
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }
    // read selected content from file
    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
    {
        pos = (long) i * sizeof(double);    // calculate offset value
        fseek(iofile, pos, SEEK_SET);       // locate to this position
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }
    // finish
    fclose(iofile);
    puts("Bye!");
    return 0;
}