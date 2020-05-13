#ifndef _MONTY_INTERPRETER_
#define _MONTY_INTERPRETER_

/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "structures.h"

/* MACROS */
#define TRUE 0
#define FALSE 1
#define DELIMITER " \t\r\n\a\""

/* PROTOTYPES */

/* Instructions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);

/* Error Messages */
void file_error(void);
void open_error(char *filename);
void line_error_code(int *line, char *opcode);
void malloc_error(void);

/* File Management */
int open_file(char *filename);
void read_file(FILE *file);

/* Utilities */
int *tokenizer(char *line, int *ar);
int isPushing(char *opcode);
int execute(char *opcode[2]);
char *_itoa(int number);
char *reverse(char *s);

#endif /* _MONTY_INTERPRETER_ */
