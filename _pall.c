#include "monty.h"

/**
 * _pall - function that print all the stack
 * @stack: the stack
 * @line_number: the line number for error
 * Return: void
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *tmp = *stack;

	(void)line_number;

	if (tmp)
	{
		while (tmp)
		{
			printf("%d\n", tmp->n);
			i++;
			tmp = tmp->next;
		}

	}
}
