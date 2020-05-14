#include "monty.h"

/**
 * isPushing - It checks is the opcode is equal to push.
 * @opcode: It's the given opcode.
 *
 * Return: It returns 0 on success, otherwise 1.
 */

int isPushing(char *opcode)
{
	if (!opcode)
		return (FALSE);

	return (strcmp(opcode, "push"));
}

/**
 * freeStack - It frees the stack data structure.
 * @stack: It's the stack data structure.
 *
 * Return: Nothing.
 */

void freeStack(stack_t *stack)
{
	stack_t *mirror = stack;

	while (stack)
	{
		stack = stack->next;
		free(mirror);
		mirror = stack;
	}
}

/**
 * isNumber - It checks whether or not the given data is integer.
 * @data: It's the given data.
 *
 * Return: It returns 0 on success, otherwise 1.
 */

int isNumber(char *data)
{
	if (!data)
		return (FALSE);

	if (*data == '-')
		data++;

	for (; *data; data++)
		if (!isdigit(*data))
			return (FALSE);

	return (TRUE);
}

/**
 * isEmpty - It checks is the opcode is equal to push.
 * @stack: It's the given stack.
 *
 * Return: It returns 0 on success, otherwise 1.
 */

int isEmpty(stack_t **stack)
{
	int i = 0;

	if (*stack)
	{
		for (; *stack; stack = &(*stack)->next, i++)
			;
	}

	return (i);
}

/**
 * opcoding - It checks whether or not is pop, pint or swap.
 * @s: It's the given opcode.
 *
 * Return: It returns 0 on not pop or pint.
 */

int opcoding(char *s)
{
	int value = 0;
	int index;
	op_t op[] = {
		{"pop", 3},
		{"pint", 4},
		{"swap", 5},
		{"add", 6},
		{"sub", 7},
		{"div", 8},
		{"mul", 9},
		{"mod", 10},
		{NULL, TRUE}
	};

	for (index = 0; op[index].opcode; index++)
	{
		if (strcmp(op[index].opcode, s) == 0)
		{
			value = op[index].code;
			break;
		}
	}

	return (value);
}
