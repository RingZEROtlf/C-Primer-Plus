#include <stdio.h>
void func(char character, int cols, int lines);
int main()
{
    func('#', 10, 8);
    return 0;
}
void func(char character, int cols, int lines)
{
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) putchar(character);
        putchar('\n');
    }
}