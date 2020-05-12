#ifndef _MONTY_INTERPRETER_
#define _MONTY_INTERPRETER_

/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* MACROS */
#define TRUE 1
#define FALSE 0
#define DELIMITER " \n"

/* PROTOTYPES */

/* Error Messages */
void file_error(void);
void open_error(char *filename);
void line_error_code(int line, char *opcode);
void malloc_error(void);

#endif /* _MONTY_INTERPRETER_ */
