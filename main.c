#include "monty.h"

/**
 * main - Monty interpreter entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	char *opcode;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		opcode = strtok(line, " \t\n");
		if (!opcode)
			continue;

		execute(opcode, &stack, line_number);
	}

	free(line);
	fclose(file);
	free_stack(stack);

	return (0);
}
