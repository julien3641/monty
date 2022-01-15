#include "monty.h"

/**
 * _push - function that adds a new node at the beginning of a stack
 * @stack: the stack
 * @line_number: The line number for error
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int return_queue_process, return_stack_process;
	(void)line_number;

	if (cline.check_process == 1)
	{
		return_queue_process = queue_process(stack);
		if (return_queue_process == 0)
			return;
	}

	else
	{
		return_stack_process = stack_process(stack);
		if (return_stack_process == 0)
			return;
	}
}
