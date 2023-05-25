#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 *
 i*/
void read_file(char *filename, stack_t **stack)
{
	char *buffer = NULL;
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	int read;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while ((read = getline(&buffer, &i, file)) != -1)
	{
		line = parse(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_func(line);
		if (s == NULL)
		{
			printf("L%d: unknown instruction %s\n", line_count, line);
			error_exit(stack);
		}
		s(stack, line_count);
		line_count++;
	}
	free(buffer);
	check = fclose(file);
	if (check == -1)
		exit(-1);
}
/**
 * get_op_func -  checks opcode and returns the correct function
 * @str: the opcode
 *
 * Return: returns a function, or NULL on failure
 */
instruct_func get_func(char *str)
{
	int i;

	instruction_t instruct[] = {
		{"push", push},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"pchar", pchar},
		{"add", add},
		{"sub", sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"nop", _nop},
		{"pstr", pstr},
		{NULL, NULL},
	};

	i = 0;
	while (instruct[i].f != NULL && strcmp(instruct[i].opcode, str) != 0)
	{
		i++;
	}

	return (instruct[i].f);
}

#include "monty.h"

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 *
 * Return: returns the opcode or null on failure
 */
char *parse(char *line)
{
	char *op_code;

	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);
	return (op_code);
}
/**
 * execute_opcode - Executes the opcode function based on the given opcode
 * @opcode: The opcode to execute
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the opcode in the file
 *
 * Return: 0 if opcode executed successfully, -1 on failure
 */

int execute_opcode(const char *opcode, stack_t **stack,
unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
		push(stack, line_number);
	else if (strcmp(opcode, "pall") == 0)
		_pall(stack);
	else if (strcmp(opcode, "pint") == 0)
		_pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		_pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		_swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		_nop(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else if (strcmp(opcode, "div") == 0)
		_div(stack, line_number);
	else if (strcmp(opcode, "mul") == 0)
		_mul(stack, line_number);
	else if (strcmp(opcode, "mod") == 0)
		_mod(stack, line_number);
	else if (strcmp(opcode, "pchar") == 0)
		pchar(stack, line_number);
	else if (strcmp(opcode, "pstr") == 0)
		pstr(stack, line_number);
	else if (strcmp(opcode, "rotl") == 0)
		_rotl(stack);
	else if (strcmp(opcode, "rotr") == 0)
		_rotr(stack);
	else if (strcmp(opcode, "stack") == 0)
		set_mode(stack, 1, 0);
	else if (strcmp(opcode, "queue") == 0)
		set_mode(stack, 0, 1);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		return (-1);
	}
	return (0);
}
