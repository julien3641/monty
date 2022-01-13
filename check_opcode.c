#include "monty.h"

/**
 * check_opcode - function that check the opcode
 * Return: 0 on success or EXIT_FAILURE on error
 */
int check_opcode(unsigned int line_number)
{
	int i = 0;
	instruction_t list[] = INSTRUCTION;

	for (i = 0; list[i].opcode != NULL; i++)

		if (strcmp(list[i].opcode, cline.command) == 0)
		{
			if (strcmp(cline.command, "push") == 0)
				check_digit(line_number);

			list[i].f(&cline.stack, line_number);
			break;
		}

	if (list[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line_number, cline.argument);
		exit(EXIT_FAILURE);
	}
	line_number++;
	return (0);
}
