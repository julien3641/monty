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
	unsigned int line_number = 1;

	cline.line = NULL;
	cline.stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	cline.cmd = fopen(argv[1], "r");
	if (cline.cmd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	check_line(&line_number);

	free(cline.line);
	free_stack(&cline.stack);
	fclose(cline.cmd);
	exit(EXIT_SUCCESS);
	return (0);
}
