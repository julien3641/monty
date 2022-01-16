#include "monty.h"

/**
 * queue_process - function that sets the format of the data to a queue
 * adds a new node at the end of a stack
 * @stack: the stack
 * Return: Nothing
 */
void queue_process(stack_t **stack)
{
	stack_t *new_node, *last_node;
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
		/*return (0);*/
	}

	else
	{
		last_node = *stack;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	/*return (0);*/
}
