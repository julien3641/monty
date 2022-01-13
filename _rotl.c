#include "monty.h"

/**
 * _rotl - function that rotates the stack to the top
 * @stack: the stack
 * @line_number: the line number for error message
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *move;
	(void)line_number;

	if (*stack != NULL || (*stack)->next != NULL)
	{
		tmp = *stack;
		move = *stack;

		while (move->next != NULL)
			move = move->next;

		*stack = (*stack)->next;
                (*stack)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = move;
		move->next = tmp;
	}
}
