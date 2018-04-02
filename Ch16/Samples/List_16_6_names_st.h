// names_st.h -- header file of List_16_7_names_st.c
// constants
#include <string.h>
#define SLEN    32
// struct declaration
struct names_st
{
    char first[SLEN];
    char last[SLEN];
};
// type definition
typedef struct names_st names;
// function prototypes
void get_names(names *);
void show_names(const names *);
char *s_gets(char *st, int n);