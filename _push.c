#include "monty.h"

/**
 * _push - function that adds a new node at the beginning of a stack
 * @stack:
 * @line_number:
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t new_node;
	(void)line_number;

	new_node = malloc(siseof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
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
