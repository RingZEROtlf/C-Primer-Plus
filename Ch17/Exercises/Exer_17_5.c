#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE    1024

typedef struct stack_s
{
    char characters[MAX_SIZE];
    int size;
} STACK;

void stack_init(STACK *p_stack);
bool stack_is_full(STACK *p_stack);
bool stack_is_empty(STACK *p_stack);
void stack_push(STACK *p_stack, char character);
char stack_top(STACK *p_stack);
void stack_pop(STACK *p_stack);

int main()
{
    STACK stack;
    stack_init(&stack);
    char string[MAX_SIZE];
    scanf("%s", string);
    for (int i = 0; i < strlen(string); i++)
        stack_push(&stack, string[i]);
    while (!stack_is_empty(&stack)) {
        putchar(stack_top(&stack));
        stack_pop(&stack);
    }
    putchar('\n');
    return 0;
}

void stack_init(STACK *p_stack)
{
    p_stack->size = 0;
}

bool stack_is_full(STACK *p_stack)
{
    return (p_stack->size == MAX_SIZE ? true : false);
}

bool stack_is_empty(STACK *p_stack)
{
    return (p_stack->size == 0 ? true : false);
}

void stack_push(STACK *p_stack, char character)
{
    int size = p_stack->size;
    if (!stack_is_full(p_stack)) {
        p_stack->characters[size] = character;
        p_stack->size++;
    }
}

char stack_top(STACK *p_stack)
{
    int size = p_stack->size;
    return p_stack->characters[size - 1];
}

void stack_pop(STACK *p_stack)
{
    if (!stack_is_empty(p_stack))
        p_stack->size--;
}
