#include "monty.h"

/**
 * _push - function that runs queue process or stack_process
 * check_process is by default 0 and the stack process run
 * if the check_process is 1, the queue process run
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
