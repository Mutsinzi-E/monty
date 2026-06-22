#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number of instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *top;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;

    (*stack)->next->n = (*stack)->next->n + top->n;

    *stack = top->next;
    (*stack)->prev = NULL;

    free(top);
}
