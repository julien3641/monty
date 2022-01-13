#include "monty.h"

/**
 * _swap - function that swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number for error
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	unsigned int number_node;
	int i, tmp1, tmp2;

	current_node = *stack;
	number_node = 0;

	for (i = 0; current_node != NULL; i++)
	{
		number_node++;
		current_node = current_node->next;
	}

	if (number_node <= 1)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	else
	{
		tmp1 = (*stack)->n;
		tmp2 = (*stack)->next->n;
		(*stack)->n = tmp2;
		(*stack)->next->n = tmp1;
	}
}
