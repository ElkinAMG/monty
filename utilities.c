#include "monty.h"
/**
 *
 *
 *
 *
 */

void tokenizer(char *line)
{
	char *container[2] = {NULL, NULL};
	/*int i;*/
	container[0] = strtok(line, DELIMITER);

	if(line != NULL)
		container[1] = strtok(NULL, DELIMITER);
	for(; container; *container++)
		printf("%s", container);
}
