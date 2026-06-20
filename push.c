#include "monty.h"

char *push_arg;

/**
 * push - pushes an element onto stack
 * @stack: stack head
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (push_arg == NULL || !is_integer(push_arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(push_arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
