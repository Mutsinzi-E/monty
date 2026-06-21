#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list node
 * @n: integer value
 * @prev: previous node
 * @next: next node
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode mapping
 * @opcode: command string
 * @f: function pointer
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* core functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

/* helpers */
void free_stack(stack_t *stack);
int is_integer(char *str);

/* opcode engine */
void execute(char *opcode, stack_t **stack, unsigned int line_number);
void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number);

#endif
