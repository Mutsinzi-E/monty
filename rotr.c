#include "monty.h"

/**
 * rotr - rotates stack to the bottom
 * @stack: pointer to stack
 * @line_number: unused
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *last;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    last = *stack;

    while (last->next)
        last = last->next;

    if (last->prev)
        last->prev->next = NULL;

    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}
