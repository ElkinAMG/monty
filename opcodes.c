#include "monty.h"


int execute(char *opcode[2])
{
	instruction_t op[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	unsigned int data = 0, tripper;
	static stack_t *stack;

	if (opcode[1] != NULL)
		data = atoi(opcode[1]);

	if (opcode[0])
	{
		for (tripper = 0; op[tripper].opcode; tripper++)
		{
			if (strcmp(op[tripper].opcode, opcode[0]) == TRUE)
			{
				op[tripper].f(&stack, data);
				return (TRUE);
			}
		}
	}

	return (!opcode[0] ? TRUE : FALSE);
}
