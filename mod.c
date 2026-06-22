#include "monty.h"

/**
 * mod - remainder of division of second top by top
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    int result;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp = *stack;
    result = tmp->next->n % tmp->n;

    tmp->next->n = result;

    *stack = tmp->next;
    (*stack)->prev = NULL;

    free(tmp);
}
