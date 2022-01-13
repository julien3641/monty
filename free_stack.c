#include "monty.h"

/**
 * free_stack - function that free a stack
 * @stack: the stack
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
