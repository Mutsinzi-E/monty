#include "monty.h"

/**
 * add - adds top two elements
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;

	free(tmp);
}
