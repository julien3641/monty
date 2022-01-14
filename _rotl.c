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

	tmp = *stack;
	move = *stack;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = (*stack)->next;
                (*stack)->prev = NULL;

		while (move->next != NULL)
			move = move->next;

		tmp->next = NULL;
		tmp->prev = move;
		move->next = tmp;
	}
}
