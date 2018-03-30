#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH          32
#define SEATS_NUMBER    12
#define FLIGHTS_NUMBER  4

struct seat_s
{
    int seat_id;
    bool is_ordered;
    char firstname[LENGTH];
    char lastname[LENGTH];
    bool is_confirmed;
};

struct flight_s
{
    int flight_id;
    struct seat_s seats[SEATS_NUMBER];
};

void seat_assignment_procedure(struct flight_s *pflight);
int compare_two_seats_by_name(const void *a, const void *b);

char buffer[1024];

int main()
{
    struct flight_s flights[FLIGHTS_NUMBER] = { { 102, {} }, { 311, {} }, { 444, {} }, { 519, {} } };
    for (int i = 0; i < FLIGHTS_NUMBER; i++) {
        struct flight_s *pflight = &flights[i];
        for (int j = 0; j < SEATS_NUMBER; j++) {
            pflight->seats[j].seat_id = j + 1;
            pflight->seats[j].is_ordered = false;
            pflight->seats[j].firstname[0] = '\0';
            pflight->seats[j].lastname[0] = '\0';
            pflight->seats[j].is_confirmed = false;
        }
    }
    while (true) {
        int flight_id;
        printf("Please enter the flight id (102, 311, 444, 519): ");
        scanf("%d", &flight_id);
        gets(buffer);
        putchar('\n');
        bool found = false;
        for (int i = 0; i < FLIGHTS_NUMBER; i++)
            if (flights[i].flight_id == flight_id) {
                seat_assignment_procedure(&flights[i]);
                found = true;
                break;
            }
        if (!found) puts("Flight id not found!");
    }
    return 0;
}

void seat_assignment_procedure(struct flight_s *pflight)
{
    int seat_id;
    char firstname[LENGTH], lastname[LENGTH];
    while (true) {
        printf("Now dealing with flight whose id is %d.\n", pflight->flight_id);
        puts("To choose a function, enter its letter label:");
        puts("a) Show number of empty seats");
        puts("b) Show list of empty seats");
        puts("c) Show alphabetical list of seats");
        puts("d) Assign a customer to a seat assignment");
        puts("e) Delete a seat assignment");
        puts("f) Confirm all assignments");
        puts("g) Quit");
        putchar('\n');
        char choice = tolower(getchar());
        gets(buffer);
        if (choice == 'g') break;       // Quit
        if (choice == 'a') {
            int count = 0;
            for (int i = 0; i < SEATS_NUMBER; i++)
                if (!pflight->seats[i].is_ordered) count++;
            printf("The number of empty seats is %d.\n", count);
        }
        else if (choice == 'b') {
            printf("The list of empty seats is: ");
            for (int i = 0; i < SEATS_NUMBER; i++)
                if (!pflight->seats[i].is_ordered) printf("%d ", pflight->seats[i].seat_id);
            putchar('\n');
        }
        else if (choice == 'c') {
            struct seat_s temp[SEATS_NUMBER];
            memcpy(temp, pflight->seats, sizeof pflight->seats);
            qsort(temp, SEATS_NUMBER, sizeof *temp, compare_two_seats_by_name);
            for (int i = 0; i < SEATS_NUMBER; i++)
                printf("%02d(%c): %s %s (Confirmed: %c)\n", temp[i].seat_id, temp[i].is_ordered ? 'x' : 'o', temp[i].firstname, temp[i].lastname, temp[i].is_confirmed ? 'y' : 'n');
        }
        else if (choice == 'd') {
            printf("Please enter the seat id and the customer's name: ");
            scanf("%d %s %s", &seat_id, firstname, lastname);
            int status = 0;     // 0 for not found, 1 for found but ordered, 2 for found and assigned
            for (int i = 0; i < SEATS_NUMBER; i++)
                if (pflight->seats[i].seat_id == seat_id) {
                    if (pflight->seats[i].is_ordered) status = 1;
                    else {
                        status = 2;
                        pflight->seats[i].is_ordered = true;
                        strcpy(pflight->seats[i].firstname, firstname);
                        strcpy(pflight->seats[i].lastname, lastname);
                        pflight->seats[i].is_confirmed = false;
                    }
                    break;
                }
            if (status == 0) puts("No such seat id!");
            else if (status == 1) puts("Selected seat ordered!");
            else if (status == 2) puts("Seat successfully assigned.");
        }
        else if (choice == 'e') {
            printf("Please enter the seat id of assignment to be deleted: ");
            scanf("%d", &seat_id);
            bool found = false;
            for (int i = 0; i < SEATS_NUMBER; i++)
                if (pflight->seats[i].seat_id == seat_id) {
                    pflight->seats[i].is_ordered = false;
                    pflight->seats[i].firstname[0] = '\0';
                    pflight->seats[i].lastname[0] = '\0';
                    pflight->seats[i].is_confirmed = false;
                    found = true;
                    break;
                }
            if (found) puts("Assignment found and deleted.");
            else puts("Sorry, assignment not found!");
        }
        else if (choice == 'f') {
            for (int i = 0; i < SEATS_NUMBER; i++)
                if (pflight->seats[i].is_ordered) pflight->seats[i].is_confirmed = true;
        }
        else puts("Invalid choice!");
        putchar('\n');
    }
}

int compare_two_seats_by_name(const void *a, const void *b)
{
    struct seat_s *pa = (struct seat_s *)a, *pb = (struct seat_s *)b;
    int cmp_firstname = strcmp(pa->firstname, pb->firstname), cmp_lastname = strcmp(pa->lastname, pb->lastname);
    return cmp_firstname != 0 ? cmp_firstname : cmp_lastname;
}