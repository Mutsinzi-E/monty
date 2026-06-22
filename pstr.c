#include "monty.h"

/**
 * pstr - prints string starting from top of stack
 * @stack: pointer to stack
 * @line_number: unused
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    (void)line_number;

    if (!stack || !*stack)
    {
        printf("\n");
        return;
    }

    current = *stack;

    while (current)
    {
        if (current->n <= 0 || current->n > 127)
            break;

        printf("%c", current->n);
        current = current->next;
    }

    printf("\n");
}
