#include "monty.h"

/**
 * check_line - function that check the line
 * at first read the line with getline
 * and check the command pass
 * @line_number: the line number for error message
 * Return: 0 on success
 */
int check_line(unsigned int *line_number)
{
	cline.command = NULL;
	cline.len = 0;
	cline.check_process = 0;

	while ((getline(&cline.line, &cline.len, cline.cmd)) != -1)
	{
		(*line_number)++;
		if (*cline.line == '\n')
			continue;

		cline.command = strtok(cline.line, " \n");
		if (cline.command == NULL || cline.command[0] == '#')
			continue;
		else if (strcmp(cline.command, "queue") == 0)
		{
			cline.check_process = 1;
			continue;
		}
		else if (strcmp(cline.command, "stack") == 0)
		{
			cline.check_process = 0;
			continue;
		}

		cline.argument = strtok(NULL, " \n");
		check_opcode(line_number);
	}
	return (0);
}
