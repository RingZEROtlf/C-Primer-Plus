// names.h -- header file List_names_st.h that is revised to avoid repeated including
#ifndef NAMES_H_
#define NAMES_H_
// explicit constants
#define SLEN    32
// declaration of struct
struct names_st
{
    char first[SLEN];
    char last[SLEN];
};
// definition of type
typedef struct names_st names;
// function prototypes
void get_names(names *);
void show_names(const names *);
char *s_gets(char *st, int n);
#endif