#include "monty.h"

/**
 * tokenizer - It makes a split from the given line of code.
 * @line: Line to tokenize.
 * @ar: It's an array with data to be returned, execution/n_line.
 * @stack: It's the stack data structure.
 *
 * Return: It returns the number line.
 */

int *tokenizer(char *line, int *ar, stack_t **stack)
{
	static unsigned int c_line = 1;
	char *container[2] = {NULL, NULL};

	container[0] = strtok(line, DELIMITER);

	if (line != NULL && isPushing(container[0]) == TRUE)
	{
		container[1] = strtok(NULL, DELIMITER);
		if (isNumber(container[1]) == FALSE)
		{
			ar[0] = 2;
			ar[1] = c_line++;
			return (ar);
		}
	}

	ar[0] = execute(container, stack);
	ar[1] = c_line++;

	return (ar);
}
