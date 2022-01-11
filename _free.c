#include "monty.h"

/**
 * _free - function that free a stack
 * @stack:
 * @line_number:
 * Return:
 */
void _free(stack_t **stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
