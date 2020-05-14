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
	char *box[2] = {NULL, NULL};

	box[0] = strtok(line, DELIMITER);
	if (line != NULL && isPushing(box[0]) == TRUE)
	{
		box[1] = strtok(NULL, DELIMITER);
		if (isNumber(box[1]) == FALSE)
		{
			ar[0] = 2, ar[1] = c_line++;
			goto out;
		}
	}

	if (box[0] != NULL && isPushing(box[0]) != TRUE)
	{
		if (isEmpty(stack) < 2)
		{
			if (pt_pp_swp(box[0]) != 5 && isEmpty(stack) == 0)
				ar[0] = pt_pp_swp(box[0]);
			else if (pt_pp_swp(box[0]) == 5 && isEmpty(stack) < 2)
				ar[0] = 5;
			else
				goto execution;
			ar[1] = c_line++;
			goto out;
		}
	}

execution:
	ar[0] = execute(box, stack);
	ar[1] = c_line++;
	goto out;

out:
	return (ar);
}

/**
 * error_handler - It manages the error flow.
 * @stack: It's the stack data structure.
 * @file: It's the given file for closing.
 * @op: Array with datas.
 * @opcode: Given opcode.
 *
 * Return: Nothing.
 */

void error_handler(stack_t **stack, FILE *file, int *op, char *opcode)
{
	if (op[0] == TRUE)
		return;

	freeStack(*stack);
	fclose(file);

	switch (op[0])
	{
	case 1:
		line_error_code(op, opcode);
		break;
	case 2:
		push_error(op, opcode);
		break;
	case 3:
		pop_error(op, opcode);
		break;
	case 4:
		pint_error(op, opcode);
		break;
	case 5:
		swap_error(op, opcode);
		break;
	}

}
