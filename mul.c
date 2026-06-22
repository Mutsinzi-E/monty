#include "monty.h"

void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;

    temp->next->n = temp->next->n * temp->n;

    *stack = temp->next;
    (*stack)->prev = NULL;

    free(temp);
}
