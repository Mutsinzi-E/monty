#include "monty.h"

/**
 * execute - runs opcode
 * @opcode: instruction
 * @stack: stack pointer
 * @line_number: line number
 *
 * Return: void
 */
void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	void (*func)(stack_t **, unsigned int);

	func = get_op_func(opcode);

	if (!func)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}

	func(stack, line_number);
}
