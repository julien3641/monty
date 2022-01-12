#define _GNU_SOURCE
#include "monty.h"
current_line cline;

/**
 * main - main
 * @argc: number of arguments
 * @argv: Value of the argument
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, line_number = 0;
	FILE *cmd;
	char *line = NULL;
	stack_t *stack;
	instruction_t list[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}};

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
	while ((getline(&line, &cline.len, cmd)) != -1)
	{
		line_number++;
		cline.command = strtok(line, " \n");
		printf("token command: %s\n", cline.command);
		printf("token[0]: %d\n", cline.command[0]);

		if (cline.command != NULL)
		{
			cline.argument = strtok(NULL, " \n");

			while (list[i].opcode != NULL)
			{
				printf("list[i].opcode: %s\n", list[i].opcode);
				if (strcmp(list[i].opcode, cline.command) == 0)
				{
					list[i].f(&stack, line_number);
 
					if (strcmp(cline.command, "push") == 0)
					{
						i = 0;
						while (cline.argument[i] != '\0')
						{
							printf("cline.argument[i] != '\\0'\n");
							if (isdigit(cline.argument[i]) == 0)
							{
								printf("isdigit: %d\n", cline.argument[i]);
								fprintf(stderr, "L%d: usage: push integer\n", line_number);
								exit(EXIT_FAILURE);
							}
							i++;
						}
					}
					list[i].f(&stack, line_number);
					i++;
				}
			}
			
		if (list[i].opcode == NULL)
		{
                        printf("opcode == NULL\n");
                        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cline.argument);
                        exit(EXIT_FAILURE);
                }
	}

	fclose(cmd);
        return (0);
}



/*if (strcmp(cline.command, "push") == 0)
		{
			printf("strcmp cline.command = push\n");
			cline.argument = strtok(NULL, " \n");
			printf("token argument: %s\n", cline.argument);
			printf("token[0]: %d\n", cline.argument[0]);
			printf("atoi: %d\n", atoi(cline.argument));

			i = 0;
			while (cline.argument[i] != '\0')
			{
				printf("cline.argument[i] != '\\0'\n");
				if (isdigit(cline.argument[i]) == 0)
				{
					printf("isdigit: %d\n", cline.argument[i]);
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				i++;

				while (list[i].opcode != NULL)
				{
					printf("opcode != NULL\n");
					printf("opcode: %s\n", list[i].opcode);
					printf("cline.command: %s\n\n", cline.command);
					if (strcmp(list[i].opcode, cline.command) == 0)
					{
						printf("list[i].ocode: %s\n", list[i].opcode);
						printf("cline.command: %s\n", cline.command);
						list[i].f(&stack, line_number);
						return (0);
					}
					i++;
				}

		if (list[i].opcode == NULL)
		{
			printf("opcode == NULL\n");
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cline.argument);
			exit(EXIT_FAILURE);
		}
	}
	fclose(cmd);

	return (0);
	}*/
