#include "monty.h"
current_line cline;

/**
 * main - function main that runs the monty program
 * @argc: number of arguments
 * @argv: Value of the argument
 * Return: 0 on success or EXIT_FAILURE on error
 */

int main(int argc, char *argv[])
{
	FILE *cmd;
	unsigned int line_number = 1;

	cline.line = NULL;
	cline.stack = NULL;
	cline.command = NULL;
	cline.len = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	cmd = fopen(argv[1], "r");
	if (cmd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((getline(&cline.line, &cline.len, cmd)) != -1)
	{
		if (*cline.line == '\n')
		{
			line_number++;
			continue;
		}
		cline.command = strtok(cline.line, " \n");
		cline.argument = strtok(NULL, " \n");
		check_opcode(line_number);
	}
	free(cline.line);
	free_stack(&cline.stack);
	fclose(cmd);
	exit(EXIT_SUCCESS);
	return (0);
}
