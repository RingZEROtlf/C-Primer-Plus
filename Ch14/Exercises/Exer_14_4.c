#include <stdio.h>
#include <string.h>

#define NAME_LENGTH     32

struct name_s
{
    char first_name[NAME_LENGTH];
    char middle_name[NAME_LENGTH];
    char last_name[NAME_LENGTH];
};

struct person_info_s
{
    int social_insurance_id;
    struct name_s name;
};

void function_a(struct person_info_s person_infos[]);
void function_b(struct person_info_s *person_infos_ptr);

int main()
{
    struct person_info_s person_infos[5] = {
        { 302039823, { "Dribble", "Mary", "Flossie" } },
        { 302039823, { "Dribble", "Mary", "Flossie" } },
        { 302039823, { "Dribble", "Mary", "Flossie" } },
        { 302039823, { "Dribble", "Mary", "Flossie" } },
        { 302039823, { "Dribble", "", "Flossie" } }
    };
    function_a(person_infos);
    function_b(person_infos);
    for (int i = 0; i < 5; i++) {
        if (strlen(person_infos[i].name.middle_name) != 0)
            printf("%s, %s %c. -- %d\n", 
                   person_infos[i].name.first_name, 
                   person_infos[i].name.last_name, 
                   person_infos[i].name.middle_name[0],
                   person_infos[i].social_insurance_id);
        else
            printf("%s, %s -- %d\n", 
                   person_infos[i].name.first_name, 
                   person_infos[i].name.last_name, 
                   person_infos[i].social_insurance_id);
    }
    return 0;
}

void function_a(struct person_info_s person_infos[])
{
    for (int i = 0; i < 5; i++) {
        if (strlen(person_infos[i].name.middle_name) != 0)
            printf("%s, %s %c. -- %d\n", 
                   person_infos[i].name.first_name, 
                   person_infos[i].name.last_name, 
                   person_infos[i].name.middle_name[0],
                   person_infos[i].social_insurance_id);
        else
            printf("%s, %s -- %d\n", 
                   person_infos[i].name.first_name, 
                   person_infos[i].name.last_name, 
                   person_infos[i].social_insurance_id);
    }
    putchar('\n');
}

void function_b(struct person_info_s *person_infos_ptr)
{
    for (int i = 0; i < 5; i++) {
        if (strlen((person_infos_ptr + i)->name.middle_name) != 0)
            printf("%s, %s %c. -- %d\n", 
                   (person_infos_ptr + i)->name.first_name, 
                   (person_infos_ptr + i)->name.last_name, 
                   (person_infos_ptr + i)->name.middle_name[0],
                   (person_infos_ptr + i)->social_insurance_id);
        else
            printf("%s, %s -- %d\n", 
                   (person_infos_ptr + i)->name.first_name, 
                   (person_infos_ptr + i)->name.last_name, 
                   (person_infos_ptr + i)->social_insurance_id);
    }
    putchar('\n');
}