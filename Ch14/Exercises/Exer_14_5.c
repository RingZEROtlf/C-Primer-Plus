#include <stdio.h>

#define LEN     32
#define CSIZE   4

struct name
{
    char first[LEN];
    char last[LEN];
};

struct student
{
    struct name name;
    double grade[3];
    double average;
};

void calculate_average_grades(struct student students[]);
void output_infomations(struct student students[]);
void output_total_average(struct student students[]);

int main()
{
    struct student students[CSIZE] = {
        { { "Alice", "Alpha" } },
        { { "Bob", "Bete" } },
        { { "Gustavo", "Gamma" } },
        { { "Drake", "Delta" } }
    };
    for (int i = 0; i < 4; i++) {
        printf("Please input the grades of student %s %s: ", students[i].name.first, students[i].name.last);
        for (int j = 0; j < 3; j++)
            scanf("%lf", &students[i].grade[j]);
    }
    calculate_average_grades(students);
    output_infomations(students);
    output_total_average(students);
    return 0;
}

void calculate_average_grades(struct student students[])
{
    for (int i = 0; i < CSIZE; i++) {
        double total = 0.0;
        for (int j = 0; j < 3; j++)
            total += students[i].grade[j];
        students[i].average = total / 3.0;
    }
}

void output_infomations(struct student students[])
{
    for (int i = 0; i < CSIZE; i++) {
        printf("The grades of student %s %s are ");
        for (int j = 0; j < 3; j++)
            printf("%.2lf ", students[i].grade[j]);
        printf(", and average is %.2lf.\n", students[i].average);
    }
}

void output_total_average(struct student students[])
{
    double total = 0.0;
    for (int i = 0; i < CSIZE; i++)
        total += students[i].average;
    printf("The total average is %.2lf.\n", total / CSIZE);
}
