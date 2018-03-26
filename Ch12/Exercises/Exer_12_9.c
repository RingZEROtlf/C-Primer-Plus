#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("How many words do you wish to enter? ");
    scanf("%d", &n);
    char **ppwords = (char **) malloc(sizeof(char *) * n);
    char temp[1024];
    printf("Enter %d words now:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        int length = strlen(temp);
        char *pword = (char *) malloc(sizeof(char) * (length + 1));
        strcpy(pword, temp);
        pword[length] = '\0';
        ppwords[i] = pword;
    }
    printf("Here are your words:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", ppwords[i]);
        free(ppwords[i]);
    }
    free(ppwords);
    return 0;
}