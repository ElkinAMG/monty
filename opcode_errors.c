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
