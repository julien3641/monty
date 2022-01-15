#include "monty.h"

/**
 * _mod - function that return the rest of the modulo of
 *  the top two elements of the stack
 * @stack: the stack
 * @line_number: line number for error message
 * Return: nothing
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node, *tmp;
	unsigned int number_node;
	int i, result;
	(void)line_number;

	current_node = *stack;
	number_node = 0;
	for (i = 0; current_node != NULL; i++)
	{
		number_node++;
		current_node = current_node->next;
	}
	if (number_node <= 1)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		result = ((*stack)->next->n) % ((*stack)->n);
		(*stack)->next->n = result;
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		(*stack)->prev = NULL;
	}
}
