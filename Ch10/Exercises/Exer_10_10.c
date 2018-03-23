#include <stdio.h>
void add_arrays(int size, int a[], int b[], int c[size]);
int main()
{
    int arr[3][5];
    for (int i = 0; i < 5; i++) {
        arr[0][i] = 2 * i;
        arr[1][i] = 2 * i + 1;
    }
    add_arrays(5, arr[0], arr[1], arr[2]);
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[2][i]);
    printf("\n");
    return 0;
}
void add_arrays(int size, int a[], int b[], int c[])
{
    for (int i = 0; i < size; i++)
        c[i] = a[i] + b[i];
}