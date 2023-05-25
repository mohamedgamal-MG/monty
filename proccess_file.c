#include "monty.h"

/**
 * process_file - Processes the Monty byte code file
 * @fp: Pointer to the file to process
 *
 * Return: 0 if file processed successfully, -1 on failure
 */

int process_file(FILE *fp)
{
	char *line = malloc(MAX_LINE_LENGTH);
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;

	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	while (fgets(line, MAX_LINE_LENGTH, fp) != NULL)
	{
		line_number++;
		if (line[0] == '#')
			continue;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL)
			continue;
		if (execute_opcode(opcode, &stack, line_number) == -1)
		{
			free(line);
			free_stack(stack);
			return (-1);
		}
	}

	free(line);
	free_stack(stack);
	return (0);
}
