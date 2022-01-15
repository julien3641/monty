#include "monty.h"

/**
 * _push - function that adds a new node at the beginning of a stack
 * @stack: the stack
 * @line_number: The line number for error
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int is_number, return_queue_process;
	(void)line_number;

	if (cline.check_process == 1)
	{
		return_queue_process = queue_process(stack);
		if (return_queue_process == 0)
			return;
	}
	
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	is_number = atoi(cline.argument);
	new_node->n = is_number;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
