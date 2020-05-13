#include "monty.h"

/**
 * open_file - It opens the file.
 * @filename: Filename.
 *
 * Return: 0 on success, otherwise ends with 1.
 */

int open_file(char *filename)
{
	FILE *fd;

	fd = fopen(filename, "r");
	if (!fd)
		open_error(filename);

	read_file(fd);

	return (0);
}

/**
 * read_file - It reads the file line by line.
 * @file: File to read.
 *
 * Return: Nothing.
 */

void read_file(FILE *file)
{
	char *opcode = NULL;
	size_t  size = 0;
	int *ops;
	stack_t *stack = NULL;

	ops = malloc(sizeof(int) * 2);
	if (!ops)
		malloc_error();

	while (getline(&opcode, &size, file) != EOF)
	{
		tokenizer(opcode, ops, &stack);
		if (ops[0] == FALSE)
		{
			freeStack(stack);
			fclose(file);
			line_error_code(ops, opcode);
		}
		else if (ops[0] == 2)
		{
			freeStack(stack);
			fclose(file);
			push_error(ops, opcode);
		}
	}

	freeStack(stack);
	free(opcode);
	free(ops);
	fclose(file);
}
