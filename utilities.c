#include "monty.h"

/**
 * isPushing - asdfasdfasdfasdfasd
 * @opcode: asdfasdfadsfasdfsadf
 *
 * Return: asdsafasdfadsfasdfa
 */

int isPushing(char *opcode)
{
	if (!opcode)
		return (FALSE);

	return (strcmp(opcode, "push"));
}

char *_itoa(int number)
{
	int i;
	char *s;

	s = malloc(sizeof(char *));
	if (!s)
		malloc_error();

	i = 0;
	do {
		s[i++] = number % 10 + '0';
	} while ((number /= 10) > 0);

	s[i] = '\0';
	reverse(s);

	return (s);
}

char *reverse(char *s)
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

	return (s);
}
