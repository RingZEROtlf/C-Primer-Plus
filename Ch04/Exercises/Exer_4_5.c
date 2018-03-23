#include <stdio.h>
int main()
{
    float download_speed, file_size;
    printf("Please enter your download speed in Mb/s: ");
    scanf("%f", &download_speed);
    printf("Please enter the size of your file in MB: ");
    scanf("%f", &file_size);
    printf("At %.2f megabits per second, a file of %.2f megabytes\ndownloads in %.2f seconds.\n", 
            download_speed, file_size, file_size * 8.0 / download_speed);
    return 0;
}

