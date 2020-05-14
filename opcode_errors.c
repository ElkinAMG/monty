#include "monty.h"

/**
 * push_error - It prints an error message for invalid push' argument.
 * @ops: It's an array with data to free.
 * @opcode: The given opcode.
 *
 * Return: Nothing.
 */

void push_error(int *ops, char *opcode)
{
	fprintf(stderr, "L%i: usage: push integer\n", ops[1]);
	free(ops);
	free(opcode);
	exit(EXIT_FAILURE);
}

/**
 * pop_error - It prints an error message for invalid pop.
 * @ops: It's an array with data to free.
 * @opcode: The given opcode.
 *
 * Return: Nothing.
 */

void pop_error(int *ops, char *opcode)
{
	fprintf(stderr, "L%i: can't pop an empty stack\n", ops[1]);
	free(ops);
	free(opcode);
	exit(EXIT_FAILURE);
}

/**
 * pint_error - It prints an error message for invalid pint.
 * @ops: It's an array with data to free.
 * @opcode: The given opcode.
 *
 * Return: Nothing.
 */

void pint_error(int *ops, char *opcode)
{
	fprintf(stderr, "L%i: can't pick, stack empty\n", ops[1]);
	free(ops);
	free(opcode);
	exit(EXIT_FAILURE);
}
