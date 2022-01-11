#include "monty.h"

/**
 * _pop - function that remove the top element of the stack
 * @stack:
 * @line_number:
 * Return:
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;

	free(tmp);
	(*stack)->prev = NULL;
}
