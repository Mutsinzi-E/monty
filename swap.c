#include "monty.h"

/**
 * swap - swaps top two elements
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}
