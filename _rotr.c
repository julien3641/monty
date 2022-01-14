#include "monty.h"

/**
 * _rotr - function that rotates the stack to the bottom
 * @stack: the stack
 * @line_nimber: the line number for error message
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *move;
	(void)line_number;

	tmp = NULL;
	move = *stack;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (move->next != NULL)
			move = move->next;

		move->prev->next = NULL;
	        move->next = *stack;
		move->prev = tmp;
		*stack = move;
		free(tmp);
	}
}
