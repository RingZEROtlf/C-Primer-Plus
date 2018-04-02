#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM     3
struct name_s
{
    char *first;
    char *last;
};
void showarray(const struct name_s names[], int n);
int mycomp(const void *p1, const void *p2);
int main(void)
{
    struct name_s names[NUM] = {
        { "Alpha", "Alice" },
        { "Gamma", "Cipher" },
        { "Beta", "Bellmont"}
    };
    puts("Initialized list:");
    showarray(names, NUM);
    qsort(names, NUM, sizeof(struct name_s), mycomp);
    puts("\nSorted list:");
    showarray(names, NUM);
    return 0;
}
void showarray(const struct name_s names[], int n)
{
    int index;
    for (index = 0; index < n; index++)
    {
        printf("%s %s\t", names[index]);
        if (index % 6 == 5)
            putchar('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}
int mycomp(const void *p1, const void *p2)
{
    const struct name_s *a1 = (const struct name_s *)p1, *a2 = (const struct name_s *)p2;
    int comp_first = strcmp(a1->first, a2->last), comp_last = strcmp(a1->first, a2->last);
    return (comp_first ? comp_first : comp_last);
}