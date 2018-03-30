#include <stdio.h>

void fa();
void fb();
void fc();

int main()
{
    void (*(fps[3]))() = { fa, fb, fc };
    char line[1024];
    while (gets(line) != NULL)
        if ('a' <= line[0] && line[0] <= 'c') fps[line[0] - 'a'](); else puts("Error!");
    return 0;
}

void fa() { puts("Executing function a"); }
void fb() { puts("Executing function b"); }
void fc() { puts("Executing function c"); }
