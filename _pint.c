#include "monty.h"

/**
 * _pint - function that prints the value at the top of the stack
 * @stack:
 * @line_number:
 * Return:
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
}
