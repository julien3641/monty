#include "monty.h"

/**
 * _pint - function that prints the value at the top of the stack
 * @stack: the stack
 * @line_number: the line number for error
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
