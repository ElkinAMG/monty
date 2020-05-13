#include "monty.h"

/**
 * _push - It make a push to the stack.
 * @stack: Stack Manager.
 * @line_number: Data for make a push.
 *
 * Return: Nothing.
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_item;

	new_item = malloc(sizeof(stack_t));
	if (!new_item)
		malloc_error();

	new_item->n = line_number;
	new_item->next = NULL;

	if (!*stack)
		new_item->prev = NULL;

	for (; *stack; stack = &(*stack)->next)
		new_item->prev = *stack;

	*stack = new_item;
}

/**
 * _pall - It prints the stack.
 * @stack: Stack Manager.
 * @line_number: Data for make a push.
 *
 * Return: Nothing.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;


	if (*stack)
	{
		for (; (*stack)->next; stack = &(*stack)->next)
			;

		for (;  (*stack); stack = &(*stack)->prev)
			printf("%d\n",  (*stack)->n);
	}

}

/**
 * _pop - removes the top element of the stack.
 * @stack: Stack Manager.
 * @line_number: Data for make push
 *
 * Return: Nothing
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *deleted_node;

	if (*stack)
	{
		deleted_node = *stack;
		if ((*stack)->next)
			(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(deleted_node);
	}
	else
	{
		printf("stderr, L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
