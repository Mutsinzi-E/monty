#include "monty.h"

/**
 * push - pushes element onto stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	stack_t *new_node;
	int value;

	arg = strtok(NULL, " \t\n");

	if (!arg || !is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
