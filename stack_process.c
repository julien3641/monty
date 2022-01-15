#include "monty.h"

/**
 * stack_process - function that sets the format of the data to a stack
 * adds a new node at the beginning of a stack
 * @stack: the stack
 * Return: 0 on success or EXIT_FAILURE on error
 */
int stack_process(stack_t **stack)
{
	stack_t *new_node;
	int is_number;

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
		return (0);
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	return (0);
}
