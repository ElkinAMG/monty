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

	if (box[0] != NULL)
	{
		if (isPushing(box[0]) != TRUE)
		{
			if (VOID(stack) && POP_PINT(box[0]))
				ar[0] = OP(box[0]);
			else if (isEmpty(stack) < 2 && OP(box[0]) >= 5)
				ar[0] = OP(box[0]);
			else
				goto execution;
			if (D_ZERO(box[0], stack) == -1 && !(VOID(stack)))
			{
				ar[0] = -1, ar[1] = c_line++;
				goto out;
			}
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
	case -1:
		zero_error(op, opcode);
		break;
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
	case 6:
		math_errors(op, opcode, "add");
		break;
	case 7:
		math_errors(op, opcode, "sub");
		break;
	case 8:
		math_errors(op, opcode, "div");
		break;
	case 9:
		math_errors(op, opcode, "mul");
		break;
	case 10:
		math_errors(op, opcode, "mod");
		break;
	}
}

/**
 * divide_by_zero - Checks whether or not dividing by zero.
 * @s: Given opcode.
 * @stack: It's the stack data structure.
 *
 * Return: It returns -1 on success, otherwise 0.
 */

int divide_by_zero(char *s, stack_t **stack)
{
	if (stack && *stack && (strcmp(s, "div") == 0 || strcmp(s, "mod") == 0))
	{
		for (; (*stack)->next; stack = &(*stack)->next)
			;

		if ((*stack)->n == 0)
			return (-1);
	}

	return (0);
}

/**
 * zero_error - It prints an error message for wrong division.
 * @ops: It's an array with data to free.
 * @opcode: The given opcode.
 *
 * Return: Nothing.
 */

void zero_error(int *ops, char *opcode)
{
	fprintf(stderr, "L%i: division by zero\n", ops[1]);
	free(ops);
	free(opcode);
	exit(EXIT_FAILURE);
}
