#include "monty.h"

void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
    void (*func)(stack_t **, unsigned int);

    func = get_op_func(opcode);

    if (!func)
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }

    func(stack, line_number);
}
