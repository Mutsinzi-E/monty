#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new;
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new = malloc(sizeof(stack_t));
    if (!new)
        exit(EXIT_FAILURE);

    new->n = atoi(arg);
    new->prev = NULL;
    new->next = *stack;

    if (*stack)
        (*stack)->prev = new;

    *stack = new;
}
