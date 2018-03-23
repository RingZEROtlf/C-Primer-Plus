#include <stdio.h>
void get_n_characters_from_input(int n, char characters[]);
int main()
{
    int n;
    char characters[100];
    scanf("%d", &n);
    get_n_characters_from_input(n, characters);
    return 0;
}
void get_n_characters_from_input(int n, char characters[])
{
    for (int i = 0; i < n; i++)
        characters[i] = getchar();
}