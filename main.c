#include "monty.h"

#define F_NAME av[1]

/**
 * main - The main function is the beginning of interpreter.
 * @ac: Arguments Counter.
 * @av: Arguments Vector.
 *
 * Return: It returns 0 on success, otherwise 1.
 */

int main(int ac, char **av)
{
	if (ac != 2)
		file_error();

	open_file(F_NAME);

	return (EXIT_SUCCESS);
}
