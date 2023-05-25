#include "monty.h"
/**
 * push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *n;
	int value;
	stack_t *new_node;
	int queue_mode = 0;
	n = strtok(NULL, " \t\n");

	if (n == NULL || !isnumber(n))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(n);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	if (queue_mode)
	{
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
}
