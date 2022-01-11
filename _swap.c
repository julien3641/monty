#include "monty.h"

/**
 * _swap - function that swaps the top two elements of the stack
 * @stack:
 * @line_number:
 * Return:
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	unsigned int number_node;
	int i, *tmp;

	current_node = *stack;
	number_node = 0;

	for (i = 0; current_node != NULL; i++)
	{
		number_node++;
		current_node = current_node->next;
	}

	if (number_node <= 1)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	else
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}
