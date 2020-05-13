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

	

	return (0);
}
