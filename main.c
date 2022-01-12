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
	int i = 0;
	int j = 0;
	unsigned int line_number = 1;
	FILE *cmd;
	char *line = NULL;
	stack_t *stack = NULL;
	/*void (*fct)(stack_t **stack, unsigned int line_number);*/
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
		cline.command = strtok(line, " \n");
		cline.argument = strtok(NULL, " \n");

		printf("Lecture ligne\n");
		printf("cline.command: %s\n\n", cline.command);

		for (i = 0; list[i].opcode != NULL; i++)
		{
			if (strcmp(list[i].opcode, cline.command) == 0)
			{
				printf("opcode == cline.command\n");
				printf("opcode: %s\n", list[i].opcode);
				printf("cline.command: %s\n\n", cline.command);

				printf("cline.argument: %s\n\n", cline.argument);

				if (strcmp(cline.command, "push") == 0)
				{

					printf("cline.command == push, alors on vérifie isdigit\n");

					for (j = 0; cline.argument[j] != '\0'; j++)
					{
						printf("cline.argument[%d]: %d\n", j, cline.argument[j]);

						if (isdigit(cline.argument[j]) == 0)
						{
							printf("cline.argument[j]: %d == digit\n\n", cline.argument[j]);
							fprintf(stderr, "L%d: usage: push integer\n", line_number);
							exit(EXIT_FAILURE);
						}
					}
				}
				list[i].f(&stack, line_number);
				printf("-----------------\n");
				break;
			}
		}
		if (list[i].opcode == NULL)
		{
			printf("if opcode == NULL\n");
			printf("list[i].opcode: %s\n", list[i].opcode);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cline.argument);
			exit(EXIT_FAILURE);
		}

		line_number++;

	}
	fclose(cmd);
	exit(EXIT_SUCCESS);
	return (0);
}


/*if (strcmp(cline.command, "push") == 0)
		{
			printf("cline.command == push\n");
			cline.argument = strtok(NULL, " \n");
			printf("cline.argument: %s\n", cline.argument);

			if (cline.argument == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}

			for (i = 0; cline.argument[i] != '\0'; i++)
			{
				printf("cline.argument[i]: %s\n\n", cline.argument);
				if (isdigit(cline.argument[i]) == 0)
				{
					printf("cline.argument[i]: %d == digit\n\n", cline.argument[i]);
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
		}

		for (i = 0; list[i].opcode != NULL; i++)
		{
			printf("list[i].opcode: %s\n", list[i].opcode);
			if (strcmp(list[i].opcode, cline.command) == 0)
			{
				printf("opcode == cline.command\n");
				printf("opcode: %s\n", list[i].opcode);
				printf("cline.command: %s\n\n", cline.command);
				list[i].f(stack, line_number);
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
	}*/
