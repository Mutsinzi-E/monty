#include "monty.h"

/**
 * is_integer - checks if string is integer
 * @str: input string
 *
 * Return: 1 if valid, 0 otherwise
 */
int is_integer(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	if (str[0] == '-' || str[0] == '+')
		i++;

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
