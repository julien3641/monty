#include "monty.h"

/**
 * free_global_process - function that free, close and exit
 * free the line
 * free stack and queue process
 * close the file
 * exit success
 * Return: 0 on success
 */
int free_global_process(void)
{
	free(cline.line);
	free_stack_queue(&cline.stack);
	fclose(cline.cmd);
	exit(EXIT_SUCCESS);

	return (0);
}



/**
 * free_stack_queue - function that free the process stack and queue
 * @stack: the stack
 * Return: void
 */
void free_stack_queue(stack_t **stack)
{
	stack_t *tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
