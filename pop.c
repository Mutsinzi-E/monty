#include "monty.h"

/**
 * pop - removes top element
 * @stack: stack head
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr,
			"L%d: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;

	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);
}
