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
	fprintf(stderr, "L%i: can't pint, stack empty\n", ops[1]);
	free(ops);
	free(opcode);
	exit(EXIT_FAILURE);
}

/**
 * swap_error - It prints an error message for wrong swap.
 * @ops: It's an array with data to free.
 * @opcode: The given opcode.
 *
 * Return: Nothing.
 */

void swap_error(int *ops, char *opcode)
{
	fprintf(stderr, "L%i: can't swap, stack too short\n", ops[1]);
	free(ops);
	free(opcode);
	exit(EXIT_FAILURE);
}

/**
 * math_errors - It prints an error message for wrong math operation.
 * @ops: It's an array with data to free.
 * @opcode: The given opcode.
 * @math_o: The given math operation.
 *
 * Return: Nothing.
 */

void math_errors(int *ops, char *opcode, char math_o[3])
{
	fprintf(stderr, "L%i: can't %s, stack too short\n", ops[1], math_o);
	free(ops);
	free(opcode);
	exit(EXIT_FAILURE);
}
