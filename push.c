#include "monty.h"
/**
 * push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *arg;
	int push_arg;

	push_arg = 0;
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg != NULL)
	{
		push_arg = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n",line_number);
		exit(EXIT_FAILURE);
	}

	if (sq_flag == 1)
	{
		add_node_end(stack, push_arg);
	}

	if (sq_flag == 0)
	{
		add_node(stack, push_arg);
	}

}
