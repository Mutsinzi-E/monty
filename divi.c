#include "monty.h"

void divi(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;

    temp->next->n = temp->next->n / temp->n;

    *stack = temp->next;
    (*stack)->prev = NULL;

    free(temp);
}
