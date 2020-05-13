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
#define DELIMITER " \n"

/* PROTOTYPES */

void tokenizer(char *line);
void read_file(FILE *file);

/* Error Messages */
void file_error(void);
void open_error(char *filename);
void line_error_code(int line, char *opcode);
void malloc_error(void);

/* File Management */
int open_file(char *filename);


/* Instructions */
void push();
void pall();

#endif /* _MONTY_INTERPRETER_ */
