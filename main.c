#define _GNU_SOURCE
#include "monty.h"

/**
 * main - main
 * @argc: number of arguments
 * @argv: Value of the argument
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i = 0, line_number = 0;
	FILE *cmd;
	char *line = NULL;
	char *token, *token2;
	size_t len = 0;
	stack_t *stack;
	instruction_t list[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}};

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
	while ((getline(&line, &len, cmd)) != -1)
	{
		line_number++;
		token = strtok(line, " \n");
		if (strcmp(token, "push") == 0)
			token2 = strtok(NULL, " \n");
		i = 1;
		while (token2 != NULL)
		{
			if (isdigit(token2[i]))
			{
				fprintf(stderr, "L%d: unknown instruction %d\n", line_number, token[0]);
				exit(EXIT_FAILURE);
			}
		}
		while (list[i].opcode != NULL)
		{
			if (strcmp(list[i].opcode, token) == 0)
			{
				list[i].f(&stack, line_number);
				return (0);
			}
		}
		if (list[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %d\n", line_number, token[0]);
			exit(EXIT_FAILURE);
		}
		fclose(cmd);
	}
	return (0);
}
