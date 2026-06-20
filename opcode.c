#include "monty.h"

/**
 * get_op_func - finds opcode function
 * @opcode: opcode
 *
 * Return: function pointer
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
