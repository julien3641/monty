#include "monty.h"

/**
 * _pop - function that remove the top element of the stack
 * @stack: the stack
 * @line_number: the line number for error
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL) /*if next line is null*/
		(*stack)->prev = NULL;
	free(tmp);
}
