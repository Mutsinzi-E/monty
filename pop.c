#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = temp->next;

    if (*stack)
        (*stack)->prev = NULL;

    free(temp);
}
