#include "monty.h"

/**
 * _pchar - function that prints the char at the top of the stack
 * @stack: the stack
 * @line_number : the line number for error message
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n < 0 && (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", (*stack)->n);
}
