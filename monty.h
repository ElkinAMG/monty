#ifndef _MONTY_INTERPRETER_
#define _MONTY_INTERPRETER_

/* LIBRARIES */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "structures.h"

/* MACROS */
#define TRUE 0
#define FALSE 1
#define DELIMITER " \t\r\n\a"
#define UNUSED __attribute__((__unused__))
#define OP(x) opcoding(x)
#define VOID(x) (isEmpty(x) == 0)
#define POP_PINT(x) (OP(x) > 0 && OP(x) < 5)
#define D_ZERO(x, y) (x != NULL && divide_by_zero(x, y) == -1)

/* PROTOTYPES */

/* Instructions */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _nop(UNUSED stack_t **stack, UNUSED unsigned int line_number);
void _add(stack_t **stack, UNUSED unsigned int line_number);
void _sub(stack_t **stack, UNUSED unsigned int line_number);
void _mul(stack_t **stack, UNUSED unsigned int line_number);
void _div(stack_t **stack, UNUSED unsigned int line_number);
void _mod(stack_t **stack, UNUSED unsigned int line_number);

/* Error Messages */
void file_error(void);
void open_error(char *filename);
void line_error_code(int *line, char *opcode);
void malloc_error(void);
void push_error(int *ops, char *opcode);
void pop_error(int *ops, char *opcode);
void pint_error(int *ops, char *opcode);
void swap_error(int *ops, char *opcode);
void math_errors(int *ops, char *opcode, char math_o[3]);
void zero_error(int *ops, char *opcode);
void error_handler(stack_t **stack, FILE *file, int *op, char *opcode);

/* File Management */
int open_file(char *filename);
void read_file(FILE *file);

/* Utilities */
int *tokenizer(char *line, int *ar, stack_t **stack);
int isPushing(char *opcode);
int execute(char *opcode[2], stack_t **stack);
void freeStack(stack_t *stack);
int isNumber(char *data);
int isEmpty(stack_t **stack);
int opcoding(char *s);
int divide_by_zero(char *s, stack_t **stack);

#endif /* _MONTY_INTERPRETER_ */
