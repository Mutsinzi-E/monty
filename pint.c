#include "monty.h"

/**
 * pint - prints top value
 * @stack: stack pointer
 * @line_number: line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
