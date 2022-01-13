#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_s - variables used in function
 * @stack: a pointer to the beginning of a stack
 * @command: a pointer to the first token
 * @argument: a pointer to the second token
 * @line: a pointer to the string of getline
 * @len: the lenght of the line
 *
 * Description: list of variables used in functions
 * for stack, queues, LIFO, FIFO
 */
typedef struct current_line_p
{
	stack_t *stack;
	char *command;
	char *argument;
	char *line;
	size_t len;
} current_line;
extern current_line cline;

#define INSTRUCTION { \
		{"push", _push},\
		{"pall", _pall},\
		{"pint", _pint},\
		{"pop", _pop},\
		{"swap", _swap},\
		{"nop", _nop},\
		{"add", _add},\
		{"sub", _sub},\
		{"mul", _mul},\
		{"div", _div},\
		{"mod", _mod},\
		{"pchar", _pchar},\
		{"pstr", _pstr},\
		{NULL, NULL}	\
	}

/* Prototype process */
int process(void);
int check_digit(unsigned int *line_number);
int check_opcode(unsigned int *line_number);
void free_stack(stack_t **stack);

/* Prototype opcode */
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
