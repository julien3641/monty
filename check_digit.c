#include "monty.h"

/**
 * check_digit - function that ckeck if argument is a digit
 * @line_number: line number for error message
 * Return: 0 on success or EXIT_FAILURE on error
 */
int check_digit(unsigned int *line_number)
{
	int j = 0;

	if (cline.argument[0] == '-')
		j = 1;
	for (; cline.argument[j] != '\0'; j++)
	{
		printf("cline.argument: %d\n", atoi(cline.argument));
		if (isdigit(cline.argument[j]) == 0)
		{
			printf("line number avant incrémentation: %d\n", *line_number);
			fprintf(stderr, "L%d: usage: push integer\n",
				*line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
