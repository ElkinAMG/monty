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

void read_file(FILE *file)
{
	char *opcode = NULL;
	size_t  size = 0;

        while (getline(&opcode, &size, file) != EOF)
	{
		tokenizer(opcode);
	}
        free(opcode);
	fclose(file);
}
