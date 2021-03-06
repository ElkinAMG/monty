#include "monty.h"

/**
 * execute - It executes the respective opcode.
 * @opcode: It's an array with opcode/data.
 * @stack: It's the stack data structure.
 *
 * Return: It returns 0 on success, otherwise 1.
 */

int execute(char *opcode[2], stack_t **stack)
{
	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{"pint", _pint},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{NULL, NULL}
	};

	unsigned int data = 0, tripper;

	if (opcode[1] != NULL)
		data = atoi(opcode[1]);

	if (opcode[0])
	{
		for (tripper = 0; op[tripper].opcode; tripper++)
		{
			if (strcmp(op[tripper].opcode, opcode[0]) == TRUE)
			{
				op[tripper].f(stack, data);
				return (TRUE);
			}
		}
	}

	return (!opcode[0] ? TRUE : opcode[0][0] == '#' ? TRUE : FALSE);
}

/**
 * _nop - It makes nothing.
 * @stack: Stack Manager.
 * @line_number: Data for make a push.
 *
 * Return: Nothing.
 */

void _nop(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	;
}
