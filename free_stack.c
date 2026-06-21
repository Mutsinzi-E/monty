#include "monty.h"

/**
 * free_stack - frees stack memory
 * @stack: stack pointer
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
