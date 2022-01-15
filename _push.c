#include "monty.h"

/**
 * _push - function that adds a new node at the beginning of a stack
 * @stack: the stack
 * @line_number: The line number for error
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (cline.check_process == 1)
		queue_process(stack);

	else
		stack_process(stack);
}
