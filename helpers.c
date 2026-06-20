#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: stack head
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

/**
 * is_integer - checks if string is integer
 * @str: string
 *
 * Return: 1 if integer, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
