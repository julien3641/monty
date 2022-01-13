#include "monty.h"

/**
 * _pstr - function that display the character corresponding in the ASCII table
 * @stack: the stack
 * @line_number: line nmuber for error message
 * Return: Nothing
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;
	if ((*stack) == NULL)
		printf("\n");
	while (tmp)
	{
		if (tmp->n != 0 || (tmp->n > 0 && tmp->n <= 127))
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
		else
			break;
	}
	printf("\n");
}
