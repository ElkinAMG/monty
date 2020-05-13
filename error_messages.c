#include "monty.h"

/**
 * file_error - Prints the error message on error argc.
 *
 *
 * Return: Nothing.
 */

void file_error(void)
{
	fputs("USAGE: monty file\n", stderr);
	exit(EXIT_FAILURE);
}

/**
 * open_error - Prints the error message on error open.
 * @filename: Name of the file.
 *
 * Return: Nothing.
 */

void open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * line_error_code - Prints the error message on error with Monty.
 * @line: The line of the current error.
 * @opcode: The code that gives an error.
 *
 * Return: Nothing.
 */

void line_error_code(int *line, char *opcode)
{
	fprintf(stderr, "L%i: unknown instruction %s\n", line[1], opcode);
	free(line);
	free(opcode);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - Prints the error message on error mallocating.
 *
 *
 * Return: Nothing.
 */

void malloc_error(void)
{
	fputs("Error: malloc failed\n", stderr);
	exit(EXIT_FAILURE);
}
